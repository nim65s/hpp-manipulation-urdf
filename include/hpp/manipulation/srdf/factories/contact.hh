// Copyright (c) 2014, LAAS-CNRS
// Authors: Joseph Mirabel (joseph.mirabel@laas.fr)
//
// This file is part of hpp-manipulation-urdf.
// hpp-manipulation-urdf is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-manipulation-urdf is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-manipulation-urdf. If not, see <http://www.gnu.org/licenses/>.

#ifndef HPP_MANIPULATION_SRDF_FACTORIES_CONTACT_HH
# define HPP_MANIPULATION_SRDF_FACTORIES_CONTACT_HH

# include <hpp/manipulation/fwd.hh>
# include <fcl/math/transform.h>
# include <fcl/shape/geometric_shapes.h>

# include "hpp/manipulation/srdf/parser.hh"
# include "hpp/manipulation/srdf/factories/sequence.hh"

namespace hpp {
  namespace manipulation {
    namespace srdf {
      class ContactFactory : public ObjectFactory {
        public:
          typedef SequenceFactory <value_type> PointFactory;
          typedef SequenceFactory <unsigned int> TriangleFactory;

          ContactFactory (ObjectFactory* parent, const XMLElement* element) :
            ObjectFactory (parent, element) {}

          virtual void finishTags ();

        private:
          std::list < Triangle > triangles_;
          std::string linkName_, objectName_;
      };
    } // namespace srdf
  } // namespace manipulation
} // namespace hpp

#endif // HPP_MANIPULATION_SRDF_FACTORIES_CONTACT_HH