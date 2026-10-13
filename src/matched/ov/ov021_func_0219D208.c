/*
 * function: FLDMMDL_BLACT_ChangeObjCode
 * address:  0x0219D208
 * packet:   pkt_ov021_0219D208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_ChangeObjCode  0x0216E204  thumb  ov010
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   FLDMMDL_BLACT_DeleteActorRes  0x0219C880  thumb  ov021
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm
 */
#include "../include/Obj03119.h"

typedef unsigned short u16;
typedef unsigned int   u32;
struct BbActSys;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern int FLDMMDL_CallDrawGetProc(void *p, unsigned int v);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void FLDMMDL_ChangeObjCode(char *a, u32 v);
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
typedef unsigned char  u8;
extern void FLDMMDL_BLACT_DeleteActorRes(u8 *o, u32 a, u32 b, u32 c);
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count);

void FLDMMDL_BLACT_ChangeObjCode(int a, unsigned int id)
{
    int *ctx;
    int i;
    unsigned char *r;
    unsigned short h;
    unsigned short v[2];

    ctx = (int *)FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)a));
    r = (unsigned char *)ctx[8];
    FLDMMDL_BLACT_FindRes((u32)ctx, id, (u32)(&v[1]), (u32)(&v[0]));
    if (v[1] != 0xFFFF && !(v[0] & 2)) {
        FLDMMDL_ChangeObjCode((char *)a, id);
        return;
    }
    i = 0;
    h = FLDMMDL_CallDrawGetProc((void *)a, 0);
    if (h == 0xFFFF) {
        FLDMMDL_ChangeObjCode((char *)a, id);
        return;
    }
    for (; i < 4; i++) {
        if (((struct Obj03119 *)r)->f0 == 0) {
            break;
        }
    }
    if (i >= 4) {
        FLDMMDL_ChangeObjCode((char *)a, id);
        return;
    }
    ((struct Obj03119 *)r)->f0 = a;
    ((struct Obj03119 *)r)->f4 = h;
    ((struct Obj03119 *)r)->f6 = FLDMMDL_GetObjCode((void *)a);
    ((struct Obj03119 *)r)->f8 = id;
    FLDMMDL_ChangeObjCode((char *)a, id);
    i = 0;
    if (FLDMMDL_CallDrawGetProc((void *)a, 0) != 0xFFFF) {
        FLDMMDL_BLACT_DeleteActorRes((u8 *)ctx, a, ((struct Obj03119 *)r)->f4, ((struct Obj03119 *)r)->f6);
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)ctx[1], ((struct Obj03119 *)r)->f4, 1);
        ((struct Obj03119 *)r)->f0 = i;
    }
}
