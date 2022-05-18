I started this project as a way to learn, at this point I am a much better programmer than when I started this project and it is still very much a work in progress so there may be some bad code artefacts residing in the project (```the next_frame()``` method in the Particle class for example, that would make more sense being broken down separated). Some of the branches may not follow any convention as I am still learning about Git and naming conventions.

The project uses the openframeworks framework (https://openframeworks.cc/) which wraps a number of graphical and input libraries into a neat package that is much easier to approach. The framework creates ofApp.cpp, ofApp.h and main.cpp as a template for you to edit but everything else in the scr folder has been created from scratch. 

The main objective of the project was to make an interactive 2d physics simulation with no additional libraries other than the openframeworks framework. Coming from an engineering background, the physics and vector maths translated well. The collision detection of particles, although primitive, was something I had not done previously so researching that and implementing it was particularly enjoyable - see ```ParticleSystem::p2p_collision()```. Another subtle yet satisfying feature is that depending on how big the particle is, it falls at different speeds, simulating fluid density and resistance.

The structure and complexity of the project has changed dramatically over time, where nearly everything is neatly organised in classes; it previously only had the particle class. An early blog post I made looking for feedback on my code can be found here - https://forum.openframeworks.cc/t/particle-physics-without-ofxbox2d/38899

If you download the bin directory and run “moving particles.exe” it should run the program, left mouse click acts as an attractor and right mouse click acts as a repulsor.

Now that I have the basis of a physics simulation, I want to add some open CV functionality to the program to allow for interactions via a camera. I would also like to make the collision detection function faster by removing the number of square root calculations it has to make allowing me to run the program with more particles.

