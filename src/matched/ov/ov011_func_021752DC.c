/*
 * function: INTRUDE_COMM_UpdateSelfRecord
 * address:  0x021752DC
 * packet:   pkt_ov011_021752DC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   COMM_PLAYER_UpdateMyPackage  0x0216786C  thumb ov010
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 */
#include "../include/Obj09349.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Hd {
    u8 pad[0x14];
    u16 f14;
    u16 lo : 3;
    u16 x : 6;
    u16 mid : 6;
    u16 top : 1;
} Hd;

typedef unsigned int   u32;
struct Report;
struct SaveBlock;
struct Work;
u32 func_02026478(void *obj);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
struct Rec44;
u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
int COMM_PLAYER_UpdateMyPackage(struct Work *w, struct Report *out);
u8 GAME_DATA_GetSymbolMapFlag(int a);

int INTRUDE_COMM_UpdateSelfRecord(u8 *p)
{
    int ctx;
    int v;
    int r;
    int k;
    Hd *h;

    ctx = func_02026478((void *)(((struct Obj09349 *)p)->f4));
    v = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)ctx));
    h = (Hd *)(p + 0x70);
    r = COMM_PLAYER_UpdateMyPackage((struct Work *)(((struct Obj09349 *)p)->f8), (struct Report *)h);
    if (h->f14 != v) {
        h->f14 = v;
        r = 1;
    }
    if (h->x != GAME_DATA_GetSymbolMapFlag(ctx)) {
        h->x = GAME_DATA_GetSymbolMapFlag(ctx);
        r = 1;
    }
    k = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    if (h->top != k) {
        h->top = k;
        r = 1;
    }
    return r;
}
