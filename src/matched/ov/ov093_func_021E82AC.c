/*
 * function: func_021E82AC
 * address:  0x021E82AC
 * packet:   pkt_ov093_021E82AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E82AC(void *a, void *b, int c)
{
    u8 *p;
    int v;

    if (c == func_021D775C(3)) {
        if (func_021D70A8(a) == 0x229)
            v = 0x35f;
        else
            v = 0x362;
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, (u16)v);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
    }
}
