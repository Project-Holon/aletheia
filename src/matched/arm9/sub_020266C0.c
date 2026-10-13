/*
 * unit:     no
 * address:  0x020266C0
 * packet:   pkt_02026250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_COMM_PushPalaceMessage
 *
 * symbols:
 *   GAME_COMM_PushInfoMessage  0x02026504  thumb
 *
 * The same wrapper shape as src/matched/GAME_COMM_PushPairMessage.c, with the constant
 * pair 0x1e/0x1d in place of 0x27/0x26. See that file's header for why it
 * is kept in its own translation unit rather than merged with its two
 * siblings.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPalaceMessage.c \
 *       --func GAME_COMM_PushPalaceMessage --addr 0x020266C0 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Obj;
extern void GAME_COMM_PushInfoMessage(struct Obj *o, u32 id0, u32 id1, u32 v);

void GAME_COMM_PushPalaceMessage(u32 a, u32 b, u32 c)
{
    GAME_COMM_PushInfoMessage((struct Obj *)a, b, c, (u16)((b == c) ? 0x1e : 0x1d));
}
