/*
 * file:     net_lower_data.c
 * unit:     yes
 * function: func_0203E5F8, func_0203E6C0, func_0203E758, func_0203E808, func_0203E8C8, func_0203E96C, func_0203E9DC, func_0203EA54, func_0203EA70, func_0203EA9C, func_0203EC04, func_0203EC7C, func_0203ECD8, func_0203ED84, func_0203EE18
 * address:  0x0203E5F8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand from net_lower_data_p01..p05 and the members func_0203EA54 and
 * func_0203EA70, with one struct per object (LowData, LowRec, LowCtx).
 *
 * symbols:
 *   g_021469F4      0x021469F4  data
 *   s_020A7D74      0x020A7D74  data
 *   s_020A7D88      0x020A7D88  data
 *   s_020A7DA0      0x020A7DA0  data
 *   s_020A7DD8      0x020A7DD8  data
 *   s_020A7DB8      0x020A7DB8  data
 *   s_020A7E00      0x020A7E00  data
 *   s_020A7E28      0x020A7E28  data
 *   func_0203CD98   0x0203CD98  arm
 *   func_0203D798   0x0203D798  arm
 *   func_02038D4C   0x02038D4C  arm
 *   func_02038D30   0x02038D30  arm
 *   func_020399A8   0x020399A8  arm
 *   func_0203D1A4   0x0203D1A4  arm
 *   func_02034734   0x02034734  arm
 */
struct Entry;
struct Link;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* One transfer record, 0x48 bytes, allocated per slot. */
struct LowRec {
    u32 base;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u8  done : 1;
    u8  owned : 1;
};

/* The block g_021469F4 points to, 0x48 bytes. */
struct LowData {
    struct LowRec *rec[8];
    u32 unk_20;
    u32 unk_24;
    u8  unk_28;
    u8  pad_29[3];
    u32 unk_2c;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
};

/* The link context func_0203D798 returns. */
struct LowCtx {
    u8  pad_00[0x61];
    u8  unk_61;
    u8  pad_62[2];
    u8  unk_64;
    u8  pad_65[7];
    u16 unk_6c;
};

struct Cmd {
    u32 cmd : 2;
    u32 data : 30;
};

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02034734(const char *file, u32 line, const char *msg, ...);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int  func_0203CD98(void);
extern void *func_0203D798(void);
extern int  func_02038D4C(void);
extern int  func_02038D30(void);
extern struct Entry *func_0203996C(s32 idx);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern char s_020A7D74[];
extern char s_020A7D88[];
extern char s_020A7DA0[];
extern char s_020A7DD8[];
extern char s_020A7DB8[];
extern char s_020A7E00[];
extern char s_020A7E28[];
extern struct LowData *g_021469F4;
void func_0203E5F8(int a0, int a1);
void func_0203E6C0(void);
void func_0203E758(int a0, int a1, int a2, int a3);
void func_0203E808(u32 a0, int a1, u32 a2, u32 a3);
void func_0203E8C8(int idx);
int func_0203E96C(unsigned int idx);
int func_0203E9DC(unsigned int idx);
int func_0203EA54(void);
int func_0203EA70(unsigned int idx);
void func_0203EA9C(void);
u32 func_0203EC04(int a0);
u32 func_0203EC7C(u32 idx);
void func_0203ECD8(u32 idx, u32 delta, u32 a2, u32 a3, u32 who);
int func_0203ED84(int a0);
void func_0203EE18(u32 idx, u32 a1, struct Cmd *pVal, u32 a3, u32 a4);


void func_0203E5F8(int a0, int a1)
{
    u8 i;
    if (g_021469F4 != 0)
        func_02034714(s_020A7D74, 0x65, s_020A7D88);
    g_021469F4 = (struct LowData *)func_02030734(a0, 0x48, 1, s_020A7D74, 0x67);
    g_021469F4->unk_20 = 0;
    g_021469F4->unk_24 = 0;
    g_021469F4->unk_44 = 0;
    g_021469F4->unk_30 = 0;
    g_021469F4->unk_34 = 0;
    g_021469F4->unk_38 = a1;
    g_021469F4->unk_3c = 1;
    g_021469F4->unk_40 = 0;
    for (i = 0; i < 8; i++)
        g_021469F4->rec[i] = 0;
}


