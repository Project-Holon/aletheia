/*
 * function: func_021D5A9C
 * address: 0x021D5A9C
 * packet: pkt_ov115_021D5A9C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5FA0 0x021D5FA0 thumb ov115
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 *   func_0203FB44 0x0203FB44 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00724.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void TIME_ICON_Delete(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_021D5D3C(u8 *p);
extern u32 func_021D5FA0(u32);
extern u32 func_021D5FC4(u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_0201DD68(void);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern u32 func_020307B0(void *p);
void func_021D5A9C(u8 *p) {
    u32 n;
    if (((struct Obj00724 *)p)->f80) { TIME_ICON_Delete(((struct Obj00724 *)p)->f80); ((struct Obj00724 *)p)->f80=0; }
    if (((struct Obj00724 *)p)->f38) { func_0201CE48(((struct Obj00724 *)p)->f38); ((struct Obj00724 *)p)->f38=0; }
    func_021D5D3C(p);
    n=((struct Obj00724 *)p)->f0;
    func_0203FB44(func_021D5FA0(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    n=((struct Obj00724 *)p)->f4;
    func_0203FB44(func_021D5FC4(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    func_0201DD68();
    func_0201ED04(((struct Obj00724 *)p)->f20);
    MSGDATA_Delete(((struct Obj00724 *)p)->f1C);
    GF_FONT_Delete(((struct Obj00724 *)p)->f24);
    STRBUF_Delete(((struct Obj00724 *)p)->f28);
    APP_TASKMENU_RES_Delete(((struct Obj00724 *)p)->f70);
    TCBL_Destroy(((struct Obj00724 *)p)->f44);
    func_0201C6EC(((struct Obj00724 *)p)->f48);
    func_0201C4C0(((struct Obj00724 *)p)->f48);
    if (((struct Obj00724 *)p)->f2C) { func_020452E8(((struct Obj00724 *)p)->f2C); ((struct Obj00724 *)p)->f2C=0; }
    if (((struct Obj00724 *)p)->f30) { func_020452E8(((struct Obj00724 *)p)->f30); ((struct Obj00724 *)p)->f30=0; }
    BMP_WIN_Exit();
    func_020307B0(p);
}
