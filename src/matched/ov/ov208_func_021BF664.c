/*
 * function: ZUKAN_DETAIL_INFO_UpdateHighlightBlink
 * address: 0x021BF664
 * packet: pkt_ov208_021BF664
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (D5-03): closed by u8 channel locals for colour A, the store as
 *   r | g << 5 | b << 10 (GX_RGB order) with the three lerps inline, and the f108 wrap
 *   written on the field directly (no x/y locals).
 * symbols:
 *   FX_SinCosTable_ 0x020A1B38 data
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   func_02061CA4 0x02061CA4 arm
 */

typedef struct {
    char pad0[0x98];
    int f98;
    char pad9c[0xa8 - 0x9c];
    unsigned short srcA[0x10];
    unsigned short srcB[0x10];
    unsigned short dst[0x10];
    int f108;
    int f10c;
} Ent;

extern short FX_SinCosTable_[];
typedef signed int     s32;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

void ZUKAN_DETAIL_INFO_UpdateHighlightBlink(int a0, Ent *e)
{
    if (e->f10c != 0) {
        int v = e->f98;

        if (v != 6)
            CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)((char *)e + v * 0x14 + 0x1c)), 2, 0);
        e->f10c = 0;
    }

    if (e->f108 + 0x400 >= 0x10000)
        e->f108 = e->f108 + 0x400 - 0x10000;
    else
        e->f108 = e->f108 + 0x400;

    {
        unsigned char i;
        int t = e->f108;
        short ratio;

        t = ((t >> 4) << 1) + 1;
        ratio = (FX_SinCosTable_[t] + 0x1000) / 2;

        for (i = 0; i < 0x10; i++) {
            unsigned short A = e->srcA[i];
            unsigned short B = e->srcB[i];
            unsigned char g = (A & 0x3e0) >> 5;
            unsigned char r = A & 0x1f;
            unsigned char b = (A & 0x7c00) >> 10;

            e->dst[i] = (unsigned short)((unsigned char)(r + ((ratio * ((unsigned char)(B & 0x1f) - r)) >> 12))
                | ((unsigned char)(g + ((ratio * ((unsigned char)((B & 0x3e0) >> 5) - g)) >> 12)) << 5)
                | ((unsigned char)(b + ((ratio * ((unsigned char)((B & 0x7c00) >> 10) - b)) >> 12)) << 10));
        }

        func_02061CA4((void *)0xe, 0xc0, (int)e->dst, 0x20);
    }
}
