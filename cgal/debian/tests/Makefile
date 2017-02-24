all: rounding_modes_simple rounding_math_simple rounding_modes_cgal rounding_math_cgal

rounding_modes_simple: rounding_modes_simple.cpp
	g++ $^ -o $@ -frounding-math $(TESTS_IEEE_FPU_OPTION) $(CXXFLAGS) $(LDFLAGS)

rounding_math_simple: rounding_math_simple.cpp
	g++ $^ -o $@ -frounding-math $(TESTS_IEEE_FPU_OPTION) $(CXXFLAGS) $(LDFLAGS)

rounding_modes_cgal: rounding_modes_cgal.cpp
	g++ $^ -o $@ -frounding-math $(TESTS_IEEE_FPU_OPTION) $(CXXFLAGS) $(LDFLAGS) -I../../include -I../../shared/include -lCGAL -L../../shared/lib

rounding_math_cgal: rounding_math_cgal.cpp
	g++ $^ -o $@ -frounding-math $(TESTS_IEEE_FPU_OPTION) $(CXXFLAGS) $(LDFLAGS) -I../../include -I../../shared/include -lCGAL -L../../shared/lib

clean:
	rm -f rounding_modes_simple rounding_math_simple rounding_modes_cgal rounding_math_cgal
