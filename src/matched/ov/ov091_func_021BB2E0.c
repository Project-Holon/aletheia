/*
 * function: PLIST_PLATE_RedrawHp
 * address: 0x021BB2E0
 * packet: pkt_ov091_021BB2E0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_FillRect 0x02043AF4 arm
 *   PLIST_PLATE_Draw 0x021BAAE4 thumb ov091
 */
#include "../include/Obj20879.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Bmp;
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void PLIST_PLATE_Draw(u8 *,u8 *,int);
void PLIST_PLATE_RedrawHp(u8 *a,u8 *s) {BMP_FillRect((struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj20879 *)s)->f20)),0,26,128,22,0);PLIST_PLATE_Draw(a,s,1);}
