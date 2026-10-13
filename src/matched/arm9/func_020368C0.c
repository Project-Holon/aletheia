/*
 * function: GFL_NET_QUEUE_Put
 * address:  0x020368C0
 * packet:   pkt_020367C4
 * isa:      arm
 * status:   EXACT
 * blocked:  own-pool - the only pooled words naming g_020A79D0 (0x020A79D0 "0")
 *           and g_020A79D4 (0x020A79D4 "(u16)size < (0xffff/2)") sit inside this
 *           function's own pool at 0x020369BC/0x020369C4; every other witness is
 *           inside 0x020368C0..0x020369C8, so the two ABS32 fields stay wildcarded.
 *           g_020A79C4 ("net_queue.c") does have 10 outside witnesses (literal class).
 *           Verified byte-correct otherwise: 264/264, 0 concrete bytes differ.
 * symbols:
 *   GFL_NET_QUEUE_GetFreeNode   0x02036670  arm
 *   GFL_NET_RING_BUFF_GetFreeSize   0x0203660C  arm
 *   GFL_NET_RING_BUFF_Write   0x02036428  arm
 *   GFL_NET_RING_BUFF_EndChange   0x0203666C  arm
 *   func_02034714   0x02034714  arm
 *   g_020A79C4      0x020A79C4  data
 *   g_020A79D0      0x020A79D0  data
 *   g_020A79D4      0x020A79D4  data
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Node020368C0 {
    u32 f0;
    struct Node020368C0 *f4;
    struct Node020368C0 *f8;
    u16 fC;
    u16 fE;
    u8 f10;
    u8 f11;
} Node020368C0;

typedef struct Queue020368C0 {
    Node020368C0 *f0;
    Node020368C0 *f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
} Queue020368C0;

extern Node020368C0 *GFL_NET_QUEUE_GetFreeNode(Queue020368C0 *q, u32 a1, u32 a2, u32 a3);
extern u32 GFL_NET_RING_BUFF_GetFreeSize(u32 h);
extern void GFL_NET_RING_BUFF_Write(u32 h, u32 a2, u32 a3);
extern void GFL_NET_RING_BUFF_EndChange(u32 h);
extern void func_02034714(char *file, u32 line, char *expr);
extern char g_020A79C4[];
extern char g_020A79D0[];
extern char g_020A79D4[];

int GFL_NET_QUEUE_Put(Queue020368C0 *q, u16 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    Node020368C0 *n = GFL_NET_QUEUE_GetFreeNode(q, a1, a2, a3);

    if (n == 0) {
        func_02034714(g_020A79C4, 0xdb, g_020A79D0);
        return 0;
    }
    if (!((u16)a3 < 0xffff / 2)) {
        func_02034714(g_020A79C4, 0xdf, g_020A79D4);
    }
    if (a5 != 0) {
        if (!((int)(a3 + 5) < (int)GFL_NET_RING_BUFF_GetFreeSize(q->f14))) {
            func_02034714(g_020A79C4, 0xe3, g_020A79D0);
            return 0;
        }
        GFL_NET_RING_BUFF_Write(q->f14, a2, a3);
        GFL_NET_RING_BUFF_EndChange(q->f14);
        n->f0 = 0;
    } else {
        n->f0 = a2;
    }
    n->fC = a3;
    n->fE = a1;
    n->f10 = a6;
    n->f11 = 0;
    if (q->f4 == 0) {
        q->f4 = n;
        q->f0 = n;
    } else {
        q->f4->f8 = n;
        n->f4 = q->f4;
        q->f4 = n;
    }
    return 1;
}
