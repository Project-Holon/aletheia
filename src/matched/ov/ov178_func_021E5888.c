/*
 * function: func_021E5888
 * address:  0x021E5888
 * packet:   pkt_021E5888
 * region:   ov178
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E5A44  0x021E5A44  thumb  ov178
 *   func_021E5B1C  0x021E5B1C  thumb  ov178
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */
typedef unsigned int u32;

extern void func_021E5A44(void **pp, u32 *c);
extern void func_021E5B1C(void *d, u32 *c);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 v);

int func_021E5888(void *a, u32 b, u32 *c, void *d)
{
    switch (c[1]) {
    case 0:
        func_021E5A44(d, c);
        break;
    case 1:
        func_021E5B1C(d, c);
        break;
    }
    func_020315D4(a);
    func_020306F0(0x58);
    return 1;
}
