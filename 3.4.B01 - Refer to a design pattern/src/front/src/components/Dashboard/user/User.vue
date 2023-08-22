<template>
  <div>
    <div class="px-4 sm:px-6 lg:px-8">
      <div class="sm:flex-auto mb-4">
        <h1 class="text-3xl font-semibold text-gray-900">Users</h1>
      </div>
      <div class="flex justify-end">
        <router-link :to="{ name: 'create.user' }" class="mt-4 sm:mt-0 sm:ml-16 sm:flex-none">
          <button type="button" class="inline-flex items-center justify-center rounded-md border border-transparent bg-indigo-600 px-4 py-2 text-sm font-medium text-white shadow-sm hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2 sm:w-auto">Add user</button>
        </router-link>
      </div>
      <div class="mt-8 flex flex-col">
        <div class="-my-2 -mx-4 overflow-x-auto sm:-mx-6 lg:-mx-8">
          <div class="inline-block min-w-full py-2 align-middle md:px-6 lg:px-8">
            <div class="overflow-hidden shadow ring-1 ring-black ring-opacity-5 md:rounded-lg">
              <table class="min-w-full divide-y divide-gray-300">
                <thead class="bg-gray-50">
                  <tr>
                    <th scope="col" class="py-3.5 pl-4 pr-3 text-left text-sm font-semibold text-gray-900 sm:pl-6">
                      <a href="#" class="group inline-flex">
                        First Name
                        <span class="invisible ml-2 flex-none rounded text-gray-400 group-hover:visible group-focus:visible">
                          <ChevronDownIcon class="h-5 w-5" aria-hidden="true" />
                        </span>
                      </a>
                    </th>
                    <th scope="col" class="py-3.5 pl-4 pr-3 text-left text-sm font-semibold text-gray-900 sm:pl-6">
                      <a href="#" class="group inline-flex">
                        Last Name
                        <span class="invisible ml-2 flex-none rounded text-gray-400 group-hover:visible group-focus:visible">
                          <ChevronDownIcon class="h-5 w-5" aria-hidden="true" />
                        </span>
                      </a>
                    </th>
                    <th scope="col" class="px-3 py-3.5 text-left text-sm font-semibold text-gray-900">
                      <a href="#" class="group inline-flex">
                        Email
                        <span class="invisible ml-2 flex-none rounded text-gray-400 group-hover:visible group-focus:visible">
                          <ChevronDownIcon class="invisible ml-2 h-5 w-5 flex-none rounded text-gray-400 group-hover:visible group-focus:visible" aria-hidden="true" />
                        </span>
                      </a>
                    </th>
                      <th scope="col" class="px-3 py-3.5 text-left text-sm font-semibold text-gray-900">
                      <a href="#" class="group inline-flex">
                        Role
                        <span class="invisible ml-2 flex-none rounded text-gray-400 group-hover:visible group-focus:visible">
                          <ChevronDownIcon class="invisible ml-2 h-5 w-5 flex-none rounded text-gray-400 group-hover:visible group-focus:visible" aria-hidden="true" />
                        </span>
                      </a>
                    </th>
                    <th scope="col" class="relative py-3.5 pl-3 pr-4 sm:pr-6">
                        Actions
                    </th>
                  </tr>
                </thead>
                <tbody v-if="people.length" class="divide-gray-200 bg-white">
                  <tr v-for="person in people" :key="person.id">
                    <td class="whitespace-nowrap py-4 pl-4 pr-3 text-left text-sm font-medium text-gray-900 sm:pl-6">{{ person.first_name }}</td>
                    <td class="whitespace-nowrap py-4 pl-4 pr-3 text-left text-sm font-medium text-gray-900 sm:pl-6">{{ person.last_name }}</td>
                    <td class="whitespace-nowrap py-4 pl-4 pr-3 text-left text-sm font-medium text-gray-900 sm:pl-6">{{ person.email }}</td>
                      <td class="whitespace-nowrap py-4 pl-4 pr-3 text-left text-sm font-medium text-gray-900 sm:pl-6">{{ person.role }}</td>
                    <td class="relative whitespace-nowrap flex justify-center py-4 pl-3 text-sm font-medium">
                      <div class="flex">
                        <img @click="openModalEditUser(person)" class="update-icon"  src="/icons/edit-icon.svg" alt="Your Company" />
                        <img @click="deleteUser(person)" class="delete-icon" src="/icons/delete-icon.svg" alt="Your Company" />
                      </div>
                    </td>
                  </tr>
                </tbody>
              </table>
            </div>
          </div>
        </div>
      </div>
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
                    <DialogTitle as="h3" class="text-lg font-medium leading-6 text-gray-900">Modifier cette utilisateur</DialogTitle>
                    <div class="container-inputs">
                      <input
                          v-model="first_name"
                          type="text"
                          id="first_name"
                          class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 mr-2 mt-5"
                          placeholder="first name"
                          required
                      >
                        <input
                          v-model="last_name"
                          type="text"
                          id="last_name"
                          class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 mr-2 mt-5"
                          placeholder="last name"
                          required
                      >
                      <input
                          v-model="email"
                          type="email"
                          id="email"
                          class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 mr-2 mt-5"
                          placeholder="email"
                          required
                      >
                      <input
                          v-model="password"
                          type="text"
                          id="password"
                          class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 mr-2 mt-5"
                          placeholder="password"
                          required
                      >
                    </div>
                  </div>
                </div>
                <div class="mt-5 sm:mt-6 sm:grid sm:grid-flow-row-dense sm:grid-cols-2 sm:gap-3">
                  <button type="button" class="inline-flex w-full justify-center rounded-md border border-transparent bg-indigo-600 px-4 py-2 text-base font-medium text-white shadow-sm hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2 sm:col-start-2 sm:text-sm" @click="updateUser(peopleId)">Confirmer</button>
                  <button type="button" class="mt-3 inline-flex w-full justify-center rounded-md border border-gray-300 bg-white px-4 py-2 text-base font-medium text-gray-700 shadow-sm hover:bg-gray-50 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2 sm:col-start-1 sm:mt-0 sm:text-sm" @click="openModal = false" ref="cancelButtonRef">Annuler</button>
                </div>
              </DialogPanel>
            </TransitionChild>
          </div>
        </div>
      </Dialog>
    </TransitionRoot>
  </div>
