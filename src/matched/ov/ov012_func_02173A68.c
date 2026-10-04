/*
 * function: func_02173A68
 * address: 0x02173A68
 * packet: pkt_ov012_02173A68
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02082D44 0x02082D44 arm
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02082D44(void *src, void *dst, u32 n);
void func_02173A68(u32 a, int b, void *c, u8 *p)
{
    u8 *q = p + 0x2830;
    if (a != func_0203D1A4((struct Link *)func_020399A8())) func_02082D44(c, q + 0x24, 8);
}
