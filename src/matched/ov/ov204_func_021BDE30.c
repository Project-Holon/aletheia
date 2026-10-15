/*
 * function: func_021BDE30
 * address: 0x021BDE30
 * packet: pkt_ov204_021BDE30
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   d_021BFD80 0x021BFD80 data a4
 *   d_021BFEFC 0x021BFEFC data a4
 *   d_021BFEDC 0x021BFEDC data a4
 *   d_021BFE7C 0x021BFE7C data a4
 *   d_021BFE9C 0x021BFE9C data a4
 *   d_021BFEBC 0x021BFEBC data a4
 */

#include "../include/G_DispConfig.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BgTemplate { u32 a,b,c,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; };
extern struct DispConfig d_021BFD80;
extern const struct BgTemplate d_021BFEFC,d_021BFEDC,d_021BFE7C,d_021BFE9C,d_021BFEBC;
extern void MI_CpuFill8(void *,u8,u32);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021BDE30(void *p,u16 heap)
{
    struct BgTemplate t1,t2,t3,t4,t5;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28(&d_021BFD80);
    t1=d_021BFEFC;
    BG_SYS_InitBgLayer(1,&t1,0);
    t2=d_021BFEDC;
    BG_SYS_InitBgLayer(2,&t2,0);
    t3=d_021BFE7C;
    BG_SYS_InitBgLayer(3,&t3,0);
    t4=d_021BFE9C;
    BG_SYS_InitBgLayer(4,&t4,0);
    t5=d_021BFEBC;
    BG_SYS_InitBgLayer(6,&t5,0);
    func_02040588(1,1);
    func_02040588(3,1);
    func_02040588(4,1);
    func_02040588(6,1);
}
