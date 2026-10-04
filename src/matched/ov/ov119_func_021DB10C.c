/*
 * function: func_021DB10C
 * address: 0x021DB10C
 * packet: pkt_ov119_021DB10C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021E131C 0x021E131C thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB030 0x021DB030 thumb ov119
 *   d_021E758C 0x021E758C data a4
 */
#include "../include/Obj00001.h"
typedef struct { int a,b; } Pair;
extern const Pair d_021E758C;
extern int func_021E12AC(char *p);
extern void func_021E131C(void *,Pair *,int,int,int);
extern void func_021E4E64(int a, char *p, int b);
extern void func_021D8E84(void *,int);
extern void func_021DB030(char *p);
void func_021DB10C(char *p)
{
    if(func_021E12AC(p)) {
        Pair t=d_021E758C;
        func_021E131C(p,&t,2,0x20,0xc);
        ((struct Obj00001 *)p)->f1080=-1;
        func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,0);
        func_021D8E84(p,(int)func_021DB030);
    }
}
