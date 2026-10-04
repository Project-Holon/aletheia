/*
 * function: func_0218C7F0
 * address:  0x0218C7F0
 * packet:   pkt_ov021_0218C7F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x60-byte node, copies a 60-byte block into it, registers it.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 *   func_0218BFB4  0x0218BFB4  thumb  ov021
 *   func_0218BA70  0x0218BA70  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data   ov021  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04199.h"
#include "../include/Obj09456.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blk {
    u32 w[15];
} Blk;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern int func_0218BBD0(u8 *owner, u32 x);
extern void func_0218BFB4(u8 *owner, u8 *node, u8 *rec);
extern void func_0218BA70(u8 *owner, u8 *node);
extern u8 d_021DD9CC[];

u8 *func_0218C7F0(u8 *owner, u32 x, Blk *src)
{
    u8 *p = func_02030734(((struct Obj04199 *)owner)->f0, 0x60, 0, (const char *)d_021DD9CC, 0x825);

    *(u8 * *)&((struct Obj09456 *)p)->f0 = owner;
    ((struct Obj09456 *)p)->f8 = 0;
    ((struct Obj09456 *)p)->f4 = 0xFFFF;
    *(Blk *)(p + 0x24) = *src;
    func_0218BFB4(owner, p + 0xC,
                  *(u8 * *)&((struct Obj04199 *)owner)->f1CC + func_0218BBD0(owner, x) * 0x18);
    func_0218BA70(owner, p);
    return p;
}
