/*
 * function: func_021C95CC
 * address: 0x021C95CC
 * packet: pkt_ov128_021C95CC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021C9626 before next label 021C9628.
 * symbols:
 *   func_021C9BEC 0x021C9BEC thumb ov128
 *   func_021C6DF8 0x021C6DF8 thumb ov128
 *   func_021C9BF8 0x021C9BF8 thumb ov128
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj02842.h"
typedef unsigned char u8;
typedef signed short s16;
extern void func_021C9BEC(u8 *,void *,void *,int,s16,int);
typedef unsigned int   u32;
extern void func_021C6DF8(u8 *p, u32 a);
extern void func_021C9BF8(u8 *p, u8 *q, int idx);
extern void func_02040618(u32 layer, u32 a, u32 b);
int func_021C95CC(u8 *p,void *a,void *b,int c)
{
    int value=((struct Obj02842 *)p)->f4;
    int offset;
    if(value>8) {
        func_021C9BEC(p,a,b,0,((struct Obj02842 *)p)->f0,c);
        func_021C6DF8(b,1);
        func_021C9BF8(p,b,255);
        return 1;
    }
    offset=(value*256)/8;
    if(((struct Obj02842 *)p)->f8==2) offset=-offset;
    func_02040618(3,0,offset);
    ((struct Obj02842 *)p)->f4=((struct Obj02842 *)p)->f4+1;
    return 0;
}
