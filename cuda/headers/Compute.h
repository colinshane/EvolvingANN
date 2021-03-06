#ifndef COMPUTE_H
#define COMPUTE_H

#include <cuda.h>
#include <curand_kernel.h>

__global__ void compute(struct Synapse *d_synapses, int *d_neuron_outputs, size_t pitch, curandState_t *curand_state, struct Parameters *d_parameters);

__global__ void read(struct Synapse *d_synapses, size_t pitch);

__global__ void learn(struct Synapse *d_synapses, float reward, size_t pitch, int *d_neuron_outputs, int *d_brain_inputs, curandState_t *d_curand_state);

__global__ void reset_synapses(struct Synapse *d_synapses, float *d_weighted_sums, size_t pitch);

__global__ void update_parameters(struct Parameters *d_parameters);

#endif