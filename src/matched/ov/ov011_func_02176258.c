/*
 * function: func_02176258
 * address: 0x02176258
 * packet: pkt_ov011_02176258
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0217627E.
 * symbols:
 *   func_0217620C 0x0217620C thumb ov011
 *   func_02026478 0x02026478 thumb
 *   func_02012B58 0x02012B58 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0217620C(u8 *p, int key);
extern u32 func_02026478(void *p);
struct BigObj;
extern u8 func_02012B58(const struct BigObj *p);
int func_02176258(u8 *p)
{
    if (func_0217620C(p + 0x1ac, func_02012B58((const void *)func_02026478(((void **)p)[1]))) == 1) return 1;
    return 0;
}
