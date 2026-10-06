/*
 * function: func_021D2358
 * address:  0x021D2358
 * packet:   pkt_ov021_021D2358
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A30A4  0x021A30A4  thumb  ov021
 *   func_02184F88  0x02184F88  thumb  ov020
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_02188D38(unsigned char *p);
extern void func_020061E4(u32 a);
extern u32 func_02188C64(unsigned char *p);
typedef unsigned short u16;
struct Evt;
extern void *func_021C7260(u32 a, u16 b, int c);
extern void *func_021C71D4(u32 a, u32 b, u32 c);
extern void func_021C6DE0(unsigned char *p, u32 a, u32 b);
extern u32 func_021A01D4(unsigned char *p);
extern void func_021A01FC(unsigned char *p, u32 a, u32 b, u32 c);
extern void *func_02188CB4(unsigned char *p);
typedef unsigned char  u8;
extern void func_021A30A4(u8 *p, u32 b);
extern void *func_02184F88(void *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_021D2358(u32 a, int *seq, int *w)
{
    u32 s, r6, r7, r4;

    s = func_02188D38((unsigned char *)w[1]);
    switch (*seq) {
    case 0:
        func_020061E4(0x63C);
        w[3] = 0x18;
        if (w[2]) {
            r6 = func_02188C64((unsigned char *)w[1]);
            r7 = (u32)func_021C7260(w[1], 0x14, 3);
            r4 = (u32)func_021C71D4(w[1], 0xc, 3);
            func_021C6DE0((unsigned char *)s, r7, 0);
            func_021C6DE0((unsigned char *)s, r4, r7);
            func_021A01FC((unsigned char *)r6, 0x7F0F, func_021A01D4((unsigned char *)r6), 0x1A);
        }
        (*seq)++;
        break;
    case 1:
        func_021A30A4(func_02188CB4((unsigned char *)w[1]), 2);
        (*seq)++;
        break;
    case 2:
        w[3]--;
        if (w[3] > 0) {
            break;
        }
        func_02012374((struct Evt *)a, func_02184F88((void *)w[0]));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
