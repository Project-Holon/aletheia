/*
 * function: func_021C70E4
 * address:  0x021C70E4
 * packet:   pkt_ov093_021C70E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021CD568(u8 *w, u16 v, u32 id, ...);
extern void func_021CD4B0(void *w, volatile u32 id, ...);

void func_021C70E4(u8 *p, int a, int b, int c, int e, u32 f)
{
    int m;
    if (c != 6) {
        m = 2;
    } else {
        m = 1;
        if (b == 6) m = 0;
    }
    if (e) {
        switch (m) {
        case 0: func_021CD568(*(u8 **)(p + 0xc), f, 0x4c, a); return;
        case 1: func_021CD568(*(u8 **)(p + 0xc), f, 0x4d, b, a); return;
        case 2: func_021CD568(*(u8 **)(p + 0xc), f, 0x4e, b, c, a); return;
        }
    } else {
        switch (m) {
        case 0: func_021CD4B0(*(u8 **)(p + 0xc), 0x4c, a); return;
        case 1: func_021CD4B0(*(u8 **)(p + 0xc), 0x4d, b, a); return;
        case 2: func_021CD4B0(*(u8 **)(p + 0xc), 0x4e, b, c, a); return;
        }
    }
}
