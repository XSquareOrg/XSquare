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
        protected:
            float amount = 0.1f;
        public:
        bool enabled = true;
        float get_amount(void) {return this->amount;}
        void set_amount(const float amt) {
            if (amt <= 0.1f) this->amount = 0.1f;
            else if (amt >= 1.0f) this->amount = 1.0f;
            else this->amount = amt;
        }
        //RGB16 color;
        bool _is_renderable(void) {
            return this->enabled && this->amount > 0.0f;
        }
    } ambient_lighting;
    struct {
        protected:
            unsigned blend_ratio = 50;
        public:
        bool enabled = true;
        bool solid_sky = false;
            /* if solid_sky is true only sky_color will be used
             *      otherwise a gradient will be formed between sky_color and
             *      horizon_color
             */
        //RGB16 sky_color;
        //RGB16 horizon_color;
        // blend ratio between sky_color and horizon_color
        unsigned get_blend_ratio(void) {return this->blend_ratio;}
        void set_blend_ratio(const unsigned r) {
            if (r >= 100) this->blend_ratio = 100;
            else this->blend_ratio = 0;
        }
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
