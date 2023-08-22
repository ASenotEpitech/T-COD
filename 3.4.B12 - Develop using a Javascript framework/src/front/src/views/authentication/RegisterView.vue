<template>
  <div class="flex min-h-full">
    <div class="hidden w-0 flex-1 lg:block">
      <img class="h-full w-full object-cover" src="/img/login-img.svg" alt="login_img" />
    </div>
    <div class="flex flex-1 flex-col justify-center py-12 px-4 sm:px-6 lg:flex-none lg:px-20 xl:px-24">
      <div class="mx-auto w-full max-w-sm lg:w-96">
        <div>
          <h2 class="mt-6 text-3xl font-bold tracking-tight text-gray-900">Sign up</h2>
        </div>
        <div class="mt-8">
          <div class="mt-6">
            <div class="space-y-1 mb-6">
              <label for="first_name" class="block text-sm font-medium text-gray-700">First name</label>
              <div class="mt-1">
                <input
                  v-model="first_name"
                  type="text"
                  id="first_name"
                  placeholder="Jhon"
                  required
                  class="block w-full appearance-none rounded-md border border-gray-300 px-3 py-2 placeholder-gray-400 shadow-sm focus:border-indigo-500 focus:outline-none focus:ring-indigo-500 sm:text-sm"
                />
              </div>
            </div>
            <div class="space-y-1 mb-6">
              <label for="last_name" class="block text-sm font-medium text-gray-700">Last name</label>
              <div class="mt-1">
                <input
                  v-model="last_name"
                  type="text"
                  id="last_name"
                  placeholder="DOE"
                  required
                  class="block w-full appearance-none rounded-md border border-gray-300 px-3 py-2 placeholder-gray-400 shadow-sm focus:border-indigo-500 focus:outline-none focus:ring-indigo-500 sm:text-sm" />
              </div>
            </div>
            <div class="space-y-1 mb-6">
              <label for="email" class="block text-sm font-medium text-gray-700">Email</label>
              <div class="mt-1">
                <input
                  v-model="email"
                  type="email"
                  id="email"
                  placeholder="john.doe@timemanger.com"
                  required
                  class="block w-full appearance-none rounded-md border border-gray-300 px-3 py-2 placeholder-gray-400 shadow-sm focus:border-indigo-500 focus:outline-none focus:ring-indigo-500 sm:text-sm" />
              </div>
            </div>
            <div class="space-y-1 mb-6">
              <label for="password" class="block text-sm font-medium text-gray-700">Password</label>
              <div class="mt-1">
                <input
                  v-model="password"
                  type="text"
                  id="password"
                  placeholder="*******"
                  required
                  class="block w-full appearance-none rounded-md border border-gray-300 px-3 py-2 placeholder-gray-400 shadow-sm focus:border-indigo-500 focus:outline-none focus:ring-indigo-500 sm:text-sm" />
              </div>
            </div>
            <div>
              <button @click="register()" class="flex w-full justify-center rounded-md border border-transparent bg-indigo-600 py-2 px-4 text-sm font-medium text-white shadow-sm hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-indigo-500 focus:ring-offset-2">Sign in</button>
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
  name: 'Register',
  data () {
    return {
      first_name: '',
      last_name: '',
      email: '',
      password: ''
    }
  },
  methods: {
    async register () {
      const data = await AuthService.register(this.first_name, this.last_name, this.email, this.password, 'user')
      if (data.status === 201) {
        this.$router.push({ path: '/sign_in' })
      }
    }
  }
}
</script>
