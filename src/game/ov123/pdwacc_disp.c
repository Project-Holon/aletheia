/*
 * file:     pdwacc_disp.c
 * unit:     yes
 * function: PDWACC_DISP_Init, PDWACC_DISP_Draw, PDWACC_DISP_Exit, PDWACC_DISP_InitBgLayers, PDWACC_DISP_VBlankTask, PDWACC_DISP_LoadResources, PDWACC_DISP_PaletteTask, PDWACC_DISP_DeleteActors
 * address:  0x021D9958
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pdwacc_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   DC_FlushRange 0x020862F0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ov067_id 0x00000043 data
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   gGsyncClactConfig 0x020A1464 data a4
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   d_021DABFC 0x021DABFC data a1
 *   d_021DABCC 0x021DABCC data a4
 *   d_021DABBC 0x021DABBC data a4
 *   d_021DA8A8      0x021DA8A8  data
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   PALANM_BlendColors 0x02021F64 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 */
#include "pdwacc_disp_types.h"
#include "../sdk_ioreg.h"

#include "../arm9/bg_sys.h"





#include "../arm9/arc_tool.h"

#include "../arm9/arc_util.h"


#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"




#include "../arm9/os_cache.h"

#include "../arm9/gx_load2d.h"

#include "../arm9/clact.h"



#include "../arm9/gx.h"

struct DispVram;




struct DispVramCfg;
struct SysInit;



#include "../arm9/gfl_use.h"


#include "../arm9/g2.h"


struct ClactActor;




struct TcbTask;

#include "../arm9/tcb_list.h"




#include "../arm9/gf_overlay.h"





#ifdef __MWERKS__
#define PALANM_BlendColors PALANM_BlendColors_hdr
#endif
#include "../arm9/palanm.h"
#ifdef __MWERKS__
#undef PALANM_BlendColors
void PALANM_BlendColors(u16 *, u16 *, int, u8, u16);
#endif

PdwaccDispWork *PDWACC_DISP_Init(int heap);

void PDWACC_DISP_Draw(PdwaccDispWork *disp);

void PDWACC_DISP_Exit(PdwaccDispWork *disp);

void PDWACC_DISP_InitBgLayers(PdwaccDispWork *disp);

void PDWACC_DISP_VBlankTask(struct TcbTask * unused0, void * unused1);

void PDWACC_DISP_LoadResources(PdwaccDispWork *disp);

void PDWACC_DISP_PaletteTask(void *unused, PdwaccPaletteAnim *palette);

void PDWACC_DISP_DeleteActors(PdwaccDispWork *disp);

extern char ov067_id[];

extern const u32 gGsyncClactConfig[];

extern unsigned char ov_id[];

extern const char d_021DABFC[];

extern const u32 d_021DABCC[];

extern const u32 d_021DABBC[];

extern const struct BgTemplate d_021DA8A8[8];

/*
 * evidence: ov123 021D9D34 callback stub filed and verified before caller rerun.
 * volatile: hardware register 04001000 is read then written at 021D9990/021D9994.
 */
PdwaccDispWork *PDWACC_DISP_Init(int heap)
{
    PdwaccDispWork *disp;
    disp=(PdwaccDispWork *) GFL_HEAP_Alloc(heap,sizeof(PdwaccDispWork),1,d_021DABFC,201);
    disp->heap=heap;
    GF_OVERLAY_Load((sptr)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)REG_DB_DISPCNT_ADDR|=0x10000;
    GX_DispOn();
    BG_SYS_Create(disp->heap);
    CLACT_InitSystem((const struct ClactSysInit *)gGsyncClactConfig,(const struct DispVramCfg *)d_021DABCC,disp->heap);
    disp->clactUnit=CLACT_CreateUnit(40,0,disp->heap);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DABCC);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021DABBC);
    PDWACC_DISP_InitBgLayers(disp);
    PDWACC_DISP_LoadResources(disp);
    disp->vblankTask=GFL_USE_AddMainTask(PDWACC_DISP_VBlankTask,(void *)disp,0);
    BG_SYS_SetSubVisiblePlanes(31);
    BG_SYS_SetMainVisiblePlanes(27);
    return disp;
}

