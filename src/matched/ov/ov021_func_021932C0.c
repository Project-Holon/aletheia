/*
 * function: FIELD_MSGBG_BlockUpdateOnePlane
 * address:  0x021932C0
 * packet:   pkt_ov021_021932C0
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
 *   FIELD_BUILDMODEL_RegisterObjects  0x0218B974  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResHasGroundAnime  0x0218DCF4  thumb ov021
 *   FIELD_G3D_MAPPER_SlotResGetGroundAnime  0x0218DCFC  thumb ov021
 *   FIELD_GROUND_ANIME_BindAnm  0x021A7410  thumb ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04210.h"
#include "../include/Obj09477.h"

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
extern void FIELD_BUILDMODEL_RegisterObjects(int a, int o, void *p, int n);
extern int FIELD_G3D_MAPPER_SlotResHasGroundAnime(unsigned int *a0);
extern int FIELD_G3D_MAPPER_SlotResGetGroundAnime(unsigned int *a0);
typedef unsigned int   u32;
extern int FIELD_GROUND_ANIME_BindAnm(u32 a, u32 b, u32 c, u32 d);

int FIELD_MSGBG_BlockUpdateOnePlane(u8 *o, unsigned int *q)
{
    u16 *st;
    int x;
    char *h;
    char *p;
    int off;

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
        ((struct Obj04210 *)st)->f18 = 1;
        ((struct Obj04210 *)st)->f1C = 1;
        ((struct Obj04210 *)st)->f20 = 1;
        *st = 3;
    case 3:
        FIELD_G3D_MAP_GetBuffer((unsigned char *)o, (int *)(&h));
        p = h;
        FIELD_G3D_MAP_SetModelRes((unsigned char *)o, (unsigned int)(p + ((struct Obj09477 *)p)->f4));
        off = ((struct Obj09477 *)p)->fC;
        if (off != ((struct Obj09477 *)p)->f10)
            FIELD_BUILDMODEL_RegisterObjects(FIELD_G3D_MAPPER_SlotResGetBuildModel((u8 *)q), (int)o, h + off + 4, *(int *)(h + off));
        FIELD_G3D_MAP_BindRenderObj((int)o);
        if (FIELD_G3D_MAPPER_SlotResHasGroundAnime(q))
            FIELD_GROUND_ANIME_BindAnm(FIELD_G3D_MAPPER_SlotResGetGroundAnime((unsigned int *)q), FIELD_G3D_MAP_GetModelRes((unsigned char *)o), FIELD_G3D_MAP_GetTextureRes((unsigned char *)o), FIELD_G3D_MAP_GetRenderObj(o));
        *st = 0;
        return 0;
    }
    return 1;
}
