/*
 * function: func_021D941C
 * address: 0x021D941C
 * packet: pkt_ov119_021D941C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 */
typedef unsigned int   u32;
extern u32 func_020221A4(void);
extern void func_021D8E84(void *, int);
void func_021D941C(void *p)
{
    if (func_020221A4() != 0)
        func_021D8E84(p, 0);
}
