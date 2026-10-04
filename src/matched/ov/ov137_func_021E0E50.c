/*
 * unit: yes
 * function: func_021E0E50,func_021E0E8C
 * address: 0x021E0E50
 * packet: pkt_ov137_021E0E50
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: unlabelled bool scan follower at 0x021E0E8C, through pool at 0x021E0EA8.
 * symbols:
 *   func_021E0E2C 0x021E0E2C thumb ov137
 */
#include "../include/Obj23788.h"
#include "../include/Obj23790.h"
extern void func_021E0E2C(char *p, int value);
typedef struct { int active; char rest[0xb0]; } Record;
typedef struct { char pad[0x140]; Record records[1]; } Block;
void func_021E0E50(char *p)
{
    Block *base=(Block *)(p+0x1a0);
    int count=((struct Obj23788 *)p)->f30;
    int i;
    i=0;
    do {
        if (base->records[i].active) func_021E0E2C(p,(int)((char *)&base->records[i]));
        i++;
    } while (i<count);
}
int func_021E0E8C(char *p)
{
    int i;
    char *q=p+0xaf8;
    for (i=0;i<5;i++,q+=0x20) if (((struct Obj23790 *)q)->f0) return 1;
    return 0;
}
