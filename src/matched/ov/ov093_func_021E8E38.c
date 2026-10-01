/*
 * function: func_021E8E38
 * address: 0x021E8E38
 * packet: pkt_ov093_021E8E38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the POWCNT read/OR/write is spelled as assignment, not compound assignment.
 * volatile: 021E8E60 POWCNT; 021E8E8E,021E8E9C,021E8EA4 DISP3DCNT; 021E8EBE BG0CNT.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   d_021F387C 0x021F387C data a4
 *   d_021F3850 0x021F3850 data a4
 *   d_021F3860 0x021F3860 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_021F387C[], d_021F3850[], d_021F3860[];
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const void *);
extern void func_0203FC28(const void *);
extern void func_02046440(u32, u32, u32, u32, u16, u16, void (*)(void));
extern void func_02046BE0(u32, u32);
extern void func_0207DC44(int, int, int, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_0204A48C(const void *, const void *, u16);
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
void func_021E8E38(u16 heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0201DD60();
    func_020433E0(d_021F387C);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28(d_021F3850);
    func_02046440(0, 1, 0, 1, 0, heap, 0);
    func_02046BE0(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    func_0207DC44(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0207D63C((void *)0x04000050, 2, 0x3d, 0x1f, 3);
    func_0204A48C(d_021F3860, d_021F387C, heap);
}
