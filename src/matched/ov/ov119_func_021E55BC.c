/*
 * function: POKETRADE_2D_InitG3DSystem
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
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   POKETRADE_2D_Setup3DRenderState 0x021E5520 thumb ov119
 *   d_021E7DE0 0x021E7DE0 data a4
 *   d_021E7CA0 0x021E7CA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_021E7C94 0x021E7C94 data a4
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 */
#include "../include/Obj08072.h"
typedef unsigned short u16;
typedef short s16;
typedef struct { int x,y,z; } Vec;
extern Vec d_021E7DE0, d_021E7CA0, d_021E7C94;
extern const s16 d_020A1EB8[];
extern void POKETRADE_2D_Setup3DRenderState(void);
extern void G3D_SYSTEM_Init(int,int,int,int,u16,u16,void (*)(void));
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const Vec *,const Vec *,const Vec *,u16);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
typedef unsigned int   u32;
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
void POKETRADE_2D_InitG3DSystem(char *p)
{
    u16 heap;
    Vec v;
    G3D_SYSTEM_Init(0,2,0,1,0,(((struct Obj08072 *)p)->f5F4&0x7fff)|0x8000,POKETRADE_2D_Setup3DRenderState);
    heap = (((struct Obj08072 *)p)->f5F4&0x7fff)|0x8000;
    v = d_021E7DE0;
    ((struct Obj08072 *)p)->f810 = G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&d_021E7CA0,&v,&d_021E7C94,heap);
    G3D_CAMERA_Reset((struct Light *)(((struct Obj08072 *)p)->f810));
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
