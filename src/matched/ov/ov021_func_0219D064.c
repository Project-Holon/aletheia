/*
 * function: FLDMMDL_BLACT_AddReservedActor
 * address:  0x0219D064
 * packet:   pkt_ov021_0219D064
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_BLACT_AddResSlot  0x0219D3F0  thumb  ov021
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   FLDMMDL_BLACT_AddActorMmdlPalette  0x0219C7B4  thumb  ov021
 *   FLDMMDL_BLACT_AddActorPosPalette  0x0219C780  thumb  ov021
 *   FLDMMDL_CallDrawProc  0x0216D758  thumb  ov010
 */
#include "../include/Obj00808.h"

extern unsigned short FLDMMDL_BLACT_AddResSlot(int *o, int a1, int a2, int a3, int a4, int a5);
typedef unsigned int   u32;
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
extern unsigned short FLDMMDL_BLACT_AddActorMmdlPalette(int, unsigned int, unsigned int);
extern unsigned short FLDMMDL_BLACT_AddActorPosPalette(int, int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FLDMMDL_CallDrawProc(void *a0);

void FLDMMDL_BLACT_AddReservedActor(int *obj, int *rec)
{
    unsigned short x[3];
    unsigned short r;

    x[0] = 0xFFFF;
    *((unsigned char *)rec + 0xd) = 0;
    if (rec[4] != 0) {
        x[2] = FLDMMDL_BLACT_AddResSlot(obj, ((struct Obj00808 *)rec)->f8, *((unsigned char *)rec + 0xa),
                             *((unsigned char *)rec + 0xb), rec[4], 1);
        rec[4] = 0;
        FLDMMDL_BLACT_FindRes((u32)obj, ((struct Obj00808 *)rec)->f8, (u32)(&x[0]), (u32)(&x[1]));
    } else {
        FLDMMDL_BLACT_FindRes((u32)obj, ((struct Obj00808 *)rec)->f8, (u32)(&x[2]), (u32)(&x[1]));
    }
    if (rec[1] != 0) {
        r = FLDMMDL_BLACT_AddActorMmdlPalette(rec[1], x[2], x[0]);
    } else {
        r = FLDMMDL_BLACT_AddActorPosPalette(obj[4], (int)(rec + 7), *((unsigned char *)rec + 0xa),
                          *((unsigned char *)rec + 0xc), x[2], x[0]);
    }
    *(unsigned short *)rec[0] = r;
    if (rec[5] != 0) {
        ((void (*)(unsigned int, int))rec[5])(*(unsigned short *)rec[0], rec[6]);
    }
    if (rec[1] != 0) {
        FLDMMDL_CallDrawProc((void *)rec[1]);
    }
}
