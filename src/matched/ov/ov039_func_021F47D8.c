/*
 * function: func_021F47D8
 * address:  0x021F47D8
 * packet:   pkt_ov039_021F47D8
 * region:   ov039
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F47D8  0x021F47D8  thumb
 *   func_021F3DE4  0x021F3DE4  thumb
 *   func_021F3E04  0x021F3E04  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B4  0x021BE6B4  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021F3DE4(void *p, u8 delta, u16 i);
extern void func_021F3E04(void *p, u8 delta, u16 i, int frame);
extern void func_021BE700(void *a, int b, int c, int d, int e);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern u8 func_021BE6B4(u8 *p);
extern void func_021BE6B0(u8 *p, int v);

void func_021F47D8(void *a, int f, int i)
{
    u8 r7;
    u8 r6;
    u8 r4;
    u8 v;
    int d;

    if (f == 0) {
        r7 = i * 2 + 1;
        r6 = r7 + 1;
    } else {
        r6 = i * 2 + 1;
        r7 = r6 + 1;
    }
    r4 = i;
    d = func_021F3DE4(a, r4, r7);
    func_021BE700(a, 0, r4, r7, 0);
    func_021BE700(a, 0, r4, r6, 1);
    func_021F3E04(a, r4, r6, d);
    v = func_021BE6B4(func_021BE674(a, 0, r4, r7));
    func_021BE6B0(func_021BE674(a, 0, r4, r6), v);
}
