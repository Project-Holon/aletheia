/*
 * function: CLACT_TransferPaletteDataEx
 * address:  0x0204DEE8
 * packet:   pkt_0204DD08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNS_G2dGetUnpackedPaletteCompressInfo  0x02062AD4  arm
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   NNSi_G2dInitVramHandleEx  0x020637D4  arm
 *   CLACT_IsVramTypeCompatible  0x0204D9B4  arm
 *   NNSi_G2dLoadVramResourceList  0x02063F4C  arm
 *   GX_GetBankForOBJExtPltt  0x02080C34  arm
 *   GX_GetBankForSubOBJExtPltt  0x02080C74  arm
 *   func_0208068C  0x0208068C  arm
 *   GX_SetBankForOBJExtPltt  0x020801F8  arm
 *   GX_SetBankForSubOBJExtPltt  0x0208083C  arm
 *
 * The one-surface sibling of CLACT_TransferPaletteData (same entry table, same 0x200
 * large-layer split, same bracketed double upload through CLACT_IsVramTypeCompatible's
 * engine select), uploading through NNSi_G2dLoadVramResourceList instead of NNSi_G2dLoadVramResourceBySel.
 * Returns nothing: the trailing read-modify-write leaves r0 as garbage.
 *
 * Levers, all measured (wave 10): the two out-locals are declared `b` then
 * `a` (NNS_G2dGetUnpackedPaletteData's out first), which puts `a` at sp+4 as the image has
 * it; and the 0x200 test is written small-arm-first
 * (`if (size < 0x200) flag = 0; else {...}`), which is what orders the
 * predicated `movlo sl,#0` before `movhs sl,#1`.  Either alone leaves 4-6
 * bytes out.  `off = idx * sizeof(struct Ent)` as a byte-offset local and
 * the entry re-derived from h->ents at the end are CLACT_TransferPaletteData's pins.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent    { u8 pad_00[0x14]; u32 unk_14; };
struct Holder { u8 pad_00[0xc]; struct Ent *ents; };

typedef signed int     s32;
struct NitroFileHeader;
extern s32 NNS_G2dGetUnpackedPaletteCompressInfo(struct NitroFileHeader *file, void **out);
extern s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
struct List02063F4C;
struct Out02063F4C;
struct Self02063F4C;
extern void NNSi_G2dInitVramHandleEx(u32 *p);
extern u32 CLACT_IsVramTypeCompatible(u32 a, u32 b);
extern void NNSi_G2dLoadVramResourceList(struct Self02063F4C *self, struct List02063F4C *list, u32 base, int sel, struct Out02063F4C *out);
extern u16 GX_GetBankForOBJExtPltt(void);
extern u16 GX_GetBankForSubOBJExtPltt(void);
extern void func_0208068C(void);
extern void GX_SetBankForOBJExtPltt(int objExtPltt);
extern void GX_SetBankForSubOBJExtPltt(int sub_objExtPltt);

void CLACT_TransferPaletteDataEx(struct Holder *h, int idx, void *src, void *sel, u32 size)
{
    void *b;
    void *a;
    u32 off;
    struct Ent *ent;
    int flag;
    u32 saved;

    off = idx * sizeof(struct Ent);
    ent = (struct Ent *)((u8 *)h->ents + off);
    if (size < 0x200) {
        flag = 0;
    } else {
        size = (u16)(size - 0x200);
        flag = 1;
    }

    NNS_G2dGetUnpackedPaletteCompressInfo(src, &a);
    if (!NNS_G2dGetUnpackedPaletteData(src, &b)) {
        return;
    }
    NNSi_G2dInitVramHandleEx((u32 *)ent);

    if (CLACT_IsVramTypeCompatible((u32)sel, 0)) {
        saved = GX_GetBankForOBJExtPltt();
        if (flag) func_0208068C();
        NNSi_G2dLoadVramResourceList(b, a, size, 1, (struct Out02063F4C *)ent);
        if (flag) GX_SetBankForOBJExtPltt(saved);
    }
    if (CLACT_IsVramTypeCompatible((u32)sel, 1)) {
        saved = GX_GetBankForSubOBJExtPltt();
        if (flag) func_0208068C();
        NNSi_G2dLoadVramResourceList(b, a, size, 2, (struct Out02063F4C *)ent);
        if (flag) GX_SetBankForSubOBJExtPltt(saved);
    }

    ((struct Ent *)((u8 *)h->ents + off))->unk_14 &= ~0x80000000;
}
