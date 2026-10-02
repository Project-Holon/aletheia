/*
 * function: func_02173AC4
 * address: 0x02173AC4
 * packet: pkt_ov012_02173AC4
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 * Live r0 from 020399A8 is the Link input of 0203D1A4.
 * Extent reaches existing matched func_02173AFC's initial push.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
typedef struct { u8 pad[0x5a]; u8 low:2; u8 mode:2; u8 high:4; } Sub;
extern struct Link *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
void func_02173AC4(u32 a, int b, u32 *c, u8 *p)
{
    Sub *q = (Sub *)(p + 0x2830);
    if (a != func_0203D1A4(func_020399A8())) q->mode = (u8)*c;
}
