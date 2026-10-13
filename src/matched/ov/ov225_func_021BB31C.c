/*
 * function: func_021BB31C
 * address: 0x021BB31C
 * packet: pkt_ov225_021BB31C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021BB3FA alignment, existing matched follower 021BB3FC.
 * Lever: switch body order 1 then 0 preserves the shared store block.
 * symbols:
 *   func_021BB504 0x021BB504 thumb ov225
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   func_021BB53C 0x021BB53C thumb ov225
 */
#include "../include/Obj00691.h"
#include "../include/Obj26231.h"
#include "../include/Obj26232.h"
#include "../include/Obj26233.h"
#include "../include/Obj26234.h"
#include "../include/Obj26235.h"
#include "../include/Obj26239.h"
typedef unsigned char u8;
extern void func_021BB504(char *);
extern void func_021B9FBC(char *);
extern unsigned func_021BA158(char *p);
extern unsigned func_021BA154(char *p);
typedef unsigned int   u32;
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern int func_021BB53C(char *);
int func_021BB31C(char *p)
{
    int done = 0;
    u8 i;
    if (((struct Obj00691 *)p)->f1C==0) done=1;
    else if (((struct Obj00691 *)p)->f1C>0) {
        if (((struct Obj00691 *)p)->f1C==1) func_021BB504(p);
        --((struct Obj00691 *)p)->f1C;
    }
    if (((struct Obj00691 *)p)->f18==0 || ((struct Obj00691 *)p)->f18==2) {
        func_021B9FBC(*(char * *)&((struct Obj26231 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34);
        if (((struct Obj00691 *)p)->f18==0) {
            if (func_021BA158(*(char * *)&((struct Obj26232 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34)!=-1)
                ((struct Obj00691 *)p)->f18=2;
        } else {
            int result=func_021BA154(*(char * *)&((struct Obj26233 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34);
            if (result!=-1) {
                switch (result) {
                case 1: ((struct Obj26234 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=1; break;
                case 0: ((struct Obj26235 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=0; break;
                }
                ((struct Obj00691 *)p)->f18=1;
                ((struct Obj00691 *)p)->f1C=1;
            }
        }
    }
    if (((struct Obj00691 *)p)->f18==0 || ((struct Obj00691 *)p)->f18==3) {
        for (i=0;i<2;i++) APP_TASKMENU_WIN_Update((u8 *)(*(char **)(p+0xc+i*4)));
        if (((struct Obj00691 *)p)->f18==0) {
            if (func_021BB53C(p)) ((struct Obj00691 *)p)->f18=3;
        } else {
            if (APP_TASKMENU_WIN_IsFinish((u8 *)(*(char **)(p+0xc+**(u8 * *)&((struct Obj00691 *)p)->f0*4)))) {
                unsigned value;
                if (**(u8 * *)&((struct Obj00691 *)p)->f0==0) value=2;
                else if (**(u8 * *)&((struct Obj00691 *)p)->f0==1) value=3;
                else goto finish;
                ((struct Obj26239 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=value;
finish:
                ((struct Obj00691 *)p)->f18=1;
                ((struct Obj00691 *)p)->f1C=1;
            }
        }
    }
    return done;
}
