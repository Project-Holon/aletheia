/*
 * function: GTSNEGO_MSG_ClearRows
 * address: 0x021D7D3C
 * packet: pkt_ov120_021D7D3C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 */
#include "../include/Obj08082.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
void GTSNEGO_MSG_ClearRows(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(((struct Obj08082 *)q)->f38) { func_02041B6C(BMP_WIN_GetBgLayer(((struct Obj08082 *)q)->f38)); BMP_MENUWORK_DrawWindowBorder(((struct Obj08082 *)q)->f38,2); BMP_WIN_ClearScreen(((struct Obj08082 *)q)->f38); } } }
