/*
 * function: func_021C01CC
 * address: 0x021C01CC
 * packet: pkt_ov099_021C01CC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_02156B8C 0x02156B8C thumb ov009
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0203C554 0x0203C554 arm
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021B9B64(char *);
extern int func_02156B8C(void);
typedef unsigned char  u8;
extern void func_0201FEF4(u8 *o);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_0203C554(u32 a);
extern void func_021BDD0C(void *p, int on);
extern void func_021C2408(char *);
extern void func_021BAADC(char *,int,int);
int func_021C01CC(char *p,int ret) {
    int r=func_021BA858(p);
    func_021B9B64(p+0x274);
    if(((struct Obj00008 *)p)->f1F0==-1 && func_02156B8C()!=-1){
        if(r==-1){func_0201FEF4((u8 *)(*(int *)&((struct Obj00008 *)p)->f108)); *(int *)&((struct Obj00008 *)p)->f108=0;}
        r=1;
    }
    if(r==-1)return ret;
    if(r==0){
        func_021C18C8(p,1,2);
        func_0203C554(1);
        func_021BDD0C(p,0);
        func_021C2408(p);
        ((struct Obj00008 *)p)->f1CC=11;
    }else {
        func_021BAADC(p,6,0);
        ((struct Obj00008 *)p)->f1CC=158;
    }
    return ret;
}
