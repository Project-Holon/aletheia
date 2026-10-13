/*
 * function: func_021E5440
 * address: 0x021E5440
 * packet: pkt_ov177_021E5440
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021E5466,021E5468 hardware stores; 021E546C,021E5474 and 021E5476,021E547A hardware read-modify-write
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
 *   func_021E5568 0x021E5568 thumb ov177
 *   func_021E560C 0x021E560C thumb ov177
 *   func_021E5554 0x021E5554 thumb ov177
 *   func_020056A0 0x020056A0 thumb
 *   d_021E8DA0 0x021E8DA0 data a1
 *   d_021E8B2C 0x021E8B2C data a4
 */
extern const char d_021E8DA0[];
extern const unsigned d_021E8B2C[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_021E5568(void *, int);
extern void func_021E560C(int *, int, int);
extern void func_021E5554(int, int *);
extern int func_020056A0(void (*)(int, int *), int *, int);
int *func_021E5440(unsigned swap, int heap)
{
    int *p = func_02030734(heap, 16, 0, d_021E8DA0, 0x1BB);
    func_02082BCC(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021E8B2C);
    func_0204363C(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021E5568(p, heap);
    func_021E560C(p + 1, (int)d_021E8B2C, heap);
    p[3] = func_020056A0(func_021E5554, p, 0);
    return p;
}
