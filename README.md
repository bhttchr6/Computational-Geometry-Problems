Each `.cpp` file is a self-contained unit and can be compiled and run independently. To compile an individual file, use the following command:

```bash
g++ -std=c++17 <filename>.cpp -o test
```
Learn ray tracing with 2 hours and play around with the `rayTracing.cpp` file to see the implementation.
A very good learning resource for understanding ray tracing, particularly how to implement it with parametric and implicit surfaces, is the following article:

[Scratchapixel - Parametric and Implicit Surfaces](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/parametric-and-implicit-surfaces.html)

`geometry.cpp` consists of a C++ program to check whether a point lies inside(including the boundary) of a triangle or outside. A good resource is the book by John Vince [Mathematics for Computer Graphics](https://www.profajaypashankar.com/wp-content/uploads/2018/09/Mathematics-for-Computer-Graphics-Fifth-Edition.pdf),  [gamemath.com](https://gamemath.com/book/geomprims.html) and Newcastle University [Game Engineering course](https://research.ncl.ac.uk/game/mastersdegree/gametechnologies/physicstutorials/1raycasting/) 

`fibonacci.cpp` is a unique `shared_ptr` based implementation for generating Fibonaci numbers. It just needs to store two numbers to generate the entire series. 

`smartptrs.cpp` is a tutorial/very basic module to learn and play with smart pointers. 

`collision.cpp` checks whether two axis-aligned bounding boxes are colliding or not. 

