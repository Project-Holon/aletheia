/*
 * function: func_021E203C
 * address:  0x021E203C
 * packet:   pkt_ov093_021E203C
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C83E8  0x021C83E8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *
 * Note: src/matched/ov/func_021E203C.c is a different function (region ov170).
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C83E8(unsigned char *p, int i, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E203C(int u, int a, int b)
{
    int t;
    u8 *s;

    if (b == BTL_EVENT_GetVar(3)) {
        t = func_021D59B4(func_021C7CF4((int *)a, b), 0xf);
        if (func_021C83E8((unsigned char *)a, t * 5, b) != 0) {
            s = func_021C88A4((char *)a, 4, b);
            func_021C8838(s + 4, 1, 0x7a);
            func_021C88C8((void *)a, s);
        }
    }
}
