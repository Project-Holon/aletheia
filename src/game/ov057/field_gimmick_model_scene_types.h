#ifndef ALETHEIA_OV057_FIELD_GIMMICK_MODEL_SCENE_TYPES_H
#define ALETHEIA_OV057_FIELD_GIMMICK_MODEL_SCENE_TYPES_H

/*
 * Model scene of overlay 57: seven resources loaded from one archive, three
 * render objects built from them, four animations and three drawable objects
 * that share the animation table.
 */

/*
 * The 3D system types come from ov021/fld_exp_obj_types.h, which the source
 * file includes first (the compiler resolves includes against the source
 * file directory, so this header cannot include it). A file that does not
 * include it sees the types as opaque.
 */
#ifndef ALETHEIA_OV021_FLD_EXP_OBJ_TYPES_H
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct G3dResource G3dResource;
typedef struct G3dRender G3dRender;
typedef struct G3dAnime G3dAnime;
typedef struct G3dObject G3dObject;
typedef struct G3dObjectStatus G3dObjectStatus;
#endif

struct FieldMap;

#define MODEL_SCENE_RESOURCE_COUNT 7
#define MODEL_SCENE_RENDER_COUNT   3
#define MODEL_SCENE_ANIME_COUNT    4
#define MODEL_SCENE_OBJECT_COUNT   3

/* The work of the scene (0x44 bytes). */
typedef struct ModelScene {
    G3dResource *resource[MODEL_SCENE_RESOURCE_COUNT];  /* 0x00 */
    G3dRender   *render[MODEL_SCENE_RENDER_COUNT];      /* 0x1C */
    G3dAnime    *anime[MODEL_SCENE_ANIME_COUNT];        /* 0x28 */
    G3dObject   *object[MODEL_SCENE_OBJECT_COUNT];      /* 0x38 */
} ModelScene;

/* The position, scale and rotation the three objects are drawn with. */
extern G3dObjectStatus sModelSceneDrawStatus;

extern void G3D_SYSTEM_DrawObject(G3dObject *object, G3dObjectStatus *status);

#endif
