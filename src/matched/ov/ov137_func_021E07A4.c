/*
 * function: func_021E07A4
 * address: 0x021E07A4
 * packet: pkt_ov137_021E07A4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initialize i before assigning count, then assign base separately; explicit signed Count enum retained. Count initializer compiled 5 differences; delayed base assignment restores the entry count load, counter zero and spill schedule. Renewed pass exact on run3, within two scheduling variants; prior permuter remains consumed.
 * symbols:
 *   func_021E09C0 0x021E09C0 thumb ov137
 *   func_021E0B38 0x021E0B38 thumb ov137
 *   func_021E0BC0 0x021E0BC0 thumb ov137
 */
#include "../include/Obj08221.h"
typedef unsigned short u16;
typedef enum { COUNT_ZERO=0, COUNT_NEGATIVE=-1 } Count;
extern void func_021E09C0(char *,int *,int,int);
extern void func_021E0B38(char *,char *,int);
extern void func_021E0BC0(char *,char *,int);
typedef struct { int active; char rest[0xb0]; } RecordA;
typedef struct { int active; char rest[0x78]; } RecordB;
typedef struct { int active; char rest[0x64]; } RecordC;
typedef struct {
    char pad[0x140];
    RecordA a[5];
    RecordB b[5];
    RecordC c[5];
} Block;
void func_021E07A4(char *p)
{
    Count count;
    int i=0;
    Block *base;
    count=((struct Obj08221 *)p)->f30;
    base=(Block *)(p+0x1a0);
    for (;i<count;i++) {
        if (base->a[i].active)
            func_021E09C0((char *)&base->a[i],(int *)(p+0x110),*(u16 *)(p+0x60+i*2)<<12,((struct Obj08221 *)p)->f5C);
        if (base->b[i].active)
            func_021E0B38(p,(char *)&base->b[i],((struct Obj08221 *)p)->f5C);
        if (base->c[i].active)
            func_021E0BC0(p,(char *)&base->c[i],i);
    }
}
