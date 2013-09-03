//
//  Deformabel Simplicial Complex (DSC) method
//  Copyright (C) 2013  Technical University of Denmark
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  See licence.txt for a copy of the GNU General Public License.

#include "normal_function.h"

void NormalFunc::deform(DeformableSimplicialComplex& dsc)
{
    clock_t init_time = clock();
    for(auto vi = dsc.vertices_begin(); vi != dsc.vertices_end(); ++vi)
    {
        if(dsc.is_movable(*vi))
        {
			std::vector<int> labels = dsc.get_interface_labels(*vi);
			if (labels[0]==0)
			{
				dsc.set_destination(*vi, dsc.get_pos(*vi) + VELOCITY * dsc.normal(*vi));
			}
        }
    }
    update_compute_time(clock() - init_time);
    init_time = clock();
    
    dsc.deform();
    
    update_deform_time(clock() - init_time);
}