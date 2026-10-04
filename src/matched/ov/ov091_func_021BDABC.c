/*
 * function: func_021BDABC
 * address: 0x021BDABC
 * packet: pkt_ov091_021BDABC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: two-halfword coordinate struct keeps its address sp-relative; int alias added 4 B.
 * symbols:
 *   func_0205121C 0x0205121C arm
 *   func_0203D7C8 0x0203D7C8 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051230 0x02051230 arm
 *   func_021BB3D4 0x021BB3D4 thumb ov091
 *   func_020515B4 0x020515B4 arm
 *   d_021BED58 0x021BED58 data ov091 a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj06215.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { s16 x,y; } Pair;
extern int func_0205121C(u32,u32,u32);
extern void *func_0203D7C8(u32,u32,const char *,u16);
extern int func_02050C04(int,int,int,int);
extern int func_020056BC(void);
extern void func_02051230(u8 *,u32,u32,u32);
extern void func_021BB3D4(u8 *,int,Pair *);
extern int func_020515B4(void *p, int b, int c);
extern u8 d_021BED58[];
#define W(o) (*(u32 *)(p+(o)))
void func_021BDABC(u8 *p)
{
    u8 count;
    int member;
    int handle;
    Pair xy;
    int vec[3];
    u8 i;
    count = 0;
    member = 0x1c;
    if (W(0x264)-1 <= 1) {
        member = 0x1b;
        count = 3;
        p[0x269] = 0x41;
    } else if (W(0x264) == 3) {
        count = 2;
        p[0x269] = 0x26;
    }
    handle = func_0205121C(0x4c,member,((struct Obj06215 *)p)->f0);
    W(0x25c) = (u32)func_0203D7C8(((struct Obj06215 *)p)->f0,0x5000,(const char *)d_021BED58,0xea);
    W(0x260) = func_02050C04(W(0x25c),0x5000,0,((struct Obj06215 *)p)->f0);
    func_02051230((u8 *)W(0x260),handle,0,func_020056BC());
    func_021BB3D4(p,*(int *)(p+W(0x2c)*4+0x160),&xy);
    xy.x -= 0x28;
    xy.y += 4;
    if (xy.x > 0) vec[0] = (int)(0.5f+(float)(xy.x<<12))/0x26;
    else vec[0] = (int)((float)(xy.x<<12)-0.5f)/0x26;
    if (xy.y > 0) vec[1] = (int)(0.5f+(float)(xy.y<<12))/0x26;
    else vec[1] = (int)((float)(xy.y<<12)-0.5f)/0x26;
    vec[2] = 0x40000;
    for (i=0;i<count;i++) func_020515B4((void *)W(0x260),i,(int)vec);
}
