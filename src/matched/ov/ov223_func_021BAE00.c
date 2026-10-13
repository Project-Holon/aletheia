/*
 * function: func_021BAE00
 * address: 0x021BAE00
 * packet: pkt_ov223_021BAE00
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   table 0x021BC770 data a1
 *   func_02049B40 0x02049B40 arm
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj00739.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct MsgBank;struct Tcbl;struct Descriptor;struct CharBuf;
typedef struct {u8 a,b,c,d,e,f,g,h,i;} Entry;
extern const Entry table[];
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void func_021BAE00(char *p)
{
    u8 i=0;
    func_02049B40(23,5,0,448,32,((struct Obj00739 *)p)->f0);
    func_02049B40(23,5,4,32,32,((struct Obj00739 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00739 *)p)->f234=func_02045B38(0,3,430,((struct Obj00739 *)p)->f0);
    *(struct Tcbl * *)&((struct Obj00739 *)p)->f254=TCBL_Create(((struct Obj00739 *)p)->f0,((struct Obj00739 *)p)->f0,1,0);
    GF_FONT_SetTextColor(15,2,0);
    for(;i<3;i++) {
        *(u32 *)(p+i*4+568)=BMP_WIN_Create(table[i].a,table[i].b,table[i].c,table[i].d,table[i].e,table[i].f,table[i].g);
        BMP_Clear(func_02045770(*(struct Descriptor **)(p+i*4+568)),0);
        BMP_WIN_TransferChars(*(struct Descriptor **)(p+i*4+568));
        *(u32 *)(p+i*4+580)=1;
    }
    ((struct Obj00739 *)p)->f250=0;((struct Obj00739 *)p)->f258=0;
}
