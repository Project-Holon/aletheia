/*
 * function: func_021C6208
 * address: 0x021C6208
 * packet: pkt_ov128_021C6208
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6EC0 0x021C6EC0 thumb ov128
 *   func_021C76F8 0x021C76F8 thumb ov128
 *   func_021C8C04 0x021C8C04 thumb ov128
 *   func_021C8E2C 0x021C8E2C thumb ov128
 *   func_021C9244 0x021C9244 thumb ov128
 *   func_021C6638 0x021C6638 thumb ov128
 */
#include "../include/Obj03279.h"
#include "../include/Obj23062.h"
#include "../include/Obj23063.h"
typedef unsigned char u8;
extern int func_021C6EC0(void *,void *,void *,int);
extern int func_021C76F8(void *,void *,void *,int);
extern int func_021C8C04(void *,void *,void *,void *,int);
extern int func_021C8E2C(void *,void *,void *,int);
extern int func_021C9244(void *,void *,void *,int);
extern void func_021C6638(void *);
int func_021C6208(int result,int *stage,int unused,char *p)
{
    switch(*stage) {
    case 0:
        switch(((struct Obj03279 *)p)->f0) {
        case 0: result=func_021C6EC0(p+0x1fc,p+0x190,p+4,52); break;
        case 1: result=func_021C76F8(p+0x24c,p+0x190,p+4,52); break;
        case 2: result=func_021C8C04(p+0x3f8,p,p+0x190,p+4,52); break;
        case 3: result=func_021C8E2C(p+0x404,p+0x190,p+4,52); break;
        case 4: result=func_021C9244(p+0x420,p+0x190,p+4,52); break;
        case 5: ((struct Obj23062 *)(*(char * *)&((struct Obj03279 *)p)->f1F8))->f4=0; return 1;
        case 6: ((struct Obj23063 *)(*(char * *)&((struct Obj03279 *)p)->f1F8))->f4=1; return 1;
        }
        if(result==1) {
            *(int *)&((struct Obj03279 *)p)->f0=((struct Obj03279 *)p)->f199;
            ((struct Obj03279 *)p)->f198=((struct Obj03279 *)p)->f19A;
            ((struct Obj03279 *)p)->f5AC=4;
            *stage=1;
        }
        break;
    case 1:
        if(--((struct Obj03279 *)p)->f5AC<=0) *stage=0;
        break;
    }
    func_021C6638(p+4);
    return 0;
}
