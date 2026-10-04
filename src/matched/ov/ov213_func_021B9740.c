/*
 * function: func_021B9740
 * address: 0x021B9740
 * packet: pkt_ov213_021B9740
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA7D0 0x021BA7D0 thumb ov213
 *   func_021B6144 0x021B6144 thumb ov067
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BAC68 0x021BAC68 thumb ov213
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../include/Obj06704.h"
extern void func_021BA7D0(void *),func_021BAC68(void *),func_02041EE4(unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct PrintSys;
struct S;
extern int func_021B6144(struct S *s);
extern u32 func_0201C4E4(struct PrintSys *ps);
int func_021B9740(int a,int b,int c,char *p)
{
    func_021BA7D0(p+0x24);
    if(func_021B6144(((struct Obj06704 *)p)->f49C4)) return 1;
    func_0201C4E4(((struct Obj06704 *)p)->f49BC);
    func_021BAC68(((struct Obj06704 *)p)->f49B4);
    (((struct Obj06704 *)p)->f49D4)++;
    func_02041EE4(3,0,((struct Obj06704 *)p)->f49D4/2);
    return 0;
}
