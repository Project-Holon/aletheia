/*
 * function: BTL_MSG_Exit
 * address:  0x021EECD8
 * packet:   pkt_ov093_021EECD8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlMsgState  0x021F6398  data  a4
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 t[8];
} D;

extern D gBtlMsgState;
struct Rec;
struct U16Vec;
struct WordSet;
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);

void BTL_MSG_Exit(void)
{
    int i;

    WORDSET_DeleteStrbufED04((struct WordSet *)gBtlMsgState.f8);
    STRBUF_Delete((struct U16Vec *)gBtlMsgState.fc);
    for (i = 0; i < 8; i++)
        MSGDATA_Delete((struct Rec *)gBtlMsgState.t[i]);
}
