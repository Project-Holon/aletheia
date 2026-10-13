/*
 * function: func_021BC930
 * address: 0x021BC930
 * packet: pkt_ov216_021BC930
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses 0x021BC956-0x021BC96A.
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
 *   func_021BCA58 0x021BCA58 thumb ov216
 *   func_021BCAFC 0x021BCAFC thumb ov216
 *   func_021BCA44 0x021BCA44 thumb ov216
 *   d_021BDDC0 0x021BDDC0 data a1
 *   d_021BDBD8 0x021BDBD8 data a4
 */
extern char d_021BDDC0[];
extern unsigned d_021BDBD8[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_021BCA58(void *,int);
extern void func_021BCAFC(void **p, void *a, int heap);
extern void func_021BCA44(void *unused, char *p);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
void *func_021BC930(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_021BDDC0,317);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BDBD8);
    func_0204363C(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021BCA58(p,heap);
    func_021BCAFC((void **)(p+1),d_021BDBD8,heap);
    p[3]=(unsigned)func_020056A0((void (*)(void *, void *))func_021BCA44,p,0);
    return p;
}
