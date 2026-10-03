/*
 * function: func_021C1350
 * address:  0x021C1350
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCC58  0x021BCC58  thumb  ov099
 *
 * Stamps the record of slot a from the three lead fields of h.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    u16 f0;
    u16 f2;
    u32 f4;
} H;

extern void func_021BCC58(char *p, u32 x);

void func_021C1350(int a, int b, H *h, char *d)
{
    *(u16 *)(d + a * 2 + 0x1F4) = h->f0;
    *(u8 *)(*(char **)(d + 0x1F4 + 0x54) + a + 0x44) = h->f2;
    func_021BCC58(d, h->f4);
}
