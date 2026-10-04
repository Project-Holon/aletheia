/*
 * function: func_021D25F4
 * address:  0x021D25F4
 * packet:   pkt_ov021_021D25F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The pooled 0x8015 is the heap id as a plain literal: it is too wide for a
 * Thumb movs, so the compiler pools it by itself; no symbol is needed. int
 * params were the fix for register allocation.
 *
 * symbols:
 *   func_0204B100  0x0204B100  arm
 *   func_0202D7C8  0x0202D7C8  thumb
 *   func_0202D81C  0x0202D81C  thumb
 *   func_0202D7D8  0x0202D7D8  thumb
 *   func_02049238  0x02049238  arm
 *   func_0202D898  0x0202D898  thumb
 *   func_0204B294  0x0204B294  arm
 *   d_021DD710     0x021DD710  data  a2
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a, b, c, d;
} Pos;

extern u32 func_0204B100(u32 a, u32 b, u32 heap);
extern u32 func_0202D7C8(u32 heap);
extern u32 func_0202D81C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 heap);
extern u32 func_0202D7D8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 heap);
extern void func_02049238(u32 a);
extern u32 func_0202D898(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 heap);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern Pos d_021DD710;

void func_021D25F4(u32 *p, int a, int b, int c, int s0, int s1)
{
    Pos loc;
    u32 t;

    p[1] = func_0204B100(1, 0, 0x8015);
    t = func_0202D7C8(0x8015);
    p[3] = func_0202D81C(t, a, b, c, s0, 0, 0, s1, 0, 0x8015);
    p[4] = func_0202D7D8(t, a, b, c, s0, 0, 0, 0, 0, 0x8015);
    func_02049238(t);
    p[5] = func_0202D898(a, b, c, s0, 0, 0, 1, 0, 0x8015);
    loc = d_021DD710;
    p[2] = (u32)func_0204B294((void *)p[1], p[3], p[4], p[5], &loc, 0, 0x8015);
}
