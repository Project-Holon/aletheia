/*
 * function: func_021D63F4
 * address: 0x021D63F4
 * packet: pkt_ov120_021D63F4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: one-word aggregate locals preserve the early address setup and merge.
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_021D6328 0x021D6328 thumb ov120
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   d_021D8920 0x021D8920 data a4
 *   d_021D891C 0x021D891C data a4
 *   d_021D8918 0x021D8918 data a4
 *   d_021D895C 0x021D895C data a4
 *   d_021D896C 0x021D896C data a4
 *   d_021D894C 0x021D894C data a4
 *   d_021D8954 0x021D8954 data a4
 *   d_021D8944 0x021D8944 data a4
 *   d_021D8964 0x021D8964 data a4
 */
#include "../include/Obj05350.h"
typedef unsigned char u8;
typedef struct Pair { int a,b; } Pair;
typedef struct Word { int a; } Word;
extern const Word d_021D8920,d_021D891C,d_021D8918;
extern const Pair d_021D895C,d_021D896C,d_021D894C,d_021D8954,d_021D8944,d_021D8964;
extern void MI_CpuCopy8(const void *,void *,unsigned int);
extern void func_021D6328(u8 *,int,int *,int *,int);
extern void DWCi_ScreenDC_FlushRange(void *,unsigned long);
extern void func_0207E5D0(void *,int,int);
extern void func_0207E468(void *,int,int);
void func_021D63F4(u8 *p,int flag,int mode)
{
    if(flag) {
        MI_CpuCopy8((void *)0x05000600,((struct Obj05350 *)p)->f124,0x200);
        MI_CpuCopy8((void *)0x05000400,((struct Obj05350 *)p)->f128,0x200);
        switch(mode) {
        case 2: {
            Word a={0};
            Word b=d_021D8920;
            func_021D6328(p,3,&a.a,&b.a,1);
            break;
        }
        case 0: {
            Word a=d_021D891C;
            Word b=d_021D8918;
            func_021D6328(p,3,&a.a,&b.a,1);
            break;
        }
        case 1: {
            Pair a=d_021D895C;
            Pair b=d_021D896C;
            func_021D6328(p,3,&a.a,&b.a,2);
            break;
        }
        }
        switch(mode) {
        case 0: case 2: {
            Pair a=d_021D894C;
            Pair b=d_021D8954;
            func_021D6328(p,1,&a.a,&b.a,2);
            break;
        }
        case 1: {
            Pair a=d_021D8944;
            Pair b=d_021D8964;
            func_021D6328(p,1,&a.a,&b.a,2);
            break;
        }
        }
    } else {
        DWCi_ScreenDC_FlushRange(((struct Obj05350 *)p)->f124,0x200);
        func_0207E5D0(((struct Obj05350 *)p)->f124,0,0x200);
        DWCi_ScreenDC_FlushRange(((struct Obj05350 *)p)->f128,0x200);
        func_0207E468(((struct Obj05350 *)p)->f128,0,0x200);
    }
}
