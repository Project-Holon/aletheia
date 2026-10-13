/*
 * function: FIELD_MSGBG_CreatePlainWin
 * address:  0x02191558
 * packet:   pkt_ov021_02191558
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   STRBUF_Create  0x020457B0  arm  arm9
 *   FIELD_MSGBG_SetupPlainWin  0x02191504  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

extern char d_021DDA50[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void FIELD_MSGBG_SetupPlainWin(u16 *a, u32 *b, u32 c, u32 d, u16 e, u16 f, u32 g);

R *FIELD_MSGBG_CreatePlainWin(Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g)
{
    R *r;

    r = func_02030734(a->f00, 0x2C, 1, d_021DDA50, 0xCA7);
    r->f0c = a;
    r->f14 = b;
    r->f08 = (u32)STRBUF_Create(0xA0, a->f00);
    FIELD_MSGBG_SetupPlainWin((u16 *)a, (u32 *)r, d, e, f, g, c);
    if (c == 1)
        r->f28 = 8;
    return r;
}
