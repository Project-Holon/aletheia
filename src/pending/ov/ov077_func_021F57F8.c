/*
 * function: func_021F57F8
 * address: 0x021F57F8
 * packet: pkt_ov077_021F57F8
 * region: ov077
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ov021 0x021CF51C unlabelled accessor, owned by Ilias.
 * symbols:
 *   func_021CF51C 0x021CF51C thumb ov021
 *   func_021CF560 0x021CF560 thumb ov021
 *   func_0207DD24 0x0207DD24 arm
 *   func_021F52D8 0x021F52D8 thumb ov075
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern u32 func_021CF51C(void *);
extern u32 func_021CF560(u32 *);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_021F52D8(u32 *);
void func_021F57F8(u32 *p) {
    u32 h = func_021CF51C(p);
    u32 w = func_021CF560(p);
    func_0207DD24(*(u32 *)(w+0x3078),31,0x7FFF,0,0);
    func_021F52D8((u32 *)h);
}
