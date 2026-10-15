/*
 * function: func_021B9740
 * address: 0x021B9740
 * packet: pkt_ov213_021B9740
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA7D0 0x021BA7D0 thumb ov213
 *   UI_SCENE_Step 0x021B6144 thumb ov067
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   COMM_BTL_DEMO_GRAPHIC_Draw 0x021BAC68 thumb ov213
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 */
#include "../include/Obj06704.h"
extern void func_021BA7D0(unsigned char *p);
extern void COMM_BTL_DEMO_GRAPHIC_Draw(char *p);
extern void BG_SYS_ResetSlot(unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct PrintSys;
struct S;
extern int UI_SCENE_Step(struct S *s);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
int func_021B9740(int a,int b,int c,char *p)
{
    func_021BA7D0((unsigned char *)(p+0x24));
    if(UI_SCENE_Step(((struct Obj06704 *)p)->f49C4)) return 1;
    PRINTSYS_QUE_Main(((struct Obj06704 *)p)->f49BC);
    COMM_BTL_DEMO_GRAPHIC_Draw(((struct Obj06704 *)p)->f49B4);
    (((struct Obj06704 *)p)->f49D4)++;
    BG_SYS_ResetSlot(3,0,((struct Obj06704 *)p)->f49D4/2);
    return 0;
}
