/*
 * function: FLD_WIPE_3DOBJ_Create
 * address:  0x021C8018
 * packet:   pkt_ov021_021C8018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFldWipe3dObjFileName  0x021DE520  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   G3D_SYSTEM_CreateResourceArc  0x02046DB8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char gFldWipe3dObjFileName[];
extern void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
typedef struct { u32 f0; u32 f4; } N;
N *FLD_WIPE_3DOBJ_Create(u32 heap)
{
    N *n = func_02030734(heap, 8, 1, gFldWipe3dObjFileName, 0x24);
    n->f0 = (u32)G3D_SYSTEM_CreateResourceArc(0x4a, 0);
    n->f4 = (u32)G3D_SYSTEM_CreateObject((u32)G3D_SYSTEM_CreateRender((void *)n->f0, 0, 0), 0, 0);
    return n;
}
