#ifndef FILEIO_H
#define FILEIO_H

#include <dccrg.hpp>
#include <string>

#include "spatial_cell.hpp"
#include "datareducer.h"


/*!

\brief Write out system into a vlsv file

\param mpiGrid   The DCCRG grid with spatial cells
\param dataReducer Contains datareductionoperators that are used to compute data that is added into file
\param name       File name prefix, file will be called "name.index.vlsv"
\param index      File index, file will be called "name.index.vlsv"
\param writeRestart If true, the full velocity distribution will be written out.
*/


bool writeGrid(const dccrg::Dccrg<spatial_cell::SpatialCell>& mpiGrid,
               DataReducer& dataReducer,
               const std::string& name,
               const uint& index,
               const bool& writeRestart);


/*!

\brief Read in state from a vlsv file in order to restart simulations
*/


bool readGrid(dccrg::Dccrg<spatial_cell::SpatialCell>& mpiGrid,
              const std::string& name);



/*!

\brief Write out simulation diagnostics into diagnostic.txt

\param mpiGrid   The DCCRG grid with spatial cells
\param dataReducer Contains datareductionoperators that are used to compute diagnostic data
\param tstep Current simulation step, first colmun in file
*/

bool writeDiagnostic(const dccrg::Dccrg<SpatialCell>& mpiGrid, DataReducer& dataReducer, luint tstep);

#endif
