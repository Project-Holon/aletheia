/*
 * function: func_021BCA20
 * address: 0x021BCA20
 * packet: pkt_ov210_021BCA20
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204162C 0x0204162C arm
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CAC4 0x0202CAC4 thumb
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct WinMgr;
extern u32 func_0204162C(int);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02041B6C(u32);
void func_021BCA20(char *p)
{
    u32 base = func_0204162C(0);
    *(struct WinMgr **)(p + 0x20) = func_0202C9B4(2, 1, 123);
    func_0202CA3C(*(struct WinMgr **)(p + 0x20), 0, 0, 32, 3);
    func_0202CAC4(*(struct WinMgr **)(p + 0x20), 0, (void *)(base + 0x540));
    func_02041300(0, 0, 0, 21, 32, 3, 0);
    func_02041B6C(0);
}
