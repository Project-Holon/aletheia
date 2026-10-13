/*
 * function: FIELD_GROUND_ANIME_Create
 * address:  0x021A7360
 * packet:   pkt_ov021_021A7360
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_GROUND_ANIME_AnmSetInit  0x021A7420  thumb  ov021
 *   FIELD_GROUND_ANIME_TexAnmSetInit  0x021A75DC  thumb  ov021
 *   _FieldGroundAnimeFileName     0x021DDF7C  data  ov021  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char _FieldGroundAnimeFileName;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void FIELD_GROUND_ANIME_AnmSetInit(u32 *s, u32 a, u32 b, u32 n, u32 heap);
struct W;
extern void FIELD_GROUND_ANIME_TexAnmSetInit(struct W *w, u32 a, u32 b, u32 c, u32 heap);

typedef struct D { u16 lo : 8; u16 hi : 8; u16 f1, f2, f3, f4, f5, f6; } D;

u32 *FIELD_GROUND_ANIME_Create(const D *p, u32 c, u32 heap)
{
    u32 *r;
    r = func_02030734(heap, 0x41c, 1, &_FieldGroundAnimeFileName, 0xd6);
    if (p->lo != 0) {
        u32 n = p->f1;
        u32 x = p->f2;
        u32 y = p->f3;
        FIELD_GROUND_ANIME_AnmSetInit(r + 2, x, y, n, heap);
    }
    if (p->hi != 0)
        FIELD_GROUND_ANIME_TexAnmSetInit((struct W *)(r + 6), p->f4, p->f5, c, heap);
    r[0] = 1;
    r[1] = 0x1000;
    return r;
}
