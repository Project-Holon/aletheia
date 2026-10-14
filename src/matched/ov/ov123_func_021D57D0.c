/*
 * function: GSYNC_MESSAGE_SetMonName
 * address: 0x021D57D0
 * packet: pkt_ov123_021D57D0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0x021D580A..021D580C is two bytes of zero alignment padding.
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned int u32;
struct MsgBank;struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
void GSYNC_MESSAGE_SetMonName(void *p, int msg, int n, void *mon) {
MSGDATA_ReadString(*(void **)((unsigned)p+0x20),msg,*(void **)((unsigned)p+0x30));
func_0201EEF4(*(void **)((unsigned)p+0x24),0,mon);
func_0201EFA4(*(void **)((unsigned)p+0x24),1,n,3,1,1);
func_0201F250(*(void **)((unsigned)p+0x24),*(void **)((unsigned)p+0x2c),*(void **)((unsigned)p+0x30));
}
