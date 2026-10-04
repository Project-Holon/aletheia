/*
 * function: func_021E55BC
 * address: 0x021E55BC
 * packet: pkt_ov119_021E55BC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const camera s16 table keeps loads interleaved with stack arguments.
 * volatile: 0x04000060 hardware read-modify-write at 021E5644 and 021E5648.
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_021E5520 0x021E5520 thumb ov119
 *   d_021E7DE0 0x021E7DE0 data a4
 *   d_021E7CA0 0x021E7CA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_021E7C94 0x021E7C94 data a4
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_02046BE0 0x02046BE0 arm
 */
#include "../include/Obj08072.h"
typedef unsigned short u16;
typedef short s16;
typedef struct { int x,y,z; } Vec;
extern Vec d_021E7DE0, d_021E7CA0, d_021E7C94;
extern const s16 d_020A1EB8[];
extern void func_021E5520(void);
extern void func_02046440(int,int,int,int,u16,u16,void (*)(void));
extern int func_02048A24(int,int,int,int,int,int,int,int,const Vec *,const Vec *,const Vec *,u16);
struct Light;
extern void func_02048AD0(struct Light *l);
typedef unsigned int   u32;
extern void func_02046BE0(u32 a, u32 b);
void func_021E55BC(char *p)
{
    u16 heap;
    Vec v;
    func_02046440(0,2,0,1,0,(((struct Obj08072 *)p)->f5F4&0x7fff)|0x8000,func_021E5520);
    heap = (((struct Obj08072 *)p)->f5F4&0x7fff)|0x8000;
    v = d_021E7DE0;
    ((struct Obj08072 *)p)->f810 = func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&d_021E7CA0,&v,&d_021E7C94,heap);
    func_02048AD0((struct Light *)(((struct Obj08072 *)p)->f810));
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    func_02046BE0(0,0);
}
