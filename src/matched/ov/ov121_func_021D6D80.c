/*
 * function: func_021D6D80
 * address: 0x021D6D80
 * packet: pkt_ov121_021D6D80
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D6DB4 0x021D6DB4 thumb ov121
 */
#include "../include/Obj00326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D9F08(u8 *,int,int,int);
extern void func_021D81B0(u8 *,u32,int);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021D6DB4(void *,int *);
void func_021D6D80(void *a,int b,u8 *p)
{
    func_021D9F08(*(u8 * *)&((struct Obj00326 *)p)->f284,((struct Obj00326 *)p)->f3A4,79,0);
    func_021D81B0(p,0,29);
    func_021DA8B0(a,(u32)func_021D6DB4);
}
