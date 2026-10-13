/*
 * function: func_021B9788, func_021B9820
 * unit: yes
 * trailing: parent-cleared Thumb empty stub 021B9820; 021B9822 is zero alignment.
 * address: 0x021B9788
 * packet: pkt_ov224_021B9788
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_IsActive 0x0204E804 arm
 *   FADE_Start 0x0204E720 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021B9A44 0x021B9A44 thumb ov224
 */
#include "../include/Obj14799.h"

typedef unsigned int u32;
extern int FADE_IsActive(void);
extern u32 KEY_GetTrg(void);
typedef unsigned char  u8;
struct PrintSys;
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void func_020355D8(u8 v);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_021B9A44(void *);
int func_021B9788(void *a,unsigned *state,int b,char *p)
{
    int x,y,flag;
    switch(*state) {
    case 0: *state=1; break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2:
        flag=0;
        if(KEY_GetTrg()&3) { func_020355D8(0); flag=1; }
        else if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))) { func_020355D8(1); flag=1; }
        if(flag) { *state=3; FADE_Start(3,0,16,0); }
        break;
    case 3: if(!FADE_IsActive()) *state=4; break;
    case 4: return 1;
    }
    PRINTSYS_QUE_Main(((struct Obj14799 *)p)->f10); func_021B9A44(((struct Obj14799 *)p)->f8);
    return 0;
}
void func_021B9820(void) {}
