/*
 * function: func_021B907C
 * address:  0x021B907C
 * packet:   pkt_ov091_021B907C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: WININ 0x04000048 and WINOUT 0x0400004A read-modify-written by the SDK inlines G2_SetWnd0InsidePlane/G2_SetWndOutsidePlane; WIN0H/WIN0V/BLDCNT hardware registers
 * symbols:
 *   func_0207D658  0x0207D658  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355D8  0x020355D8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0204B3DC(int h, int f);
extern void func_02041B6C(int a);
extern void func_020355D8(int a);

#define reg_G2_WIN0H  (*(volatile u16 *)0x04000040)
#define reg_G2_WIN0V  (*(volatile u16 *)0x04000044)
#define reg_G2_WININ  (*(volatile u16 *)0x04000048)
#define reg_G2_WINOUT (*(volatile u16 *)0x0400004A)
#define reg_G2_BLDCNT (*(volatile u16 *)0x04000050)

static inline void G2_SetBlendBrightness(int plane, int brightness)
{
    func_0207D658((u32)&reg_G2_BLDCNT, plane, brightness);
}

static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    reg_G2_WIN0H = (u16)(((x1 << 8) & 0xff00) | ((x2 << 0) & 0x00ff));
    reg_G2_WIN0V = (u16)(((y1 << 8) & 0xff00) | ((y2 << 0) & 0x00ff));
}

static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WININ = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WINOUT = (u16)tmp;
}

#define W(o) (*(int *)(p + (o)))

void func_021B907C(u8 *p)
{
    p[0xc] = 6;
    p[0xe] = 0;
    G2_SetBlendBrightness(0x1e, 8);
    G2_SetWnd0Position(0xe0, 0xa8, 0xf8, 0xc0);
    G2_SetWnd0InsidePlane(0x1f, 0);
    G2_SetWndOutsidePlane(0x1f, 1);
    W(0x10) = 1;
    func_0204B3DC(W(0x1e4), 0);
    func_0204B3DC(W(0x1e0), 0);
    func_02041B6C(0);
    func_020355D8(W(8));
}
