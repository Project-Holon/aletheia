/*
 * function: func_021BDDD8
 * address: 0x021BDDD8
 * packet: pkt_ov203_021BDDD8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 04000050/04001050 hardware stores DE06/DE0C; 04000000/04001000 rereads DE10/DE1A.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BE938 0x021BE938 thumb ov203
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BDFC0 0x021BDFC0 thumb ov203
 *   func_021BE084 0x021BE084 thumb ov203
 *   func_020056A0 0x020056A0 thumb
 *   func_021BDFA8 0x021BDFA8 thumb ov203
 *   func_021BE0F4 0x021BE0F4 thumb ov203
 *   d_021C3CCC 0x021C3CCC data a1
 *   d_021BFBC4 0x021BFBC4 data a4
 */
#include "../include/Obj08374.h"
extern const char d_021C3CCC[];
extern const unsigned char d_021BFBC4[][48];
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, unsigned, unsigned);
extern int func_021BE938(void *);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_021BDFC0(void *, unsigned);
extern void func_021BE084(unsigned char *, int, int);
extern void *func_020056A0(unsigned, unsigned, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021BDFA8(u32 a, u8 *p);
extern void func_021BE0F4(unsigned char *, int);
void *func_021BDDD8(unsigned swap, void *config, unsigned heap)
{
    unsigned char *ctx = func_02030734(heap, 24, 0, d_021C3CCC, 0x15a);
    func_02082BCC(ctx, 0, 24);
    ((struct Obj08374 *)ctx)->f14 = func_021BE938(config);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BFBC4[((struct Obj08374 *)ctx)->f14]);
    func_0204363C(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    if (((struct Obj08374 *)ctx)->f14 == 0) {
        func_021BDFC0(ctx, heap);
        func_021BE084(ctx + 4, (int)d_021BFBC4, heap);
        ((struct Obj08374 *)ctx)->f10 = func_020056A0((unsigned)func_021BDFA8, (unsigned)ctx, 0);
    }
    func_021BE0F4(ctx + 8, heap);
    return ctx;
}
