/*
 * function: func_021C3C60
 * address:  0x021C3C60
 * packet:   pkt_ov093_021C3C60
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The handed address 0x021C3C62 is the second label after `push {r0-r3}`
 * (0x021C3C60). The third parameter is a one-word struct passed by value
 * (its home slot is read through `add r7, sp, #0x20`).
 *
 * symbols:
 *   func_021EF8C8  0x021EF8C8  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021EF8F8  0x021EF8F8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { int x; } S;
extern int func_021EF8C8(int a, S c);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021E8A98(S c);
extern void func_021EF8F8(int a, int r);

int func_021C3C60(u8 *p, int a, S c, int d)
{
    int r;
    if (func_021EF8C8(a, c)) {
        func_021CD4B0(*(void **)(p + 0xc), 0x21, (u8)a, c.x);
        return 1;
    }
    if (d) {
        r = func_021E8A98(c);
        if (r != 0x1f) {
            func_021EF8F8(a, r);
            func_021CD4B0(*(void **)(p + 0xc), 0x22, (u8)a, r);
            return 1;
        }
    }
    return 0;
}
