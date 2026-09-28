/*
 * function: ov208_func_021BD574
 * address:  0x021BD574
 * packet:   pkt_ov208_021BD574
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Scrn {
    u8  pad0[0xc];
    u16 data[1];
};

extern u32  func_0204A380(u32 a0, u32 a1, u32 a2, u16 a3);
extern int  func_02062B30(u32 file, struct Scrn **out);
extern int  func_0204169C(u8 channel);
extern int  func_0204162C(u8 channel);
extern void func_020410D0(u8 index, u32 a1, u32 a2, u32 a3, u8 a4, void *a5, u8 a6,
                          u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 channel);
extern void func_020307B0(u32 file);

void ov208_func_021BD574(u32 a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                         u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap)
{
    struct Scrn *scr;
    u32 file;
    int i;
    u16 *d;

    file = func_0204A380(a0, a1, a13, (u16)((heap & 0x7fff) | 0x8000));
    func_02062B30(file, &scr);
    if (add != 0 && func_0204169C(channel) == 0) {
        d = scr->data;
        for (i = 0; i < a6 * a7; i++)
            d[i] += (u16)add;
    }
    if (func_0204162C(channel) != 0) {
        func_020410D0(channel, x, y, w, h, scr->data, a4, a5, a6, a7);
        func_020413B0(channel, x, y, w, h, pal);
        func_020409B4(channel);
    }
    func_020307B0(file);
}
