/*
 * function: func_021F3BD4
 * address: 0x021F3BD4
 * packet: pkt_ov194_021F3BD4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: unsigned result minus two tests the contiguous range; point precedes x/y declarations.
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021F265C 0x021F265C thumb ov194
 *   func_021F2614 0x021F2614 thumb ov194
 *   func_020355D8 0x020355D8 arm
 */
#include "../include/Obj00117.h"
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_021F265C(char *,int *,int *);
extern unsigned func_021F2614(char *,int *,unsigned short *);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
int func_021F3BD4(char *p,int *out) {
    int point[2],u;
    unsigned x,y;
    if (((struct Obj00117 *)p)->f118==0) {
        if (func_02035D20(&x,&y)) {
            point[0]=x; point[1]=y;
            if (func_021F265C(p,point,(int *)(p+0xd8))) {
                if (func_021F2614(p,(int *)(p+0xd8),0)-2<=3) {
                    u=((struct Obj00117 *)p)->fD8;
                    out[3]=((struct Obj00117 *)p)->fDC;
                    out[1]=1; out[2]=u;
                    func_020355D8(1);
                    return 1;
                }
            }
        }
    }
    return 0;
}
