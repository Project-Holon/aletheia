/*
 * function: func_021E0080
 * address: 0x021E0080
 * packet: pkt_ov183_021E0080
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
extern void func_020409B4(u32 index);
int func_021E0080(char *p)
{
    func_021FFE70(*(void **)(p + 0x1c));
    func_021FFC6C(*(void **)(p + 0x1c));
    func_020409B4(4);
    return 1;
}
