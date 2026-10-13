/*
 * function: HAND_ITEM_KingsRockSetFlinchChance
 * address: 0x021DE4C4
 * packet: pkt_ov093_021DE4C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 021DE4F2.
 * lever: u8 result local narrows in r0 before copying to r1; twin 021DE3FC.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   HAND_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern int HAND_ITEM_GetParam(int,int);
extern int BTL_EVENT_OverwriteVar(int,u32);
void HAND_ITEM_KingsRockSetFlinchChance(int a, int b, int c) { u8 j; if(c == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x25)==0) { j=HAND_ITEM_GetParam(a,2); BTL_EVENT_OverwriteVar(0x26,j); } }
