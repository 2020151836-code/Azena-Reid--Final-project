// SDLC Animation Script
const phases = document.querySelectorAll('.phase');
const arrows = document.querySelectorAll('.arrow');
let index = 0;

function animateWaterfall() {
  // Reset all
  phases.forEach(p => p.classList.remove('active'));
  arrows.forEach(a => a.classList.remove('active'));

  // Activate current phase and arrows
  for (let i = 0; i <= index; i++) {
    phases[i].classList.add('active');
    if (i > 0) arrows[i - 1].classList.add('active');
  }

  index++;
  if (index >= phases.length) index = 0;
}

// Run animation
animateWaterfall();
setInterval(animateWaterfall, 2000);
