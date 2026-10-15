/*
 * function: func_0220E168
 * address: 0x0220E168
 * packet: pkt_ov198_0220E168
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: global pointer re-read at 0220E17C and 0220E196 before PRINTSYS_PrintStream.
 * symbols:
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj02247.h"
#include "../include/Obj25194.h"
#include "../include/Obj25195.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { char *volatile global; } Context;
struct Descriptor;
struct Cfg;
extern unsigned GF_FONT_SetTextColor(unsigned,unsigned,unsigned);
extern int MSG_SPEED_GetWait(unsigned);
extern int PRINTSYS_PrintStream(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
void func_0220E168(char *p)
{
    int v;
    void *obj;
    v = MSG_SPEED_GetWait(GF_FONT_SetTextColor(1,2,0));
    ((struct Obj02247 *)p)->f1EB0 = PRINTSYS_PrintStream(*(unsigned *)&((struct Obj02247 *)p)->f1F68,0,0,*(unsigned *)&((struct Obj02247 *)p)->f1EA8,((struct Obj25194 *)(((Context *)p)->global))->fC,v,((struct Obj02247 *)p)->f1D4,10,((struct Obj25195 *)(((Context *)p)->global))->f10,15);
    obj = ((struct Obj02247 *)p)->f1F68;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_02041B6C(BMP_WIN_GetBgLayer(obj));
}
