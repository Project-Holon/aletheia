/*
 * function: FIELD_G3D_MAPPER_ReleaseBlocks
 * address:  0x0218D05C
 * packet:   pkt_ov021_0218D05C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3D_MAP_ClearPlacedModels  0x021693CC  thumb ov010
 *   FIELD_G3D_MAP_ClearAltTextureRes  0x021693BC  thumb ov010
 *   FIELD_G3D_MAP_CloseArchive  0x021693A0  thumb ov010
 *   FIELD_G3D_MAP_Destroy  0x0216928C  thumb ov010
 *   FIELD_G3D_MAPPER_FreeGroundAnimeSlot  0x0218DD38  thumb ov021
 *   func_020307B0  0x020307B0  arm
 *   FIELD_GROUND_ANIME_Delete  0x021A73C0  thumb ov021
 *   FIELD_G3D_MAPPER_FreeTexture  0x0218D13C  thumb ov021
 */
#include "../include/Obj01208.h"

typedef unsigned short u16;

extern void FIELD_G3D_MAP_ClearPlacedModels(char *p);
extern void FIELD_G3D_MAP_ClearAltTextureRes(char *p);
extern void FIELD_G3D_MAP_CloseArchive(int o);
extern void FIELD_G3D_MAP_Destroy(void *p);
typedef unsigned char  u8;
extern void FIELD_G3D_MAPPER_FreeGroundAnimeSlot(void **a);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void FIELD_GROUND_ANIME_Delete(int p);
extern void FIELD_G3D_MAPPER_FreeTexture(u8 *a);

void FIELD_G3D_MAPPER_ReleaseBlocks(char *p)
{
    int i;

    if (*(int *)&((struct Obj01208 *)p)->f24 != 0) {
        for (i = 0; i < ((struct Obj01208 *)p)->f2E; i++) {
            int off = i * 0x28;
            FIELD_G3D_MAP_ClearPlacedModels((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            FIELD_G3D_MAP_ClearAltTextureRes((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            FIELD_G3D_MAP_CloseArchive(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off));
            FIELD_G3D_MAP_Destroy((void *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            FIELD_G3D_MAPPER_FreeGroundAnimeSlot((void **)(*(char * *)&((struct Obj01208 *)p)->f24 + off + 4));
        }
        func_020307B0(((struct Obj01208 *)p)->f24);
        func_020307B0(((struct Obj01208 *)p)->f28);
        func_020307B0(((struct Obj01208 *)p)->f44);
        *(int *)&((struct Obj01208 *)p)->f28 = 0;
        *(int *)&((struct Obj01208 *)p)->f24 = 0;
        *(int *)&((struct Obj01208 *)p)->f44 = 0;
        ((struct Obj01208 *)p)->f2E = 0;
    }
    if (((struct Obj01208 *)p)->f68 != 0) {
        FIELD_GROUND_ANIME_Delete(((struct Obj01208 *)p)->f68);
        ((struct Obj01208 *)p)->f68 = 0;
    }
    FIELD_G3D_MAPPER_FreeTexture((u8 *)p);
}
