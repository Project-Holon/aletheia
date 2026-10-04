/*
 * function: func_021E2268
 * address:  0x021E2268
 * packet:   pkt_ov093_021E2268
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7DC0  0x021D7DC0  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern void *func_021C88A4(int a, int k, int b);
extern void func_021C88C8(int a, void *b);
extern void func_021D7DC0(int a, void *b, void *c);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021E03D8(u8 *a, int b);
struct QQ;
extern u16 func_021D70A8(struct QQ *p);

void func_021E2268(void *u, int a, int b, int *p)
{
    void *q;
    u8 *r;
    int f;

    if (b == func_021D775C(2)) {
        q = func_021C7CF4(a, b);
        if (p[6] != 0) {
            f = 0;
            if (p[0] != 0)
                p[0] = p[0] - 1;
            if (func_021D775C(0x51) == 0) {
                r = func_021C88A4(a, 0xb, b);
                *(int *)(r + 4) = 0x19;
                f = 1;
                r[0x14] = 1;
                r[8] = b;
                func_021C88C8(a, r);
            }
            if (p[0] == 0) {
                r = func_021C88A4(a, 0xc, b);
                *(int *)(r + 4) = 6;
                func_021D7DC0(6, q, r + 8);
                f = 1;
                r[0xd] = 1;
                r[0xf] = b;
                func_021C8838(r + 0x14, 2, 0x168);
                func_021C8860((struct S *)(r + 0x14), b);
                func_021C88C8(a, r);
            }
            if (f != 0)
                func_021E03D8(q, func_021D70A8(u));
        }
    }
}
