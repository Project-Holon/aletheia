/*
 * function: func_021BC3F0
 * address: 0x021BC3F0
 * packet: pkt_ov223_021BC3F0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: C660 heap remains int here: no caller truncation; callee u16 body also accepts the observed full-width input.
 * volatile: hardware accesses 0x021BC416-0x021BC42A.
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
 *   func_021BC54C 0x021BC54C thumb ov223
 *   func_021BC5F0 0x021BC5F0 thumb ov223
 *   func_021BC660 0x021BC660 thumb ov223
 *   func_021BC538 0x021BC538 thumb ov223
 *   d_021BCB08 0x021BCB08 data a1
 *   d_021BC980 0x021BC980 data a4
 */
extern char d_021BCB08[];
extern unsigned d_021BC980[];
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
extern void func_021BC54C(void *,int);
extern void func_021BC5F0(int *,int,int);
extern void func_021BC660(int *,int);
extern void func_021BC538(void *,char *);
extern void *func_020056A0(void (*)(void *,char *),void *,int);
void *func_021BC3F0(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_021BCB08,463);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BC980);
    func_0204363C(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021BC54C(p,heap);
    func_021BC5F0((int *)(p+1),(int)d_021BC980,heap);
    func_021BC660((int *)(p+2),heap);
    p[3]=(unsigned)func_020056A0(func_021BC538,p,0);
    return p;
}
