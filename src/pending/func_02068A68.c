/*
 * function: func_02068A68
 * address:  0x02068A68
 * packet:   pkt_02068808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 116 compiled against 128: the rotated row loop, the
 *           per-row fill and the stride advance are recognisable, but the shared
 *           `| (x << 8)` step is factored out of the two bit-depth arms exactly as in
 *           func_02068A18 (see
 *           docs/idioms/both-arms-of-an-if-else-sharing-a-step-are-factored-into-one-unpredicated-instruction.md),
 *           and the cursor, both byte counts and the destination advance come out in
 *           different registers on top of that.  All relocations resolve; the residue
 *           is codegen only.
 *
 * symbols:
 *   func_02082AC0    0x02082AC0  arm
 *
 * Row loop around func_02068A18's fill: same pixel expansion (4bpp doubles
 * twice, 8bpp once, then once more for the word), then one fill call per row
 * over the row's byte count, advancing the destination by the row stride.
 * The row count is re-read from the surface word at +8 on every iteration,
 * and the loop is the rotated `while` (guard before, test at the bottom).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02068A68.c \
 *       --func func_02068A68 --addr 0x02068A68 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02082AC0(u32 px, void *dst, int n);

void func_02068A68(char *p, u32 arg)
{
    int bpp = *(u8 *)(p + 0xC);
    u32 px;
    int n;
    char *dst = *(char **)p;
    u32 i = 0;

    if (bpp == 4) {
        px = arg | (arg << 4);
        px = px | (px << 8);
    } else {
        px = arg | (arg << 8);
    }
    px = px | (px << 16);
    n = (bpp << 6) / 8;
    if (*(u32 *)(p + 8) == 0)
        return;
    do {
        func_02082AC0(px, dst, *(int *)(p + 4) * n);
        dst += *(int *)(p + 0x10) * n;
        i++;
    } while (i < *(u32 *)(p + 8));
}
