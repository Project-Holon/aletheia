/*
 * unit: yes
 * function: func_021B8724,func_021B8794
 * address: 0x021B8724
 * packet: pkt_ov102_021B8724
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes the 8-byte setter follower at 021B8794.
 * symbols:
 *   func_02045730 0x02045730 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
extern void func_020413B0(u32, u8, u8, u8, u8, u8);
extern void func_020409B4(u32);
void func_021B8724(u8 *p)
{
    int i;
    u32 win;
    u8 palette;
    u8 a, b, c, d;
    u16 *row;
    *(u16 *)(p + 0x34) = 0;
    *(u16 *)(p + 0x32) = 0;
    for (i = 0; i < *(u16 *)(p + 0x2c); i++) {
        win = func_02045730((struct Descriptor *)(*(int *)(p + i * 4 + 4)));
        row = (u16 *)(*(u8 **)(p + 0x28) + i * 12);
        a = row[1];
        b = row[2];
        c = row[3];
        d = row[4];
        switch (i) {
        case 0: palette = 11; break;
        case 1: palette = 4; break;
        }
        func_020413B0(win, a, b, c, d, palette);
        func_020409B4(win);
    }
}
void func_021B8794(u16 value, int flag, u8 *p)
{
    if (flag == 0) *(u16 *)(p + 0x30) = value;
}
