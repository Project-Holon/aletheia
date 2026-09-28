/*
 * function: func_021A9508
 * address:  0x021A9508
 * packet:   pkt_ov021_021A9508
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_021A996C  0x021A996C  thumb
 *   func_021A9C58  0x021A9C58  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Slot14 { u8 pad00[4]; u8 f04; u8 pad05[0xF]; };

extern void func_021A9C58(void *u, void *arg, struct Slot14 *s);
extern int func_021A996C(void *u, u8 n);

int func_021A9508(u8 *u, void *arg, struct Slot14 *slots)
{
    int n = 0;
    int i;

    for (i = 0; i < u[0x15]; i++) {
        struct Slot14 *s = &slots[n];
        func_021A9C58(u, arg, s);
        if (func_021A996C(u, s->f04) == 0)
            n++;
    }
    return n;
}
