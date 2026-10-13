/*
 * function: func_02193628
 * address:  0x02193628
 * packet:   pkt_ov021_02193628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_G3D_MAP_GetActiveRef  0x02169520  thumb ov010
 *   FIELD_G3D_MAP_ResetLoadState  0x0216959C  thumb ov010
 *   FIELD_G3D_MAP_GetMemberIndex  0x02169530  thumb ov010
 *   FIELD_G3D_MAP_BeginChunkedLoad  0x021695BC  thumb ov010
 *   FIELD_G3D_MAP_ReadNextChunk  0x02169620  thumb ov010
 *   FIELD_G3D_MAP_GetBuffer  0x02169528  thumb ov010
 *   FIELD_G3D_MAP_SetModelRes  0x02169540  thumb ov010
 *   FIELD_G3D_MAP_BindRenderObj  0x02169580  thumb ov010
 *   FIELD_G3D_MAP_GetModelRes  0x02169560  thumb ov010
 *   FIELD_G3D_MAP_GetTextureRes  0x02169578  thumb ov010
 *   FIELD_G3D_MAP_GetRenderObj  0x02169598  thumb ov010
 *   FIELD_G3D_MAPPER_SlotResGetBuildModel  0x0218DD04  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetWfbc  0x0218DD08  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetSlotIndex  0x0218DD0C  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetHeapId  0x0218DD10  thumb ov021
 *   FIELD_BUILDMODEL_RegisterObjects  0x0218B974  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResHasGroundAnime  0x0218DCF4  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetGroundAnime  0x0218DCFC  thumb ov021
 *   FIELD_WFBC_PatchLandData  0x02193924  thumb ov021
 *   FIELD_GROUND_ANIME_BindAnm  0x021A7410  thumb ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03576.h"
#include "../include/Obj07438.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct S;
extern int FIELD_G3D_MAP_GetActiveRef(int a0, int a1);
extern void FIELD_G3D_MAP_ResetLoadState(u8 *p);
extern void FIELD_G3D_MAP_GetMemberIndex(unsigned char *a, int *out);
extern void FIELD_G3D_MAP_BeginChunkedLoad(struct S *p, int b);
extern int FIELD_G3D_MAP_ReadNextChunk(struct S *p);
extern void FIELD_G3D_MAP_GetBuffer(unsigned char *a, int *out);
extern void FIELD_G3D_MAP_SetModelRes(unsigned char *a, unsigned int v);
extern int FIELD_G3D_MAP_BindRenderObj(int a0);
extern int FIELD_G3D_MAP_GetModelRes(unsigned char *a);
extern int FIELD_G3D_MAP_GetTextureRes(unsigned char *a);
extern unsigned int FIELD_G3D_MAP_GetRenderObj(u8 *p);
extern int FIELD_G3D_MAPPER_SlotResGetBuildModel(u8 *p);
extern int FIELD_G3D_MAPPER_SlotResGetWfbc(u8 *p);
extern int FIELD_G3D_MAPPER_SlotResGetSlotIndex(u8 *p);
extern u16 FIELD_G3D_MAPPER_SlotResGetHeapId(u8 *p);
extern int FIELD_BUILDMODEL_RegisterObjects(int a, int o, void *p, int n);
extern int FIELD_WFBC_PatchLandData(u8 *a, void *q, int c, int d, int e, int f, int g, u16 h);
extern int FIELD_G3D_MAPPER_SlotResHasGroundAnime(unsigned int *a0);
extern int FIELD_G3D_MAPPER_SlotResGetGroundAnime(unsigned int *a0);
typedef unsigned int   u32;
extern int FIELD_GROUND_ANIME_BindAnm(u32 a, u32 b, u32 c, u32 d);

int func_02193628(u8 *o, unsigned int *q)
{
    u16 *st;
    int x;
    char *h;
    int boff;
    char *base;
    int j;
    int y0;
    int g;
    int id;
    u16 c;
    char *p;
    int off;
    int r;
    int n;
    int i;
    int x0;

    FIELD_G3D_MAPPER_SlotResGetHeapId((u8 *)q);
    FIELD_G3D_MAP_GetActiveRef((int)o, (int)(&st));
    switch (*st) {
    case 1:
        FIELD_G3D_MAP_ResetLoadState((u8 *)o);
        FIELD_G3D_MAP_GetMemberIndex((unsigned char *)o, &x);
        FIELD_G3D_MAP_BeginChunkedLoad((struct S *)o, x);
        *st = 2;
        break;
    case 2:
        if (FIELD_G3D_MAP_ReadNextChunk((struct S *)o) != 0)
            break;
        ((struct Obj03576 *)st)->f18 = 1;
        ((struct Obj03576 *)st)->f1C = 1;
        ((struct Obj03576 *)st)->f20 = 1;
        *st = 3;
        break;
    case 3:
        FIELD_G3D_MAP_GetBuffer((unsigned char *)o, (int *)(&h));
        p = h;
        FIELD_G3D_MAP_SetModelRes((unsigned char *)o, (unsigned int)(p + ((struct Obj07438 *)p)->f4));
        off = ((struct Obj07438 *)p)->fC;
        if (off != ((struct Obj07438 *)p)->f10)
            r = FIELD_BUILDMODEL_RegisterObjects(FIELD_G3D_MAPPER_SlotResGetBuildModel((u8 *)q), (int)o, h + off + 4, *(int *)(h + off));
        g = FIELD_G3D_MAPPER_SlotResGetBuildModel((u8 *)q);
        base = h;
        boff = ((struct Obj07438 *)p)->f8;
        n = FIELD_G3D_MAPPER_SlotResGetSlotIndex((u8 *)q);
        id = FIELD_G3D_MAPPER_SlotResGetWfbc((u8 *)q);
        c = FIELD_G3D_MAPPER_SlotResGetHeapId((u8 *)q);
        x0 = (n % 2) * 4;
        y0 = (n / 2) * 4;
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++) {
                r = FIELD_WFBC_PatchLandData((u8 *)id, base + boff, g, (int)o, r, x0 + i, y0 + j, c);
            }
        }
        FIELD_G3D_MAP_BindRenderObj((int)o);
        if (FIELD_G3D_MAPPER_SlotResHasGroundAnime(q))
            FIELD_GROUND_ANIME_BindAnm(FIELD_G3D_MAPPER_SlotResGetGroundAnime((unsigned int *)q), FIELD_G3D_MAP_GetModelRes((unsigned char *)o), FIELD_G3D_MAP_GetTextureRes((unsigned char *)o), FIELD_G3D_MAP_GetRenderObj(o));
        *st = 4;
        break;
    case 4:
        *st = 0;
        return 0;
    }
    return 1;
}
