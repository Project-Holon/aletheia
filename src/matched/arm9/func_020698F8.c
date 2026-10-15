/*
 * function: NNS_G2dFontLoad
 * address:  0x020698F8
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * NFTR font-resource open (docs/families/cluster_020694D8.h): validate the
 * resource against version 0x0102, then 0x0101, else assert 0x0100 and mark
 * it legacy; relocate the section table, find 'FINF', hand back payload + 8,
 * and for a legacy resource clear byte 7 of the FINF's +8 pointee.
 *
 * Closed wave 12.  The six doubly-normalised guards are three INLINE helper
 * levels, and the leaf helpers are written as `if (cond) return 1; return 0;`
 * -- the only spelling that materialises the `&&` value (moveq #1 / beq /
 * mov #0) instead of merging it into the caller's branch.  The caller's `&&`
 * then normalises it (movne #1 / moveq #0) and tests it; the outer
 * `r != 0 ? ... : 0` is the leading null test whose false value is the r4
 * zero.  `return r && cond;` in the leaves merges into control flow (256
 * bytes); `if (r == 0) return 0; return cond;` gives movhs/movlo (122 out).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNS_G2dFontLoad.c \
 *       --func NNS_G2dFontLoad --addr 0x020698F8 --arm --cc ../2.0/sp2
 *   EXACT, 460 bytes, 3 of 3 relocation sites resolved.
 *   ../2.0/sp2p2: EXACT as well; dsi/1.1p1: 452 bytes, DIFF.
 *
 * symbols:
 *   NNSi_G2dFontFixupSections  0x02069AC4  arm
 *   NNS_G2dFindBinaryBlock  0x02062B64  arm
 *   OS_Terminate  0x02088234  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef struct {
    u32 sig;
    u16 unk04;
    u16 ver;
} Res;

extern void NNSi_G2dFontFixupSections(Res *base);
struct NitroFileHeader;
extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void OS_Terminate(void);

static inline BOOL IsNftr(const Res *r)
{
    if (r != 0 && r->sig == 0x4e465452u)
        return 1;
    return 0;
}

static inline BOOL VerAtLeast(const Res *r, u16 v)
{
    if (r != 0 && r->ver >= v)
        return 1;
    return 0;
}

static inline BOOL IsValid(const Res *r, u16 v)
{
    return r != 0 ? (IsNftr(r) && VerAtLeast(r, v)) : 0;
}

u32 NNS_G2dFontLoad(Res *res, void **out)
{
    BOOL legacy = 0;
    u8 *finf;

    if (!IsValid(res, 0x102) && !IsValid(res, 0x101)) {
        if (!IsValid(res, 0x100))
            OS_Terminate();
        legacy = 1;
    }
    NNSi_G2dFontFixupSections(res);
    finf = NNS_G2dFindBinaryBlock((struct NitroFileHeader *)res, 0x46494e46u);
    if (finf == 0) {
        *out = 0;
        return 0;
    }
    *out = finf + 8;
    if (legacy)
        (*(u8 **)((u8 *)*out + 8))[7] = 0;
    return 1;
}
