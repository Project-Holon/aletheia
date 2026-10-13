/*
 * function: func_021F8BD4
 * address: 0x021F8BD4
 * packet: pkt_ov132_021F8BD4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F6F24 0x021F6F24 thumb ov112
 */
#include "../include/Obj00503.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void MIi_CpuCopy16(const void *,void *,u32);
extern void func_020409B4(u32);
extern u8 *func_021F6F24(u32 heap, u32 v);
void func_021F8BD4(u8 *p)
{
    u16 palette[16];
    u8 i=0;
    u16 old,new;
    ARC_UTIL_UploadPaletteFromHandle((void *)(((struct Obj00503 *)p)->f18),2,0,32,32,32,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),8,3,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),14,3,0,0,0,((struct Obj00503 *)p)->f0);
    ARC_UTIL_UploadPaletteFromHandle((void *)(((struct Obj00503 *)p)->f18),3,0,0,0,32,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),9,2,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),15,2,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049B68((void *)(((struct Obj00503 *)p)->f18),5,4,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),13,5,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),17,5,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),12,6,0,0,0,((struct Obj00503 *)p)->f0);
    func_020498F4((void *)(((struct Obj00503 *)p)->f18),16,6,0,0,0,((struct Obj00503 *)p)->f0);
    func_02049658((void *)(((struct Obj00503 *)p)->f18),11,4,0,0,0,((struct Obj00503 *)p)->f0);
    MIi_CpuCopy16((void *)0x05000400,p+0x16a,32);
    MIi_CpuCopy16((void *)0x05000420,palette,32);
    for(i=0;i<16;i++){
        old=*(u16 *)(p+0x16a+i*2);
        new=palette[i];
        p[0x18a+i]=(u8)(new&31)-(u8)(old&31);
        p[0x19a+i]=(u8)((new&0x3e0)>>5)-(u8)((old&0x3e0)>>5);
        p[0x1aa+i]=(u8)((new&0x7c00)>>10)-(u8)((old&0x7c00)>>10);
    }
    func_020409B4(3);
    func_020409B4(5);
    ((struct Obj00503 *)p)->f3C=func_021F6F24(((struct Obj00503 *)p)->f0,(u32)p);
}