</template>

<script setup>
import usersService from '@/api/users/usersService.js'
import { ChevronDownIcon } from '@heroicons/vue/20/solid'
import { Dialog, TransitionChild, TransitionRoot, DialogTitle, DialogPanel } from '@headlessui/vue'
import { ClockIcon } from '@heroicons/vue/24/outline'

</script>

<script>
export default {
  // eslint-disable-next-line
  name: 'User',
  data () {
    return {
      people: [],
      openModal: false,
      first_name: '',
      last_name: '',
      email: '',
      password: '',
      peopleId: '',
      token: ''
    }
  },

  created () {
    this.token = localStorage.getItem('token')
    this.getAllUsers()
  },

  methods: {
    async getAllUsers () {
      this.people = await usersService.getAllUsers(this.token)
    },
    async openModalEditUser (person) {
      this.openModal = true
      this.peopleId = person.id
      this.first_name = person.first_name
      this.last_name = person.last_name
      this.email = person.email
    },
    async updateUser (peopleId) {
      const response = await usersService.updateUser(peopleId, this.first_name, this.last_name, this.email, this.password, this.token)
      if (response) {
        this.openModal = false
        this.getAllUsers()
      }
    },
    async deleteUser (person) {
      try {
        await usersService.deleteUser(person.id, this.token)
      } catch (e) {
        return e
      }
      this.getAllUsers()
    }
  }
}
</script>

<style>
  .update-icon {
    cursor: pointer;
    margin:5px;
  }
  .delete-icon {
    cursor: pointer;
    margin:5px;
  }
  /* .container-inputs { */
    /* display:flex; */
  /* } */
</style>
