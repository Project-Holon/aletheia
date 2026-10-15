/*
 * function: Wf2dmapFriend_ClearItemScreens
 * address: 0x021C7E48
 * packet: pkt_ov128_021C7E48
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original 021C7E64 sets r2=r+364 before Wf2dmapFriend_ClearEntryPage;
 * its filed source omits that argument. Preserve the caller's explicit third input.
 * symbols:
 *   Wf2dmapFriend_ClearWindow 0x021C6B38 thumb ov128
 *   Wf2dmapFriend_ClearEntryPage 0x021C89C4 thumb ov128
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void Wf2dmapFriend_ClearWindow(u8 *);
extern void Wf2dmapFriend_ClearEntryPage(char *,void *,void *);
extern void func_02041B6C(u32);
void Wf2dmapFriend_ClearItemScreens(u8 *p,void *q,u8 *r) {int i;Wf2dmapFriend_ClearWindow(r);for(i=0;i<3;i++)Wf2dmapFriend_ClearEntryPage((char *)(p+12+i*76),r,r+364);func_02041B6C(0);}
