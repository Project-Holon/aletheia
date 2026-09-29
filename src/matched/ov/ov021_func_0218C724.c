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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

extern void *func_02030734(int, int, int, void *, int);
extern void func_0207AF1C(void *m, int a, int b);
extern void func_02169510(u32 a, void *b);
extern void func_0207C9D0(void *a, void *b, void *c);
extern void func_0218DC5C(u32 a, void *b);
extern void func_0218BFB4(u8 *owner, u8 *node, u8 *rec);
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

    p = func_02030734(*(u16 *)owner, 0x60, 0, d_021DD9CC, 0x7E9);
    *(u8 **)p = owner;
    *(u32 **)(p + 8) = obj;
    *(u32 *)(p + 4) = 0xFFFF;
    k = *(u16 *)(def + 0x10) >> 4;
    func_0207AF1C(p + 0x3C, d_020A1B38[k * 2], d_020A1B38[k * 2 + 1]);
    func_02169510(obj[0], p + 0x24);
    func_0207C9D0(p + 0x24, def + 4, p + 0x24);
    func_0218DC5C(*(u32 *)(owner + 4), tmp);
    func_0207C9D0(p + 0x24, tmp, p + 0x24);
    *(u32 *)(p + 0x30) = 0x1000;
    *(u32 *)(p + 0x34) = 0x1000;
    *(u32 *)(p + 0x38) = 0x1000;
    func_0218BFB4(owner, p + 0xC, *(u8 **)(owner + 0x1CC) + *(u32 *)def * 0x18);
    func_0218BA70(owner, p);
    func_0218C54C(*(u32 *)(p + 8), 0);
    return p;
}
