/*
 * function: func_021D4CB8
 * address: 0x021D4CB8
 * packet: pkt_ov093_021D4CB8
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
 *   d_021F3B88 0x021F3B88 data ov093 a4
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

void func_021D4CB8(int unused, u32 v);
extern struct BtlNet *d_021F3B88;

void func_021D4CB8(int unused, u32 v)
{
    struct BtlNet *d = d_021F3B88;

    if (d->f0d == 0) {
        struct BtlNetRec *r = &d->rec0;
        r->fBB8 = (u16)v;
        r->fBBA = 0;
        d_021F3B88->f0d = 1;
    }
}
