/*
 * function: func_021DEF48
 * address:  0x021DEF48
 * packet:   pkt_ov093_021DEF48
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
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
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
extern void *func_021C7CF4(int *p, int i);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021D5B48(u8 *p);
extern u16 func_021D70A8(struct QQ *p);

void func_021DEF48(int a, void *b, int c)
{
    void *m;
    u8 *r;

    if (c == func_021D775C(2)) {
        m = func_021C7CF4(b, c);
        if (func_021D5B48(m) == 0) {
            r = (u8 *)func_021C88A4(b, 5, c);
            r[6] = c;
            *(u16 *)(r + 4) = func_021D7B74(m, 16);
            func_021C8838(r + 8, 2, 0x392);
            func_021C8860((struct S *)(r + 8), c);
            func_021C8860((struct S *)(r + 8), func_021D70A8((void *)a));
            func_021C88C8(b, r);
        }
    }
}
