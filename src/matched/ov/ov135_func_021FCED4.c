/*
 * function: func_021FCED4
 * address: 0x021FCED4
 * packet: pkt_ov135_021FCED4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD0F4 0x021FD0F4 thumb ov135
 *   func_021FD2FC 0x021FD2FC thumb ov135
 *   func_021FD1E0 0x021FD1E0 thumb ov135
 *   func_021FCFC8 0x021FCFC8 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char  u8;
extern void func_021FD0F4(u8 *p);
extern void func_021FD2FC(u8 *p);
extern void func_021FD1E0(u8 *p);
extern void func_021FCFC8(void);
extern void func_022000E4(void *);
extern void func_021F4EC8(u8 *p);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0203D34C(u32 a, u32 b);
int func_021FCED4(unsigned char *p)
{
    *(int *)(p + 0xec0) = 0;
    func_021FD0F4(p);
    func_021FD2FC(p);
    func_021FD1E0(p);
    func_021FCFC8();
    func_022000E4(p);
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0xd38), 0);
    func_021F4EC8(p);
    if (*(int *)(p + 0x12fc) == 0)
        func_0203D34C(0, 0x48);
    return 0;
}
