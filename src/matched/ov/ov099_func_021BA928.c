/*
 * function: WIFICLUB_UpdateTalkStream
 * address:  0x021BA928
 * packet:   pkt_ov099_021BA928
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   func_02028484  0x02028484  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 */

typedef unsigned char  u8;
typedef unsigned long  u32;

struct Ctx;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
typedef signed int     s32;
struct Blk;
extern s32 func_02028484(struct Blk *blk, void *h);
struct Rec3;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

typedef struct {
    char pad00[0x190];
    int f190;
    char pad194[0x28];
    void *f1bc;
    char pad1c0[0x26c - 0x1c0];
    char f26c[0x744];
    void *f9b0;
} W;

int WIFICLUB_UpdateTalkStream(W *w)
{
    int r = 1;
    if (w->f1bc != 0) {
        if (w->f190 != 0) {
            APP_KEYCURSOR_Update(w->f9b0, w->f1bc, (void *)w->f190);
        }
        r = func_02028484((struct Blk *)w->f26c, w->f1bc);
        if (r != 0 && w->f1bc != 0) {
            PRINTSYS_PrintStreamDelete(w->f1bc);
            w->f1bc = 0;
        }
    }
    return r;
}
