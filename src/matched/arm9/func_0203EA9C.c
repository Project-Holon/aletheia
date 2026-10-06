/*
 * function: func_0203EA9C
 * address:  0x0203EA9C
 * packet:   pkt_0203EA9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F4     0x021469F4  data
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203ED84  0x0203ED84  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02038D4C  0x02038D4C  arm
 *   func_02038D30  0x02038D30  arm
 *   func_0203EC04  0x0203EC04  arm
 *
 * net_lower_data.c's per-frame pump over the transfer block g_021469F4
 * points to: while the block is live (+0x20) and the link reports state 1,
 * either flush the pending first packet (+0x34, func_0203ED84(0)), or, while
 * the sent count +0x44 is below the total +0x24 and sending is armed (+0x3C),
 * send as many bytes as the link window allows (ctx +0x6C or +0x61 minus the
 * in-flight count, less a 0x10 header, clamped to what remains) through
 * func_0203EC04, or, once everything is sent, post the end packet
 * (func_0203ED84(1)) once; then post a pending ack (+0x40, func_0203ED84(2)).
 * Written as one if / else-if chain with no gotos; exact on the first compile.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8  pad_00[0x61];
    u8  unk_61;
    u8  pad_62[0xa];
    u16 unk_6c;
};

struct Tbl {
    u8  pad_00[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
};

extern struct Tbl *g_021469F4;
extern int  func_0203CD98(void);
extern int  func_0203ED84(int a0);
extern void *func_0203D798(void);
extern int  func_02038D4C(void);
extern int  func_02038D30(void);
extern u32 func_0203EC04(int a0);

void func_0203EA9C(void)
{
    struct Ctx *ctx;
    int d;

    if (g_021469F4 == 0 || g_021469F4->unk_20 == 0) {
        return;
    }
    if (func_0203CD98() != 1) {
        return;
    }
    if (g_021469F4->unk_34 == 1) {
        if (func_0203ED84(0) == 1) {
            g_021469F4->unk_34 = 0;
        }
    } else if (g_021469F4->unk_44 < g_021469F4->unk_24) {
        if (g_021469F4->unk_3c == 1) {
            ctx = func_0203D798();
            if (g_021469F4->unk_2c == 1) {
                d = ctx->unk_6c - func_02038D4C();
            } else {
                d = ctx->unk_61 - func_02038D30();
            }
            d -= 0x10;
            if (d > 0x10) {
                if (g_021469F4->unk_44 + d > g_021469F4->unk_24) {
                    d = g_021469F4->unk_24 - g_021469F4->unk_44;
                }
                if (func_0203EC04(d) == 1) {
                    g_021469F4->unk_44 += d;
                    if (g_021469F4->unk_38 == 1) {
                        g_021469F4->unk_3c = 0;
                    }
                }
            }
        }
    } else if (g_021469F4->unk_30 == 0) {
        if (func_0203ED84(1) == 1) {
            g_021469F4->unk_30 = 1;
            g_021469F4->unk_20 = 0;
        }
    }
    if (g_021469F4->unk_40 == 1) {
        if (func_0203ED84(2) == 1) {
            g_021469F4->unk_40 = 0;
        }
    }
}
