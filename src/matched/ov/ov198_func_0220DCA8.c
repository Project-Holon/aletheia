/*
 * function: func_0220DCA8
 * address: 0x0220DCA8
 * packet: pkt_ov198_0220DCA8
 * region: ov198
 * status: EXACT
 * symbols:
 *   d_02211B50 0x02211B50 data a1
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_0220BEB8 0x0220BEB8 thumb ov198
 *   func_0220CDF0 0x0220CDF0 thumb ov198
 *   func_0220C2F8 0x0220C2F8 thumb ov198
 *   func_02045334 0x02045334 arm
 *   func_0220C714 0x0220C714 thumb ov198
 *   func_0220C8F0 0x0220C8F0 thumb ov198
 *   func_0220C9F0 0x0220C9F0 thumb ov198
 *   func_0220CAF0 0x0220CAF0 thumb ov198
 *   func_0220CBF0 0x0220CBF0 thumb ov198
 *   func_0220CCF0 0x0220CCF0 thumb ov198
 *   func_0220C398 0x0220C398 thumb ov198
 *   func_0220C42C 0x0220C42C thumb ov198
 *   func_0220CFC4 0x0220CFC4 thumb ov198
 *   func_0220C694 0x0220C694 thumb ov198
 */
#include "../include/Obj00507.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B50[];
extern void func_0220BDA0(char *);
extern void func_0220BEB8(char *,int,int,u8,u8);
extern void func_0220CDF0(char *,int),func_0220C714(char *,int),func_0220C8F0(char *,int);
extern void func_0220C2F8(char *,int,int,u16,u8);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_0220C9F0(char *,int),func_0220CAF0(char *,int),func_0220CBF0(char *,int),func_0220CCF0(char *,int);
extern void func_0220C398(char *,int,int),func_0220C42C(char *,int,int),func_0220CFC4(char *,int),func_0220C694(char *,int,int);
void func_0220DCA8(char *p) {
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B50;
    func_0220BDA0(p);
    func_0220BEB8(p,0,(*(u8 **)p)[32],0,0);
    func_0220CDF0(p,(*(u8 **)p)[32]);
    func_0220C2F8(p,10,(*(u8 **)p)[32],0,0);
    func_02045334(((struct Obj00507 *)p)->f1FC0);
    func_0220C714(p,(*(u8 **)p)[32]);
    func_0220C8F0(p,(*(u8 **)p)[32]);
    func_0220C9F0(p,(*(u8 **)p)[32]);
    func_0220CAF0(p,(*(u8 **)p)[32]);
    func_0220CBF0(p,(*(u8 **)p)[32]);
    func_0220CCF0(p,(*(u8 **)p)[32]);
    func_0220C398(p,1,(*(u8 **)p)[32]);
    func_0220C42C(p,3,(*(u8 **)p)[32]);
    func_0220CFC4(p,(*(u8 **)p)[32]);
    func_0220C694(p,21,25);
}
