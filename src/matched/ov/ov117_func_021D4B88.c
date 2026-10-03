/*
 * function: func_021D4B88
 * address:  0x021D4B88
 * packet:   pkt_ov117_021D4B88
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4490  0x021D4490  thumb  ov117
 *   func_02016028  0x02016028  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_021D4484  0x021D4484  thumb  ov117
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D449C  0x021D449C  thumb  ov117
 *   d_021D51DC     0x021D51DC  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D4490(u8 *p);
extern void func_02016028(u32 obj, u32 flag);
extern void func_02015E04(u32);
extern void func_02015C48(u32, Vec *);
extern void func_021D4484(u8 *p, u32 v);
extern void func_021D8E84(void *p, int next);
extern void func_021D449C(u8 *p);
extern const Vec d_021D51DC;

void func_021D4B88(u8 *p)
{
    func_021D4490(p);
    *(u32 *)(p + 0x854) = 1;
    func_02016028(*(u32 *)(p + 0x844), 0);
    func_02015E04(*(u32 *)(p + 0x844));
    if (*(u32 *)(p + 0x118C) == 4) {
        Vec v = d_021D51DC;
        func_02015C48(*(u32 *)(p + 0x844), &v);
    }
    func_021D4484(p, 0);
    func_021D8E84(p, (int)func_021D449C);
}
