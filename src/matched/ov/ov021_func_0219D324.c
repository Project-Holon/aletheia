/*
 * function: FLDMMDL_BLACT_UpdateCodeChange
 * address:  0x0219D324
 * packet:   pkt_ov021_0219D324
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckStatusBitUse  0x0216DA30  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_BLACT_DeleteActorRes  0x0219C880  thumb  ov021
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm
 */
#include "../include/Obj02700.h"

extern int FLDMMDL_CheckStatusBitUse(int a0, int a1);
typedef unsigned short u16;
typedef unsigned int   u32;
struct BbActSys;
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern u16 FLDMMDL_GetObjCode(void *p);
typedef unsigned char  u8;
extern void FLDMMDL_BLACT_DeleteActorRes(u8 *o, u32 a, u32 b, u32 c);
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count);

void FLDMMDL_BLACT_UpdateCodeChange(int *obj, int *rec)
{
    int h;
    unsigned int n;

    h = rec[0];
    if (FLDMMDL_CheckStatusBitUse(h, (int)rec) == 0) {
        FLDMMDL_BLACT_DeleteActorRes((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, *((unsigned short *)(rec + 1) + 1));
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
        return;
    }
    if ((unsigned short)FLDMMDL_CallDrawGetProc((void *)h, 0) != 0xFFFF) {
        n = *((unsigned short *)(rec + 1) + 1);
        if (n != FLDMMDL_GetObjCode((void *)h)) {
            FLDMMDL_BLACT_DeleteActorRes((u8 *)obj, h, ((struct Obj02700 *)rec)->f4, n);
        }
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)obj[1], ((struct Obj02700 *)rec)->f4, 1);
        rec[0] = 0;
    }
}
