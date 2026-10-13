/*
 * function: ICA_ANIME_LoadFrames
 * address:  0x0201183C
 * packet:   pkt_0201183C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fgr           0x0209BBB0  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02030734  0x02030734  arm
 *   _IcaAnimeFileName  0x020A7270  data
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *
 * Load one frame of an ICA animation: the frame index is (q >> 12) modulo
 * the frame count s->f0c; the file offset is 8 + 12 * index per enabled
 * channel and the read size 12 * s->f18 per enabled channel.  The floats are
 * read into a scratch buffer (ARC_TOOL_ReadHandleMemberRange, fifth argument = destination),
 * converted with the TwlSDK FX_F32_TO_FX32 macro into the three Vec3 tables
 * (f30 gates f24, f2c gates f20, f28 gates f1c), then freed; s->f14 = q >> 12.
 *
 * Levers (wave 10), each measured; together 631 bytes out -> EXACT:
 *  - 0x0209C95C is _fadd and 0x0209CB8C is _fsub (layout/runtime_arm9.txt
 *    had them swapped until 2026-09-28).  With them declared that way the
 *    plain SDK macro `x > 0 ? x*4096.0f + .5f : x*4096.0f - .5f` reproduces
 *    both arms, including the (0.5, prod) / (prod, 0.5) argument orders.
 *  - the conversion is a MACRO over `f[k + j]`, not an inline function, and
 *    the buffer is `volatile float *`: the element is then loaded for the
 *    compare and again in the taken arm, off a byte offset that gets its own
 *    stack slot per site (the image's nine slots sp+0x18..0x38).
 *  - ARC_TOOL_ReadHandleMemberRange takes five arguments; the fifth is the buffer ([sp]).
 *  - `q >> 12` is written twice (the modulo and the final store) and never
 *    named: its CSE temporary takes the lowest spill slot (sp+4).  A named
 *    `frame` local lands above the i*12 temporaries (14 bytes out).
 *  - `i = 0` sits between the alloc and the fill call (the image stores it
 *    there, sharing the alloc's zero), and the loop is `for (; i < ...)`.
 *  - declaration order i, k, f, size, ofs, n.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Vec3 { s32 x; s32 y; s32 z; };

struct IcaAnime {
    u16 f00;
    u16 f02;
    u32 f04;
    u32 f08;
    u32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    struct Vec3 *f1c;
    struct Vec3 *f20;
    struct Vec3 *f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u8    _IcaAnimeFileName;
struct ArcFile;
extern void  ARC_TOOL_ReadHandleMemberRange(struct ArcFile *a, u32 b, u32 ofs, u32 size, void *dst);

#define FX_F32_TO_FX32(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

void ICA_ANIME_LoadFrames(struct IcaAnime *s, s32 q)
{
    s32 i;
    s32 k;
    volatile float *f;
    u32 size;
    u32 ofs;
    u32 n;

    n = (q >> 12) % s->f0c;

    ofs = 8;
    size = 0;
    if (s->f30 != 0) ofs += n * 0xc;
    if (s->f2c != 0) ofs += n * 0xc;
    if (s->f28 != 0) ofs += n * 0xc;
    if (s->f30 != 0) size += s->f18 * 0xc;
    if (s->f2c != 0) size += s->f18 * 0xc;
    if (s->f28 != 0) size += s->f18 * 0xc;

    f = (volatile float *)func_02030734((u16)((s->f00 & 0x7fff) | 0x8000), size, 0, (const char *)&_IcaAnimeFileName, 0x2bd);
    i = 0;
    ARC_TOOL_ReadHandleMemberRange((struct ArcFile *)s->f04, s->f08, ofs, size, (void *)f);

    k = 0;
    for (; i < s->f18; i++) {
        if (s->f30 != 0) {
            s->f24[i].x = FX_F32_TO_FX32(f[k]);
            s->f24[i].y = FX_F32_TO_FX32(f[k + 1]);
            s->f24[i].z = FX_F32_TO_FX32(f[k + 2]);
            k += 3;
        }
        if (s->f2c != 0) {
            s->f20[i].x = FX_F32_TO_FX32(f[k]);
            s->f20[i].y = FX_F32_TO_FX32(f[k + 1]);
            s->f20[i].z = FX_F32_TO_FX32(f[k + 2]);
            k += 3;
        }
        if (s->f28 != 0) {
            s->f1c[i].x = FX_F32_TO_FX32(f[k]);
            s->f1c[i].y = FX_F32_TO_FX32(f[k + 1]);
            s->f1c[i].z = FX_F32_TO_FX32(f[k + 2]);
            k += 3;
        }
    }
    func_020307B0((void *)f);
    s->f14 = q >> 12;
}
