/*
 * function: func_021BA160
 * address: 0x021BA160
 * packet: pkt_ov225_021BA160
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: args before gManualGraphicMainBgLayerTable declaration puts the 64-byte copy at sp+0.
 * symbols:
 *   d_021BBF4C 0x021BBF4C data a4
 *   MI_CpuFill8 0x02082BCC arm
 *   MANUAL_GRAPHIC_GetClactUnit 0x021B9A08 thumb ov225
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   gManualGraphicMainBgLayerTable  0x021BBE4C  data
 */
#include "../include/Obj08468.h"
#include "../include/Obj26147.h"
#include "../include/Obj26148.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u8 *f0;u32 f4;int f8;u32 fC,f10,f14;int f18,f1c;} A;
typedef struct {int f0;u32 f4;int f8;u8 sub[0x14];u8 elem[1];} R;
struct Block {u32 words[16];};
extern const struct Block d_021BBF4C;
extern void MI_CpuFill8(void *,u8,u32);
extern u32 MANUAL_GRAPHIC_GetClactUnit(const u8 *p);
extern R *TOUCHBAR_Create(A *,int);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
void func_021BA160(char *p)
{
    A args;
    struct Block gManualGraphicMainBgLayerTable=d_021BBF4C;
    MI_CpuFill8(&args,0,sizeof(args));
    args.f0=(u8 *)&gManualGraphicMainBgLayerTable;args.f4=2;
    args.f8=(int)MANUAL_GRAPHIC_GetClactUnit(((struct Obj26147 *)(*(char * *)&((struct Obj08468 *)p)->f0))->f8);
    args.fC=6;args.f10=3;args.f14=1;args.f18=0;
    *(R * *)&((struct Obj08468 *)p)->f4=TOUCHBAR_Create(&args,((struct Obj26148 *)(*(char * *)&((struct Obj08468 *)p)->f0))->f4);
    TOUCHBAR_SetButtonVisible(((struct Obj08468 *)p)->f4,0,0);
}
