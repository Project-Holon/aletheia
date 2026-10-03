/*
 * function: func_021DFD7C
 * address:  0x021DFD7C
 * packet:   pkt_ov119_021DFD7C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005DF8  0x02005DF8  thumb
 */

typedef unsigned char u8;

extern void func_02005E9C(void);
typedef unsigned int   u32;
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);

void func_021DFD7C(void *p)
{
    u8 *b = p;

    func_02005E9C();
    *(u8 *)(b + 0x11f8) -= 1;
    func_02005DE4(0);
    func_02005DF8(0x18);
}
