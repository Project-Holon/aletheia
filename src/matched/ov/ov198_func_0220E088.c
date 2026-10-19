/*
 * function: B_PLIST_DRAW_DrawMode5
 * address: 0x0220E088
 * packet: pkt_ov198_0220E088
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02211AF9 0x02211AF9 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   B_PLIST_DRAW_ClearWindowBitmaps 0x0220BDA0 thumb ov198
 *   B_PLIST_DRAW_PrintRowName 0x0220BEB8 thumb ov198
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PrintNumberAt 0x0220C4DC thumb ov198
 *   B_PLIST_DRAW_PrintMoveRowValues 0x0220D6DC thumb ov198
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
 *   B_PLIST_DRAW_PrintHeader 0x0220C60C thumb ov198
 */
#include "../include/Obj00507.h"
#include "../include/Obj25192.h"
#include "../include/Obj25193.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211AF9[];
extern const int d_02211B3C[];
extern void B_PLIST_DRAW_ClearWindowBitmaps(u8 *p);
extern void B_PLIST_DRAW_PrintRowName(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PrintNumberAt(char *,int,int,int,u16,short,unsigned);
extern void B_PLIST_DRAW_PrintMoveRowValues(char *p, u8 *record, int slot);
typedef unsigned int   u32;
extern u32 FILE_UTIL_GetItemParam(void *a, u32 sel, u32 id);
extern void B_PLIST_DRAW_PrintHeader(char *p, int id);
void B_PLIST_DRAW_DrawMode5(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211AF9;
    B_PLIST_DRAW_ClearWindowBitmaps((u8 *)p);
    B_PLIST_DRAW_PrintRowName((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + B_PLIST_MAIN_GetOrderIndex((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            B_PLIST_DRAW_PrintNumberAt((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            B_PLIST_DRAW_PrintMoveRowValues((char *)p,(u8 *)(rec+offset),i+1);
        }
    }
    if (FILE_UTIL_GetItemParam((void *)(((struct Obj25192 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f24),40,((struct Obj25193 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f10) == 0)
        B_PLIST_DRAW_PrintHeader((char *)p,104);
}
