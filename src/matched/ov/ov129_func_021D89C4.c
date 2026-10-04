/*
 * function: func_021D89C4
 * address: 0x021D89C4
 * packet: pkt_ov129_021D89C4
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: copy the table through a second aggregate, retain its indexed read,
 * and initialize i before selecting q. The copy folds into the existing slot.
 * symbols:
 *   func_021D8950 0x021D8950 thumb ov129
 *   d_021DA744 0x021DA744 data a4
 */
#include "../include/Obj01938.h"
typedef unsigned short u16;
typedef struct { int rows[2][3]; } Table;
extern const Table d_021DA744;
extern void func_021D8950(char *,int);
void func_021D89C4(char *p)
{
    int i,j,n,sum;
    Table t;
    Table copy;
    const int *q;
    ((struct Obj01938 *)p)->f2FC=1;
    ((struct Obj01938 *)p)->f21C=0;
    n=((struct Obj01938 *)p)->f330;
    ((struct Obj01938 *)p)->f21E=n;
    ((struct Obj01938 *)p)->f220=n;
    n+=((struct Obj01938 *)p)->f334;
    ((struct Obj01938 *)p)->f222=n;
    ((struct Obj01938 *)p)->f224=n;
    ((struct Obj01938 *)p)->f226=((struct Obj01938 *)p)->f338+n;
    func_021D8950(p,1);
    for(i=0;i<3;i++) ((struct Obj01938 *)p)->f23C+=*(int *)(p+i*4+0x330);
    t=d_021DA744;
    n=0;
    copy=t;
    if(((struct Obj01938 *)p)->f330!=4) n=1;
    i=0;
    q=copy.rows[n];
    for(;i<3;i++) *(u16 *)(p+i*2+0x214)=copy.rows[n][i];
    *(u16 *)(p+i*2+0x214)=q[i-1];
    sum=0;
    for(i=0;i<2;i++) {
        sum+=*(int *)(p+i*4+0x330);
        *(int *)(p+i*28+0x150)=sum-1;
    }
    i=0;
    n=0;
    do {
        for(j=0;j<*(int *)(p+i*4+0x330);j++) {
            *(int *)(p+n*28+4)=i+1;
            n++;
        }
        i++;
    } while(n<((struct Obj01938 *)p)->f23C);
}
