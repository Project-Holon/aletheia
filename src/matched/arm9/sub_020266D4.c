/*
 * unit:     no
 * address:  0x020266D4
 * packet:   pkt_02026250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_COMM_PushPlayerMessage
 *
 * symbols:
 *   GAME_COMM_PushInfoMessage  0x02026504  thumb
 *
 * The simplest of the three GAME_COMM_PushInfoMessage wrappers: forwards its first
 * argument, repeats its second as both the second and third callee
 * argument, and appends the literal 0x1f. See
 * src/matched/GAME_COMM_PushPairMessage.c's header for why the three are kept as
 * separate files rather than one unit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_COMM_PushPlayerMessage.c \
 *       --func GAME_COMM_PushPlayerMessage --addr 0x020266D4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Obj;
extern void GAME_COMM_PushInfoMessage(struct Obj *o, u32 id0, u32 id1, u32 v);

void GAME_COMM_PushPlayerMessage(u32 a, u32 b)
{
    GAME_COMM_PushInfoMessage((struct Obj *)a, b, b, 0x1f);
}
