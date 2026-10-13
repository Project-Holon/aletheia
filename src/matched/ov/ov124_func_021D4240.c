/*
 * function: func_021D4240
 * address: 0x021D4240
 * packet: pkt_ov124_021D4240
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D43F8 0x021D43F8 thumb ov124
 *   func_021D4558 0x021D4558 thumb ov124
 *   func_021D46BC 0x021D46BC thumb ov124
 *   func_021D43F0 0x021D43F0 thumb ov124
 *   func_021D4940 0x021D4940 thumb ov124
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj00068.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021D43F8(char *);
extern void func_021D4558(char *);
extern void func_021D46BC(char *);
extern void func_021D43F0(void);
extern void *func_020056A0(void *,void *,int);
extern void func_021D4940(char *,int);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
void func_021D4240(char *p)
{
    ((struct Obj00068 *)p)->f10 = 0;
    func_021D43F8(p);
    func_021D4558(p);
    func_021D46BC(p);
    ((struct Obj00068 *)p)->f14 = func_020056A0(func_021D43F0,p,8);
    ((struct Obj00068 *)p)->f18 = 0;
    ((struct Obj00068 *)p)->fC = 1;
    func_021D4940(p,((struct Obj00068 *)p)->f18);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00068 *)p)->f0);
}
