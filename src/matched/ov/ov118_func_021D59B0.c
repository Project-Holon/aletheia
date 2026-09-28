/*
 * function: func_021D59B0
 * address:  0x021D59B0
 * packet:   pkt_ov118_021D59B0
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D56F0  0x021D56F0  thumb  ov118
 *   func_02016028  0x02016028  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021D54F0  0x021D54F0  thumb  ov118
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D5A60  0x021D5A60  thumb  ov118
 *   d_021D7CA8     0x021D7CA8  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021D56F0(void *p);
extern void func_02016028(u32 obj, u32 flag);
extern void func_02015EA0(u32);
extern void func_02015C48(u32, Vec *);
extern void func_021E71F0(void *p, int a);
extern void func_021E7208(void *p, int a);
extern void func_021D54F0(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
extern void func_021D8E84(void *p, int next);
extern void func_021D5A60(u8 *p);
extern const Vec d_021D7CA8;

void func_021D59B0(u8 *p)
{
    func_021D56F0(p);
    *(u32 *)(p + 0x854) = 1;
    func_02016028(*(u32 *)(p + 0x844), 0);
    func_02015EA0(*(u32 *)(p + 0x844));
    func_02015EA0(*(u32 *)(p + 0x848));
    if (*(u32 *)(p + 0x118C) == 6) {
        Vec v = d_021D7CA8;
        func_02015C48(*(u32 *)(p + 0x844), &v);
    }
    func_021E71F0(p, 0x11);
    func_021E7208(p, 0);
    func_021D54F0(p, p + 0x11ED, p + 0x11EF, *(u32 *)(p + 0x834), 1);
    func_021D54F0(p, p + 0x11EE, p + 0x11F0, *(u32 *)(p + 0x830), 0);
    func_021D8E84(p, (int)func_021D5A60);
}
