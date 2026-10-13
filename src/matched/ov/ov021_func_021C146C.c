/*
 * function: FIELD_PLAYER_GRID_EVENT_JumpUpApproach
 * address:  0x021C146C
 * packet:   pkt_ov021_021C146C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_NAMIPOKE_SPLASH_StartOnEffect  0x021AD564  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset  0x021C12E4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01359.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec3;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FLDMMDL_SetPos(void *a, Vec3 *v);
extern void FIELD_EFFECT_DeleteObject(u32 a);
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(u32 a, u32 b, u32 c);
extern void FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(void *a, u8 *b);

int FIELD_PLAYER_GRID_EVENT_JumpUpApproach(u8 *p)
{
    Vec3 v;
    void *r4;
    u32 r6;

    r4 = FIELD_PLAYER_GetMmdl(((struct Obj01359 *)p)->f3C);
    FLDMMDL_GetPos(r4, (struct VecFx32 *)&v);
    v.x += ((struct Obj01359 *)p)->f30;
    v.z += ((struct Obj01359 *)p)->f38;
    FLDMMDL_SetPos(r4, &v);
    ((struct Obj01359 *)p)->f1C = -((struct Obj01359 *)p)->f1C;
    ((struct Obj01359 *)p)->f8 += 1;
    if (((struct Obj01359 *)p)->f8 >= 0x10) {
        ((struct Obj01359 *)p)->f8 = 0;
        ((struct Obj01359 *)p)->f1C = 0;
        ((struct Obj01359 *)p)->f2 = ((struct Obj01359 *)p)->f2 + 1;
        FIELD_EFFECT_DeleteObject(((struct Obj01359 *)p)->f48);
        r6 = FIELD_PLAYER_GetRideEffect((u8 *)(*(u32 *)&((struct Obj01359 *)p)->f3C));
        {
            u32 k = 2;
            if ((u16)(((struct Obj01359 *)p)->f4 + 0xfffe) <= 1)
                k = 2;
            ((struct Obj01359 *)p)->f48 = FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(FIELDMAP_GetEffect((u8 *)(((struct Obj01359 *)p)->f40)), k, r6);
        }
    }
    FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(r4, p + 0x18);
    return 0;
}
