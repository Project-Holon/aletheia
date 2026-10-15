/*
 * function: MUSICAL_MCSS_GetElemFlag
 * address: 0x021F4EFC
 * packet: pkt_ov112_021F4EFC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
typedef struct { u16 lo : 2; u16 flag : 1; u16 hi : 13; } Flags;
int MUSICAL_MCSS_GetElemFlag(int unused, Flags *p)
{
    return p->flag;
}
