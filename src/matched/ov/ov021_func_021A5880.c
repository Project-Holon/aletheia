/*
 * function: FIELD_PLAYER_NOGRID_Create
 * address:  0x021A5880
 * packet:   pkt_ov021_021A5880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_ChangeHeader  0x0216E0AC  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb  ov021
 *   FIELD_PLAYER_NOGRID_InitInputHold  0x021A6B88  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFormCode  0x021A3974  thumb  ov021
 *   FIELD_PLAYER_CORE_StartFormChange  0x021A3CB0  thumb  ov021
 *   FIELD_PLAYER_CORE_FinishFormChange  0x021A3CE8  thumb  ov021
 *   d_021DDF04     0x021DDF04  data  a4
 *   gFieldPlayerNogridMmdlHeader     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01499.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern char d_021DDF04;
extern u16  gFieldPlayerNogridMmdlHeader[2];
extern u16  d_021DDEE0b[2];

typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 FIELD_PLAYER_CORE_GetFieldMap(u8 *p);
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetMoveCode(void *p);
extern u16 FLDMMDL_GetObjCode(void *o);
extern void FLDMMDL_ChangeHeader(void *o, void *d);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FLDMMDL_RAIL_SetLocation(void *a, void *r);
extern int FIELD_PLAYER_NOGRID_InitInputHold(void *a);
extern u32 FIELD_PLAYER_CORE_GetFormCode(u8 *p);
extern int FIELD_PLAYER_CORE_StartFormChange(u32 a, u32 b);
extern void FIELD_PLAYER_CORE_FinishFormChange(u8 *p);

static void clr4(u16 *q)
{
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
}

u8 *FIELD_PLAYER_NOGRID_Create(u8 *obj, int heap)
{
    u8 *p;

    p = func_02030734(heap, 0x24, 1, &d_021DDF04, 0x1a0);
    *(u8 * *)&((struct Obj01499 *)p)->f14 = obj;
    ((struct Obj01499 *)p)->f18 = FIELD_PLAYER_CORE_GetFieldMap(obj);
    ((struct Obj01499 *)p)->f1C = FIELD_PLAYER_CORE_GetMmdl(*(u8 * *)&((struct Obj01499 *)p)->f14);
    if (FLDMMDL_GetMoveCode(((struct Obj01499 *)p)->f1C) != 0x45) {
        gFieldPlayerNogridMmdlHeader[1] = FLDMMDL_GetObjCode(((struct Obj01499 *)p)->f1C);
        FLDMMDL_ChangeHeader(((struct Obj01499 *)p)->f1C, d_021DDEE0b);
    }
    ((struct Obj01499 *)p)->f20 = (int)FLDMMDL_RAIL_GetRailWork(((struct Obj01499 *)p)->f1C);
    {
        u16 v[4] = {0, 0, 0, 0};
        FLDMMDL_RAIL_SetLocation(((struct Obj01499 *)p)->f1C, v);
    }
    FIELD_PLAYER_NOGRID_InitInputHold(p + 0xc);
    {
        int t = FIELD_PLAYER_CORE_GetFormCode(*(u8 * *)&((struct Obj01499 *)p)->f14);
        switch (t) {
        case 2:
            FIELD_PLAYER_CORE_StartFormChange((u32)(*(u8 * *)&((struct Obj01499 *)p)->f14), 4);
            FIELD_PLAYER_CORE_FinishFormChange(*(u8 * *)&((struct Obj01499 *)p)->f14);
            break;
        case 3:
            FIELD_PLAYER_CORE_StartFormChange((u32)(*(u8 * *)&((struct Obj01499 *)p)->f14), 0x100);
            FIELD_PLAYER_CORE_FinishFormChange(*(u8 * *)&((struct Obj01499 *)p)->f14);
            break;
        }
    }
    return p;
}
