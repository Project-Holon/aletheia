/*
 * function: BTLV_INPUT_LoadCommonGraphics
 * address: 0x022033F4
 * packet: pkt_ov094_022033F4
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker (cleared 2026-10-01, arm9 leaf filed): ARM9 0x02021728 at +0072 has no admissible outside witness.
 * Verified C copied from ov029_func_021F0DB4.c's EXACT 8-byte scratch proof:
 * int PALANM_GetDefaultWork(char *p, int i) { return *(int *)(p + i * 0x14); }
 * ARM9 belongs to the integrator. Caller sets r0 to the palette object, r1 to 1.
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   PALANM_GetDefaultWork 0x02021728 thumb
 *   MIi_CpuCopy16 0x02082A60 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Main {
    unsigned char pad00[0x48];
    void *f48;
    unsigned char pad4c[0x64 - 0x4c];
    void *pal;
    unsigned char pad68[0x104 - 0x68];
    int h104;
    int h108;
    int h10c;
    int h110;
    int h114;
    int h118;
    unsigned char pad11c[0x1e0 - 0x11c];
    int h1e0[4];
    int h1f0;
    int h1f4;
    unsigned char pad1f8[0x23c - 0x1f8];
    int f23c;
    u16 heap;
    unsigned char pad242[0x284 - 0x242];
    unsigned char buf284[0x20];
} Main;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
struct PalAnmSlot;
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern int BTLV_EFFECT_GetPalanm(void);
extern int PALANM_GetDefaultWork(char *p, int i);
extern void MIi_CpuCopy16(const void *, void *, u32);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern u32 APP_ICON_GetArchiveId(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 APP_ICON_GetTypePaletteFileId(u32);
extern u32 APP_ICON_GetTypeAnimFileId(u32);
extern u32 APP_ICON_GetTouchBarFileId(void);
extern u32 APP_ICON_GetTypeCellFileId(u32);
extern void ARC_TOOL_DeleteHandle(void *);
void BTLV_INPUT_LoadCommonGraphics(Main *m)
{
    void *arc;
    u32 file;
    int i;

    func_02049658(m->f48, 0x5b, 4, 0, 0, 0, m->heap);
    func_02049658(m->f48, 0x71, 7, 0, 0x8000, 0, m->heap);
    func_020498F4(m->f48, 0x72, 7, 0, 0, 0, m->heap);
    PALANM_LoadHandlePaletteToSlot(m->pal, m->f48, 0x5c, m->heap, 1, 0x1e0, 0);
    if (m->f23c == 1)
        MIi_CpuCopy16((const void *)(PALANM_GetDefaultWork((char *)BTLV_EFFECT_GetPalanm(), 1) + 0x40), m->buf284, 0x20);
    m->h104 = CLACT_RegisterCharacter(m->f48, 0x73, 0, 1, m->heap);
    m->h10c = CLACT_RegisterCellAnim(m->f48, 0x75, 0x76, m->heap);
    m->h108 = CLACT_RegisterPalette(m->f48, 0x74, 1, 0, m->heap);
    PALANM_CopyHwPaletteToSlot(m->pal, 3, (u16)(CLACT_GetPaletteVramAddress(m->h108, 1) >> 1), 0x100);
    m->h110 = CLACT_RegisterCharacter(m->f48, 0x77, 0, 1, m->heap);
    m->h114 = CLACT_RegisterCellAnim(m->f48, 0x78, 0x79, m->heap);
    arc = func_020490F4(APP_ICON_GetArchiveId(), (u16)((m->heap & 0x7fff) | 0x8000));
    file = APP_ICON_GetTypePaletteFileId(0);
    m->h1f4 = CLACT_RegisterCellAnim(arc, file, APP_ICON_GetTypeAnimFileId(0), m->heap);
    m->h1f0 = CLACT_RegisterPalette(arc, APP_ICON_GetTouchBarFileId(), 1, 0x100, m->heap);
    PALANM_CopyHwPaletteToSlot(m->pal, 3, (u16)(CLACT_GetPaletteVramAddress(m->h1f0, 1) >> 1), 0x60);
    for (i = 0; i < 4; i++)
        m->h1e0[i] = CLACT_RegisterCharacter(arc, APP_ICON_GetTypeCellFileId(0), 0, 1, m->heap);
    ARC_TOOL_DeleteHandle(arc);
}
