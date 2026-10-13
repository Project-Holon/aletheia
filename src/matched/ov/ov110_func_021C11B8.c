/*
 * function: func_021C11B8
 * address: 0x021C11B8
 * packet: pkt_ov110_021C11B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_021C080C 0x021C080C thumb ov110
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj10286.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021C080C(u8 *,int,int,int);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
void func_021C11B8(u8 *p,int index,int unused,int flag) {
    void *str;
    u16 color;
    str=func_02045EC0(((struct Obj10286 *)p)->f60,17);
    func_021C080C(p+0x24,index,6,flag);
    if (flag) {
        BMP_Clear(func_02045770(*(void **)(p+0x6c+index*4)),14);
        color=0x44e;
    } else {
        BMP_Clear(func_02045770(*(void **)(p+0x6c+index*4)),13);
        color=0x44d;
    }
    PRINTSYS_PrintQueColor(((struct Obj10286 *)p)->f5C,(u32)func_02045770(*(void **)(p+0x6c+index*4)),0,0,(u32)str,((struct Obj10286 *)p)->f58,color);
    STRBUF_Delete(str);
    BMP_WIN_MakeScreen(*(void **)(p+0x6c+index*4));
    func_02041B6C(func_02045730(*(void **)(p+0x6c+index*4)));
    *(int *)(p+0x7c+index*4)=1;
}
