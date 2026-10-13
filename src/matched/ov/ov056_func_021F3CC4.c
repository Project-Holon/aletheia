/*
 * function: FIELD_FK_DEMO_SetPlayerHidden
 * address:  0x021F3CC4
 * packet:   pkt_ov056_021F3CC4
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_InitGridPosition  0x0216E084  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 */
#include "../include/Obj01881.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

struct Actor;
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern void FLDMMDL_InitGridPosition(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);
extern int FLDMMDL_SetMoveBitReflect(void *a0, int a1);

void FIELD_FK_DEMO_SetPlayerHidden(u8 *p, int flag)
{
    VecFx32 v;

    if (flag) {
        ((struct Obj01881 *)p)->f5C = 1;
        FLDMMDL_SetStatusBitVanish(((struct Obj01881 *)p)->f68, 1);
        return;
    }
    ((struct Obj01881 *)p)->f5C = 0;
    FLDMMDL_SetStatusBitVanish(((struct Obj01881 *)p)->f68, 0);
    FLDMMDL_InitGridPosition(((struct Obj01881 *)p)->f68, (s16)(((struct Obj01881 *)p)->f6C), (s16)(((struct Obj01881 *)p)->f70),
                  (s16)(((struct Obj01881 *)p)->f74), ((struct Obj01881 *)p)->f78);
    FLDMMDL_MOVE_UpdateHeight((int)(((struct Obj01881 *)p)->f68));
    FLDMMDL_GetPos(((struct Obj01881 *)p)->f68, &v);
    FIELD_PLAYER_SetPos(((struct Obj01881 *)p)->f64, &v);
    FLDMMDL_SetMoveBitReflect(((struct Obj01881 *)p)->f68, 0);
}
