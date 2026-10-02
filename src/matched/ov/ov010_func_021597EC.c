/*
 * function: func_021597EC
 * address: 0x021597EC
 * packet: pkt_ov010_021597EC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x0215980A.
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(void *, void *);
extern unsigned int func_02159B10(void *, void *);
int func_021597EC(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    *p = *p * func_02159B10(a, b);
    return 0;
}