void PDWACC_DISP_Draw(PdwaccDispWork *disp) { CLACT_DrawSystem(); }

void PDWACC_DISP_Exit(PdwaccDispWork *disp)
{
    int resourceIndex;
    PDWACC_DISP_DeleteActors(disp);
    if (disp->palette.task) {
        TCB_DeleteTask(disp->palette.task);
        disp->palette.task=0;
        disp->palette.enabled=0;
    }
    resourceIndex=0;
    do { if (disp->clactResources[resourceIndex]) CLACT_ReleasePalette(disp->clactResources[resourceIndex]); resourceIndex++; } while(resourceIndex<3);
    for(;resourceIndex<6;resourceIndex++) if (disp->clactResources[resourceIndex]) CLACT_ReleaseCharacter(disp->clactResources[resourceIndex]);
    for(;resourceIndex<9;resourceIndex++) if (disp->clactResources[resourceIndex]) CLACT_ReleaseCellAnim(disp->clactResources[resourceIndex]);
    if (disp->unusedTask) TCB_DeleteTask(disp->unusedTask);
    TCB_DeleteTask(disp->vblankTask);
    CLACT_DeleteUnit(disp->clactUnit);
    CLACT_ExitSystem();
    BG_SYS_FreeTiles(1,1,0);
    BG_SYS_FreeTiles(6,1,0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_SetPlaneVisible(5,0);
    BG_SYS_Delete();
    GFL_HEAP_Free(disp);
    GF_OVERLAY_Unload((sptr)ov_id);
}

/*
 * BG-layer init, same shape as GTSNEGO_DISP_InitBgLayers (ov120) with its own template
 * table at 0x021DA8A8 (index order 1,4,3,7,5,0,6,2) and slight per-layer
 * differences in the enable/fill sequence.
 */
void PDWACC_DISP_InitBgLayers(PdwaccDispWork *disp)
{
    struct BgTemplate bgTemplates[8];

    bgTemplates[7] = d_021DA8A8[1];
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&bgTemplates[7]), 0);
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_PushTile(0);

    bgTemplates[6] = d_021DA8A8[4];
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&bgTemplates[6]), 0);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_SetTileEntry(1, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(1);

    bgTemplates[5] = d_021DA8A8[3];
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&bgTemplates[5]), 0);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(2);

    bgTemplates[4] = d_021DA8A8[7];
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&bgTemplates[4]), 0);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_Init(3, 0, 1, 0);
    BG_SYS_SetTileEntry(3, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(3);

    bgTemplates[3] = d_021DA8A8[5];
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&bgTemplates[3]), 0);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_PushTile(4);

    bgTemplates[2] = d_021DA8A8[0];
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&bgTemplates[2]), 0);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(5);

    bgTemplates[1] = d_021DA8A8[6];
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&bgTemplates[1]), 0);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_Init(6, 0, 1, 0);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(6);

    bgTemplates[0] = d_021DA8A8[2];
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&bgTemplates[0]), 0);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_Init(7, 0, 1, 0);
    BG_SYS_SetTileEntry(7, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_PushTile(7);
}

/*
 * leaf: sole blocker of owned ov123 021D9958; parent ownership audit passed.
 * extent: 8-byte tailcall stub; next labelled function 021D9D3C follows.
 */
void PDWACC_DISP_VBlankTask(struct TcbTask * unused0, void * unused1)
{
    CLACT_VBlankSystem();
}

/*
 * note 2026-10-05 (wD9r lane50): closed. ARC_UTIL_UploadBgCharFromHandle returns a value (it ends in a call whose r0 it
 *   keeps; ov110 PMSIV_CATEGORY_Setup declares it u32); declared void, it moved the constant 3 into r5 and
 *   tied the late zero arguments to j. The two palette bases are assigned inside the outer loop (mwcc
 *   hoists them after i = 0), and the source row is written inline in the 02021F64 call.
 */
