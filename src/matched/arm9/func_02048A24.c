/*
 * function: func_02048A24
 * address:  0x02048A24
 * packet:   pkt_02048330
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A7EC4     0x020A7EC4  data
 *   func_02030734  0x02030734  arm
 *
 * Constructor for a 0x44-byte record: eight words straight from the
 * parameters, then three 12-byte (three-word) aggregates at +0x20, +0x2C and
 * +0x38, each copied with `ldm`/`stm` because a three-word aggregate is above
 * the point where the compiler moves them word by word.  The last parameter
 * is a `u16` heap id -- it arrives at [sp+0x34] and is read with `ldrh`, and
 * it is forwarded widened to the allocator, which is the same
 * func_02030734(heap, size, 0, file, line) debug allocator every other site
 * in src/matched/ spells the same way (the pool word is this translation
 * unit's allocation-site string, 0x020A7EC4).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048A24.c \
 *       --func func_02048A24 --addr 0x02048A24 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

extern char  g_020A7EC4[];
extern void *func_02030734(int a, int b, int c, void *d, int e);

u32 *func_02048A24(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8,
                   Vec3 *a9, Vec3 *a10, Vec3 *a11, u16 heap)
{
    u32 *p = (u32 *)func_02030734(heap, 0x44, 0, g_020A7EC4, 0x38);

    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    p[3] = a4;
    p[4] = a5;
    p[5] = a6;
    p[6] = a7;
    p[7] = a8;
    *(Vec3 *)(p + 8) = *a9;
    *(Vec3 *)(p + 11) = *a10;
    *(Vec3 *)(p + 14) = *a11;
    return p;
}