void func_0203E6C0(void)
{
    u8 i;
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x81, s_020A7DA0);
    for (i = 0; i < 8; i++) {
        struct LowRec *p = g_021469F4->rec[i];
        if (p == 0)
            continue;
        if (p->owned == 1)
            func_020307B0((void *)p->base);
        func_020307B0(g_021469F4->rec[i]);
    }
    func_020307B0(g_021469F4);
    g_021469F4 = 0;
}


void func_0203E758(int a0, int a1, int a2, int a3)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x9f, s_020A7DA0);
    if (g_021469F4->unk_20 != 0)
        func_02034714(s_020A7D74, 0xa0, s_020A7DB8);
    g_021469F4->unk_20 = a0;
    g_021469F4->unk_24 = a1;
    g_021469F4->unk_28 = (u8)a2;
    g_021469F4->unk_2c = a3;
    g_021469F4->unk_44 = 0;
    g_021469F4->unk_34 = 1;
    g_021469F4->unk_30 = 0;
}


void func_0203E808(u32 a0, int a1, u32 a2, u32 a3)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xcf, s_020A7DA0);
    if (g_021469F4->rec[a1] != 0)
        func_02034714(s_020A7D74, 0xd0, s_020A7DD8);
    g_021469F4->rec[a1] = (struct LowRec *)func_02030734(a2, 0x48, 1, s_020A7D74, 0xd2);
    g_021469F4->rec[a1]->base = a3;
    g_021469F4->rec[a1]->unk_04 = a0;
    g_021469F4->rec[a1]->owned = 0;
}


void func_0203E8C8(int idx)
{
    struct LowRec *p;
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xe2, s_020A7DA0);
    if (g_021469F4->rec[idx] == 0)
        func_02034714(s_020A7D74, 0xe3, s_020A7E00);
    p = g_021469F4->rec[idx];
    if (p->owned == 1)
        func_020307B0((void *)p->base);
    func_020307B0(g_021469F4->rec[idx]);
    g_021469F4->rec[idx] = 0;
}


int func_0203E96C(unsigned int idx)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xf6, s_020A7DA0);
    if (g_021469F4->rec[idx] == 0)
        func_02034714(s_020A7D74, 0xf7, s_020A7E00);
    return g_021469F4->rec[idx]->base;
}

int func_0203E9DC(unsigned int idx)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x105, s_020A7DA0);
    if (g_021469F4->rec[idx] == 0)
        func_02034714(s_020A7D74, 0x106, s_020A7E00);
    return g_021469F4->rec[idx]->unk_0c;
}

int func_0203EA54(void)
{
    if (g_021469F4 == 0)
        return 0;
    return g_021469F4->unk_30;
}

int func_0203EA70(unsigned int idx)
{
    struct LowRec *p;
    if (g_021469F4 == 0 || (p = g_021469F4->rec[idx]) == 0)
        return 0;
    return p->done;
}


/*
 * net_lower_data.c's per-frame pump over the transfer block g_021469F4
 * points to: while the block is live (+0x20) and the link reports state 1,
 * either flush the pending first packet (+0x34, func_0203ED84(0)), or, while
 * the sent count +0x44 is below the total +0x24 and sending is armed (+0x3C),
 * send as many bytes as the link window allows (ctx +0x6C or +0x61 minus the
 * in-flight count, less a 0x10 header, clamped to what remains) through
 * func_0203EC04, or, once everything is sent, post the end packet
 * (func_0203ED84(1)) once; then post a pending ack (+0x40, func_0203ED84(2)).
 */
