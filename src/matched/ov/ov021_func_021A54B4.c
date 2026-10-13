/*
 * function: FIELD_PLAYER_GRID_FinishHop
 * address:  0x021A54B4
 * packet:   pkt_ov021_021A54B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_MOVE_UpdateMapAttr  0x021640B0  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetMoveBitShadowVanish  0x0216DCE8  thumb  ov010
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12739.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;

extern void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern int FLDMMDL_SetMoveBitShadowVanish(void *a0, int a1);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *obj, struct VecFx32 *out);
extern void FLDMMDL_SetGridNowY(void *p, int v);
extern int FLDMMDL_MOVE_UpdateMapAttr(int a);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);

void FIELD_PLAYER_GRID_FinishHop(u8 *p)
{
    VecFx32 v;
    void *o = FIELD_PLAYER_CORE_GetMmdl(((struct Obj12739 *)p)->fC);

    FLDMMDL_SetStatusBitHeightGetOff(o, 0);
    FLDMMDL_SetMoveBitShadowVanish(o, 0);
    FLDMMDL_SetMoveBit(o, 0x140);
    FLDMMDL_MOVE_UpdateHeight((int)o);
    FLDMMDL_GetPos(o, (struct VecFx32 *)&v);
    FLDMMDL_SetGridNowY(o, (s16)((v.y >> 4) / 4096));
    FLDMMDL_MOVE_UpdateMapAttr((int)o);
    FLDMMDL_MOVE_UpdateOldGridPos((int)o);
}
