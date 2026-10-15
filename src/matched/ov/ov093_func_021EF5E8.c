/*
 * function: BTL_MSG_BuildItemUse
 * address:  0x021EF5E8
 * packet:   pkt_ov093_021EF5E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_SetPokeName  0x021EED00  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_IsOpposingPos  0x021B8CE8  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
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

extern void BTL_MSG_SetPokeName(u8 a, u32 b);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern int BTL_MAIN_IsOpposingPos(int a, int b, int c);
extern void *BTL_MAIN_GetCompetitor(void ***p);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct WordSet;
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern D gBtlMsgState;

void BTL_MSG_BuildItemUse(u32 a, u8 b, u16 c)
{
    int k;
    u16 t;

    if (gBtlMsgState.f58 == 0 &&
        BTL_MAIN_IsOpposingPos((int)gBtlMsgState.f0, (u8)gBtlMsgState.f54, BTL_MAIN_PokeIdToClientIdThunk(b))) {
        if (BTL_MAIN_GetCompetitor(gBtlMsgState.f0) == 0 || BTL_MAIN_GetCompetitor(gBtlMsgState.f0) == (void *)4)
            k = 1;
        else
            k = 2;
    } else {
        k = 0;
    }
    BTL_MSG_SetPokeName(b, 0);
    t = c * 3;
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.f18, (u16)(t + k), (void *)gBtlMsgState.fc);
    WORDSET_CopyTaggedText((struct WordSet *)gBtlMsgState.f8, (void *)a, (void *)gBtlMsgState.fc);
}
