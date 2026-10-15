/*
 * function: POKE_SUMMARY_MAIN_DrawMoveRow
 * address: 0x021B6FDC
 * packet: pkt_ov173_021B6FDC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 */
#include "../include/Obj00837.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Cfg;
struct Descriptor;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);
extern u8 WAZA_TOOL_GetMaxPP(u16,u32);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
static inline void flush(void *win)
{
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}
void POKE_SUMMARY_MAIN_DrawMoveRow(char *p,u8 first,u8 row)
{
    int y;
    int index;
    u32 value;
    y=row*24;
    index=first+row;
    if(index>=((struct Obj00837 *)p)->f1B8) return;
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30),0,y,*(void **)(*(char * *)&((struct Obj00837 *)p)->f58+index*8),((struct Obj00837 *)p)->f60,0x3c40);
    flush(((struct Obj00837 *)p)->f30);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30),96,y,((struct Obj00837 *)p)->f50,((struct Obj00837 *)p)->f60,0x440);
    flush(((struct Obj00837 *)p)->f30);
    value=WAZA_TOOL_GetMaxPP(*(u32 *)(*(char * *)&((struct Obj00837 *)p)->f58+index*8+4),0);
    WORDSET_SetSlotNumber(((struct Obj00837 *)p)->f48,0,value,2,1,1);
    WORDSET_SetSlotNumber(((struct Obj00837 *)p)->f48,1,value,2,0,1);
    WORDSET_CopyTaggedText(((struct Obj00837 *)p)->f48,((struct Obj00837 *)p)->f4C,((struct Obj00837 *)p)->f54);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30),120,y,((struct Obj00837 *)p)->f4C,((struct Obj00837 *)p)->f60,0x440);
    flush(((struct Obj00837 *)p)->f30);
}
