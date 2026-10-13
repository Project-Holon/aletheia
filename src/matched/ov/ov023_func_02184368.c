/*
 * function: OEKAKI_RecvSyncMessage
 * address:  0x02184368
 * packet:   pkt_ov023_02184368
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The message is copied field by field through a const pointer: that is
 * what lets the four loads pair up ahead of the stores and keeps m->b2 in
 * r0 for the switch (a struct copy, or a non-const m, reloads it).
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   UNION_APP_GetMemberCount  0x021841A4  thumb  ov022
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 *   func_02080D24  0x02080D24  arm
 *   UNION_APP_Open  0x02184134  thumb  ov022
 *   OEKAKI_QueueCommand  0x02186860  thumb  ov023
 *   OEKAKI_HandleEvent  0x02185AB0  thumb  ov023
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Msg {
    u8 b0, b1, b2, b3;
} Msg;

typedef struct W {
    u8   pad0[4];
    u32 *h4;
    u8   pad8[0x1ac - 8];
    u32  f1ac;
    u8   pad1b0[0x9278 - 0x1b0];
    Msg  msg;
    u8   pad927c[0x9284 - 0x927c];
    u16  h9284;
    u16  pad9286;
    u16  h9288;
} W;

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);
extern u32 func_02080D24(u32 x);
extern void UNION_APP_Open(u8 *p);
extern void OEKAKI_QueueCommand(char *p, int x, int y);
extern void OEKAKI_HandleEvent(char *p, int msg, int arg);

void OEKAKI_RecvSyncMessage(int a, int b, const Msg *m, W *p)
{
    int k;

    if (a != 0) {
        if (GFL_NET_SYSTEM_GetCurrentAid() != 0) {
            return;
        }
        p->msg.b0 = m->b0;
        p->msg.b1 = m->b1;
        p->msg.b2 = m->b2;
        p->msg.b3 = m->b3;
        p->msg.b0 = a;
        p->msg.b1 = p->f1ac;
        switch (m->b2) {
        case 0:
            if (p->f1ac != UNION_APP_GetMemberCount((unsigned char *)(*p->h4))
                || p->f1ac != func_02080D24(UNION_APP_GetJoinedBits((unsigned char *)(*p->h4)))) {
                p->msg.b3 = 0;
            } else {
                p->msg.b3 = 1;
                UNION_APP_Open((u8 *)(*p->h4));
            }
            break;
        case 1:
            break;
        }
        OEKAKI_QueueCommand((char *)p, 0x2905, 0);
        return;
    }
    switch (m->b2) {
    case 0:
        k = m->b0;
        if (k != GFL_NET_SYSTEM_GetCurrentAid()) {
            return;
        }
        if (m->b3 == 0) {
            OEKAKI_HandleEvent((char *)p, 0xb, k);
            return;
        }
        p->h9284 = m->b1;
        OEKAKI_HandleEvent((char *)p, 9, m->b0);
        p->h9288 = 1;
        return;
    case 1:
        if (p->h9288 == 0) {
            OEKAKI_HandleEvent((char *)p, 0x18, m->b0);
        }
        return;
    }
}
