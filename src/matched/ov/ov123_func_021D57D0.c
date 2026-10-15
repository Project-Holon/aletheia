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
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 */
typedef unsigned int u32;
struct MsgBank;struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *,u32,void *);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
void GSYNC_MESSAGE_SetMonName(void *p, int msg, int n, void *mon) {
MSGDATA_ReadString(*(void **)((unsigned)p+0x20),msg,*(void **)((unsigned)p+0x30));
WORDSET_SetSlotMonSpecies(*(void **)((unsigned)p+0x24),0,mon);
WORDSET_SetSlotNumber(*(void **)((unsigned)p+0x24),1,n,3,1,1);
WORDSET_CopyTaggedText(*(void **)((unsigned)p+0x24),*(void **)((unsigned)p+0x2c),*(void **)((unsigned)p+0x30));
}
