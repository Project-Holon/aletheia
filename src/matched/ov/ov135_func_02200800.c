/*
 * function: func_02200800
 * address: 0x02200800
 * packet: pkt_ov135_02200800
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: if/else dispatch retains the compare after the first full arm.
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021F4D14(void *);
extern void func_021F4CE4(void *);
extern void func_021F4EC0(void *, u32, u32);
extern void func_0201F7A8(u32, u32);
extern void func_020456F8(u32);
extern u32 func_02045730(u32);
extern void func_02041B6C(u32);
extern void func_02040588(u32, u32);
extern void func_0204B3DC(u32, int);
extern void func_0204B92C(u32, int);
int func_02200800(u8 *p)
{
    u32 w;
    u32 state;
    state = func_021F4D14(p);
    if (state == 1) {
        func_021F4CE4(p);
        func_0201F7A8(*(u32 *)(p + 0xdd0), 2);
        w = *(u32 *)(p + 0xdd0);
        func_020456F8(w);
        func_02041B6C(func_02045730(w));
        w = *(u32 *)(p + 0xde0);
        func_020456F8(w);
        func_02041B6C(func_02045730(w));
        func_02040588(6, 0);
        func_0204B3DC(*(u32 *)(p + 0xd38), 0);
        func_021F4EC0(p, 0, 0x14);
        *(u32 *)(p + 0x28) = 7;
    } else if (state == 2) {
        func_021F4CE4(p);
        func_0201F7A8(*(u32 *)(p + 0xdd0), 2);
        w = *(u32 *)(p + 0xdd0);
        func_020456F8(w);
        func_02041B6C(func_02045730(w));
        func_0204B92C(*(u32 *)(p + 0xbf4), 1);
        *(u32 *)(p + 0x28) = 5;
        func_0204B3DC(*(u32 *)(p + 0xbf4), 1);
    }
    return 2;
}
