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


#ifndef XS_WORLD__
#define XS_WORLD__

namespace xsquare {


class WorldVariables {
public:
    struct {
        bool enabled = true;
        float amount = 0.1f;
        //RGB16 color;
        bool _is_renderable(void) {
            return this->enabled && this->amount > 0.0f;
        }
    } ambient_lighting;
    struct {
        bool enabled = true;
        bool solid_sky = false;
            /* if solid_sky is true only sky_color will be used
             *      otherwise a gradient will be formed between sky_color and
             *      horizon_color
             */
        //RGB16 sky_color;
        //RGB16 horizon_color;
        unsigned blend_ratio = 50; // blend ratio between sky_color and horizon_color
        int draw(void);
    } sky;
    float gravity = 9.8f;

    WorldVariables() {}

    int draw(void) { // automatic world draw handler
        return draw(this->sky.enabled);
    }
    int draw(bool draw_sky) { // manual world draw handler
        if (draw_sky) {return 1;}
        return 1;
    }
};


class World {
protected:
public:
    WorldVariables variables = WorldVariables();
};



} // xsquare

#endif // XS_WORLD__
