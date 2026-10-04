/*
 * function: func_021DD428
 * address: 0x021DD428
 * packet: pkt_ov119_021DD428
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Separate two-by-three struct fields recompute the side offset;
 * raw combined offsets cached it in ip and produced 208 rather than 204 bytes.
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   func_021DF918 0x021DF918 thumb ov119
 *   d_021E80E0 0x021E80E0 data ov119 a4
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020173EC(void);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082D44(void *,const void *,int);
extern void func_021DF918(void *,int,void *);
extern const char d_021E80E0[];
typedef struct State {
    char pad[0xfa4];
    int a[2][3];
    int b[2][3];
    char gap[4];
    void *value[2][3];
} State;
int func_021DD428(State *p,int side,int a,int b,void *value)
{
    int i;
    for(i=0;i<3;i++) {
        if(a==p->a[side][i] && b==p->b[side][i])
            return -1;
    }
    for(i=0;i<3;i++) {
        if(p->a[side][i]==-1 || i==2) {
            p->a[side][i]=a;
            p->b[side][i]=b;
            if(p->value[side][i]==0)
                p->value[side][i]=func_02030734(((struct Obj00001 *)p)->f5F4,func_020173EC(),1,d_021E80E0,0x14c);
            func_02082D44(value,p->value[side][i],func_020173EC());
            func_021DF918(p,side,value);
            return i;
        }
    }
    return -1;
}
