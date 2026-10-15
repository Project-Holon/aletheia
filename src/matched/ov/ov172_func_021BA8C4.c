/*
 * function: CTVT_DRAW_Exit
 * address:  0x021BA8C4
 * packet:   pkt_ov172_021BA8C4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scene teardown.
 *
 * symbols:
 *   COMM_TVT_SYS_GetHeapId  0x021BE00C  thumb  ov172
 *   COMM_TVT_SYS_ClearNameWindows  0x021BE1A4  thumb  ov172
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 *   BG_SYS_ClearSlot  0x020414EC  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01265.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16  COMM_TVT_SYS_GetHeapId(u16 *p);
extern void COMM_TVT_SYS_ClearNameWindows(char *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
struct Descriptor;
struct Obj;
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);
extern void BG_SYS_ClearSlot(u32 a);
extern void func_02040618(u32 a, u32 b, u32 c);
extern void func_02040588(unsigned char which, unsigned char enable);

void CTVT_DRAW_Exit(u16 *a0, char *p)
{
    u32 r;
    u8 i;
    u16 v;

    v = COMM_TVT_SYS_GetHeapId(a0);
    if (((struct Obj01265 *)p)->f28 == 1) {
        ((struct Obj01265 *)p)->f28 = (((struct Obj01265 *)p)->f24 == 0) ? 0 : 3;
    }
    r = 0;
    GFL_NET_RestartWithDefaultTimeout(0, v);
    func_0201F7A8((void *)(((struct Obj01265 *)p)->f48), 0);
    r = ((struct Obj01265 *)p)->f48;
    BMP_WIN_ClearScreen((struct Descriptor *)r);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)r));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj01265 *)p)->f48));
    r = ((struct Obj01265 *)p)->f4C;
    BMP_WIN_ClearScreen((struct Descriptor *)r);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)r));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj01265 *)p)->f4C));
    r = ((struct Obj01265 *)p)->f50;
    if (r != 0) {
        BMP_WIN_ClearScreen((struct Descriptor *)r);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)r));
        BMP_WIN_Delete((struct Descriptor *)(((struct Obj01265 *)p)->f50));
        ((struct Obj01265 *)p)->f50 = 0;
    }
    for (i = 0; i < 5; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32 *)(p + i * 4 + 0x70)));
    }
    for (i = 0; i < 6; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32 *)(p + i * 4 + 0x58)));
    }
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f90));
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f8C));
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01265 *)p)->f88, 0);
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f88));
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj01265 *)p)->f84, 0);
    CLACT_DeleteActor((struct Obj *)(((struct Obj01265 *)p)->f84));
    BG_SYS_ClearSlot(0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    BG_SYS_ClearSlot(6);
    func_020409B4(6);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    COMM_TVT_SYS_ClearNameWindows((char *)a0);
}
