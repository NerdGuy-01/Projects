const form = document.querySelector('form')

form.addEventListener('submit',function(event){
    event.preventDefault()

  const height =   parseInt(document.querySelector('#height').value)  // because the value we will get will be in string 
  const weight =   parseInt(document.querySelector('#weight').value)  // If we declare the value before form then empty value will be stored in height
  const result = document.querySelector('#result')

  if(height === '' || height < 0 || isNaN(height)){ 
  result.innerHTML = `Please give a valid height ${height}`
  } else if(weight === '' || weight < 0 || isNaN(weight)){ 
  result.innerHTML = `Please give a valid weight ${weight}`
  }
  else {
    const bmi = (weight / ((height * height) / 10000)).toFixed(2)
    // will show result 
  result.innerHTML = `<span>${bmi}</span>`
  }
  
  
})
