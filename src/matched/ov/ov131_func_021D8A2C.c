/*
 * function: func_021D8A2C
 * address: 0x021D8A2C
 * packet: pkt_ov131_021D8A2C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): the p+0x64 store precedes the p+0x58 store; with source order 58/64/68 the
 *   allocator hoists constant 0 into r7 instead.
 * symbols:
 *   func_021D8E24 0x021D8E24 thumb ov131
 *   func_020362DC 0x020362DC arm
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021D8EA8 0x021D8EA8 thumb ov131
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_021D964C 0x021D964C thumb ov131
 *   func_021D949C 0x021D949C thumb ov131
 *   func_021D8AD0 0x021D8AD0 thumb ov131
 *   func_021D8CD0 0x021D8CD0 thumb ov131
 */
#include "../include/Obj00091.h"
#include "../include/Obj00136.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D8E24(u8 *,u8 *);
extern u32 func_020362DC(void);
extern void func_021D5A9C(char *p, int a);
extern void func_021D8EA8(u8 *,u8 *);
extern unsigned int func_021D9428(unsigned char *p, unsigned int target);
extern void func_020061E4(u32 a);
extern void func_021D964C(u8 *,u8 *);
extern void func_021D949C(u8 *,u8 *);
extern int func_021D8AD0(u8 *,u8 *);
extern void func_021D8CD0(u8 *,u8 *);
void func_021D8A2C(u8 *a,u8 *p)
{
    int index;
    if(((struct Obj00136 *)a)->f44==1) {
        if(p[0x10]==0) return;
        index=func_021D8E24(a,p);
        if(func_020362DC()!=1 && index==-1) return;
        ((struct Obj00091 *)p)->f5C=0;
        func_021D5A9C((char *)a,0);
        if(func_020362DC()==1) {
            func_021D8EA8(a,p);
            a[0x1c]=0;
        } else {
            ((struct Obj00091 *)p)->f64=1;
            p[0x58]=(u8)index;
            ((struct Obj00091 *)p)->f68=1;
            p[0x59]=func_021D9428(p,(u8)index);
            func_021D5A9C((char *)a,0);
            a[0x1c]=1;
        }
        func_020061E4(0x54c);
        func_021D964C(a,p);
        func_021D949C(a,p);
    } else {
        if(*(u32 *)&((struct Obj00091 *)p)->f8==0 && func_021D8AD0(a,p)==0) func_021D8CD0(a,p);
    }
}
