/*
 * function: sub_02042FF8
 * address:  0x02042FF8
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_020341F0  0x020341F0  arm
 *
 * The reserve half of the pair whose release half is sub_02043094: same
 * arena selection by slot index (0..3 at +0x168, 4..7 at +0x16c, anything
 * else a no-op), same bias by the per-slot base at +0x190 and the same
 * round-up of the byte length to 32-byte units, but handed to
 * func_020341F0 instead of AREAMAN_Free.
 *
 * Codegen note: the round-up flag must be spelled as the ternary
 * `(size & 0x1f) ? 1 : 0`; see sub_02043094.c for why the relational form
 * reschedules.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx {
    u8  pad_00[0x168];
    void *unk_168;
    void *unk_16c;
    u8  pad_170[0x20];
    u32 unk_190[8];
};

extern struct Ctx *g_02146A44;

typedef signed int     s32;
struct AreaMan;
extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);

void sub_02042FF8(u32 idx, u32 offset, u32 size)
{
    switch (idx) {
    case 0:
    case 1:
    case 2:
    case 3:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->unk_168,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        {
            u32 count = ((size & 0x1f) ? 1 : 0) + (size >> 5);
            func_020341F0(g_02146A44->unk_16c,
                          (offset + g_02146A44->unk_190[idx]) >> 5, count);
        }
        break;
    }
}
