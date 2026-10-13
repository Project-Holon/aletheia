/*
 * function: P_STA_RIBBON_Hide
 * address: 0x021D90C0
 * packet: pkt_ov131_021D90C0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   P_STA_OAM_SetBitmapActorsEnabled 0x021DBCA4 thumb ov131
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj23151.h"
#include "../include/Obj23152.h"

typedef unsigned short u16;
typedef unsigned char  u8;
struct Obj;
extern void P_STA_OAM_SetBitmapActorsEnabled(u8 *p, int v);
extern void func_02041300(unsigned int,int,int,int,unsigned char,unsigned char,unsigned char);
extern void func_020409B4(unsigned int);
extern void func_0204B878(struct Obj *p, u16 value);
void P_STA_RIBBON_Hide(unsigned char *a, unsigned char *p)
{
    unsigned char i;
    for(i=0;i<10;i++) P_STA_OAM_SetBitmapActorsEnabled(*(void **)(p+0x80+i*20),0);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    ((struct Obj23152 *)p)->f0=0;
    func_0204B878(((struct Obj23151 *)a)->f180,2);
}
