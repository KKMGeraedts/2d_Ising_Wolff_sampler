# 2d_Ising_Wolff_sampler

A C++ implementation of the Wolff algorithm.

Run 'make' to compile the code or have a look at the Makefile.

Then run the compiled code which should be stored in  the 'ising_model' file. 

USAGE:
In the src/main.cpp file you can change some parameters.
  1. L - lattice size of LxL lattice.
  2. J - coupling parameter.
  3. N_thermal - number of steps before sampling starts.
  4. N_mc - number of samples.
  5. n_autocorr - during the sampling stage you might want to only store every n-th sample. This prevents samples from being correlated with each other.
  6. temperatures - list of temperatures to sample at.
  7. filename - the file the samples are stored in. Samples at different temperatures are stored in separate files.
