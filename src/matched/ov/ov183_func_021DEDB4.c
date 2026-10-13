/*
 * function: func_021DEDB4
 * address: 0x021DEDB4
 * packet: pkt_ov183_021DEDB4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF3DC 0x021DF3DC thumb ov183
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DED64 0x021DED64 thumb ov183
 *   func_021DF8F0 0x021DF8F0 thumb ov183
 *   func_021DF41C 0x021DF41C thumb ov183
 *   func_02034714 0x02034714 arm
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   d_021E3964 0x021E3964 data a1
 */
#include "../include/Obj03880.h"
#include "../include/Obj24605.h"
#include "../include/Obj24606.h"
#include "../include/Obj24607.h"
#include "../include/Obj24608.h"
#include "../include/Obj24609.h"
#include "../include/Obj24610.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_021DF3DC(char *, int);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int, int, int *);
extern void func_021F9BA0(unsigned *ctx);
extern int *func_021FD73C(int *p, int v);
extern void func_021DED64(int *p, int *state, char *q);
extern int func_021DF8F0(int x, int y);
extern int func_021DF41C(char *p);
extern void func_02034714(const char *, u32, const char *);
extern void func_021F9BF4(unsigned *, unsigned);
extern const char d_021E3964[];
void func_021DEDB4(int *task, int *state, char *p)
{
    u32 x,y;
    func_021DF3DC(p+0x28,((struct Obj03880 *)p)->f18);
    if (TOUCHPANEL_GetPointTrg(&x,&y)) {
        if (func_021FB4B4((unsigned int *)(((struct Obj03880 *)p)->f4),x,y)) {
            int args[2];
            args[0]=x; args[1]=y;
            func_021FD860(((struct Obj03880 *)p)->f20,1,args);
            func_021F9BA0(((struct Obj24605 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14);
            func_021FD73C(task,(int)func_021DED64);
        }
        if (func_021DF8F0(x,y)) {
            u32 selection;
            int args[2];
            selection=func_021DF41C(p+0x28);
            if (selection>=((struct Obj24607 *)(*(char * *)&((struct Obj24606 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f1718)
                func_02034714(d_021E3964,0,d_021E3964);
            ((struct Obj24609 *)(*(char * *)&((struct Obj24608 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f171C=selection;
            func_021F9BF4(*(unsigned * *)&((struct Obj24610 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14,2);
            func_021FD73C(task,(int)func_021DED64);
            args[0]=x; args[1]=y;
            func_021FD860(((struct Obj03880 *)p)->f20,1,args);
        }
    }
}
