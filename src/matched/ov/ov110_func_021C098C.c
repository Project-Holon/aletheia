/*
 * function: func_021C098C
 * address: 0x021C098C
 * packet: pkt_ov110_021C098C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C088C 0x021C088C thumb ov110
 *   data_021C39E0 0x021C39E0 data a4
 */
#include "../include/Obj05299.h"
extern void func_021C088C(void *,void *,void *,int);
extern unsigned short data_021C39E0[];
void func_021C098C(char *p) {
    int v;
    if (((struct Obj05299 *)p)->f1C) {
        v=1;
        if (((struct Obj05299 *)p)->f20<16) {
            v=(((struct Obj05299 *)p)->f20/4)%2;
            (((struct Obj05299 *)p)->f20)++;
        }
        if(v) ((struct Obj05299 *)p)->fC=0xfc00;
        else ((struct Obj05299 *)p)->fC=0x7c00;
    }
    func_021C088C(p+0xc,p+0xe,data_021C39E0,3);
}
