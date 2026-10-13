/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200CED4
 * packet:   pkt_0200CA98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ZUKAN_SAVE_IsCaught, ZUKAN_SAVE_CountCaught, ZUKAN_SAVE_CountCaughtNational, ZUKAN_SAVE_CountCaughtRegional
 *
 * symbols:
 *   POKE_PERSONAL_LoadFormTable  0x0201AF80  thumb
 *   ZUKAN_SAVE_IsInvalidSpecies  0x0200C720  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Blk37 {
    u32 unk00;
    u32 f0  : 1;
    u32 f1  : 10;
    u32 f11 : 1;
    u32 f12 : 10;
    u32 f22 : 10;
    u8  unk008[0x54];
    u8  unk05C[4][0x54];
    u8  unk1AC[4][0x54];
    u8  unk2FC[4][9];
    u8  unk320[0x1B0];
    u32 unk4D0;
};

extern u32 ZUKAN_SAVE_IsInvalidSpecies(u32 v);
extern u32   ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern u32 func_020307B0(void *p);

u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);
u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p);
u16 ZUKAN_SAVE_CountCaughtRegional(struct Blk37 *p, u32 heap);

u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id)
{
    s32 y;
    u32 r;

    if (ZUKAN_SAVE_IsInvalidSpecies(id) != 0) {
        return 0;
    }
    y = (u16)(id - 1);
    r = 1;
    if ((p->unk008[y >> 3] & (1 << (y & 7))) == 0) {
        r = 0;
    }
    return r;
}

u16 ZUKAN_SAVE_CountCaught(struct Blk37 *p, u32 heap)
{
    if (ZUKAN_SAVE_IsNationalDexEnabled(p) != 0) {
        return ZUKAN_SAVE_CountCaughtNational(p);
    }
    return ZUKAN_SAVE_CountCaughtRegional(p, heap);
}

u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p)
{
    s32 n;
    s32 i;

    n = 0;
    for (i = 1; i <= 0x289; i++) {
        if (ZUKAN_SAVE_IsCaught(p, (u16)i) == 1) {
            n++;
        }
    }
    return (u16)n;
}

u16 ZUKAN_SAVE_CountCaughtRegional(struct Blk37 *p, u32 heap)
{
    u16 i;
    u16 n;
    u16 *t;

    n = 0;
    t = POKE_PERSONAL_LoadFormTable(heap, 0);
    for (i = 1; i <= 0x289; i++) {
        if (ZUKAN_SAVE_IsCaught(p, i) == 1 && t[i] != 0x3E7) {
            n = (u16)(n + 1);
        }
    }
    func_020307B0(t);
    return n;
}
