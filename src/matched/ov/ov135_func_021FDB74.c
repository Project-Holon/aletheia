/*
 * function: func_021FDB74
 * address: 0x021FDB74
 * packet: pkt_ov135_021FDB74
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99D0 0x021F99D0 thumb ov135
 *   func_021FDEFC 0x021FDEFC thumb ov135
 *   func_021FE178 0x021FE178 thumb ov135
 *   func_021FE0BC 0x021FE0BC thumb ov135
 *   func_021FDCE4 0x021FDCE4 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned int u32;
typedef unsigned char  u8;
extern void func_021F99D0(u8 *p);
extern void func_021FDEFC(void *);
extern void func_021FE178(void *);
extern void func_021FE0BC(unsigned char *p);
extern void func_021FDCE4(void);
extern void func_022000E4(void *);
extern void func_021F4EC8(u8 *p);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
int func_021FDB74(unsigned char *p)
{
    *(int *)(p + 0xec0) = 0;
    func_021F99D0(*(void **)(p + 0xde4));
    func_021FDEFC(p);
    func_021FE178(p);
    func_021FE0BC(p);
    func_021FDCE4();
    if (*(int *)(p + 0x14) == 1)
        *(int *)(p + 0x12e4) = 1;
    func_022000E4(p);
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0xd38), 0);
    func_021F4EC8(p);
    return 0;
}
