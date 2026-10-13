/*
 * function: func_021BD3B4
 * address:  0x021BD3B4
 * packet:   pkt_ov217_021BD3B4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`sysOff=0x140;` before `sysOff=0x12C;`; `outOff=0x140;` before
 * `outOff=0x130;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   func_021BC708  0x021BC708  thumb  ov217
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   d_021C31BC 0x021C31BC data a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25887.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };
struct Entry { s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };
struct Sys;
struct Grid;
struct Obj;
extern const struct Entry d_021C31BC[];
extern u32 func_021BC708(void *,u32);
extern struct Grid *BMP_OAM_Create(struct Sys *,const struct Param *);
extern void BMP_OAM_SetEnabled(u8 *,u32);
extern void BMP_OAM_UploadChars(struct Obj *);
void func_021BD3B4(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct Entry *q;
    u8 *dest;
    sysOff=0x12C;
    outOff=0x130;
    callOff=0x130;
    uploadOff=0x130;
    for(i=0;i<4;i++) {
        dest=p+i*4;
        param.bmp=((struct Obj25887 *)dest)->f140;
        q=&d_021C31BC[i];
        param.x=q->x; param.y=q->y;
        param.f8=func_021BC708(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=BMP_OAM_Create(*(struct Sys **)(p+sysOff),&param);
        BMP_OAM_SetEnabled(*(u8 **)(dest+callOff),0);
        BMP_OAM_UploadChars(*(struct Obj **)(dest+uploadOff));
    }
}
