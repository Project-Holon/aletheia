/*
 * function: func_021DCD20
 * address:  0x021DCD20
 * packet:   pkt_ov093_021DCD20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021B8C5C  0x021B8C5C  thumb  ov093
 *   func_021C8020  0x021C8020  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C815C(void *p);
extern u8 func_021B8C5C(int kind, u32 flags);
extern u8 func_021C8020(u8 *p, u8 v);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B68(void *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DCD20(int a, void *b, int c)
{
    u8 *m;
    void *p;
    int k;
    int n;

    if (c == func_021D775C(2)) {
        n = func_021C8010(b, c);
        k = func_021C8020(b, func_021B8C5C(func_021C815C(b), n));
        p = func_021C7CF4(b, k);
        if (func_021D5B68(func_021C7CF4(b, c)) == 0 && func_021D5B68(p) == 0) {
            m = (u8 *)func_021C88A4(b, 0x33, c);
            *(u32 *)m |= 2 << 22;
            m[4] = k;
            func_021C8838(m + 8, 2, 0x284);
            func_021C8860((struct S *)(m + 8), c);
            func_021C8860((struct S *)(m + 8), m[4]);
            func_021C88C8(b, m);
        }
    }
}
