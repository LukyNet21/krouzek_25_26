const todoForm = document.getElementById("todo-form")
const todoItems = document.getElementById("todo-items")

const todos = JSON.parse(localStorage.getItem("todos")) || []

function renderTodos() {
  todoItems.innerHTML = ""
  todos.forEach((todo, idx) => {
    const todoItem = document.createElement("li")

    const textItem = document.createElement("span")
    textItem.innerText = todo

    const editButton = document.createElement("button")
    editButton.innerText = "Upravit"

    const editInput = document.createElement("input")
    editInput.value = todo
    editInput.style.display = "none"

    editButton.addEventListener("click", () => {
      if (editInput.style.display === "none") {
        editInput.style.display = "inline"
        textItem.style.display = "none"
        editButton.innerText = "Uložit"
      } else {
        editInput.style.display = "none"
        textItem.style.display = "inline"
        editButton.innerText = "Upravit"

        todos[idx] = editInput.value
        localStorage.setItem("todos", JSON.stringify(todos))
        renderTodos()
      }
    })

    const deleteButton = document.createElement("button")
    deleteButton.innerText = "Smazat"
    deleteButton.addEventListener("click", () => {
      if (!confirm(`Opravdu chcete smazat: "${todo}"`)) return
      todos.splice(idx, 1)
      localStorage.setItem("todos", JSON.stringify(todos))
      renderTodos()
    })

    todoItem.appendChild(textItem)
    todoItem.appendChild(editInput)
    todoItem.appendChild(editButton)
    todoItem.appendChild(deleteButton)
    
    todoItems.appendChild(todoItem)
  })
}

todoForm.addEventListener("submit", (e) => {
  e.preventDefault()
  const formData = new FormData(todoForm)
  todos.push(formData.get("todo"))
  todoForm.reset()
  renderTodos()
  localStorage.setItem("todos", JSON.stringify(todos))
})

renderTodos()