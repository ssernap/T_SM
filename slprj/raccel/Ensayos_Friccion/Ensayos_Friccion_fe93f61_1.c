#include "__cf_Ensayos_Friccion.h"
#include "ne_std.h"
#include "ne_default_allocator.h"
#include "ne_dae_fwd.h"
#include "ne_profiler_fwd.h"
#include "ne_dae_construct.h"
#include "Ensayos_Friccion_fe93f61_1_ds.h"
void Ensayos_Friccion_fe93f61_1_dae ( NeDae * * dae , const NeModelParameters
* modelParams , const NeSolverParameters * solverParams , const
NeLinearAlgebra * linear_algebra_ptr ) { NeAllocator * ne_allocator ;
ne_allocator = ne_default_allocator ( ) ; ne_dae_create ( dae ,
Ensayos_Friccion_fe93f61_1_dae_ds ( ne_allocator , NULL ) , * solverParams ,
* modelParams , linear_algebra_ptr , NULL , NULL , NULL , ne_allocator ) ; }
