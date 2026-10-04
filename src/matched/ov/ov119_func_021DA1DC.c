/*
 * function: func_021DA1DC
 * address: 0x021DA1DC
 * packet: pkt_ov119_021DA1DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD3D4 0x021DD3D4 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA1B4 0x021DA1B4 thumb ov119
 */
#include "../include/Obj08053.h"

typedef unsigned short u16;
struct Entry;
extern int func_021DD3D4(const char *p, int n, int a, int b);
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern void func_021D8E84(void *,int);
extern void func_021DA1B4(char *p);
void func_021DA1DC(char *p) {
    int v=0;
    int n;
    if(((struct Obj08053 *)p)->fF88==((struct Obj08053 *)p)->f630) v=1;
    n=func_021DD3D4(p,0,((struct Obj08053 *)p)->fF84,((struct Obj08053 *)p)->fF88);
    if(n!=-1) {
        if(func_0203D3A8(func_020399A8(),n+0xC13,1,(u32)(&v))) {
            func_021D8E84(p,(int)func_021DA1B4);
            return;
        }
    } else func_021D8E84(p,(int)func_021DA1B4);
}
