<template>
  <div>
    <h1 class="text-3xl font-semibold text-gray-900 mb-4">User Register</h1>
    <form>
      <div class="bg-white px-4 py-5 shadow sm:rounded-lg sm:p-6 mb-4">
        <div class="grid grid-cols-2 gap-4">
          <div>
            <p class="flex">First name</p>
            <input
              v-model="first_name"
              type="text"
              id="first_name"
              class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
              placeholder="John"
              required
            >
          </div>
          <div>
            <p class="flex">Last name</p>
            <input
              v-model="last_name"
              type="text"
              id="last_name"
              class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
              placeholder="DOE"
              required
            >
          </div>
          <div>
            <p class="flex">Email</p>
            <input
              v-model="email"
              type="text"
              id="email"
              class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
              placeholder="john.doe@timemanger.com"
              required
            >
          </div>
          <div>
            <p class="flex">Password</p>
            <input
              v-model="password"
              type="text"
              id="password"
              class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
              placeholder="********"
              required
            >
          </div>
          <div>
            <p class="flex">Role</p>
            <input
              v-model="role"
              type="text"
              id="role"
              class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
              placeholder="user"
              required
            >
          </div>
        </div>
      </div>
    </form>
    <div class="flex justify-end">
        <button @click="submit()" class="ml-3 inline-flex justify-center rounded-md border border-transparent bg-indigo-600 py-2 px-4 text-sm font-medium text-white shadow-sm hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2">Save</button>
    </div>
  </div>
</template>

<script>
import UserService from '@/api/users/usersService.js'

export default {

  data () {
    return {
      first_name: '',
      last_name: '',
      email: '',
      password: '',
      role: '',
      token: ''
    }
  },

  created () {
    this.token = localStorage.getItem('token')
  },

  methods: {
    async submit () {
      await UserService.createUser(this.first_name, this.last_name, this.email, this.password, this.role, this.token)
      this.$router.push({ path: '/users' })
    }
  }
}
</script>
