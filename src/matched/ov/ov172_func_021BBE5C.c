/*
 * function: CTVT_CALL_Exit
 * address:  0x021BBE5C
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frees the 0x1c owner, both stream buffers, the two 0x400/0x404 blocks, the
 * 0xf by 0x1c record ring and the 0xf by 0x24 handle ring.
 *
 * symbols:
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_020307B0  0x020307B0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03316.h"
#include "../include/Obj08261.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Descriptor;
struct Obj;
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 func_020307B0(void *p);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);

void CTVT_CALL_Exit(void *a0, char *a1)
{
    u32 p;
    u8 i, j;

    if (((struct Obj03316 *)a1)->f1C != 0) {
        APP_TASKMENU_WIN_Delete((u8 *)(*(u32 *)&((struct Obj03316 *)a1)->f1C));
        *(u32 *)&((struct Obj03316 *)a1)->f1C = 0;
    }

    p = ((struct Obj03316 *)a1)->f2C;
    BMP_WIN_ClearScreen((struct Descriptor *)p);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03316 *)a1)->f2C));

    p = ((struct Obj03316 *)a1)->f30;
    BMP_WIN_ClearScreen((struct Descriptor *)p);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj03316 *)a1)->f30));

    CLACT_DeleteActor((struct Obj *)(((struct Obj03316 *)a1)->f404));
    CLACT_DeleteActor((struct Obj *)(((struct Obj03316 *)a1)->f400));

    for (i = 0; i < 0xf; i++) {
        char *q = a1 + i * 0x1c;

        BMP_WIN_Delete((struct Descriptor *)(((struct Obj08261 *)q)->f54));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f50));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f4C));
        CLACT_DeleteActor((struct Obj *)(((struct Obj08261 *)q)->f48));
    }

    for (j = 0; j < 0xf; j++)
        func_020307B0((void *)(*(u32 *)(a1 + j * 0x24 + 0x1f8)));

    BG_SYS_ClearSlot(6);
    BG_SYS_PushTile(6);
    BG_SYS_ResetSlot(6, 3, 0);
    BG_SYS_ClearSlot(4);
    BG_SYS_PushTile(4);
    BG_SYS_ResetSlot(4, 3, 0);
}
