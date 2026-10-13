/*
 * function: func_021B8304
 * address: 0x021B8304
 * packet: pkt_ov106_021B8304
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020452E8 0x020452E8 arm
 *   func_021B8D8C 0x021B8D8C thumb ov106
 *   func_021B89F4 0x021B89F4 thumb ov106
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   func_021B8B4C 0x021B8B4C thumb ov106
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj05281.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Node;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_021B8D8C(u8 *);
extern void func_021B89F4(u8 *);
extern void CLACT_ReleasePalette(u32 i);
extern void func_021B8B4C(void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_02082BCC(void *,int,int);
void func_021B8304(u8 *p) {
    int i;
    func_02030EAC(((struct Obj05281 *)p)->f58C);
    for(i=0;i<2;i++)func_020452E8(*(void **)((u8 *)((u32 *)p+i)+0x568));
    for(i=0;i<func_021B8D8C(*(u8 * *)&((struct Obj05281 *)p)->f550);i++)func_021B89F4(p+0x188+i*32);
    CLACT_ReleasePalette((u32)(((struct Obj05281 *)p)->f0));
    CLACT_ReleasePalette((u32)(((struct Obj05281 *)p)->f4));
    func_021B8B4C(p+8);
    func_0201ED04(((struct Obj05281 *)p)->f588);
    GF_FONT_Delete(((struct Obj05281 *)p)->f570);
    func_02082BCC(p,0,0x59c);
}
