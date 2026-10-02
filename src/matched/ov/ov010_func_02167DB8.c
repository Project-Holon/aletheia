/*
 * function: func_02167DB8
 * address: 0x02167DB8
 * packet: pkt_ov010_02167DB8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_02082D44(void *, void *, unsigned int);
void func_02167DB8(u16 a, int b, void *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338() && func_02039338() != 0)
        func_02082D44(c, p + 0x32, 0x1c);
}
