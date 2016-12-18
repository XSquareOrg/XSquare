/* ------------------------------------------------------------------------ *
 *   XSquare is free software: you can redistribute it and/or               *
 *   modify it under the terms of the GNU Lesser General Public License as  *
 *   published by the Free Software Foundation version 3 of the Licence, or *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   XSquare is distributed in the hope that it will be useful,             *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 *   General Public License for more details.                               *
 *                                                                          *
 *   You should have received copies of the GNU General Public License and  *
 *   the GNU Lesser General Public License along with this program.  If     *
 *   not, see http://www.gnu.org/licenses/.                                 *
* ------------------------------------------------------------------------- */


#ifndef XS_VALIDATE__
#define XS_VALIDATE__

#define MIN_XS_CORE_VER_MAJOR 0
#define MIN_XS_CORE_VER_MINOR 1
#define MIN_XS_CORE_VER_STRING "0.1"

#if (XS_CORE_VERSION_MAJOR < MIN_XS_CORE_VER_MAJOR) || \
    (XS_CORE_VERION_MINOR < MIN_XS_CORE_VER_MINOR)
    // FIXME
    #error Requires xs-core >= "0.1"//MIN_XS_CORE_VER_STRING
#else
    #undef MIN_XS_CORE_VER_MAJOR
    #undef MIN_XS_CORE_VER_MINOR
    #undef MIN_XS_CORE_VER_STRING
#endif

#endif // XS_VALIDATE__
