/*
 * function: GFL_NET_ERR_RecordError
 * address:  0x0200FAAC
 * packet:   pkt_0200FAAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wave 13: the parked MATCH named its global as 0x0202617C, a transcription
 * slip; the pool word at 0x0200FB20 reads 0x0214617C, the net_err.c module
 * object every sibling uses (literal x42), and the site resolves with it.
 *
 * symbols:
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_NET_STATE_GetErrorMode  0x0203C990  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   sub_02010054   0x02010054  thumb
 *   g0214617C      0x0214617C  data
 */
#include "../include/Obj03039.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Blk16_0200FAAC {
    u32 w[4];
};

extern int   sub_02010054(void);
extern int   GFL_NET_IsSessionNull(void);
extern u32 GFL_NET_STATE_GetErrorMode(void);
extern u32 GFL_NET_STATE_GetError(void);
extern u8   *GFL_NET_GetInitParam(void);
extern u8    g0214617C[];

void GFL_NET_ERR_RecordError(void)
{
    u8 *g = g0214617C;
    u8 t;

    if (sub_02010054() == 0) {
        return;
    }
    if (((struct Obj03039 *)g)->f2C != 0) {
        return;
    }
    ((struct Obj03039 *)g)->f2C = 1;
    if (GFL_NET_IsSessionNull() != 0) {
        return;
    }
    ((struct Obj03039 *)g)->f59 = GFL_NET_GetInitParam()[0x65];
    *(struct Blk16_0200FAAC *)(g + 0x48) = *(struct Blk16_0200FAAC *)GFL_NET_STATE_GetError();
    ((struct Obj03039 *)g)->f58 = (u8)GFL_NET_STATE_GetErrorMode();
    t = ((struct Obj03039 *)g)->f59;
    if (t == 1 || t == 2 || t == 6) {
        if ((u32)(((struct Obj03039 *)g)->f4C - 1) <= 1) {
            ((struct Obj03039 *)g)->f5C = 2;
        } else {
            ((struct Obj03039 *)g)->f5C = 1;
        }
        return;
    }
    ((struct Obj03039 *)g)->f5C = 2;
}
