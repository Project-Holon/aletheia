/*
 * function: func_021E58A4
 * address: 0x021E58A4
 * packet: pkt_ov177_021E58A4
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
extern int func_020490F4(int, unsigned short);
extern void func_020498F4(int, int, int, int, int, int, unsigned short);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02049238(int);
void func_021E58A4(int unused, int mode, unsigned color)
{
    int h;
    unsigned c = (color & 0x7fff) | 0x8000;
    h = func_020490F4(0x85, c);
    func_020498F4(h, 5, 3, 0, 0, 0, c);
    func_020498F4(h, 6, 7, 0, 0, 0, c);
    switch (mode) {
    case 2:
        func_020498F4(h, 8, 6, 0, 0, 0, c);
        break;
    case 3:
        func_020498F4(h, 10, 2, 0, 0, 0, c);
        break;
    case 0:
    case 1:
        func_020498F4(h, 10, 6, 0, 0, 0, c);
        break;
    }
    func_02040618(2, 0, -256);
    func_02040618(1, 0, -256);
    func_02040618(6, 0, -256);
    func_02040618(5, 0, -256);
    func_02049238(h);
}
