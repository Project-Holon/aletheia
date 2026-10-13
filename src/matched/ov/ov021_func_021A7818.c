/*
 * function: FIELD_GROUND_ANIME_TexAnmUpdate
 * address:  0x021A7818
 * packet:   pkt_ov021_021A7818
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GROUND_ANIME_KeyTableGetDuration  0x021A7A8C  thumb  ov021
 *   FIELD_GROUND_ANIME_KeyTableGetKey  0x021A7A40  thumb  ov021
 *   FIELD_GROUND_ANIME_GetTexData  0x021A79E4  thumb  ov021
 *   func_02061CA4  0x02061CA4  arm
 *   _s32_div_f     0x0209C0A4  arm
 * Addresses are Black-image addresses.
 * FIELD_GROUND_ANIME_KeyTableGetKey returns its two-byte Pair by value in r0 (see its matched
 * file): the call result is spilled to a compiler temporary at sp+0x14 and
 * copied into t at sp+0x16, and every later use reads t. An inline unpack
 * of a u16 return forwards the copy and reads the temporary instead.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Pair { u8 lo; u8 hi; } Pair;

typedef struct Obj {
    u32 f00;
    Pair *f04;
    s32 *f08;
    u32 *f0C;
    s32 *f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u8 f20[0x1C];
    void *f3C;
} Obj;

extern u32 FIELD_GROUND_ANIME_KeyTableGetDuration(u8 *p);
extern Pair FIELD_GROUND_ANIME_KeyTableGetKey(void *t, u32 idx, u32 key);
extern u8 *FIELD_GROUND_ANIME_GetTexData(void *a, u32 idx);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

void FIELD_GROUND_ANIME_TexAnmUpdate(Obj *a, s32 dt)
{
    s32 lim;
    u32 i;
    Pair t;

    if (a->f1C == 0)
        return;
    lim = FIELD_GROUND_ANIME_KeyTableGetDuration(a->f20) << 12;
    for (i = 0; i < a->f14; i++) {
        a->f10[i] += dt;
        if (a->f10[i] >= lim) {
            a->f10[i] %= lim;
        } else if (a->f08[i] != -1) {
            t = FIELD_GROUND_ANIME_KeyTableGetKey(a->f20, i, a->f10[i] >> 12);
            if (t.lo != a->f04[i].lo || a->f00)
                func_02061CA4(0, a->f08[i], (u32)FIELD_GROUND_ANIME_GetTexData(a->f3C, t.lo), a->f0C[i]);
            a->f04[i] = t;
        }
    }
    a->f00 = 0;
}
