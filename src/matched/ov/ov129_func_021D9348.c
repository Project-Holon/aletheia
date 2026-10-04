/*
 * function: func_021D9348
 * address: 0x021D9348
 * packet: pkt_ov129_021D9348
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_021DA158 0x021DA158 thumb ov129
 *   func_0204B878 0x0204B878 arm
 *   func_0201F35C 0x0201F35C thumb
 *   func_02045AA8 0x02045AA8 arm
 *   func_02045808 0x02045808 arm
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 */
#include "../include/Obj06479.h"
#include "../include/Obj08137.h"

typedef signed int     s32;
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021DA158(int x, int flag);
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0201F35C(void *ctx, s32 n, u32 kind, u32 mode, u32 flag);
extern void func_02045AA8(struct U16Vec *dst, struct U16Vec *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_021D8AF4(char *,int);
void func_021D9348(char *p)  {
    int i;
    char *q;
    void *v=func_020457B0(100,50);
    ((struct Obj08137 *)p)->f1F8=1;
    ((struct Obj08137 *)p)->f210=0;
    for(i=0;i<((struct Obj08137 *)p)->f23C;i++)  {
        q=p+i*28;
        if(((struct Obj06479 *)q)->f0==0)  {
            ((struct Obj06479 *)q)->f0=1;
            func_0204B878((struct Obj *)(((struct Obj06479 *)q)->fC),func_021DA158(1,((struct Obj06479 *)q)->f8));
        }
        func_0201F35C(v,((struct Obj06479 *)q)->f0-1,1,1,1);
        func_02045AA8((struct U16Vec *)(((struct Obj08137 *)p)->f348),v);
    }
    func_02045808(v);
    func_021D8AF4(p,3);
}
