/*
 * function: Wf2dmapFriend_PrintEntryInfo
 * address: 0x021C83B0
 * packet: pkt_ov128_021C83B0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_GetEntryIndex 0x021C87A0 thumb ov128
 *   Wf2dmapFriend_PrintMyStatus 0x021C6BCC thumb ov128
 *   Wf2dmapFriend_PrintEntryMessage 0x021C867C thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int Wf2dmapFriend_GetEntryIndex(s16 *);
extern void Wf2dmapFriend_PrintMyStatus(u8 *,u8 *,int,unsigned);
extern void Wf2dmapFriend_PrintEntryMessage(u8 *p, u8 *a, int n, int heap);
void Wf2dmapFriend_PrintEntryInfo(s16 *p,u8 *q,u8 *r,u16 heap) {Wf2dmapFriend_PrintMyStatus(r,q,*(u8 *)(q+24+Wf2dmapFriend_GetEntryIndex(p)),heap);Wf2dmapFriend_PrintEntryMessage((u8 *)p,r,12,heap);}
