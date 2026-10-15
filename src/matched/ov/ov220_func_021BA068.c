/*
 * function: TH_AWARD_GetLevelIndex
 * address: 0x021BA068
 * packet: pkt_ov220_021BA068
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BA3A8 0x021BA3A8 data a2
 */
struct Record { unsigned short a,b,c,level,d,e; };
extern const struct Record d_021BA3A8[];
unsigned char TH_AWARD_GetLevelIndex(unsigned value)
{
    unsigned level;
    unsigned char i;
    if(value>=6000) level=6;
    else if(value>=5000) level=5;
    else if(value>=4000) level=4;
    else if(value>=3000) level=3;
    else if(value>=2000) level=2;
    else if(value>=1000) level=1;
    else level=0;
    for(i=0;i<7;i++) if(level==d_021BA3A8[i].level) return i;
    return 0;
}
