/*
 * function: BTL_MSG_BuildBallStatusRefresh
 * address:  0x021EF7AC
 * packet:   pkt_ov093_021EF7AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
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

struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern D gBtlMsgState;

void BTL_MSG_BuildBallStatusRefresh(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    MSGDATA_ReadString((struct MsgBank *)gBtlMsgState.f1c, 0x11, (void *)gBtlMsgState.fc);
    func_0201EFA4((struct WordSet *)gBtlMsgState.f8, 0, b, 3, 0, 1);
    func_0201EFA4((struct WordSet *)gBtlMsgState.f8, 1, c, 3, 0, 1);
    func_0201EFA4((struct WordSet *)gBtlMsgState.f8, 2, d, 3, 0, 1);
    func_0201EFA4((struct WordSet *)gBtlMsgState.f8, 3, e, 3, 0, 1);
    func_0201EFA4((struct WordSet *)gBtlMsgState.f8, 4, f, 3, 0, 1);
    func_0201EFA4((struct WordSet *)gBtlMsgState.f8, 5, g, 3, 0, 1);
    func_0201F250((struct WordSet *)gBtlMsgState.f8, (void *)a, (void *)gBtlMsgState.fc);
}
