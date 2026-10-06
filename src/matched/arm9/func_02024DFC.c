/*
 * function: func_02024DFC
 * address:  0x02024DFC
 * packet:   pkt_02024DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     infowin redraw task (the TCB callback func_02024A20 registers):
 *           clock digits, battery/link/wireless icons, per dirty bit of
 *           +0x04.  Levers, in the order they closed it: tens use `/ 10`
 *           and ones `% 10` (the remainder comes back in r1); every access
 *           goes through the global (reloaded at each join); the two
 *           six-entry tables are struct copies (local initialised arrays);
 *           `k = (c) ? a : b` for all three tile selectors; the draw call
 *           in each arm of block 0x10; `done = 1` after the block-0 draw.
 *
 * symbols:
 *   gInfoWin            0x0214693C  data a4
 *   d_0209F830          0x0209F830  data a4
 *   d_0209F834          0x0209F834  data a2
 *   d_0209F838          0x0209F838  data a4
 *   d_0209F840          0x0209F840  data a4
 *   d_0209F848          0x0209F848  data a4
 *   d_0209F852          0x0209F852  data a2
 *   d_0209F868          0x0209F868  data a4
 *   d_0209F870          0x0209F870  data a2
 *   func_02025154       0x02025154  thumb
 *   func_020251D8       0x020251D8  thumb
 *   func_020410D0       0x020410D0  arm
 *   func_020409B4       0x020409B4  arm
 *   func_02035630       0x02035630  arm
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   _s32_div_f          0x0209C0A4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
    u8  pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u8  f1C;
    u8  f1D;
    u8  f1E;
    u8  f1F;
    u32 f20;
    void *f24;
};

struct Sel6 { u8 v[6]; };
struct Ofs6 { u16 v[6]; };

struct W {
    u16 scr[4];     /* +0x00 */
    struct Sel6 sel; /* +0x08 */
    u16 col[2];     /* +0x0E */
    struct Ofs6 ofs; /* +0x12 */
    u16 clk[10];    /* +0x1E */
};

extern struct InfoWin *gInfoWin;
extern const u16 d_0209F834[];
extern const u32 d_0209F840[];
extern const u16 d_0209F848[];
extern const u16 d_0209F852[][2];
extern const u32 d_0209F838[];
extern const struct Ofs6 d_0209F870;
extern const struct Sel6 d_0209F868;
extern const u16 d_0209F830[];

extern void func_02025154(u32 base, u32 blk, u8 x, u8 y, u8 w, u8 h);
extern int  func_020251D8(int a0, const void *a1, int a2);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 a0);
extern u8 func_02035630(void);
extern int  OS_IsRunOnTwl(void);

void func_02024DFC(void)
{
    struct W buf;
    int done;
    int k;

    done = 0;
    if (gInfoWin == 0)
        return;

    if (gInfoWin->f04 & 1) {
        if (gInfoWin->f1D < 10) {
            buf.clk[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + 0xF);
            buf.clk[5] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + 0x1F);
        } else {
            buf.clk[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1D / 10 + 1));
            buf.clk[5] = buf.clk[0] + 0x10;
        }
        buf.clk[1] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1D % 10 + 1));
        k = (gInfoWin->f14 != 0) ? 11 : 15;
        buf.clk[2] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + k);
        buf.clk[3] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1C / 10 + 1));
        buf.clk[4] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + (gInfoWin->f1C % 10 + 1));
        buf.clk[6] = buf.clk[1] + 0x10;
        k = (gInfoWin->f14 != 0) ? 27 : 31;
        buf.clk[7] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + k);
        buf.clk[8] = buf.clk[3] + 0x10;
        buf.clk[9] = buf.clk[4] + 0x10;
        func_020410D0(gInfoWin->f06, 1, 0, 5, 2, (u32)buf.clk, 0, 0, 5, 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 1;
    }

    if (gInfoWin->f04 & 4) {
        u8 sel = (gInfoWin->f04 & 0x200) ? 1 : 0;
        func_02025154(d_0209F834[sel], gInfoWin->f07, 9, 0, 3, 2);
        func_020251D8(6, &d_0209F840[sel], 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 4;
    }

    if (gInfoWin->f04 & 8) {
        func_02025154(d_0209F848[gInfoWin->f20], gInfoWin->f07, 13, 0, 6, 2);
        func_020251D8(8, d_0209F852[gInfoWin->f20], 2);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 8;
    }

    if (gInfoWin->f04 & 0x10) {
        func_02025154(0x20, gInfoWin->f07, 0x13, 0, 7, 2);
        if (gInfoWin->f04 & 0x800) {
            u8 t;
            u8 ph;
            if (func_02035630() == 0x1E)
                gInfoWin->f08 = gInfoWin->f08 + 2;
            else
                gInfoWin->f08 = gInfoWin->f08 + 1;
            if (gInfoWin->f08 >= 0x50)
                gInfoWin->f08 = 0;
            t = gInfoWin->f08 / 16;
            ph = gInfoWin->f08 % 16;
            if (t < 4) {
                int d;
                u8 c;
                d = ph - 8;
                if (d < 0)
                    d = -d;
                ph = 8 - d;
                c = ph * 13 / 8 + 6;
                buf.col[0] = (c << 5) | c | (c << 10);
                c = ph * 22 / 8 + 9;
                buf.col[1] = (c << 5) | c | (c << 10);
                func_020251D8(10, buf.col, 2);
            } else {
                func_020251D8(10, &d_0209F838[0], 2);
            }
        } else {
            u8 sel = (gInfoWin->f04 & 0x1400) ? 1 : 0;
            func_020251D8(10, &d_0209F838[sel], 2);
        }
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 0x10;
    }

    if (gInfoWin->f04 & 0x20) {
        u8 *sp8 = buf.sel.v;
        buf.ofs = d_0209F870;
        buf.sel = d_0209F868;
        if (OS_IsRunOnTwl()) {
            k = sp8[gInfoWin->f1F];
        } else {
            k = (gInfoWin->f1F == 5) ? 5 : 4;
        }
        buf.scr[0] = gInfoWin->f00 + ((gInfoWin->f07 << 12) + buf.ofs.v[k]);
        buf.scr[2] = buf.scr[0] + 0x10;
        buf.scr[1] = buf.scr[0] + 0x400;
        buf.scr[3] = buf.scr[2] + 0x400;
        func_020410D0(gInfoWin->f06, 0x1C, 0, 2, 2, (u32)buf.scr, 0, 0, 2, 2);
        func_020251D8(13, d_0209F830, 1);
        done = 1;
        gInfoWin->f04 = gInfoWin->f04 - 0x20;
    }

    if (done == 1)
        func_020409B4(gInfoWin->f06);
}
