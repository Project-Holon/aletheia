/*
 * function: PLIST_MESSAGE_DrawKeyCursorMark
 * address: 0x021BBA70
 * packet: pkt_ov091_021BBA70
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   APP_KEYCURSOR_DrawMark 0x02028618 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj09931.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned int   u32;
struct Bmp;
struct Ctx;
extern void APP_KEYCURSOR_DrawMark(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void PLIST_MESSAGE_DrawKeyCursorMark(int a,int b) {APP_KEYCURSOR_DrawMark((struct Ctx *)(((struct Obj09931 *)b)->f14),(const struct Bmp *)((unsigned int)func_02045770((struct Descriptor *)((struct Obj09931 *)b)->f4)),15);BMP_WIN_TransferChars((struct Descriptor *)((struct Obj09931 *)b)->f4);}