void func_0203EA9C(void)
{
    struct LowCtx *ctx;
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

u32 func_0203EC04(int a0)
{
    int a = g_021469F4->unk_2c;
    int b = g_021469F4->unk_20;
    int c = g_021469F4->unk_44;
    int v = b + c;
    int t;
    if (a == 1)
        t = (int)func_0203996C(0xff);
    else
        t = (int)func_020399A8();
    return func_0203D4D0(t, g_021469F4->unk_28, 0xe, a0, v, 0, 1, 1);
}


/*
 * End offset (+0x00 base plus +0x0C length) of record idx (0xFF meaning 0)
 * in the table g_021469F4 points to, re-checked after func_0203D798; 0 when
 * the table or record is missing.
 */
/*
 * net_lower_data.c: end offset (+0x00 base plus +0x0C length) of record
 * idx (0xFF meaning 0) in the table g_021469F4 points to, re-checked after
 * func_0203D798; 0 when the table or record is missing.  Same double guard
 * as the matched func_0203ECD8, but the FIRST guard is a wrapping positive
 * test (`!= 0 && != 0`) whose failure falls through to the one trailing
 * return 0, which is the shared null-exit block the earlier note wanted.
 */
u32 func_0203EC7C(u32 idx)
{
    struct LowRec *rec;
    if (idx == 0xff) {
        idx = 0;
    }
    if (g_021469F4 != 0 && g_021469F4->rec[idx] != 0) {
        func_0203D798();
        if (g_021469F4 == 0 || g_021469F4->rec[idx] == 0) {
            return 0;
        }
        rec = g_021469F4->rec[idx];
        return rec->base + rec->unk_0c;
    }
    return 0;
}


/*
 * Credit `delta` to the score record of player `idx` (0xff meaning "me",
 * folded to slot 0 on entry).  The global is re-read after every call
 * because each callee may publish a new table.
 */
void func_0203ECD8(u32 idx, u32 delta, u32 a2, u32 a3, u32 who)
{
    struct LowCtx *ctx;
    struct LowRec *rec;

    if (idx == 0xff) {
        idx = 0;
    }
    if (g_021469F4 == 0 || g_021469F4->rec[idx] == 0) {
        return;
    }

    ctx = func_0203D798();

    if (g_021469F4 == 0 || g_021469F4->rec[idx] == 0) {
        return;
    }

    if ((u32)func_020399A8() != who && ctx->unk_64 == 0) {
        return;
    }

    rec = g_021469F4->rec[idx];
    rec->unk_0c += delta;

    if (g_021469F4->unk_38 != 1) {
        return;
    }

    if (idx != func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
        g_021469F4->unk_40 = 1;
    }
}

int func_0203ED84(int a0)
{
    struct Cmd sv;
    int t;
    if (g_021469F4->unk_2c == 1)
        t = (int)func_0203996C(0xff);
    else
        t = (int)func_020399A8();
    sv.cmd = a0;
    sv.data = g_021469F4->unk_24;
    return func_0203D4D0(t, g_021469F4->unk_28, 0xf, 4, (u32)(&sv), 0, 1, 0);
}


/*
 *           --suggest-split offers nothing (single function, the one
 *           unresolved site's only witness is inside this range).
 */
void func_0203EE18(u32 idx, u32 a1, struct Cmd *pVal, u32 a3, u32 a4)
{
    struct LowCtx *r7;

    if (idx == 0xff) {
        idx = 0;
    }
    if (g_021469F4 == 0 || g_021469F4->rec[idx] == 0) {
        return;
    }

    r7 = func_0203D798();
    if (g_021469F4 == 0 || g_021469F4->rec[idx] == 0) {
        return;
    }

    if (a4 != (u32)func_020399A8()) {
        if (r7->unk_64 == 0) {
            return;
        }
    }

    switch (pVal->cmd) {
    case 0:
        if (g_021469F4->rec[idx]->unk_04 < pVal->data) {
            func_02034734(s_020A7D74, 543, s_020A7E28, g_021469F4->rec[idx]->unk_04, pVal->data);
        }
        g_021469F4->rec[idx]->unk_08 = pVal->data;
        g_021469F4->rec[idx]->unk_0c = 0;
        g_021469F4->rec[idx]->done = 0;
        break;

    case 1:
        if (g_021469F4->rec[idx]->unk_0c == g_021469F4->rec[idx]->unk_08) {
            g_021469F4->rec[idx]->done = 1;
        }
        break;

    case 2:
        if (idx != func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
            g_021469F4->unk_3c = 1;
        }
        break;
    }
}
