/*
 * function: func_021D8430
 * address: 0x021D8430
 * packet: pkt_ov120_021D8430
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_021D60FC 0x021D60FC thumb ov120
 *   func_0202DB0C 0x0202DB0C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D60FC(void *);
extern void *func_0202DB0C(void *,int,void *,void *,int,int,u16);
void func_021D8430(u8 *p,void *q)
{
    if(!*(void **)(p+0xcc))
        *(void **)(p+0xcc)=func_0202DB0C(func_021D60FC(q),0,*(void **)(p+0xa4),*(void **)(p+0x14),8,4,*(u16 *)(p+0xc8));
}
