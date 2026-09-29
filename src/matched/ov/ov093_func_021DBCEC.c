/*
 * function: func_021DBCEC
 * address:  0x021DBCEC
 * packet:   pkt_ov093_021DBCEC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E86E8  0x021E86E8  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021E85F8(int id);
extern int func_021D775C(int key);
extern int func_021E86E8(void *a, int b, int c);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5B40(void *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DBCEC(int u, void *a, int b)
{
    u8 t;
    void *x;
    void *y;
    u8 *e;
    if (func_021E85F8(b) != 0) {
        t = func_021D775C(3);
        if (func_021E86E8(a, b, t) == 0
            && func_0201BEB8(func_021D775C(0x12), 0) != 0) {
            x = func_021C7CF4(a, b);
            y = func_021C7CF4(a, t);
            if (func_021D5B40(x) == 0 && func_021D5B40(y) != 0) {
                e = func_021C88A4(a, 0x24, b);
                *(u32 *)e |= 2 << 22;
                e[4] = t;
                func_021C8838(e + 8, 2, 0x1cc);
                func_021C8860(e + 8, t);
                func_021C8860(e + 8, func_021D5B40(y));
                func_021C88C8(a, e);
            }
        }
    }
}
