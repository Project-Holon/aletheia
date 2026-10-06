/*
 * function: func_02155244
 * address:  0x02155244
 * packet:   pkt_ov010_02155244
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Walks the party (two slots when the single-battle flag at f88->f22 is
 * clear, four otherwise), skipping the local player's slot, and sets each
 * member's display state from the mode word at +0xcc.
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012950  0x02012950  thumb
 *   func_0201283C  0x0201283C  thumb
 *   func_02009D1C  0x02009D1C  thumb
 *   func_02009BB8  0x02009BB8  thumb
 *   func_02009B80  0x02009B80  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Info {
    u8 pad00[0x22];
    u8 f22;
};

struct Ctx {
    u8 pad00[0x78];
    u8 b78[4];
    u8 pad7c[0x0c];
    struct Info *f88;
    u8 pad8c[0x40];
    int fcc;
};

struct Entry;
extern struct Entry *func_020399A8(void);
struct BigObj;
struct Link;
extern u32 func_0203D1A4(struct Link *p);
struct Rec44;
struct Sub020097BCObj;
struct Sub24;
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u32 func_0201283C(const struct BigObj *p);
struct Sub0200852CObj;
extern int func_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
extern void func_02009BB8(struct Sub020097BCObj *obj, int i, int a, int b, int c);
extern void func_02009B80(struct Sub020097BCObj *obj, int i);

void func_02155244(struct Ctx *ctx, void *party)
{
    int sel;
    int count;
    int out;
    int i;
    int t;
    u32 v;
    void *mon;

    sel = 0;
    if (ctx->f88->f22 == 0) {
        sel = sel - 1;
        count = 2;
    } else {
        v = ctx->b78[func_0203D1A4((struct Link *)((u32)func_020399A8()))];
        if (v < 2) {
            t = 1;
        } else {
            v -= 2;
            t = 3;
        }
        t = t - v;
        for (i = 0; i < 4; i++) {
            if (t == ctx->b78[i]) {
                sel = i;
                break;
            }
        }
        count = 4;
    }

    for (i = 0; i < count; i++) {
        mon = func_02012950(party, i);
        if (i != func_0203D1A4((struct Link *)((u32)func_020399A8())) && mon != 0
            && func_02009D1C((void *)func_0201283C(party), mon, (u32 *)(&out)) != 0) {
            if (i == sel) {
                func_02009B80((struct Sub020097BCObj *)func_0201283C(party), out);
            } else if (ctx->fcc == 0) {
                func_02009BB8((struct Sub020097BCObj *)func_0201283C(party), out, 1, 0, 0);
            } else if (ctx->fcc == 1) {
                func_02009BB8((struct Sub020097BCObj *)func_0201283C(party), out, 0, 1, 0);
            } else {
                func_02009B80((struct Sub020097BCObj *)func_0201283C(party), out);
            }
        }
    }
}
