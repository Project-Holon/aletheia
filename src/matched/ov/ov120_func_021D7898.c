/*
 * function: func_021D7898
 * address: 0x021D7898
 * packet: pkt_ov120_021D7898
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021D79F2.
 * lever: decode the high halfword, retain u16 payload arguments, remove
 * the p+16 address temporary and declare every Thumb callee explicitly.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_021D7710 0x021D7710 thumb ov120
 *   func_021D846C 0x021D846C thumb ov120
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00286.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_021D7710(u8 *p);
extern void func_0201DD68(void);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021D846C(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void TCBL_Destroy(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern u32 func_020307B0(void *p);
static inline u16 decode(u32 value)
{
    u32 n=value >> 16;
    return (u16)n;
}
void func_021D7898(char *p)
{
    int i;
    u32 t;
    t=((struct Obj00286 *)p)->f4;
    func_0203FB44(1,(u16)t,decode(t));
    t=((struct Obj00286 *)p)->f0;
    func_0203FB44(6,(u16)t,decode(t));
    func_021D7710((u8 *)p);
    func_0201DD68();
    MSGDATA_Delete(((struct Obj00286 *)p)->fC);
    GF_FONT_Delete(((struct Obj00286 *)p)->f14);
    STRBUF_Delete(((struct Obj00286 *)p)->f18);
    STRBUF_Delete(((struct Obj00286 *)p)->f1C);
    STRBUF_Delete(((struct Obj00286 *)p)->f20);
    func_021D846C((u8 *)p);
    if(((struct Obj00286 *)p)->f9C) {func_0201CE48(((struct Obj00286 *)p)->f9C);((struct Obj00286 *)p)->f9C=0;}
    func_0201ED04(((struct Obj00286 *)p)->f10);
    if(((struct Obj00286 *)p)->fC4) {APP_TASKMENU_WIN_Delete(((struct Obj00286 *)p)->fC4);((struct Obj00286 *)p)->fC4=0;}
    APP_TASKMENU_RES_Delete(((struct Obj00286 *)p)->fC0);
    TCBL_Destroy(((struct Obj00286 *)p)->fA0);
    func_0201C6EC(((struct Obj00286 *)p)->fA4);
    func_0201C4C0(((struct Obj00286 *)p)->fA4);
    if(((struct Obj00286 *)p)->f30) func_020452E8(((struct Obj00286 *)p)->f30);
    if(((struct Obj00286 *)p)->f84) func_020452E8(((struct Obj00286 *)p)->f84);
    if(((struct Obj00286 *)p)->f98) func_020452E8(((struct Obj00286 *)p)->f98);
    if(((struct Obj00286 *)p)->f90) func_020452E8(((struct Obj00286 *)p)->f90);
    if(((struct Obj00286 *)p)->f8C) func_020452E8(((struct Obj00286 *)p)->f8C);
    if(((struct Obj00286 *)p)->f94) func_020452E8(((struct Obj00286 *)p)->f94);
    if(((struct Obj00286 *)p)->f88) func_020452E8(((struct Obj00286 *)p)->f88);
    if(((struct Obj00286 *)p)->f34) func_020452E8(((struct Obj00286 *)p)->f34);
    if(((struct Obj00286 *)p)->f68) func_020452E8(((struct Obj00286 *)p)->f68);
    for(i=0;i<12;i++) if(*(void **)(p+i*4+0x38)) func_020452E8(*(void **)(p+i*4+0x38));
    for(i=0;i<6;i++) if(*(void **)(p+i*4+0x6c)) func_020452E8(*(void **)(p+i*4+0x6c));
    BMP_WIN_Exit();
    func_020307B0(p);
}
