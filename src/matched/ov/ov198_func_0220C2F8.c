/*
 * function: B_PLIST_DRAW_FillTypeBar
 * address: 0x0220C2F8
 * packet: pkt_ov198_0220C2F8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 value and u8 width/return preserve stack-store scheduling.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   func_0202D01C 0x0202D01C thumb
 *   func_0202D034 0x0202D034 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_FillRect 0x02043AF4 arm
 */
#include "../include/Obj08357.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern u8 func_0202D01C(u32,u32,u32);
extern int func_0202D034(u32,u32);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Bmp;
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
void B_PLIST_DRAW_FillTypeBar(u8 *p,int slot,int index,u16 value,u8 extra)
{
    char *elem=(char *)(p+4)+B_PLIST_MAIN_GetOrderIndex(p,index)*0x4C;
    u8 color=1;
    u8 width=func_0202D01C(((struct Obj08357 *)elem)->f10,((struct Obj08357 *)elem)->f12,48);
    switch(func_0202D034(((struct Obj08357 *)elem)->f10,((struct Obj08357 *)elem)->f12)) {
    case 3: return;
    case 0: color=1; break;
    case 1: color=3; break;
    case 2: color=5; break;
    }
    BMP_FillRect((struct Bmp *)((u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16)(extra+3),width,(u8)1,(u8)color);
    color++;
    BMP_FillRect((struct Bmp *)((u32)BMP_WIN_GetBmp(*(void **)(p+0x1F70+slot*8))),(u16)value,(s16)(extra+4),width,(u8)1,(u8)color);
}
