/*
 * function: BMP_MENU_ProcessYesNo
 * address:  0x0201FEBC
 * packet:   pkt_0201FC5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * Verified with:
 *   python tools/match.py one --src src/pending/BMP_MENU_ProcessYesNo.c \
 *       --func BMP_MENU_ProcessYesNo --addr 0x0201FEBC --cc 1.1p1 --thumb
 *
 * symbols:
 *   BMP_MENU_ProcessInput  0x0201FA04  thumb
 *   BMP_MENU_DeleteYesNo  0x0201FEF4  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj02590.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Obj;
extern u32 BMP_MENU_ProcessInput(struct Obj *o);
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_MENU_DeleteYesNo(u8 *o);

u32 BMP_MENU_ProcessYesNo(u8 *p)
{
    u32 r = BMP_MENU_ProcessInput((struct Obj *)p);
    u32 t = PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj02590 *)p)->f18));

    if (((struct Obj02590 *)p)->f20 == 0 && t != 0) {
        BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02590 *)p)->f4);
        ((struct Obj02590 *)p)->f20 = 1;
    }
    if (r != 0xffffffff) {
        BMP_MENU_DeleteYesNo(p);
    }
    return r;
}

