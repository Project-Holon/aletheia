/*
 * function: func_021FB614
 * address: 0x021FB614
 * packet: pkt_ov135_021FB614
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021FA9C8 0x021FA9C8 thumb ov135
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   tbl_02203298 0x02203298 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0204B3DC(u32 p, int on);
extern u32 func_0204B898(u32 p);
extern void func_0204B878(u32 p, u16 k);
extern void func_021FA9C8(void *p, u32 mode, int n);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern int func_020355C4(void);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern const u8 tbl_02203298[][2];
int func_021FB614(u8 *p)
{
    func_021FA9C8(p, 6, 0x20);
    func_0204B878(*(u32 *)(p + 8), 18);
    func_0202CD64(*(void **)(p + 0x18), 0, -4, 0, 4);
    *(int *)(p + 0x48) = 1;
    *(int *)(p + 0x4c) = 19;
    *(int *)(p + 0x44) = 10;
    *(s16 *)(p + 0x38) = -1;
    func_021F4FF4(*(u32 *)(p + 8), (tbl_02203298[*(int *)(p + 0x44)][0] + 16) * 8, tbl_02203298[*(int *)(p + 0x44)][1] * 8);
    func_0204B878(*(u32 *)(p + 8), 6);
    return -1;
}
