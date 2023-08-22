<template>
  <div class="container-top">
    <BarChartYear />
    <DoughnutChart />
  </div>
  <div class="container-bottom">
    <BubbleChart />
    <LineChart />
  </div>
</template>
<script>

import BarChartYear from '../graphics/BarChartYear.vue'
import DoughnutChart from '../graphics/DoughnutChart.vue'
import BubbleChart from '../graphics/BubbleChart.vue'
import LineChart from '../graphics/LineChart.vue'

export default {
  name: 'DashboardView',
  components: {
    BarChartYear,
    DoughnutChart,
    BubbleChart,
    LineChart
  }
}
</script>

<style>
  .container-top {
    display: flex;
    justify-content: space-between;
    margin-bottom:10vh;
    height:32vh;
  }
  .container-bottom {
    display: flex;
    justify-content: space-between;
    height:32vh;
  }
</style>
