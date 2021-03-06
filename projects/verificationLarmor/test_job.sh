#!/bin/bash -l
## Generated by cscrun
#PBS -l mppwidth=120
#PBS -l mppdepth=1
#PBS -q short
#PBS -V  
#PBS -N ver-Lmr
#PBS -l walltime=0:15:0
cd $PBS_O_WORKDIR 

#increase some variabls to avoid mpi problems
export MPICH_PTL_OTHER_EVENTS=4096
export MPICH_UNEX_BUFFER_SIZE=240000000
export MPICH_MAX_NUM_THREADS=1
aprun -n 120 -d 1 ./vlasiator_meteo_DP_verification-Larmor --run_config=verification-Larmor.cfg

#compute diff between steps separated by one full gyroperiod  
rm diff.dat
for ((i=0;i<1000;i+=50));
  do j=$((i+1000)); 
  filea=$( printf 'grid.%07d.vlsv' $i ); 
  fileb=$( printf 'grid.%07d.vlsv' $j );
  diff=$( vlsvdiff_DP $filea $fileb rho 0 |grep  "The absolute 1-distance" |gawk '{print $8}' ); 
  echo  $i $j $diff >> diff.dat ; 
done

