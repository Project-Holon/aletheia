/*
 * function: func_021DDE20
 * address: 0x021DDE20
 * packet: pkt_ov170_021DDE20
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two bytes alignment padding at 0x021DDE7E.
 * symbols:
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021DD694 0x021DD694 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 */
extern unsigned func_021DD25C(void ***,unsigned short,int,unsigned,unsigned);
extern int func_021DD694(void ***,unsigned);
extern void *func_0201AB28(void *,unsigned);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern unsigned func_0202136C(unsigned short);
int func_021DDE20(unsigned char *p,unsigned a,unsigned b)
{
    int result = 0;
    if (func_021DD25C((void ***)p,(unsigned short)b,p[0x14],0xa9,0))
        return result;
    if (!func_021DD694((void ***)p,a-30))
        return result;
    if (func_0202136C((unsigned short)func_02017E1C(func_0201AB28((*(void ***)p)[2],a-30),6,0)) != 1)
        result = 1;
    return result;
}
