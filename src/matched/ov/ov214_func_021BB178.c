/*
 * function: func_021BB178
 * address: 0x021BB178
 * packet: pkt_ov214_021BB178
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * volatile: MMIO accesses 021BB19E..021BB1B2
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BB2C8 0x021BB2C8 thumb ov214
 *   func_021BB36C 0x021BB36C thumb ov214
 *   func_021BB3DC 0x021BB3DC thumb ov214
 *   func_021BB2B4 0x021BB2B4 thumb ov214
 *   func_020056A0 0x020056A0 thumb
 *   site 0x021BB668 data ov214
 *   config 0x021BB588 data ov214
 */
#include "../include/Obj25730.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern const char site[];
extern const u32 config[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,u32,u32);
extern void BG_SYS_ClearGraphicsMemory(u32);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_021BB2C8(void *,u32);
extern void func_021BB36C(unsigned char *,int,int);
extern void func_021BB3DC(u32 **,u32);
typedef unsigned char  u8;
extern void func_021BB2B4(void *unused, u8 *p);
extern u32 func_020056A0(void (*)(void *),void *,u32);
char *func_021BB178(u32 a,u32 heap)
{
    char *p=func_02030734(heap,16,0,site,458);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)config);
    func_0204363C(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021BB2C8(p,heap);
    func_021BB36C((unsigned char *)p+4,(int)config,heap);
    func_021BB3DC((u32 **)(p+8),heap);
    ((struct Obj25730 *)p)->fC=func_020056A0((void (*)(void *))func_021BB2B4,p,0);
    return p;
}
