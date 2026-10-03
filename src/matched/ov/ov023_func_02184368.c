/*
 * function: func_02184368
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
 *   func_02039338  0x02039338  arm
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_02080D24  0x02080D24  arm
 *   func_02184134  0x02184134  thumb  ov022
 *   func_02186860  0x02186860  thumb  ov023
 *   func_02185AB0  0x02185AB0  thumb  ov023
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

extern u16 func_02039338(void);
extern u32 func_021841A4(u32 x);
extern u32 func_021841A0(u32 x);
extern u32 func_02080D24(u32 x);
extern void func_02184134(u32 x);
extern void func_02186860(W *p, int x, int y);
extern void func_02185AB0(W *p, int a, int b);

void func_02184368(int a, int b, const Msg *m, W *p)
{
    int k;

    if (a != 0) {
        if (func_02039338() != 0) {
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
            if (p->f1ac != func_021841A4(*p->h4)
                || p->f1ac != func_02080D24(func_021841A0(*p->h4))) {
                p->msg.b3 = 0;
            } else {
                p->msg.b3 = 1;
                func_02184134(*p->h4);
            }
            break;
        case 1:
            break;
        }
        func_02186860(p, 0x2905, 0);
        return;
    }
    switch (m->b2) {
    case 0:
        k = m->b0;
        if (k != func_02039338()) {
            return;
        }
        if (m->b3 == 0) {
            func_02185AB0(p, 0xb, k);
            return;
        }
        p->h9284 = m->b1;
        func_02185AB0(p, 9, m->b0);
        p->h9288 = 1;
        return;
    case 1:
        if (p->h9288 == 0) {
            func_02185AB0(p, 0x18, m->b0);
        }
        return;
    }
}
