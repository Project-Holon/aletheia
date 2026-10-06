/*
 * function: func_021C6180
 * address: 0x021C6180
 * packet: pkt_ov128_021C6180
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   id127 0x0000007F data
 *   id67 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021C63EC 0x021C63EC thumb ov128
 *   func_021C658C 0x021C658C thumb ov128
 *   func_020056A0 0x020056A0 thumb
 *   func_021C6354 0x021C6354 thumb ov128
 */
#include "../include/Obj06476.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern char id127[],id67[];
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(void *,int,int);
extern void func_02082BCC(void *,int,int);
extern void func_021C63EC(u8 *p, const u32 *q, int heap);
extern void func_021C658C(char *p, void *q, int heap);
extern void *func_020056A0(void *,void *,int);
extern void func_021C6354(void *p, char *q);
int func_021C6180(void *p,int unused,void *q)
{
    char *v;
    func_02034AC4((u32)id127); func_02034AC4((u32)id67);
    func_0203064C(1,52,0xc0000);
    v=func_0203159C(p,0x5b0,52);
    func_02082BCC(v,0,0x5b0);
    ((struct Obj06476 *)v)->f1F8=q; ((struct Obj06476 *)v)->f5A8=0;
    func_021C63EC((u8 *)(v+0x190),((struct Obj06476 *)v)->f1F8,52);
    func_021C658C(v+4,v+0x190,52);
    if(((struct Obj06476 *)v)->f5A8==0) ((struct Obj06476 *)v)->f5A8=func_020056A0(func_021C6354,v,16);
    return 1;
}
