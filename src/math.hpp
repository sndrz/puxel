/*
    Puxel
    Copyright (C) 2015  Sergey Ivanov

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Sergey Ivanov <sivanov@openmailbox.org>
*/

#ifndef __MATH_HPP
#define __MATH_HPP

namespace math {

    class Vector {
    private:

        float a1, a2, a3;
        float abs;

    public:

        float Abs();

    }; // class Vector

} // namespace math

#endif // __MATH_HPP
