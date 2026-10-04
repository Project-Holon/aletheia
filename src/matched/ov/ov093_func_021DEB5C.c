/*
 * function: func_021DEB5C
 * address:  0x021DEB5C
 * packet:   pkt_ov093_021DEB5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);

void func_021DEB5C(int a, void *b, int c)
{
    u8 *r;

    if (c == func_021D775C(2)) {
        r = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(r + 4, 2, 0x3ef);
        func_021C8860((struct S *)(r + 4), c);
        func_021C8860((struct S *)(r + 4), func_021D70A8((void *)a));
        func_021C88C8(b, r);
    }
}
