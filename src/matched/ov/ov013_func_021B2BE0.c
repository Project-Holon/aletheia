/*
 * function: VCT_SESSION_HandleSharedPacket
 * address:  0x021B2BE0
 * packet:   pkt_ov013_021B2BE0
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * note: types and the Pool/Node/Stats layouts come from matched ov013
 * 021B22B4, 021B2AA0, 021B2894, 021B279C, 021B26DC. Audio session start/
 * continue gate. d_021B4C0C is the same node as g_021B4BE0.active (separate
 * pool word in the listing, so two externs).
 *
 * note pass 2 2026-10-06 P2L53: EXACT (c99 and c). The event fill
 * (ev->type, ev->node, n->fc) is written out in each arm and only the tick
 * stamp is shared. The two fill copies are cross-jumped after jump threading,
 * which leaves the lone `b` hop at +0x88 (idiom
 * a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy).
 * The ev->type compare then sits after a join with two stored values, so it
 * is reloaded (`ldr r0,[r7]`), and the zero/result colours (r6/r4) follow.
 *
 * symbols:
 *   g_021B4BE0     0x021B4BE0  data  a4
 *   d_021B4C0C     0x021B4C0C  data  a4
 *   g_021B4BD0     0x021B4BD0  data  a4
 *   VCT_SESSION_AdvancePhase  0x021B2894  arm  ov013
 *   VCT_SESSION_GetEventCode  0x021B279C  arm  ov013
 *   VCT_SESSION_BroadcastState  0x021B26DC  arm  ov013
 *   func_020870D0  0x020870D0  arm
 */

#include "../include/G_Pool.h"
#include "../include/G_Stats.h"
#include "../include/G_N.h"

struct Node {
    unsigned int state;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
    unsigned int f8;
    unsigned int fc;
    unsigned int f10;
    struct Node *next;
};

struct Pkt {
    unsigned char pad0[4];
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned int fc;
};

struct Event {
    int type;
    struct Node *node;
};

extern struct Pool g_021B4BE0;
extern struct Stats g_021B4BD0;
extern struct N d_021B4C0C;
typedef unsigned char  u8;
struct Ctx;
struct Msg;
struct Q;
extern int VCT_SESSION_AdvancePhase(struct Ctx *c, struct Msg *m);
extern int VCT_SESSION_GetEventCode(u8 *o, struct Q *q);
extern void VCT_SESSION_BroadcastState(int x);
extern unsigned long long func_020870D0(void);

int VCT_SESSION_HandleSharedPacket(struct Pkt *pkt, struct Event *ev)
{
    struct Node *n;
    int r;

    if (g_021B4BE0.active_state == 2) {
        if (g_021B4BE0.id == pkt->f8) {
            n = ((struct Node *)&d_021B4C0C);
            r = VCT_SESSION_AdvancePhase((struct Ctx *)n, (struct Msg *)pkt);
            switch (r) {
            case -2:
                ev->type = 0xC;
                ev->node = 0;
                return 1;
            case -3:
            case -1:
                return 0;
            default:
                break;
            }
            ev->type = VCT_SESSION_GetEventCode((u8 *)pkt, (struct Q *)n);
            ev->node = n;
            n->fc = r;
        } else {
            VCT_SESSION_BroadcastState(1);
            return 0;
        }
    } else {
        if (!(g_021B4BD0.f4 & ((pkt->f8 != 0) ? (1 << pkt->f8) : 1)))
            return 0;
        g_021B4BE0.id = pkt->f8;
        g_021B4BE0.active_state = 2;
        g_021B4BE0.active_fc = 0;
        n = ((struct Node *)&d_021B4C0C);
        r = VCT_SESSION_AdvancePhase((struct Ctx *)n, (struct Msg *)pkt);
        switch (r) {
        case -3:
        case -2:
        case -1:
            g_021B4BE0.active_state = 0;
            return 0;
        }
        ev->type = VCT_SESSION_GetEventCode((u8 *)pkt, (struct Q *)n);
        ev->node = n;
        n->fc = r;
    }
    if (ev->type == 10) {
        VCT_SESSION_BroadcastState(1);
        g_021B4BD0.f8 = func_020870D0();
    } else {
        VCT_SESSION_BroadcastState(0);
        g_021B4BD0.f8 = 0;
    }
    return 1;
}
