/*
 * function: func_02173B78
 * address: 0x02173B78
 * packet: pkt_ov012_02173B78
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
 * Enum-typed local offset keeps 0x2830 and the +0x5d field add separate;
 * raw/nested pointer arithmetic and an inline setter folded to 0x288d.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Link;
typedef struct { u8 pad[0x5d]; u8 flag; } Sub;
typedef struct { u8 pad[0x2830]; Sub sub; } Work;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern void func_02082D44(void *src, void *dst, u32 n);
void func_02173B78(u32 a, u32 b, const void *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        enum { OFFSET = 0x2830 } off = OFFSET;
        Sub *q = (Sub *)(p + off);
        q->flag = 1;
        func_02082D44((void *)c, *(void **)(p + 0x3544), b);
    }
}
