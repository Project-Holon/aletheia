/*
 * function: Wf2dmapFriend_ListInput, Wf2dmapFriend_SetListState
 * unit: yes
 * address: 0x021C74C4
 * packet: pkt_ov128_021C74C4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_SetState 0x021C6438 thumb ov128
 *   gWf2dmapListStateTable 0x021CA51C data a4
 *   Wf2dmapFriend_ListTouchInput 0x021C7460 thumb ov128
 *   Wf2dmapFriend_ListKeyInput 0x021C734C thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern const u8 gWf2dmapListStateTable[];
extern void Wf2dmapFriend_SetState(u8 *,u8,u8);
extern int Wf2dmapFriend_ListTouchInput(int *,int *,u8 *);
extern int Wf2dmapFriend_ListKeyInput(u32 *,int *,u8 *);
int Wf2dmapFriend_ListInput(int *p,int *q,u8 *r) {if(Wf2dmapFriend_ListTouchInput(p,q,r)!=-1) return 1;return Wf2dmapFriend_ListKeyInput((u32 *)p,q,r);}
void Wf2dmapFriend_SetListState(u32 *p,u8 *q) {Wf2dmapFriend_SetState(q,gWf2dmapListStateTable[*p],0);}
