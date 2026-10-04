/*
 * function: func_021C0698
 * address: 0x021C0698
 * packet: pkt_ov099_021C0698
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9B64 0x021B9B64 thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020200CC 0x020200CC thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021C23D8 0x021C23D8 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 */
#include "../include/Obj00008.h"
extern void func_021B9B64(char *);
extern int func_021BA928(char *);
typedef signed int     s32;
typedef unsigned short u16;
struct Obj;
extern s32 func_020200CC(struct Obj *o);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021BA8EC(char *);
extern void func_021C23C8(void *a, void *b);
extern void func_021C23D8(char *,int);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201F868(void *p);
typedef enum { K274=0x274 } Off;
int func_021C0698(char *p,int ret) {
    int r;
    Off o=K274;
    func_021B9B64(p+o);
    if(!func_021BA928(p))return ret;
    r=func_020200CC((struct Obj *)(*(int *)&((struct Obj00008 *)p)->fBC));
    switch(r) {
    case -1: return ret;
    case -2:
        func_020061E4(1356);
        *(int *)(p+(o-0xa8))=28;
        break;
    default:
        func_020061E4(1356);
        func_021C18C8(p,2,r);
        *(int *)(p+(o-0xa8))=11;
        func_021BA8EC(p);
        break;
    }
    if(((struct Obj00008 *)p)->f1CC==11){func_021C23C8(p,(void *)(-1));func_021C23D8(p,1);}
    ((struct Obj00008 *)p)->f1A4=(void *)func_021BA8BC(((struct Obj00008 *)p)->f1A4);
    func_0202020C((struct Obj *)(*(int *)&((struct Obj00008 *)p)->fBC),0,(u16 *)(p+0x234+2* ((struct Obj00008 *)p)->f240));
    func_0201F868((void *)(*(int *)&((struct Obj00008 *)p)->fB8));
    return ret;
}
