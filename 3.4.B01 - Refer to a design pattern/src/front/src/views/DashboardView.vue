<template>
  <div class="home">
    <Sidebar />
  </div>
</template>

<script setup>
import Sidebar from '@/components/Partials/Sidebar.vue'
</script>

<script>

export default {

  data () {
    return {
      token: null
    }
  },

  created () {
    this.token = localStorage.getItem('token')
    if (!this.token) {
      this.$router.push({ name: 'login' })
    }
  }
}
</script>
