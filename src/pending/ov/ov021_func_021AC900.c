/*
 * function: func_021AC900
 * address:  0x021AC900
 * packet:   pkt_ov021_021AC900
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * match.py prints MATCH* (compiled 212 of a 216-byte extent: the follower at
 * 0x021AC9D4 is an unlabelled `bx lr` stub). Every concrete byte matches.
 * Blocker: func_020508EC (0x020508EC, arm9, unlabelled leaf, Ilias's), no
 * witness outside this range. Its verified C (EXACT from a scratch file,
 * region arm9, --arm; recorded first in src/pending/ov/ov021_func_02199ED4.c):
 *   u32 func_020508EC(u8 *p, int i, u16 *out)
 *   {
 *       u16 v = *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x1c);
 *       *out = v;
 *       return (u16)(v + 4 + 0xC000) <= 3;
 *   }
 *
 * symbols:
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_021AC9D8  0x021AC9D8  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_020508EC  0x020508EC  arm
 *   func_0205085C  0x0205085C  arm
 *   d_021D90C0     0x021D90C0  data
 *   d_021D90C8     0x021D90C8  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blk { u32 w[9]; } Blk;

typedef struct B {
    u32 f0;
    Blk blk;
    u16 f28[4];
    u16 f30;
} B;

extern int func_0216E1C4(u32 a, u16 *b);
extern int func_021AC9D8(B *p);
extern u32 func_0216D608(u32 a);
extern void func_021AC154(u32 a);
extern u32 func_020508EC(u32 h, u32 i, u16 *out);
extern void func_0205085C(u32 h, u32 i, u32 v);
extern u8 d_021D90C0[];
extern u16 d_021D90C8[];

void func_021AC900(u32 a, B *b)
{
    u32 h = *(u32 *)(b->blk.w[0] + 4);
    u32 m;
    u16 tmp;

    switch (b->f0) {
    case 0:
        if (d_021D90C0[b->blk.w[8]] == 1) {
            m = b->blk.w[1];
            if (func_0216E1C4(m, b->f28) == 1 && func_021AC9D8(b) == 0 && func_0216D608(m) == 1) {
                func_021AC154(a);
                return;
            }
        }
        if (func_020508EC(h, b->f30, &tmp) != 0)
            b->f0++;
        break;
    case 1:
        if (func_0216E1C4(b->blk.w[1], b->f28) == 0) {
            func_021AC154(a);
            return;
        }
        func_0205085C(h, b->f30, d_021D90C8[b->blk.w[8]]);
        b->f0++;
        break;
    case 2:
        b->f0++;
    case 3:
        if (func_0216E1C4(b->blk.w[1], b->f28) == 0) {
            func_021AC154(a);
            return;
        }
        if (func_021AC9D8(b) == 0)
            func_021AC154(a);
        break;
    }
}
