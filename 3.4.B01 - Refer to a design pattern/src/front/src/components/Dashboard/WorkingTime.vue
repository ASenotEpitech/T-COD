<template>
    <BarChart v-if="periods[0].current === true" width="100vw" height="100vh"/>
    <BarChartYear v-if="periods[1].current === true" width="100vw" height="100vh" />
    <div>
    <div>
        <span class="mt-10 isolate inline-flex rounded-md shadow-sm">
            <button v-for="item in periods"
            :key='item.name'
                type="button"
                class="relative inline-flex items-center mx-5 border border-gray-300 bg-white px-4 py-2 text-sm font-medium text-gray-700 hover:bg-gray-50 focus:z-10 focus:border-indigo-500 focus:outline-none focus:ring-1 focus:ring-indigo-500"
                @click="setCurrent(item)"
            >
                {{item.period}}
            </button>
            <!-- <button type="button" class="relative -ml-px inline-flex items-center border border-gray-300 bg-white px-4 py-2 text-sm font-medium text-gray-700 hover:bg-gray-50 focus:z-10 focus:border-indigo-500 focus:outline-none focus:ring-1 focus:ring-indigo-500">Months</button>
            <button type="button" class="relative -ml-px inline-flex items-center rounded-r-md border border-gray-300 bg-white px-4 py-2 text-sm font-medium text-gray-700 hover:bg-gray-50 focus:z-10 focus:border-indigo-500 focus:outline-none focus:ring-1 focus:ring-indigo-500">Days</button> -->
        </span>
    </div>
      <WorkingTimes />
    </div>
</template>

<script setup>
import BarChart from '../graphics/BarChartDays.vue'
import BarChartYear from '../graphics/BarChartYear.vue'
import WorkingTimes from '../Dashboard/WorkingTimes.vue'

import { reactive } from 'vue'

const periods = reactive([
  { period: 'Day', current: true },
  { period: 'Year', current: false }
])
function setCurrent (item) {
  periods.forEach(element => {
    element.current = false
  })
  item.current = true
}
</script>
