/*
 * function: BTL_NET_RecvEntry
 * address: 0x021D42BC
 * packet: pkt_ov093_021D42BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/btl_net.c and filed here.
 *
 * symbols:
 *   gBtlNet 0x021F3B88 data ov093 a4
 */

struct BtlNet;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int w[8];
} S32;

struct BtlNetRec {
    u8 pad00[0xbb8];
    u16 fBB8;
    u16 fBBA;
};

struct BtlNetSync {
    struct {
        u8 val;
        u8 ok;
    } e[4];
    u8 n;
    u8 mx;
    u8 pad[2];
};

struct BtlNet {
    void *link;                 /* 0x00 */
    u16 heap;                   /* 0x04 */
    u8 id;                      /* 0x06 */
    u8 f07;                     /* 0x07 */
    u16 mask;                   /* 0x08 */
    u8 f0a, count, f0c, f0d, f0e, f0f, f10;
    u8 states[4];               /* 0x11 */
    u8 pad15[3];
    S32 f18;                    /* 0x18 */
    struct BtlNetRec rec0;      /* 0x38 */
    struct BtlNetRec peer[4];   /* 0xbf4 */
    void *tblA[4];              /* 0x3ae4 */
    void *tblB[4];
    void *tblC[4];
    void *f3b14;
    void *f3b18;
    union {
        u32 f3b1c;
        u16 buf[2];
    } u;                        /* 0x3b1c */
    struct BtlNetSync sync;     /* 0x3b20 */
};

void BTL_NET_RecvEntry(int idx, int unused, u16 *data);
extern struct BtlNet *gBtlNet;

void BTL_NET_RecvEntry(int idx, int unused, u16 *data)
{
    struct BtlNet *d = gBtlNet;
    struct BtlNetSync *s = &d->sync;
    int i;

    if (s->e[idx].ok == 0) {
        u16 v = data[0];
        d->states[idx] = data[1];
        s->e[idx].val = v;
        s->e[idx].ok = 1;
        if (s->mx < v)
            s->mx = v;
        s->n++;
        if (s->n >= gBtlNet->count) {
            gBtlNet->f07 = 0x28;
            for (i = 0; i < 4; i++) {
                if (s->e[i].ok != 0 && s->mx == s->e[i].val) {
                    gBtlNet->f07 = i;
                    return;
                }
            }
        }
    }
}
