/*
 * function: func_02062B30
 * address:  0x02062B30
 * packet:   pkt_02062688
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * The 'NRCS' (NSCR screen data) accessor of docs/families/cluster_02062688.h,
 * NitroSystem NNS_G2dGetUnpackedScreenData shape: find the block, hand back
 * its body (block + 8) through *out and return 1, else *out = 0 and 0.
 *
 * Closed wave 12 (was src/pending/func_02062B30.c, DIFF 48/52 under every
 * front end on the NEGATIVE spelling).  The fix is the POSITIVE spelling
 * `if (b) { ...; return 1; } else { ...; return 0; }` under ../2.0/sp2 (also
 * ../2.0/base and sp1): 2.0 predicates only the zero arm (`popeq`) and keeps
 * the fall-through, exactly the image.  dsi/1.1p1 predicates both arms under
 * every spelling measured.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02062B30.c \
 *       --func func_02062B30 --addr 0x02062B30 --arm --cc ../2.0/sp2
 *   EXACT, 52 bytes, 1 of 1 relocation site resolved.
 *
 * symbols:
 *   func_02062B64  0x02062B64  arm
 */
typedef unsigned int u32;
typedef int BOOL;

typedef struct {
    u32 sig;
    u32 size;
} Blk;

struct NitroFileHeader;
extern void *func_02062B64(struct NitroFileHeader *file, u32 signature);

BOOL func_02062B30(void *file, void **out)
{
    Blk *b = 0;

    b = func_02062B64(file, 0x5343524E);
    if (b) {
        *out = (void *)(b + 1);
        return 1;
    } else {
        *out = 0;
        return 0;
    }
}
