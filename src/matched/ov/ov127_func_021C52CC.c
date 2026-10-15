/*
 * function: WF2DMAP_OBJCMD_OffsetPos
 * address: 0x021C52CC
 * packet: pkt_ov127_021C52CC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_OffsetPos 0x021C4A54 thumb ov127
 */
typedef unsigned short u16;
struct pair { u16 a,b; };
extern struct pair WF2DMAP_OBJ_OffsetPos(struct pair,int);
struct pair WF2DMAP_OBJCMD_OffsetPos(struct pair p,int i)
{
 return WF2DMAP_OBJ_OffsetPos(p,i);
}
