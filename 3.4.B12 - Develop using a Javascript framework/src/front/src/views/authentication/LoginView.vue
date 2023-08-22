<template>
  <div class="flex min-h-full">
    <div class="hidden w-0 flex-1 lg:block">
      <img class="h-full w-full object-cover" src="/img/login-img.svg" alt="login_img" />
    </div>
    <div class="flex flex-1 flex-col justify-center py-12 px-4 sm:px-6 lg:flex-none lg:px-20 xl:px-24">
      <div class="mx-auto w-full max-w-sm lg:w-96">
        <div>
          <h2 class="mt-6 text-3xl font-bold tracking-tight text-gray-900">Sign in</h2>
        </div>
        <div class="mt-8">
          <div class="mt-6">
            <div class="space-y-1 mb-6">
              <label for="email" class="block text-sm font-medium text-gray-700">Email address</label>
              <div class="mt-1">
                <input v-model="email" id="email" name="email" type="email" autocomplete="email" required="" class="block w-full appearance-none rounded-md border border-gray-300 px-3 py-2 placeholder-gray-400 shadow-sm focus:border-indigo-500 focus:outline-none focus:ring-indigo-500 sm:text-sm" />
              </div>
            </div>
            <div class="space-y-1 mb-6">
              <label for="password" class="block text-sm font-medium text-gray-700">Password</label>
              <div class="mt-1">
                <input v-model="password" id="password" name="password" type="password" autocomplete="current-password" required="" class="block w-full appearance-none rounded-md border border-gray-300 px-3 py-2 placeholder-gray-400 shadow-sm focus:border-indigo-500 focus:outline-none focus:ring-indigo-500 sm:text-sm" />
              </div>
            </div>
            <div>
              <button @click="login()" class="flex w-full justify-center rounded-md border border-transparent bg-indigo-600 py-2 px-4 text-sm font-medium text-white shadow-sm hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2">Sign in</button>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>

import AuthService from '@/api/authentication/authService.js'

export default {
  // eslint-disable-next-line
  name: 'Login',
  data () {
    return {
      email: '',
      password: ''
    }
  },
  methods: {
    async login () {
      const data = await AuthService.login(this.email, this.password)
      if (data) {
        localStorage.setItem('token', data)
        this.$router.push({ path: '/' })
      }
    }
  }
}

</script>
