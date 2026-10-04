/*
 * unit: yes
 * function: func_021D9FD4, func_021DA030, func_021DA034
 * address: 0x021D9FD4
 * packet: pkt_ov123_021D9FD4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead with store-and-return follower 021DA030 and tailcall follower 021DA034.
 * symbols:
 *   func_021DA1EC 0x021DA1EC thumb ov123
 */
#include "../include/Obj03804.h"
#include "../include/Obj22984.h"
extern void func_021DA1EC(char *p);
void func_021DA030(char *, int, int);
void func_021DA034(char *, int, int);
int func_021D9FD4(char *p, int n)
{
    switch (n) {
    case 503:
        ((struct Obj03804 *)p)->f70=0xfff1;
        func_021DA034(p,(int)func_021DA1EC,0x99);
        return 1;
    case 502:
        ((struct Obj03804 *)p)->f70=0xfff2;
        func_021DA034(p,(int)func_021DA1EC,0x9d);
        return 1;
    default:
        if (n>=400) {
            ((struct Obj03804 *)p)->f70=0xfff3;
            func_021DA034(p,(int)func_021DA1EC,0xa3);
            return 1;
        }
        return 0;
    }
}
void func_021DA030(char *p, int n, int unused)
{
    ((struct Obj22984 *)p)->f30=n;
}
void func_021DA034(char *p, int n, int unused)
{
    func_021DA030(p,n,unused);
}
