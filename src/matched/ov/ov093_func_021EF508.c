/*
 * function: BTL_MSG_BuildMoveEffectC
 * address:  0x021EF508
 * packet:   pkt_ov093_021EF508
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: `t = b + r5 * 3;` as its own statement, then `t + k` (the one-line
 * `b + r5 * 3 + k` swaps the last add); `id = p[0]` re-read after the first
 * call into a u8 local hoists the load above the u16 test.
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

void BTL_MSG_BuildMoveEffectC(u32 a, int b, u32 *p)
{
    u8 r5 = p[1] - 1;
    int k;
    int t;
    u8 id;

    BTL_MSG_SetPokeName(p[0], 0);
    id = p[0];
    if (gBtlMsgState.f58 == 0 &&
        BTL_MAIN_IsOpposingPos((int)gBtlMsgState.f0, (u8)gBtlMsgState.f54,
                      BTL_MAIN_PokeIdToClientIdThunk(id))) {
        if (BTL_MAIN_GetCompetitor(gBtlMsgState.f0) == 0 || BTL_MAIN_GetCompetitor(gBtlMsgState.f0) == (void *)4)
            k = 1;
        else
            k = 2;
    } else {
        k = 0;
    }
    t = b + r5 * 3;
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.f14, (u16)(t + k), (void *)gBtlMsgState.fc);
    WORDSET_CopyTaggedText((struct WordSet *)gBtlMsgState.f8, (void *)a, (void *)gBtlMsgState.fc);
}
