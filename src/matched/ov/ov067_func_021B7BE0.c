/*
 * function: FRAME_LIST_Redraw
 * address:  0x021B7BE0
 * packet:   pkt_ov067_021B7BE0
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * f5 is a u8 read as (s8) in every loop step; the one uncast read in the
 * second window's start (`f3 + 0x18 - f5`) is what makes the original load
 * it with ldrb and sign-extend the CSE'd copy for the loop.  All four loops
 * are `for (;;) { if (!cond) break; ... }` (top test, unconditional b back).
 *
 * symbols:
 *   func_02041EE4  0x02041EE4  arm
 *   FRAME_LIST_DrawRowA  0x021B91D0  thumb  ov067
 *   FRAME_LIST_DrawRowB  0x021B9228  thumb  ov067
 *   FRAME_LIST_SetCursorHighlight  0x021B92F0  thumb  ov067
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct Ops {
    void (*fn0)(void);
    void (*fn4)(void *a, int b, int c);
};

typedef struct S {
    u8 f0;
    u8 f1;
    u8 f2;
    s8 f3;
    u8 f4;
    u8 f5;
    u8 pad06[0x20 - 0x06];
    struct Ops *f20;
    void *f24;
    u8 pad28[0x46 - 0x28];
    s8 f46;
    s8 f47;
    s8 f48;
    s8 f49;
    u8 pad4a[0x5c - 0x4a];
    s16 f5c;
    u8 pad5e[0x62 - 0x5e];
    s16 f62;
    u8 pad64[0x66 - 0x64];
    s8 f66;
} S;

extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void FRAME_LIST_DrawRowA(S *p, int i, int a2);
extern void FRAME_LIST_DrawRowB(S *p, int i, int a2);
extern void FRAME_LIST_SetCursorHighlight(struct S *p, u32 a1, u32 a2);

void FRAME_LIST_Redraw(S *p, int a1)
{
    s16 i;
    s8 j;

    func_02041EE4(p->f0, 3, 0);
    p->f66 = 0;
    i = p->f62;
    j = p->f3;
    for (;;) {
        if (i == 0 || j <= 0)
            break;
        i = i - 1;
        j = j - (s8)p->f5;
    }
    p->f46 = 0;
    for (;;) {
        if (j >= 0x18)
            break;
        FRAME_LIST_DrawRowA(p, i, j);
        p->f46++;
        i = i + 1;
        j = j + (s8)p->f5;
    }
    p->f48 = p->f46;
    if (p->f1 == 0xff)
        return;
    func_02041EE4(p->f1, 3, 0);
    j = p->f3 + 0x18 - p->f5;
    i = p->f62 - 1;
    for (;;) {
        if (j <= 0)
            break;
        i = i - 1;
        j = j - (s8)p->f5;
    }
    p->f47 = 0;
    for (;;) {
        if (j >= 0x18)
            break;
        FRAME_LIST_DrawRowB(p, i, j);
        p->f47++;
        i = i + 1;
        j = j + (s8)p->f5;
    }
    p->f49 = p->f47;
    FRAME_LIST_SetCursorHighlight(p, (u16)p->f5c, 0xff);
    p->f20->fn4(p->f24, p->f5c + p->f62, a1);
}
