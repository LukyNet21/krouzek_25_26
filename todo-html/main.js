const todoForm = document.getElementById("todo-form")
const todoItems = document.getElementById("todo-items")

todoForm.addEventListener("submit", (e) => {
  e.preventDefault()
  const formData = new FormData(todoForm)
  const todoItem = document.createElement("li")
  todoItem.innerText = formData.get("todo")
  todoItems.appendChild(todoItem)
  todoForm.reset()
})