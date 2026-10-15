/*
 * function: BOX2_MAIN_ComparePartyValue
 * address: 0x021DDE20
 * packet: pkt_ov170_021DDE20
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two bytes alignment padding at 0x021DDE7E.
 * symbols:
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   BOX2_MAIN_HasOtherTradable 0x021DD694 thumb ov170
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 */
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***,unsigned short,int,unsigned,unsigned);
extern int BOX2_MAIN_HasOtherTradable(void ***,unsigned);
extern void *POKEPARTY_GetMember(void *,unsigned);
extern unsigned POKE_TOOL_GetPartyValue(void *,unsigned,unsigned);
extern unsigned func_0202136C(unsigned short);
int BOX2_MAIN_ComparePartyValue(unsigned char *p,unsigned a,unsigned b)
{
    int result = 0;
    if (BOX2_MAIN_GetPartyValueAt((void ***)p,(unsigned short)b,p[0x14],0xa9,0))
        return result;
    if (!BOX2_MAIN_HasOtherTradable((void ***)p,a-30))
        return result;
    if (func_0202136C((unsigned short)POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((*(void ***)p)[2],a-30),6,0)) != 1)
        result = 1;
    return result;
}
