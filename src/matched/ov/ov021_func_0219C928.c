/*
 * function: FLDMMDL_BLACT_AddActorPosOrReserve
 * address:  0x0219C928
 * packet:   pkt_ov021_0219C928
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   FLDMMDL_BLACT_AddActorPos  0x0219C6B8  thumb  ov021
 *   FLDMMDL_BLACT_ReserveActor  0x0219CFB0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03118.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
extern u32 FLDMMDL_BLACT_AddActorPos(u32, V3 *, int, u32, u16);
extern void FLDMMDL_BLACT_ReserveActor(u32, u32, u16 *, u16 *, u32, u32, u32);

/* b is const: that is what lets the b[7]/b[9] loads schedule above the
 * outgoing stack-argument store of v. */
int FLDMMDL_BLACT_AddActorPosOrReserve(u32 a, const u8 *b, u16 *c, V3 *d, u32 s0, u32 s1)
{
    u16 v;
    u32 t = FLDMMDL_SysGetBlActCont((void *)a);
    FLDMMDL_BLACT_FindRes(t, *(const u16 *)&((struct Obj03118 *)b)->f0, (u32)(&v), (u32)c);
    if (!(*c & 2)) {
        c[1] = FLDMMDL_BLACT_AddActorPos(a, d, b[7], b[9], v);
        return 1;
    }
    c[1] = 0xFFFF;
    FLDMMDL_BLACT_ReserveActor(t, 0, (u16 *)b, &c[1], s0, s1, (u32)d);
    return 0;
}
