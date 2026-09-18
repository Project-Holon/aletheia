/*
 * function: func_02068A18
 * address:  0x02068A18
 * packet:   pkt_02068808
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 68 compiled against 80: mwccarm factors the two arms' shared `| (x << 8)` step into one unpredicated `orr lr` fed by an `orreq`-computed base, where the original keeps both arms predicated into the same register (`orreq r0,r0,r0,lsl #8` plus `orrne r0,r1,r1,lsl #8`).  Nested temporary, single-expression arms, else-first order and writing through the parameter all produce the factored form; source shape that prevents the merge not found
 *
 * symbols:
 *   func_02082AC0    0x02082AC0  arm
 *
 * Expands one pixel value to the surface's bit depth and fills the surface
 * through func_02082AC0: 8bpp replicates the byte, 4bpp first duplicates the
 * nibble then the byte.  The byte count is the surface's two dimensions times
 * the expanded bit depth over eight.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02068A18.c \
 *       --func func_02068A18 --addr 0x02068A18 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02082AC0(u32 px, void *dst, int n);

void func_02068A18(char *p, u32 arg)
{
    int bpp = *(u8 *)(p + 0xC);
    u32 px;
    int n;

    if (bpp == 4) {
        u32 t = arg | (arg << 4);
        px = t | (t << 8);
    } else {
        px = arg | (arg << 8);
    }
    px = px | (px << 16);
    n = (*(int *)(p + 4) * *(int *)(p + 8)) * ((bpp << 6) / 8);
    func_02082AC0(px, *(void **)p, n);
}
