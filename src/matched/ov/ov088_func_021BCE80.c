/*
 * function: STARTMENU_SaveEraseStepErase
 * address:  0x021BCE80
 * packet:   pkt_ov088_021BCE80
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STARTMENU_SaveEraseUpdateMessage  0x021BD188  thumb  ov088
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02005654  0x02005654  thumb
 *   STARTMENU_SaveEraseUpdateTimeIcon  0x021BCE70  thumb  ov088
 *   func_020070A4  0x020070A4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_021DFF18  0x021DFF18  thumb  ov228
 *   func_02034A5C  0x02034A5C  arm
 *   func_02007230  0x02007230  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   SAVE_CONTROL_EraseExtraSave  0x02007400  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_0200566C  0x0200566C  thumb
 *   func_02087BCC  0x02087BCC  arm
 *   d_021BDA20     0x021BDA20  data  a4
 *   ov228_id       0x000000E4  data
 */
#include "../include/Obj00578.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *d_021BDA20;
extern char ov228_id[];

extern int STARTMENU_SaveEraseUpdateMessage(char *p);
typedef signed int     s32;
struct Ctrl;
struct Descriptor;
struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
struct Sub020072A4Ctrl;
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern int func_02005654(int a, int b);
extern void STARTMENU_SaveEraseUpdateTimeIcon(void);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern int func_02034AC4(s32 handle);
extern void func_021DFF18(u32 heap);
extern void func_02034A5C(s32 handle);
extern void *func_02007230(struct Sub020071E4Ctrl *ctrl);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void SAVE_CONTROL_EraseExtraSave(char *a0, u32 a1, u32 a2);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void func_0200566C(void);
extern void func_02087BCC(u32 parameter);

void STARTMENU_SaveEraseStepErase(u8 *p, int *a1)
{
    void *r;
    u32 i;

    if (STARTMENU_SaveEraseUpdateMessage((char *)p) == 0) {
        d_021BDA20 = TIME_ICON_Create(0, ((struct Obj00578 *)p)->f1C, 0xf, 0x10, 0x81);
        func_020409B4(BMP_WIN_GetBgLayer(((struct Obj00578 *)p)->f1C));
        func_02005654((int)STARTMENU_SaveEraseUpdateTimeIcon, 0);
        r = func_020070A4();
        func_02034AC4((u32)ov228_id);
        func_021DFF18(0x81);
        func_02034A5C((u32)ov228_id);
        func_02007230(r);
        for (i = 0; i < 9; i++) {
            if (SAVE_CONTROL_LoadExtraSave(r, i, 0x81) == 1)
                SAVE_CONTROL_EraseExtraSave(r, i, 0x81);
            func_020072A4(r, i);
        }
        func_0200566C();
        func_02087BCC(0);
    }
}
