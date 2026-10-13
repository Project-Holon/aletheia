/*
 * function: PLIST_DEMO_CreateParticles
 * address: 0x021BDABC
 * packet: pkt_ov091_021BDABC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: two-halfword coordinate struct keeps its address sp-relative; int alias added 4 B.
 * symbols:
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PLIST_PLATE_GetCenterPos 0x021BB3D4 thumb ov091
 *   PARTICLE_StartEffect 0x020515B4 arm
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
extern int PARTICLE_LoadArchiveMember(u32,u32,u32);
extern void *GFL_NET_AllocAligned(u32,u32,const char *,u16);
extern int PARTICLE_CreateSystemDefault(int,int,int,int);
extern u32 func_020056BC(void);
extern void PARTICLE_SetupSystem(u8 *,u32,u32,u32);
extern void PLIST_PLATE_GetCenterPos(void *a, u8 *s, u16 *out);
extern int PARTICLE_StartEffect(void *p, int b, int c);
extern u8 d_021BED58[];
#define W(o) (*(u32 *)(p+(o)))
void PLIST_DEMO_CreateParticles(u8 *p)
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
    handle = PARTICLE_LoadArchiveMember(0x4c,member,((struct Obj06215 *)p)->f0);
    W(0x25c) = (u32)GFL_NET_AllocAligned(((struct Obj06215 *)p)->f0,0x5000,(const char *)d_021BED58,0xea);
    W(0x260) = PARTICLE_CreateSystemDefault(W(0x25c),0x5000,0,((struct Obj06215 *)p)->f0);
    PARTICLE_SetupSystem((u8 *)W(0x260),handle,0,func_020056BC());
    PLIST_PLATE_GetCenterPos(p,(u8 *)(*(int *)(p+W(0x2c)*4+0x160)),(u16 *)(&xy));
    xy.x -= 0x28;
    xy.y += 4;
    if (xy.x > 0) vec[0] = (int)(0.5f+(float)(xy.x<<12))/0x26;
    else vec[0] = (int)((float)(xy.x<<12)-0.5f)/0x26;
    if (xy.y > 0) vec[1] = (int)(0.5f+(float)(xy.y<<12))/0x26;
    else vec[1] = (int)((float)(xy.y<<12)-0.5f)/0x26;
    vec[2] = 0x40000;
    for (i=0;i<count;i++) PARTICLE_StartEffect((void *)W(0x260),i,(int)vec);
}
