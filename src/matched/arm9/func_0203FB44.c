/*
 * unit:     no
 * function: func_0203FB44
 * address:  0x0203FB44
 * packet:   pkt_0203FA08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   sub_020416B8   0x020416B8  arm
 *   AREAMAN_Free  0x0203422C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *
 * TU: bg_sys.c.
 *
 * Release half of the pair whose reserve half is sub_02042FF8: same arena
 * selection by layer index (0-3 at +0x168, 4-7 at +0x16c, anything else a
 * no-op) and the same round-up of a byte length to arena units, but the unit
 * here is the layer's own tile stride from sub_020416B8 rather than the
 * constant 32, so both the bias and the round-up are real divisions.
 *
 * Codegen note: the biased start index must be written back into the
 * `offset` parameter rather than into a fresh local.  A fresh local is
 * coalesced onto a different callee-saved register and shuffles the whole
 * r5/r6/r7 assignment (14 bytes wrong, same instructions); see
 * docs/idioms/reassigning-a-parameter-keeps-its-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203FB44.c \
 *       --func func_0203FB44 --addr 0x0203FB44 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BgSys {
    u8    pad_00[0x168];
    void *unk_168;
    void *unk_16c;
    u32   unk_170[8];
};

extern struct BgSys *g_02146A44;

typedef signed int     s32;
struct AreaMan;
extern u8 sub_020416B8(int channel);
extern void AREAMAN_Free(struct AreaMan *p, u32 start, s32 len);

void func_0203FB44(u32 layer, u32 offset, u32 size)
{
    u32           unit = sub_020416B8((u8)layer);
    struct BgSys *p    = g_02146A44;

    offset = (p->unk_170[layer] + offset * unit) / unit;

    switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
        AREAMAN_Free(p->unk_168, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        AREAMAN_Free(p->unk_16c, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    }
}
