/*
 * function: MYSTERY_DATA_Init
 * address:  0x02009EDC
 * packet:   pkt_02009EDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 */
#include "../include/Obj11227.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02082BCC(void *p, int c, u32 n);
struct Obj;
extern void MYSTERY_DATA_Encrypt(struct Obj *p);

void MYSTERY_DATA_Init(void *a0)
{
    u8 buf[12];

    func_02082BCC(buf, 0, 0xc);
    ((struct Obj11227 *)buf)->f0 = a0;
    ((struct Obj11227 *)buf)->f4 = 1;
    func_02082BCC(a0, 0, 0xa94);
    MYSTERY_DATA_Encrypt((struct Obj *)buf);
}
