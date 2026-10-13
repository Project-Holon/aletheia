/*
 * function: func_021BF788
 * address: 0x021BF788
 * packet: pkt_ov208_021BF788
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_021BC32C 0x021BC32C thumb ov208
 *   func_021BC3A8 0x021BC3A8 thumb ov208
 *   func_021BCF4C 0x021BCF4C thumb ov208
 *   func_021BC3AC 0x021BC3AC thumb ov208
 *   func_021C0048 0x021C0048 thumb ov208
 *   func_021BFFEC 0x021BFFEC thumb ov208
 *   func_021C06C8 0x021C06C8 thumb ov208
 *   func_021BC448 0x021BC448 thumb ov208
 *   func_021BC518 0x021BC518 thumb ov208
 *   func_021BC508 0x021BC508 thumb ov208
 *   func_021BC560 0x021BC560 thumb ov208
 *   TOWNMAP_GRH_LoadTownInfo 0x021BBB24 thumb ov072
 *   func_02012984 0x02012984 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020490F4 0x020490F4 arm
 *   func_020056A0 0x020056A0 thumb
 *   ov072_id 0x00000048 data a1
 */
#include "../include/Obj00510.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 ov072_id[];
struct BigObj;
extern int func_021BC3A4(int *p);
struct Ov208Buf;
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern int func_021BC3A8(int *p);
extern int func_021BCF4C(char *);
extern int func_021BC3AC(int *p);
extern int func_02034AC4(int);
extern void MI_CpuFill8(void *,int,u32);
extern u8 func_02012984(const struct BigObj *p);
extern int TOWNMAP_GRH_LoadTownInfo(int);
extern void func_021C0048(u16 *,char *,int);
extern void func_021C06C8(u16 *,char *,int);
extern void func_021BFFEC(void *,char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020056A0(u32,u32,u32);
extern void *func_021BC448(u32);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void *func_021BC560(u32,u16);
/* Caller explicitly loads r2 for setup helpers whose filed bodies omit it. */
u32 func_021BF788(void *a0,u32 a1,u16 *heap,u32 a3,int key)
{
    u8 *p;
    int save;
    u8 i;
    save = func_021BC3A4((int *)key);
    func_02034AC4((int)ov072_id);
    p = (u8 *)func_021BC32C(a0,0x438,*heap);
    i = 0;
    MI_CpuFill8(p,0,0x438);
    ((struct Obj00510 *)p)->f0 = func_021BCF4C((char *)func_021BC3A8((int *)key));
    ((struct Obj00510 *)p)->f4 = func_021BC3AC((int *)key);
    for (;i<2;i++) *(u32 *)(p+i*4+0x5c)=0;
    ((struct Obj00510 *)p)->f64=0;
    ((struct Obj00510 *)p)->f8C=0;
    ((struct Obj00510 *)p)->f90=1;
    ((struct Obj00510 *)p)->f94=0;
    ((struct Obj00510 *)p)->f6C=0;
    ((struct Obj00510 *)p)->f70=0;
    ((struct Obj00510 *)p)->f74=0;
    p[0x78]=func_02012984((const struct BigObj *)save);
    p[0x79]=0xff;
    ((struct Obj00510 *)p)->f84=0;
    ((struct Obj00510 *)p)->f88=1;
    ((struct Obj00510 *)p)->f3C8=TOWNMAP_GRH_LoadTownInfo(*heap);
    func_021C0048(heap,(char *)p,key);
    ((struct Obj00510 *)p)->f40C=func_020490F4(0xb2,*heap);
    ((struct Obj00510 *)p)->f410=func_020056A0((u32)func_021BFFEC,(u32)p,1);
    p[0x414]=0;
    func_021C06C8(heap,(char *)p,key);
    ((struct Obj00510 *)p)->f418=func_021BC448(*heap);
    ((struct Obj00510 *)p)->f41C=func_021BC448(*heap);
    func_021BC518((int *)(*(u32 * *)&((struct Obj00510 *)p)->f418));
    func_021BC518((int *)(*(u32 * *)&((struct Obj00510 *)p)->f41C));
    func_021BC508(0,(int *)(*(u32 * *)&((struct Obj00510 *)p)->f418));
    func_021BC508(1,(int *)(*(u32 * *)&((struct Obj00510 *)p)->f41C));
    ((struct Obj00510 *)p)->f420=func_021BC560(*heap,0xa);
    ((struct Obj00510 *)p)->f424=0;
    ((struct Obj00510 *)p)->f428=1;
    ((struct Obj00510 *)p)->f42C=0;
    ((struct Obj00510 *)p)->f430=1;
    ((struct Obj00510 *)p)->f434=1;
    return 1;
}
