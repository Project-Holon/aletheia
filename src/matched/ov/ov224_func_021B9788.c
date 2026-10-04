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
 *   func_0204E804 0x0204E804 arm
 *   func_0204E720 0x0204E720 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021B9A44 0x021B9A44 thumb ov224
 */
#include "../include/Obj14799.h"

typedef unsigned int u32;
extern int func_0204E804(void);
extern u32 func_020362DC(void);
typedef unsigned char  u8;
struct PrintSys;
extern void func_0204E720(int,int,int,int);
extern void func_020355D8(u8 v);
extern int func_02035D20(int *,int *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021B9A44(void *);
int func_021B9788(void *a,unsigned *state,int b,char *p)
{
    int x,y,flag;
    switch(*state) {
    case 0: *state=1; break;
    case 1: if(!func_0204E804()) *state=2; break;
    case 2:
        flag=0;
        if(func_020362DC()&3) { func_020355D8(0); flag=1; }
        else if(func_02035D20(&x,&y)) { func_020355D8(1); flag=1; }
        if(flag) { *state=3; func_0204E720(3,0,16,0); }
        break;
    case 3: if(!func_0204E804()) *state=4; break;
    case 4: return 1;
    }
    func_0201C4E4(((struct Obj14799 *)p)->f10); func_021B9A44(((struct Obj14799 *)p)->f8);
    return 0;
}
void func_021B9820(void) {}
