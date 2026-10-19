/*
 * file:     land_data_patch.c
 * unit:     yes
 * function: LAND_DATA_PATCH_Create, LAND_DATA_PATCH_Delete, LAND_DATA_PATCH_OverwriteAttr, LAND_DATA_PATCH_AddBuildModels, LAND_DATA_PATCH_GetAttrBlock, LAND_DATA_PATCH_GetBuildModelBlock
 * address:  0x021C939C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C939C: land_data_patch.c __FILE__ anchor at 0x021C939C.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   d_021DE558  0x021DE558  data  ov021  a4
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   FIELD_BUILDMODEL_RegisterObject  0x0218BA04  thumb  ov021
 */
#include "../types.h"

/* Patch file from archive 0x9C: u16 offset of the attribute block, u16 offset of the build-model block, then the blocks. */
typedef struct LandDataPatch {
    u8 *data;      /* +0x00: archive file loaded by ARC_UTIL_LoadMember */
} LandDataPatch;

/* Attribute block of a patch, and the map attribute block it overwrites: u16 width, then 0x18-byte cells. */
typedef struct LandAttrBlock {
    u16 width;
} LandAttrBlock;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern int ARC_UTIL_LoadMember(int archiveID, int memberIdx, int decompress, int heapID);
extern void MI_CpuCopy8(void *src, void *dst, int n);
struct BuildModelObjectDesc;
struct BuildModelMan;
extern void FIELD_BUILDMODEL_RegisterObject(struct BuildModelMan *man, int mapObject, struct BuildModelObjectDesc *desc, int index);
u32 *LAND_DATA_PATCH_Create(u32 patchId, u32 heapId);
void LAND_DATA_PATCH_Delete(void **patch);
void LAND_DATA_PATCH_OverwriteAttr(u32 patch, u8 *mapAttr, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height);
u32 LAND_DATA_PATCH_AddBuildModels(u32 patch, u32 bmodelMan, u32 mapIndex, u32 firstIndex, int offsetX, int offsetZ);
int LAND_DATA_PATCH_GetAttrBlock(u32 patch);
int LAND_DATA_PATCH_GetBuildModelBlock(u32 patch);
extern char d_021DE558[];

/* Allocates a patch handle and loads patch file patchId. */
u32 *LAND_DATA_PATCH_Create(u32 patchId, u32 heapId)
{
    u32 *patch = GFL_HEAP_Alloc(heapId, 4, 1, d_021DE558, 0x4f);
    patch[0] = ARC_UTIL_LoadMember(0x9c, patchId, 0, heapId);
    return patch;
}

void LAND_DATA_PATCH_Delete(void **patch)
{
    GFL_HEAP_Free(patch[0]);
    GFL_HEAP_Free(patch);
}

/* Copies a height x width rectangle of attribute cells from the patch into the map attributes. */
void LAND_DATA_PATCH_OverwriteAttr(u32 patch, u8 *mapAttr, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height)
{
    u8 *patchAttr = (u8 *)LAND_DATA_PATCH_GetAttrBlock(patch);
    u8 *dstCells = mapAttr + 4;
    u8 *srcCells = patchAttr + 4;
    u32 i;

    for (i = 0; i < height; i++) {
        MI_CpuCopy8(srcCells + (srcX + (srcY + i) * ((LandAttrBlock *)patchAttr)->width) * 0x18,
                      dstCells + (dstX + (dstY + i) * ((LandAttrBlock *)mapAttr)->width) * 0x18, width * 0x18);
    }
}

/* Adds the patch's build models (0x10-byte entries) moved by offsetX/offsetZ tiles; returns the next free index. */
u32 LAND_DATA_PATCH_AddBuildModels(u32 patch, u32 bmodelMan, u32 mapIndex, u32 firstIndex, int offsetX, int offsetZ)
{
    u32 *models = (u32 *)LAND_DATA_PATCH_GetBuildModelBlock(patch);
    u32 *entries = models + 1;
    u32 i;
    u32 entry[4];

    for (i = 0; i < models[0]; i++) {
        MI_CpuCopy8(entries + i * 4, entry, 0x10);
        entry[0] += offsetX << 16;
        entry[2] -= offsetZ << 16;
        FIELD_BUILDMODEL_RegisterObject((struct BuildModelMan *)bmodelMan, mapIndex, (struct BuildModelObjectDesc *)entry, firstIndex + i);
    }
    return firstIndex + models[0];
}

int LAND_DATA_PATCH_GetAttrBlock(u32 patch)
{
    return (int)(((LandDataPatch *)patch)->data + *(u16 *)(((LandDataPatch *)patch)->data));
}

int LAND_DATA_PATCH_GetBuildModelBlock(u32 patch)
{
    return (int)(((LandDataPatch *)patch)->data + *(u16 *)(((LandDataPatch *)patch)->data + 2));
}
