/*
 * This file is part of Vlasiator.
 * Copyright 2010-2016 Finnish Meteorological Institute
 *
 * For details of usage, see the COPYING file and read the "Rules of the Road"
 * at http://vlasiator.fmi.fi/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FIREHOSE_H
#define FIREHOSE_H

#include "../../definitions.h"
#include "../project.h"

namespace projects {
   class Firehose: public Project {
    public:
      Firehose();
      virtual ~Firehose();
      
      virtual bool initialize(void);
      static void addParameters(void);
      virtual void getParameters(void);
      
    protected:
      Real getDistribValue(
                           creal& x,creal& y,
                           creal& vx, creal& vy, creal& vz,
                           creal& dvx, creal& dvy, creal& dvz
                          );
      Real profile(creal top, creal bottom, creal x);
      virtual void calcCellParameters(spatial_cell::SpatialCell* cell,creal& t);
      virtual Real calcPhaseSpaceDensity(
                                         creal& x, creal& y, creal& z,
                                         creal& dx, creal& dy, creal& dz,
                                         creal& vx, creal& vy, creal& vz,
                                         creal& dvx, creal& dvy, creal& dvz,const int& popID
                                        );
      
      Real rho[2];
      Real Tx[2];
      Real Ty[2];
      Real Tz[2];
      Real Vx[2];
      Real Vy[2];
      Real Vz[2];
      Real Bx;
      Real By;
      Real Bz;   
      Real lambda;
      Real amp;
      uint nSpaceSamples;
      uint nVelocitySamples;
   }; // class Firehose
} // namespace projects

#endif
