/*
 * function: func_021C5A4C
 * address:  0x021C5A4C
 * packet:   pkt_ov093_021C5A4C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *w, u8 id, ...);

void func_021C5A4C(u8 *p, u8 *a, int b, int c)
{
    u8 n = func_021D5440(a);
    if (c > 0) {
        func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x99, n, b, 0xffff0000);
    } else {
        func_021CD64C(*(void **)(p + 0xc), 0x5b, 0xae, n, b, 0xffff0000);
    }
}
