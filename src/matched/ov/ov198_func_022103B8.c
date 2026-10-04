/*
 * function: func_022103B8
 * address: 0x022103B8
 * packet: pkt_ov198_022103B8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02210EFC 0x02210EFC thumb ov198
 *   func_0202173C 0x0202173C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02210EFC(char **p);
extern int func_0202173C(void *,u16,u16,short,u8,u8,u16,void *);
int func_022103B8(char *p)
{
    if (func_02210EFC((char **)((unsigned)p))==1 && (*(u8 **)p)[0x20]!=6)
        (*(u8 **)p)[0x20]/=2u;
    func_0202173C(*(void **)(p+0x1d8),10,0xffff,0,0,0x10,0,*(void **)(*(char **)p+0x28));
    return 0x20;
}
