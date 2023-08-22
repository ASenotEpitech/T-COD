import axios from 'axios'

const createUser = async (firstname, lastname, email, password, role, token) => {
  try {
    const response = await axios.post('http://localhost:4000/api/users',
      {
        user: {
          first_name: firstname,
          last_name: lastname,
          email: email,
          password: password,
          role: role
        }
      },
      {
        headers: { Authorization: `Bearer ${token}` }
      }
    )
    return response
  } catch (e) {
    return e
  }
}

const getAllUsers = async (token) => {
  try {
    const response = await axios.get(
      'http://localhost:4000/api/users',
      {
        headers: { Authorization: `Bearer ${token}` }
      })
    return response.data.data
  } catch (e) {
    return e
  }
}

const getUser = async (id) => {
  try {
    const response = await axios.get(`http://localhost:4000/api/users/${id}`)
    return response.data.data
  } catch (e) {
    return e
  }
}

const updateUser = async (id, firstName, lastName, email, password, token) => {
  try {
    const response = await axios.put(`http://localhost:4000/api/users/${id}`,
      {
        user: {
          first_name: firstName,
          last_name: lastName,
          email: email,
          password: password,
          role: 'user'
        }
      },
      {
        headers: { Authorization: `Bearer ${token}` }
      }
    )
    return response
  } catch (e) {
    return e
  }
}

const deleteUser = async (id, token) => {
  try {
    const response = await axios.delete(`http://localhost:4000/api/users/${id}`,
      {
        headers: { Authorization: `Bearer ${token}` }
      })
    return response
  } catch (e) {
    return e
  }
}

export default { createUser, getAllUsers, getUser, updateUser, deleteUser }
