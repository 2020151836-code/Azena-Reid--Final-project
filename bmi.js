function BMI() {
			var h=document.getElementById('h').value;
			var w=document.getElementById('w').value;
			var bmi=(w/h/h) * 703;
			var bmio=(bmi.toFixed(2));
			
			if(bmio < 18.5) {
				document.getElementById("result").innerHTML="Your BMI is " + bmio + " Weight Category: Underweight";
			}
			
			else if (bmio >= 18.5 && bmio < 24.9) {
				document.getElementById("result").innerHTML="Your BMI is " + bmio + " Weight Category: Healthy";
			}
			
			else if ( bmio >= 25 && bmio < 29.9) {
				document.getElementById("result").innerHTML="Your BMI is " + bmio + " Weight Category: Overweight";
			}
			
			else if ( bmio > 30) {
				document.getElementById("result").innerHTML="Your BMI is " + bmio + " Weight Category: Obese";
			}

			
		}
