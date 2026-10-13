/*
 * function: func_021BAB64
 * address: 0x021BAB64
 * packet: pkt_ov213_021BAB64
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BAB92/021BAB9C read DISPCNT hardware before masking.
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
 *   func_021BACB4 0x021BACB4 thumb ov213
 *   func_021BAD58 0x021BAD58 thumb ov213
 *   func_021BADC8 0x021BADC8 thumb ov213
 *   func_020056A0 0x020056A0 thumb
 *   func_021BACA0 0x021BACA0 thumb ov213
 *   d_021BB33C 0x021BB33C data a4
 *   d_021BB1C8 0x021BB1C8 data a4
 * arity: 434CC full body/4349C/434B4 read no incoming inputs;
 * own 4361C and 43588 units prove void, overriding stale caller externs.
 */
#include "../include/Obj25714.h"
struct DispVram;
extern char d_021BB33C[];
extern const struct DispVram d_021BB1C8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p,unsigned value,unsigned size);
extern void BG_SYS_ClearGraphicsMemory(unsigned mode);
extern void BG_SYS_SetVramBanks(const struct DispVram *p);
extern void func_0204363C(unsigned swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_021BACB4(void *p,unsigned heap);
extern void func_021BAD58(void **out, int a, int b);
extern void func_021BADC8(unsigned **p,unsigned heap);
extern void func_021BACA0(void *unused, char *p);
extern void *func_020056A0(void *callback,void *ctx,int priority);
void *func_021BAB64(unsigned mode,unsigned heap)
{
    unsigned char *p;
    p=func_02030734(heap,16,0,d_021BB33C,0x1B4);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BB1C8);
    func_0204363C(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021BACB4(p,heap);
    func_021BAD58((void **)(p+4),(int)&d_021BB1C8,heap);
    func_021BADC8((unsigned **)(p+8),heap);
    ((struct Obj25714 *)p)->fC=func_020056A0((void *)func_021BACA0,p,0);
    return p;
}
