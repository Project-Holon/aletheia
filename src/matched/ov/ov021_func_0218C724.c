/*
 * function: func_0218C724
 * address:  0x0218C724
 * packet:   pkt_ov021_0218C724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x60-byte node for a definition, builds its matrices, registers it.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0207AF1C  0x0207AF1C  thumb
 *   func_02169510  0x02169510  thumb  ov010
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0218DC5C  0x0218DC5C  thumb  ov021
 *   func_0218BFB4  0x0218BFB4  thumb  ov021
 *   func_0218BA70  0x0218BA70  thumb  ov021
 *   func_0218C54C  0x0218C54C  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data   ov021  a4
 *   d_020A1B38     0x020A1B38  data   a2
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04199.h"
#include "../include/Obj04200.h"
#include "../include/Obj12576.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0207AF1C(void *m, int a, int b);
struct V3;
extern void func_02169510(u8 *src, struct V3 *dst);
extern void func_0207C9D0(void *a, void *b, void *c);
extern void func_0218DC5C(u32 a, void *b);
extern void func_0218BFB4(u8 *a, u32 *out, u32 *st);
extern void func_0218BA70(u8 *owner, u8 *node);
extern void func_0218C54C(u32 a, int b);
extern s16 d_020A1B38[];
extern u8 d_021DD9CC[];

u8 *func_0218C724(u8 *owner, u32 *obj)
{
    u8 *def = (u8 *)obj[3];
    u8 *p;
    u32 tmp[3];
    int k;

    p = func_02030734(((struct Obj04199 *)owner)->f0, 0x60, 0, (const char *)d_021DD9CC, 0x7E9);
    *(u8 * *)&((struct Obj04200 *)p)->f0 = owner;
    *(u32 * *)&((struct Obj04200 *)p)->f8 = obj;
    ((struct Obj04200 *)p)->f4 = 0xFFFF;
    k = ((struct Obj12576 *)def)->f10 >> 4;
    func_0207AF1C(p + 0x3C, d_020A1B38[k * 2], d_020A1B38[k * 2 + 1]);
    func_02169510((u8 *)obj[0], (struct V3 *)(p + 0x24));
    func_0207C9D0(p + 0x24, def + 4, p + 0x24);
    func_0218DC5C(((struct Obj04199 *)owner)->f4, tmp);
    func_0207C9D0(p + 0x24, tmp, p + 0x24);
    ((struct Obj04200 *)p)->f30 = 0x1000;
    ((struct Obj04200 *)p)->f34 = 0x1000;
    ((struct Obj04200 *)p)->f38 = 0x1000;
    func_0218BFB4(owner, (u32 *)(p + 0xC), (u32 *)(*(u8 * *)&((struct Obj04199 *)owner)->f1CC + ((struct Obj12576 *)def)->f0 * 0x18));
    func_0218BA70(owner, p);
    func_0218C54C(*(u32 *)&((struct Obj04200 *)p)->f8, 0);
    return p;
}
