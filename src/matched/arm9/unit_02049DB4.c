/*
 * unit:     yes
 * function: ARC_UTIL_LoadBgCharDataFromArchive, ARC_UTIL_LoadBgCharDataFromHandle, ARC_UTIL_LoadScreenDataFromArchive, ARC_UTIL_LoadScreenDataFromHandle, ARC_UTIL_LoadPaletteDataFromArchive, ARC_UTIL_LoadPaletteDataFromHandle, ARC_UTIL_LoadPaletteBlockFromArchive, ARC_UTIL_LoadPaletteBlockFromHandle, ARC_UTIL_LoadCellBankFromArchive, ARC_UTIL_LoadCellBankFromHandle
 * address:  0x02049DB4
 * packet:   pkt_02049B90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cell-actor binding helpers.  Each binds an actor of a given kind through
 * ARC_UTIL_LoadMember (kind table 1, 5-argument form) or ARC_UTIL_LoadHandleMember (kind
 * table 2, wrapper over ARC_UTIL_LoadHandleMemberWithSize), runs the per-kind hook, and releases
 * the actor again when the hook fails.  ARC_UTIL_LoadPaletteBlockFromArchive / ARC_UTIL_LoadPaletteBlockFromHandle are
 * the 4-argument forms and pass 0 as the third argument.
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   NNS_G2dGetUnpackedCellBank  0x02062820  arm
 *   NNS_G2dGetUnpackedCharacterData  0x02062A00  arm
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct NitroFileHeader;
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern int NNS_G2dGetUnpackedCellBank(int a, int *out);
extern s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out);
extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
extern int   NNS_G2dGetUnpackedScreenData(void *ptr, void **out);
extern u32 func_020307B0(void *p);

void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterDataEx(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadBgCharDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterDataEx(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterData(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadScreenDataFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCharacterData(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedScreenData(res, (void **)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteDataFromHandle(void *a0, u32 a1, u32 a2, void **out, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedScreenData(res, out)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, 0, a3);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedPaletteData(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, 0, a3);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedPaletteData(res, (void **)a2)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = (void *)ARC_UTIL_LoadMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCellBank((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}

void *ARC_UTIL_LoadCellBankFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    void *res = ARC_UTIL_LoadHandleMember(a0, a1, a2, a4);
    if (res != 0) {
        if (!NNS_G2dGetUnpackedCellBank((int)res, (int *)a3)) {
            func_020307B0(res);
            return 0;
        }
    }
    return res;
}
