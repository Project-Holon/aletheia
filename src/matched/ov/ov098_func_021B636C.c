/*
 * function: func_021B636C
 * address: 0x021B636C
 * packet: pkt_ov098_021B636C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B6394 POWCNT; 021B63C2,021B63D0,021B63D8 DISP3DCNT; 021B63F0 BG0CNT.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02046440 0x02046440 arm
 *   func_02046BE0 0x02046BE0 arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204044C 0x0204044C arm
 *   func_020434DC 0x020434DC arm
 *   d_021B6DF4 0x021B6DF4 data a4
 *   d_021B6DB0 0x021B6DB0 data a4
 *   d_021B6DD8 0x021B6DD8 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct DispVram;
struct DispConfig;
struct Cfg;
extern const struct DispVram d_021B6DF4;
extern struct DispConfig d_021B6DB0;
extern const struct Cfg d_021B6DD8;
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0203FC28(struct DispConfig *);
extern void func_02046440(u32, u32, u32, u32, u16, u32, void (*)(void));
extern void func_02046BE0(u32, u32);
extern void func_0207DC44(int, int, int, int);
extern void func_0204A48C(const struct Cfg *, u32, u32);
extern void func_0204044C(u32);
extern void func_020434DC(u32, u32);
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
void func_021B636C(u16 heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0201DD60();
    func_020433E0(&d_021B6DF4);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28(&d_021B6DB0);
    func_02046440(0, 1, 0, 1, 0, heap, 0);
    func_02046BE0(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    func_0207DC44(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0204A48C(&d_021B6DD8, (u32)&d_021B6DF4, heap);
    func_0204044C(1);
    func_020434DC(16, 1);
}
