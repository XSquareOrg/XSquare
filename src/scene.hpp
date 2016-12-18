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


#ifndef XS_SCENE__
#define XS_SCENE__

namespace xsquare {


class SceneLayer {
protected:
    // priorities (_render_priority and _update_priority)
    // - min -10, max 10;
    // - defines a base render and draw priority for this layer
    //      can help to speed up rendering or updating (in some cases)
    //      by allowing higher priority layers to be processed first
    // NOTE: ultimately the renderer or updater will decide how and if priorities
    //      are used in somecases they may be ignored.
    // - is not affected by force_render_mode
    int _render_priority = 0;
    int _update_priority = 0;
public:
    bool enabled = true;
    bool force_render_mode = 0;
        // -1 - never render -- renderer ignores this layer
        // 0  - off -- normal
        // 1  - always render -- renderer always attempts to render this layer
        //         even if there is nothing renderable (useful in debugging or
        //         in some complex setups where entities are linked on another
        //         layer.
    bool is_empty(void);
    bool has_renderable(void);

    /*
    bool has_empty(void);
    bool has_light(void);
    bool has_camera(void);
    bool has_mesh(void);
    bool has_meta(void);
    bool has_armature(void);
    */
};


class SceneLayers {
public:

};


class Scene {
public:
    // SceneLayers layers;
    // Camera primary_camera = Cameras.dummy;
    Scene() {
        //this->layers = SceneLayers();
    }
    /*
    unsigned long empty_count(void);
    unsigned long light_count(void);
    unsigned long camera_count(void);
    unsigned long mesh_count(void);
    unsigned long meta_count(void);
    unsigned long armature_count(void);
    */
};


} // xsquare

#endif // XS_SCENE__
