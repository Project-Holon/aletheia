/*
 * function: FLDMMDL_BLACT_Init
 * address:  0x0219C554
 * packet:   pkt_ov021_0219C554
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Former blocker (now filed in src/matched/arm9): BILLBOARD_ACT_GetBoard (0x02050080) is an unlabelled arm9 leaf with no witness
 * outside this range (the integrator's). Verified C, EXACT under --arm --region arm9:
 *     u32 BILLBOARD_ACT_GetBoard(u32 *p) { return p[1]; }
 * symbols:
 *   FLDMMDL_SysGetHeapId  0x0216D4F8  thumb  ov010
 *   sub_02030734   0x02030734  arm
 *   FLDMMDL_SysSetBlActCont  0x0216D51C  thumb  ov010
 *   FLDMMDL_BLACT_CreateResTable  0x0219CAD8  thumb  ov021
 *   FLDMMDL_BLACT_CreateReserve  0x0219CBE0  thumb  ov021
 *   FLDMMDL_BLACT_CreateCodeChange  0x0219D2CC  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetField10  0x0204ED70  arm
 *   BILLBOARD_SetField24  0x0204EDB0  arm
 *   sBlactFileName     0x021DDD70  data  a1
 *   sBlactBoardScale     0x021D8058  data  a4
 */
#include "../include/Obj03116.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct { u32 a, b, c; } T12;
extern int sBlactFileName;
extern T12 sBlactBoardScale;
extern u32 FLDMMDL_SysGetHeapId(u8 *p);
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void FLDMMDL_SysSetBlActCont(u8 *p, u32 v);
extern void FLDMMDL_BLACT_CreateResTable(void *, u32);
extern void FLDMMDL_BLACT_CreateReserve(u8 *o);
struct Blk3;
extern void FLDMMDL_BLACT_CreateCodeChange(int *obj);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void BILLBOARD_SetField10(u8 *dst, struct Blk3 *src);
extern void BILLBOARD_SetField24(u8 *dst, u8 *src);

void FLDMMDL_BLACT_Init(u32 a, u32 b, u32 c)
{
    u8 *p = sub_02030734(FLDMMDL_SysGetHeapId((u8 *)a), 0x24, 1, (const char *)&sBlactFileName, 360);
    u32 h;
    T12 t;
    u8 z;
    ((struct Obj03116 *)p)->f10 = a;
    ((struct Obj03116 *)p)->f4 = b;
    ((struct Obj03116 *)p)->f2 = c;
    FLDMMDL_SysSetBlActCont((u8 *)a, (u32)p);
    FLDMMDL_BLACT_CreateResTable(p, c);
    FLDMMDL_BLACT_CreateReserve(p);
    FLDMMDL_BLACT_CreateCodeChange((int *)p);
    h = BILLBOARD_ACT_GetBoard((u32 *)b);
    t = sBlactBoardScale;
    BILLBOARD_SetField10((u8 *)h, (struct Blk3 *)(&t));
    z = 0;
    BILLBOARD_SetField24((u8 *)h, &z);
}
