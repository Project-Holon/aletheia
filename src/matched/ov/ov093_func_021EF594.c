/*
 * function: BTL_MSG_BuildClientAction
 * address:  0x021EF594
 * packet:   pkt_ov093_021EF594
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_MAIN_IsTrainerSlotNpc  0x021B9F70  thumb  ov093
 *   BTL_MSG_ExpandTags  0x021EEFE0  thumb  ov093
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   gBtlMsgState     0x021F6398  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

extern u8 BTL_MAIN_GetOwnClientId(u8 *p);
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
struct MsgBank;
struct WordSet;
extern void BTL_MSG_ExpandTags(void *s, const u32 *values, void *w);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern D gBtlMsgState;

void BTL_MSG_BuildClientAction(u32 a, u32 b, u32 *p)
{
    u8 id = p[0];
    int k;

    if (id != BTL_MAIN_GetOwnClientId((u8 *)gBtlMsgState.f0)) {
        if (BTL_MAIN_IsTrainerSlotNpc((u8 *)gBtlMsgState.f0, id))
            k = 0x23;
        else
            k = 0x22;
    } else {
        k = 0x21;
    }
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.f10, k, (void *)gBtlMsgState.fc);
    BTL_MSG_ExpandTags((void *)gBtlMsgState.fc, (const u32 *)((u32)p), (void *)gBtlMsgState.f8);
    WORDSET_CopyTaggedText((struct WordSet *)gBtlMsgState.f8, (void *)a, (void *)gBtlMsgState.fc);
}
