/*
 * function: func_021B9BB0, func_021B9BFC
 * unit: yes
 * address: 0x021B9BB0
 * packet: pkt_ov222_021B9BB0
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * function_starts: 021B9BFC
  * extent: lead 74B; 2 padding bytes; approved follower 30B; 2 terminal zero bytes at 021B9C1A outside TU.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 */
#include "../include/Obj02560.h"
#include "../include/Obj08457.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
struct PrintSys;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned);
void func_021B9BB0(char*p)
{
    u8 i;
    for(i=0;i<5;i++){
        char*q=p+i*4;
        if(((struct Obj08457 *)q)->f30==0){
            if(func_0201C6C4(*(void* *)&((struct Obj02560 *)p)->f10,func_02045770(*(void* *)&((struct Obj08457 *)q)->f1C))==0){
                void*h=*(void* *)&((struct Obj08457 *)q)->f1C;
                BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);func_02041B6C(func_02045730(h));
                ((struct Obj08457 *)q)->f30=1;
            }
        }
    }
}
int func_021B9BFC(char*p)
{
    u8 i;
    for(i=0;i<5;i++){
        if(*(int*)(p+i*4+0x30)==0)return 0;
    }
    return 1;
}
