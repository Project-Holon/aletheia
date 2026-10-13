/*
 * file:     land_data_patch.c
 * unit:     yes
 * function: func_021C939C, func_021C93D0, func_021C93E4, func_021C9450, func_021C94AC, func_021C94B4
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
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021DE558  0x021DE558  data  ov021  a4
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0218BA04  0x0218BA04  thumb  ov021
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

/* Patch file from archive 0x9C: u16 offset of the attribute block, u16 offset of the build-model block, then the blocks. */
typedef struct LandDataPatch {
    u8 *data;      /* +0x00: archive file loaded by func_0204A1BC */
} LandDataPatch;

/* Attribute block of a patch, and the map attribute block it overwrites: u16 width, then 0x18-byte cells. */
typedef struct LandAttrBlock {
    u16 width;
} LandAttrBlock;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_0218BA04(u32 a, u32 b, u32 *c, u32 d);
u32 *func_021C939C(u32 patchId, u32 heapId);
void func_021C93D0(void **patch);
void func_021C93E4(u32 patch, u8 *mapAttr, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height);
u32 func_021C9450(u32 patch, u32 bmodelMan, u32 mapIndex, u32 firstIndex, int offsetX, int offsetZ);
int func_021C94AC(u32 patch);
int func_021C94B4(u32 patch);
extern char d_021DE558[];

/* Allocates a patch handle and loads patch file patchId. */
u32 *func_021C939C(u32 patchId, u32 heapId)
{
    u32 *patch = func_02030734(heapId, 4, 1, d_021DE558, 0x4f);
    patch[0] = func_0204A1BC(0x9c, patchId, 0, heapId);
    return patch;
}

void func_021C93D0(void **patch)
{
    func_020307B0(patch[0]);
    func_020307B0(patch);
}

/* Copies a height x width rectangle of attribute cells from the patch into the map attributes. */
void func_021C93E4(u32 patch, u8 *mapAttr, u32 srcX, u32 srcY, u32 dstX, u32 dstY, u32 width, u32 height)
{
    u8 *patchAttr = (u8 *)func_021C94AC(patch);
    u8 *dstCells = mapAttr + 4;
    u8 *srcCells = patchAttr + 4;
    u32 i;

    for (i = 0; i < height; i++) {
        func_02082D44(srcCells + (srcX + (srcY + i) * ((LandAttrBlock *)patchAttr)->width) * 0x18,
                      dstCells + (dstX + (dstY + i) * ((LandAttrBlock *)mapAttr)->width) * 0x18, width * 0x18);
    }
}

/* Adds the patch's build models (0x10-byte entries) moved by offsetX/offsetZ tiles; returns the next free index. */
u32 func_021C9450(u32 patch, u32 bmodelMan, u32 mapIndex, u32 firstIndex, int offsetX, int offsetZ)
{
    u32 *models = (u32 *)func_021C94B4(patch);
    u32 *entries = models + 1;
    u32 i;
    u32 entry[4];

    for (i = 0; i < models[0]; i++) {
        func_02082D44(entries + i * 4, entry, 0x10);
        entry[0] += offsetX << 16;
        entry[2] -= offsetZ << 16;
        func_0218BA04(bmodelMan, mapIndex, entry, firstIndex + i);
    }
    return firstIndex + models[0];
}

int func_021C94AC(u32 patch)
{
    return (int)(((LandDataPatch *)patch)->data + *(u16 *)(((LandDataPatch *)patch)->data));
}

int func_021C94B4(u32 patch)
{
    return (int)(((LandDataPatch *)patch)->data + *(u16 *)(((LandDataPatch *)patch)->data + 2));
}
