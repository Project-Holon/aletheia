/*
 * function: func_021DECF4
 * address: 0x021DECF4
 * packet: pkt_ov137_021DECF4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_021841A0 0x021841A0 thumb ov022
 *   func_0203D4D0 0x0203D4D0 arm
 */
#include "../include/Obj01753.h"
typedef unsigned char u8;
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern void *func_021DEB10(char *p);
extern unsigned char func_021841A0(unsigned char *p);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_021DECF4(u8 *p)
{
    void *q;
    q = func_020399A8();
    if ((int)func_0203D4D0((u32)q, (u8)((int)func_021841A0(func_021DEB10((char *)p))), (int)10255, (int)1428, (u32)(((struct Obj01753 *)p)->f24), (int)1, (int)1, (int)1))
        ((struct Obj01753 *)p)->f0 = 14;
    return 0;
}
