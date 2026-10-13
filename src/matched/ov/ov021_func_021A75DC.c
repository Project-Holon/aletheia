/*
 * function: FIELD_GROUND_ANIME_TexAnmSetInit
 * address:  0x021A75DC
 * packet:   pkt_ov021_021A75DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   FIELD_GROUND_ANIME_TexAnmInit  0x021A7678  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct T { u32 n; } T;
typedef struct W { u8 a[0x400]; T *tbl; } W;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern void FIELD_GROUND_ANIME_TexAnmInit(u8 *a, T *b, u32 c, u32 d, u32 e);

void FIELD_GROUND_ANIME_TexAnmSetInit(W *w, u32 a, u32 b, u32 c, u32 heap)
{
    u32 i;
    w->tbl = (T *)ARC_UTIL_LoadMember(a, b, 0, heap);
    for (i = 0; i < w->tbl->n; i++)
        FIELD_GROUND_ANIME_TexAnmInit(&w->a[i * 64], w->tbl, i, c, heap);
}
