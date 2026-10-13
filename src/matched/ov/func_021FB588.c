/*
 * function: func_021FB588
 * address:  0x021FB588
 * packet:   pkt_021FB588
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9660  0x021F9660  thumb  ov135
 *   g_022033FC  0x022033FC  data  ov135
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9

 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0xd/0x9 code from the table.
 */
#include "../include/Obj00098.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct Actor;
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *v, unsigned int k);
extern void func_021F9660(u8 *p, u32 k);
extern u32 BMP_MENUWORK_Delete(void *p);
extern u8 g_022033FC[];

int func_021FB588(u8 *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(*(u32 *)&((struct Obj00098 *)p)->f8)) != 0) {
        return -1;
    }
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660(p, 0x0);
    BMP_MENUWORK_Delete((void *)(*(u32 *)&((struct Obj00098 *)p)->f30));
    *(u32 *)&((struct Obj00098 *)p)->f48 = (*(s32 *)(g_022033FC + ((struct Obj00098 *)p)->f38 * 8) != 1) ? 0xd : 0x9;
    return -1;
}
