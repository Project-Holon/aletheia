/*
 * function: func_021EB90C
 * address: 0x021EB90C
 * packet: pkt_ov170_021EB90C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment padding at 0x021EB95A.
 * symbols:
 *   func_021EB6D8 0x021EB6D8 thumb ov170
 *   func_0202CE50 0x0202CE50 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct WinMgr;
extern void func_021EB6D8(char *, int, int, int);
extern void func_0202CE50(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
void func_021EB90C(char *p)
{
    func_021EB6D8(p, 20, 84, 0);
    func_021EB6D8(p, 21, 85, 1);
    func_0202CE50(*(struct WinMgr **)(*(char **)(p + 0x2c) + 0x74), 7, 0, 9, 11, 3, 12);
    func_0202CE50(*(struct WinMgr **)(*(char **)(p + 0x2c) + 0x74), 7, 0, 12, 11, 3, 12);
}
