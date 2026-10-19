/*
 * function: PARTY_SELECT_LIST_FreeMessageResources
 * address:  0x021CCEE4
 * packet:   pkt_021CCEE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   WORDSET_Delete  0x0201ED04  thumb
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct WordSet;
extern u32 WORDSET_Delete(struct WordSet *p);
struct Rec;
extern u32 FIELD_MSGBG_DeleteMsgData(struct Rec *a0);

int PARTY_SELECT_LIST_FreeMessageResources(u32 a)
{
WORDSET_Delete((struct WordSet *)(*(u32 *)((u8 *)((a + 160)))));
return FIELD_MSGBG_DeleteMsgData((struct Rec *)(*(u32 *)((u8 *)((a + 168)))));
}

