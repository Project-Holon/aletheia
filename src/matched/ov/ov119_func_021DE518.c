/*
 * function: func_021DE518
 * address: 0x021DE518
 * packet: pkt_ov119_021DE518
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_021E1D68 0x021E1D68 thumb ov119
 *   func_021E6440 0x021E6440 thumb ov119
 *   func_021DEBD4 0x021DEBD4 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE3E8 0x021DE3E8 thumb ov119
 */
#include "../include/Obj03775.h"
typedef unsigned short u16;
typedef struct { char pad[0xfd8]; void *obj[2][3]; } State;
extern int func_020221A4(void *);
typedef unsigned int   u32;
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_021E1D68(char *p, void *a);
extern void func_021E6440(int p, int a, int b);
extern void func_021DEBD4(void *);
extern void func_0202208C(int,int,int,int,int,int,int);
extern int func_021D8980(char *p);
extern void func_021DD09C(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DE3E8(char *p);
void func_021DE518(State *p)
{
    char *b=(char *)p;
    u16 idx;
    int col,row;
    void *obj;
    int other;
    if(func_020221A4(p)) {
        idx=(u16)((struct Obj03775 *)b)->f10A0;
        col=idx%3; row=idx/3;
        other=1-row;
        obj=p->obj[other][col];
        b[0x11f3]=1;
        if(obj && func_02017E1C(obj,169,0)) {
            func_021E1D68((char *)p,obj); func_021E6440((int)p,row,col);
        }
        func_021DEBD4(p);
        func_0202208C(3,1,1,0,6,1,((struct Obj03775 *)b)->f5F4);
        func_021D8980((char *)p); func_021DD09C((char *)p);
        func_021D8E84(p,(int)func_021DE3E8);
    }
}
