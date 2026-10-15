/*
 * function: ZUKAN_TOROKU_GRAPHIC_CreateDisplay
 * address: 0x0220B318
 * packet: pkt_ov207_0220B318
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses 0x0220B33E-0x0220B352.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   ZUKAN_TOROKU_GRAPHIC_InitBg 0x0220B448 thumb ov207
 *   ZUKAN_TOROKU_GRAPHIC_InitActors 0x0220B4EC thumb ov207
 *   ZUKAN_TOROKU_GRAPHIC_VBlank 0x0220B434 thumb ov207
 *   d_0220BC20 0x0220BC20 data a1
 *   d_0220BAE8 0x0220BAE8 data a4
 */
extern char d_0220BC20[];
extern unsigned d_0220BAE8[];
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
typedef unsigned char  u8;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void ZUKAN_TOROKU_GRAPHIC_InitBg(void *,int);
extern void ZUKAN_TOROKU_GRAPHIC_InitActors(unsigned char *p, int a, int b);
extern void ZUKAN_TOROKU_GRAPHIC_VBlank(void *unused, u8 *p);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
void *ZUKAN_TOROKU_GRAPHIC_CreateDisplay(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_0220BC20,455);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_0220BAE8);
    func_0204363C(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    ZUKAN_TOROKU_GRAPHIC_InitBg(p,heap);
    ZUKAN_TOROKU_GRAPHIC_InitActors((unsigned char *)(p+1),(int)d_0220BAE8,heap);
    p[3]=(unsigned)func_020056A0((void (*)(void *, void *))ZUKAN_TOROKU_GRAPHIC_VBlank,p,0);
    return p;
}
