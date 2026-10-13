/*
 * function: GAME_BEACON_UpdateGreeting
 * address:  0x02027198
 * packet:   pkt_02027198
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_Work  0x02146940  data
 *   GAME_DATA_GetSaveControl    0x02012EBC  thumb
 *   func_0200C0F0    0x0200C0F0  thumb
 *   STRBUF_GetEosChar    0x02045A98  arm
 *   func_0200C1F4    0x0200C1F4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Inner {
    u8  pad00[0x20];
    u16 arr[8];         /* 0x20 */
    u8  pad30[0x2e];
    u8  f5e;            /* 0x5e */
};

struct Outer {
    u32 f00;
    struct Inner in;
};

extern struct Outer *GAME_BEACON_Work;

struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *sv);
extern u16 STRBUF_GetEosChar(void);
struct Blk34;
extern u16 *func_0200C1F4(struct Blk34 *p);

void GAME_BEACON_UpdateGreeting(void)
{
    struct Outer *g = GAME_BEACON_Work;
    struct Inner *in;
    u16 *q;
    u32 v;
    u32 t;
    int i;

    in = &g->in;
    t = (u32)func_0200C0F0(GAME_DATA_GetSaveControl((void *)g->f00));
    v = STRBUF_GetEosChar();
    q = func_0200C1F4((struct Blk34 *)t);
    for (i = 0; i < 8; i++) {
        in->arr[i] = q[i];
        if (q[i] == v) {
            break;
        }
    }
    in->f5e = 1;
}