void PDWACC_DISP_LoadResources(PdwaccDispWork *disp)
{
    struct { u8 pad[0xc]; void *data; } *record;
    u16 *base0;
    u16 *base1;
    void *archiveHandle;
    int finished;
    int blendStep;
    int blendRow;
    int rowIndex;
    u16 *srcRow;
    void *allocated;
    int colorIndex;
    int nextRow;
    u16 *dstRow;
    u16 heap;
    archiveHandle = ARC_TOOL_CreateHandle(0x91, disp->heap);
    blendRow = 0;
    ARC_UTIL_UploadPaletteFromHandleWhole(archiveHandle, 3, 4, 0, blendRow, disp->heap);
    ARC_UTIL_UploadBgCharFromHandle(archiveHandle, 4, 4, 0, blendRow, blendRow, disp->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(archiveHandle, 6, 4, 0, blendRow, blendRow, disp->heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(archiveHandle, 3, 0, 0, blendRow, disp->heap);
    ARC_UTIL_UploadBgCharFromHandle(archiveHandle, 4, 0, 0, blendRow, blendRow, disp->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(archiveHandle, 5, 0, 0, blendRow, blendRow, disp->heap);
    ARC_UTIL_UploadBgCharFromHandle(archiveHandle, 4, 3, 0, blendRow, blendRow, disp->heap);
    ARC_UTIL_UploadBgPaletteFromHandle(archiveHandle, 7, 3, 0, blendRow, blendRow, disp->heap);
    heap = disp->heap;
    MI_CpuFill8(&disp->palette, 0, sizeof(disp->palette));
    allocated = ARC_UTIL_LoadPaletteBlockFromHandle((void *)archiveHandle, 2, &record, heap);
    MI_CpuCopy8(record->data, disp->palette.basePalettes, 0x1e0);
    MI_CpuCopy8(record->data, disp->palette.blendedPalettes, 0x1e0);
    GFL_HEAP_Free(allocated);
    for (rowIndex = 0; rowIndex < 15; rowIndex++) {
        base1 = (u16 *)disp->palette.blendedPalettes;
        base0 = (u16 *)disp->palette.basePalettes;
        nextRow = rowIndex + 1;
        if (nextRow >= 15) nextRow -= 15;
        blendStep = 0;
        finished = 0;
        srcRow = disp->palette.basePalettes[nextRow] - 8;
        while (1) {
            dstRow = base0 + rowIndex * 16;
            for (colorIndex = 4; colorIndex < 11; colorIndex++) {
                PALANM_BlendColors(dstRow + colorIndex, base1 + blendRow * 16 + colorIndex, 1, (u8)(blendStep >> 8), srcRow[colorIndex + 8]);
            }
            blendRow++;
            if (finished == 1) break;
            blendStep += 0x600;
            if (blendStep >= 0x1000) {
                blendStep = 0x1000;
                finished = 1;
            }
        }
    }
    DC_FlushRange(disp->palette.blendedPalettes, sizeof(disp->palette.blendedPalettes));
    disp->palette.enabled = 1;
    disp->palette.task = GFL_USE_AddMainTask((void *)PDWACC_DISP_PaletteTask, &disp->palette, 0x14);
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 1, 8, 8, 0x10);
    disp->palette.bgLayer = 0;
    ARC_TOOL_DeleteHandle(archiveHandle);
}

void PDWACC_DISP_PaletteTask(void *unused, PdwaccPaletteAnim *palette)
{
    if (palette->enabled) {
        palette->halfStep^=1;
        if (!(*(volatile u8 *)&palette->halfStep&1)) {
            GX_LoadBGPltt(&palette->blendedPalettes[palette->frame][4],40,14);
            GXS_LoadBGPltt(&palette->blendedPalettes[palette->frame][4],40,14);
            ++palette->frame;
            if (palette->frame>=60) palette->frame=0;
            BG_SYS_ChangeScrollImmediate(palette->bgLayer,2,7);
        }
    }
}

void PDWACC_DISP_DeleteActors(PdwaccDispWork *disp) { int slotIndex; for(slotIndex=0;slotIndex<PDWACC_ACTOR_COUNT;slotIndex++) { if(disp->actors[slotIndex]) { CLACT_DeleteActor(disp->actors[slotIndex]); disp->actors[slotIndex]=0; } } }
