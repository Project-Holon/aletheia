/*
 * function: POKEGRA_LoadTrainerGraphics
 * address:  0x0202DAA4
 * packet:   pkt_0202DAA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads two archived resources into a pair of consumers.  Each half
 * turns the caller's id into an archive entry index (POKEGRA_GetTrainerPalArcIndex for
 * the first, POKEGRA_GetTrainerCgrArcIndex for the second), pulls the entry out of the
 * archive set named by the fifth, stack-passed u16 argument, hands the
 * unpacked payload to its consumer and then frees the container with
 * the common finalizer func_020307B0.
 *
 * The u16 fifth argument is re-read from the incoming argument area for
 * the second call rather than cached, so it is spelled as a `volatile
 * u16' stack parameter.
 *
 * symbols:
 *   POKEGRA_GetTrainerCgrArcIndex  0x0202D5D8  thumb
 *   POKEGRA_GetTrainerPalArcIndex  0x0202D61C  thumb
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   ARC_UTIL_LoadScreenDataFromHandle  0x02049E74  arm
 *   CLACT_TransferCharacter  0x0204A9D0  arm
 *   CLACT_TransferPalette  0x0204ADEC  arm
 *   func_02062A98  0x02062A98  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   POKEGRA_GetTrainerCgrArcIndex(u32 id, u32 sel);
extern u32   POKEGRA_GetTrainerPalArcIndex(u32 id, u32 sel);
extern u32 func_020307B0(void *p);
typedef signed int     s32;
struct ArcFile;
struct NitroFileHeader;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
struct Sub0204A9D0;
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void  CLACT_TransferPalette(void *dst, void *src, u32 flag);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);

void POKEGRA_LoadTrainerGraphics(void *set, u32 id, void *dstA, void *dstB, volatile u16 which)
{
    void *res;
    void *b;
    void *a;

    res = ARC_TOOL_LoadHandleMember(set, POKEGRA_GetTrainerPalArcIndex(id, 0), which);
    func_02062A98(res, &b);
    CLACT_TransferPalette(dstB, b, 1);
    func_020307B0(res);

    res = ARC_UTIL_LoadScreenDataFromHandle(set, POKEGRA_GetTrainerCgrArcIndex(id, 0), 1, (u32)(&a), which);
    CLACT_TransferCharacter((int)dstA, a);
    func_020307B0(res);
}
