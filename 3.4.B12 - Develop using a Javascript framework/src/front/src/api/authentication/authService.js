import axios from 'axios'

const register = async (firstname, lastname, email, password, role) => {
  try {
    const response = await axios.post('http://localhost:4000/users/sign_up',
      {
        user: {
          first_name: firstname,
          last_name: lastname,
          email: email,
          password: password,
          role: role
        }
      }
    )
    return response
  } catch (e) {
    return e
  }
}

const login = async (email, password) => {
  try {
    const response = await axios.post('http://localhost:4000/users/sign_in',
      {
        email: email,
        password: password
      }
    )
    return response.data.access_token
  } catch (e) {
    return e
  }
}

// const logout = async (token) => {
//   console.log('test', token)
//   try {
//     const response = await axios.post('http://localhost:4000/users/sign_out',
//       {
//         headers: { Authorization: `Bearer ${token}` }
//       })
//     console.log('ici', response)
//     return response
//   } catch (e) {
//     return e
//   }
// }

export default { register, login }
