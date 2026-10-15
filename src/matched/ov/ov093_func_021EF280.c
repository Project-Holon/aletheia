/*
 * function: BTL_MSG_BuildStandardPair
 * address: 0x021EF280
 * packet: pkt_ov093_021EF280
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: explicit b = b + classify(k) avoids compound-assignment RHS narrowing.
 * symbols:
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_MAIN_IsOpposingPos 0x021B8CE8 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BTL_MSG_ExpandTags 0x021EEFE0 thumb ov093
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   gBtlMsgState 0x021F6398 data a4
 *   gBtlMsgFlags 0x021F63D8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f00,f04,f08,f0c,f10,f14; u8 pad18[0x3c]; u32 f54; } G;
typedef struct { u8 pad00[0x18]; u16 f18; } H;
extern G gBtlMsgState;
extern H gBtlMsgFlags;
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern int BTL_MAIN_IsOpposingPos(int a, int b, int c);
extern void *BTL_MAIN_GetCompetitor(void ***);
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void BTL_MSG_ExpandTags(void *s, const u32 *values, void *w);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
static inline int classify(u8 k)
{
    int x;
    if (gBtlMsgFlags.f18 == 0 && BTL_MAIN_IsOpposingPos(gBtlMsgState.f00, (u8)gBtlMsgState.f54, BTL_MAIN_PokeIdToClientIdThunk(k))) {
        if (BTL_MAIN_GetCompetitor((void ***)gBtlMsgState.f00) == 0 || (int)BTL_MAIN_GetCompetitor((void ***)gBtlMsgState.f00) == 4) x = 1;
        else x = 2;
    } else x = 0;
    return x;
}
void BTL_MSG_BuildStandardPair(u32 a, u16 b, u32 *p)
{
    u8 k = p[1];
    int x = classify(p[0]);
    switch (x) {
    case 0:
        b = b + classify(k);
        break;
    case 1:
        b += 3;
        goto second;
    case 2:
        b += 5;
    default:
second:
        if (x == classify(k)) b++;
        break;
    }
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.f14, b, (void *)gBtlMsgState.f0c);
    BTL_MSG_ExpandTags((void *)gBtlMsgState.f0c, p, (void *)gBtlMsgState.f08);
    WORDSET_CopyTaggedText((struct WordSet *)gBtlMsgState.f08, (void *)a, (void *)gBtlMsgState.f0c);
}
