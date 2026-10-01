/*
 * function: func_021F5204
 * address: 0x021F5204
 * packet: pkt_ov135_021F5204
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D55C 0x0207D55C arm
 *   func_021FFD74 0x021FFD74 thumb ov135
 *   func_021F577C 0x021F577C thumb ov135
 *   func_021F59E8 0x021F59E8 thumb ov135
 *   func_021F5940 0x021F5940 thumb ov135
 *   func_021F5358 0x021F5358 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0207D55C(u16 *);
extern void func_021FFD74(u8 *);
extern void func_021F577C(u8 *);
extern void func_021F59E8(u8 *);
extern void func_021F5940(u8 *);
extern void func_021F5358(void);
extern void func_022000E4(u8 *);
extern void func_0204B3DC(u32, int);
extern void func_021F4EC8(u8 *);
int func_021F5204(u8 *p)
{
    if (func_0207D55C((u16 *)0x0400106c)) {
        func_021FFD74(p);
    }
    func_021F577C(p);
    func_021F59E8(p);
    func_021F5940(p);
    func_021F5358();
    func_022000E4(p);
    func_0204B3DC(*(u32 *)(p + 0xd38), 0);
    func_021F4EC8(p);
    return 0;
}
