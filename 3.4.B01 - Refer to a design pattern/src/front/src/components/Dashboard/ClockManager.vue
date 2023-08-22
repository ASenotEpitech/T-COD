<template>
  <div v-if="deletedTime === false">
    <p class="text-2xl mb-20">
    Vous avez badgé une
    <span v-if="previousClock.status === true" class="font-bold">
      entrée
    </span>
    <span v-if="previousClock.status === false" class="font-bold">
      sortie
    </span>
      à cette date : {{previousClock.time.toUTCString()}}
    </p>
  </div>
  <div v-if="deletedTime === true" class="text-2xl mb-20">
    Vous n'avez pas d'enregistrement récent.
  </div>
  <div class="text-4xl mb-20">{{ dateTime.hours }}:{{ dateTime.minutes }}:{{ dateTime.seconds }}</div>
  <div v-if="deletedTime === false" class="mb-10">
    <button
      type="button"
      class="relative inline-flex items-center rounded-md border border-gray-300 bg-white px-4 py-2 text-l font-medium text-gray-700 hover:bg-gray-50 focus:z-10 focus:border-indigo-500 focus:outline-none focus:ring-1 focus:ring-indigo-500"
      data-bs-toggle="modal" data-bs-target="#exampleModal"
      @click="openModal = true"
    >
        Enregistrer une {{previousClock.status ? 'sortie' : 'entrée'}}
    </button>
  </div>
  <div v-if="deletedTime === true" class="mb-10">
    <button
      type="button"
      class="relative inline-flex items-center rounded-md border border-gray-300 bg-white px-4 py-2 text-l font-medium text-gray-700 hover:bg-gray-50 focus:z-10 focus:border-indigo-500 focus:outline-none focus:ring-1 focus:ring-indigo-500"
      data-bs-toggle="modal" data-bs-target="#exampleModal"
      @click="openModal = true"
    >
        Enregistrer une entrée
    </button>
  </div>

  <div>
    <button
      type="button"
      class="relative inline-flex items-center rounded-md border border-gray-300 bg-white px-4 py-2 text-l font-medium text-gray-700 hover:bg-gray-50 focus:z-10 focus:border-indigo-500 focus:outline-none focus:ring-1 focus:ring-indigo-500"
      data-bs-toggle="modal" data-bs-target="#exampleModal"
      @click="deletePreviousTime"
    >
        Supprimer le dernier passage
    </button>
  </div>

  <TransitionRoot as="template" :show="openModal">
    <Dialog as="div" class="relative z-10" @close="openModal = false">
      <TransitionChild as="template" enter="ease-out duration-300" enter-from="opacity-0" enter-to="opacity-100" leave="ease-in duration-200" leave-from="opacity-100" leave-to="opacity-0">
        <div class="fixed inset-0 bg-gray-500 bg-opacity-75 transition-opacity" />
      </TransitionChild>

      <div class="fixed inset-0 z-10 overflow-y-auto">
        <div class="flex min-h-full items-end justify-center p-4 text-center sm:items-center sm:p-0">
          <TransitionChild as="template" enter="ease-out duration-300" enter-from="opacity-0 translate-y-4 sm:translate-y-0 sm:scale-95" enter-to="opacity-100 translate-y-0 sm:scale-100" leave="ease-in duration-200" leave-from="opacity-100 translate-y-0 sm:scale-100" leave-to="opacity-0 translate-y-4 sm:translate-y-0 sm:scale-95">
            <DialogPanel class="relative transform overflow-hidden rounded-lg bg-white px-4 pt-5 pb-4 text-left shadow-xl transition-all sm:my-8 sm:w-full sm:max-w-lg sm:p-6">
              <div>
                <div class="mx-auto flex h-12 w-12 items-center justify-center rounded-full bg-green-100">
                  <ClockIcon class="h-6 w-6 text-green-600" aria-hidden="true" />
                </div>
                <div class="mt-3 text-center sm:mt-5">
                  <DialogTitle as="h3" class="text-lg font-medium leading-6 text-gray-900">Enregistrer cet horaire ?</DialogTitle>
                  <div class="mt-2">
                    <p class="text-sm text-gray-500">Vous allez enregistrer ce nouvel horaire.</p>
                    <p class="text-sm text-gray-500">Êtes-vous sûr de vouloir le faire ?</p>
                  </div>
                </div>
              </div>
              <div class="mt-5 sm:mt-6 sm:grid sm:grid-flow-row-dense sm:grid-cols-2 sm:gap-3">
                <button type="button" class="inline-flex w-full justify-center rounded-md border border-transparent bg-indigo-600 px-4 py-2 text-base font-medium text-white shadow-sm hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2 sm:col-start-2 sm:text-sm" @click="setClocking">Confirmer</button>
                <button type="button" class="mt-3 inline-flex w-full justify-center rounded-md border border-gray-300 bg-white px-4 py-2 text-base font-medium text-gray-700 shadow-sm hover:bg-gray-50 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2 sm:col-start-1 sm:mt-0 sm:text-sm" @click="openModal = false" ref="cancelButtonRef">Annuler</button>
              </div>
            </DialogPanel>
          </TransitionChild>
        </div>
      </div>
    </Dialog>
  </TransitionRoot>
</template>

<script setup>
import { Dialog, DialogPanel, DialogTitle, TransitionChild, TransitionRoot } from '@headlessui/vue'
import { ClockIcon } from '@heroicons/vue/24/outline'
</script>

<script>
const date = new Date()
export default {
  name: 'ClockManager',

  data () {
    return {
      openModal: false,
      dateTime: {
        hours: date.getHours(),
        minutes: date.getMinutes(),
        seconds: date.getSeconds()
      },

      timer: undefined,
      previousClock: {
        time: new Date(Date.UTC(2022, 10, 28, 8, 30, 0)),
        status: true,
        user: 2
      },
      deletedTime: false
    }
  },
  methods: {
    setClocking () {
      this.previousClock.time = date
      if (this.previousClock.status === true) {
        this.previousClock.status = false
      } else {
        this.previousClock.status = true
      }
      this.openModal = false
      this.deletedTime = false
    },

    setDateTime () {
      const date = new Date()
      this.dateTime = {
        hours: date.getHours(),
        minutes: date.getMinutes(),
        seconds: date.getSeconds()
      }
    },

    deletePreviousTime () {
      this.deletedTime = true
    }
  },
  beforeMount () {
    this.timer = setInterval(this.setDateTime, 1000)
  },
  beforeUnmount () {
    clearInterval(this.timer)
  }
}
</script>
