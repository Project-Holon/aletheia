/*
 * function: func_021E4BB0
 * address:  0x021E4BB0
 * packet:   pkt_ov093_021E4BB0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void func_021E4BB0(int a, void *b, int c)
{
    void *q;
    u8 *w;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        q = func_021C7CF4(b, k);
        w = func_021C88A4(b, 0xf, c);
        w[4] = c;
        w[5] = func_021D59B4(q, 1);
        w[6] = func_021D59B4(q, 2);
        w[7] = func_021D59B4(q, 3);
        w[8] = func_021D59B4(q, 4);
        w[9] = func_021D59B4(q, 5);
        w[10] = func_021D59B4(q, 6);
        w[11] = func_021D59B4(q, 7);
        func_021C88C8(b, w);
        w = func_021C88A4(b, 4, c);
        func_021C8838(w + 4, 2, 0x417);
        func_021C8860((struct S *)(w + 4), c);
        func_021C8860((struct S *)(w + 4), k);
        func_021C88C8(b, w);
    }
}
