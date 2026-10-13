/*
 * function: func_021C52F8
 * address: 0x021C52F8
 * packet: pkt_ov136_021C52F8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: base + i * 4 + 0x44 keeps the base-plus-index inside the loop;
 * base + 0x44 + i * 4 hoists the field address and changes the loads.
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 */
#include "../include/Obj01751.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
struct U16Vec;
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
void func_021C52F8(u8 *p)
{
    int i;
    void *q;
    if (p[0xB] == 1) {
        APP_TASKMENU_WIN_Delete(((struct Obj01751 *)p)->f128);
        APP_TASKMENU_WIN_Delete(((struct Obj01751 *)p)->f12C);
        STRBUF_Delete(((struct Obj01751 *)p)->f130);
        STRBUF_Delete(((struct Obj01751 *)p)->f13C);
    }
    func_0201C4C0(((struct Obj01751 *)p)->f98);
    ((struct Obj01751 *)p)->f98 = 0;
    for (i = 0; i < 7; i++) {
        q = *(void **)(p + i * 4 + 0x44);
        BMP_WIN_ClearScreen(q);
        func_020409B4(func_02045730(q));
        func_020452E8(*(void **)(p + i * 4 + 0x44));
    }
    BMP_WIN_Exit();
}
