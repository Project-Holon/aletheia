/*
 * function: func_021E1E10
 * address:  0x021E1E10
 * packet:   pkt_ov093_021E1E10
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E1E10(int u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        s = func_021C88A4((char *)a, 0x13, b);
        s[4] = b;
        func_021C88C8((void *)a, s);
    }
}
