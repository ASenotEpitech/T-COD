/* eslint-disable */
import { createRouter, createWebHistory } from "vue-router";
import DashboardView from "@/views/DashboardView.vue";
import LoginView from "@/views/authentication/LoginView.vue";
import RegisterView from "@/views/authentication/RegisterView.vue"

const routes = [
  {
    path: "/",
    name: "home",
    component: DashboardView,
    children: [
      {
        path: "/working-time",
        name: "workingTime",
        component: DashboardView,
      },
      {
        path: "/reports-times",
        name: "reportsTimes",
        component: DashboardView,
      },
      {
        path: "/users",
        name: "users",
        component: DashboardView,
        children: [
          {
            path: "/users/create",
            name: "create.user",
            component: DashboardView,
          }
        ]
      },
    ]
  },
  {
    path: "/sign_in",
    name: "login",
    component: LoginView,
  },
  {
    path: "/sign_up",
    name: "register",
    component: RegisterView,
  },
];

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes,
});

export default router;
