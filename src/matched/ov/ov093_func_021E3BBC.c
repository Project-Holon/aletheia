/*
 * function: func_021E3BBC
 * address:  0x021E3BBC
 * packet:   pkt_ov093_021E3BBC
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
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
struct Node;
extern void BTL_EVENT_RemoveFactor(struct Node *n);

void func_021E3BBC(void *u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        s = func_021C88A4((char *)a, 0x26, b);
        s[4] = b;
        s[5] = 3;
        s[6] = 0;
        func_021C88C8((void *)a, s);
        BTL_EVENT_RemoveFactor(u);
    }
}
