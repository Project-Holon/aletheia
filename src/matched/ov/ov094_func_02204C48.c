/*
 * function: func_02204C48
 * address:  0x02204C48
 * packet:   pkt_ov094_02204C48
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: sub-engine DISPCNT 0x04001000, WININ 0x04001048, WINOUT 0x0400104A read-modify-written by the SDK inlines (0x02204C4C..0x02204C76)
 * symbols:
 *   func_0207D658  0x0207D658  arm
 *   func_0220687C  0x0220687C  thumb  ov094
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0220687C(void *m, void *a);

#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_G2S_DB_WININ   (*(volatile u16 *)0x04001048)
#define reg_G2S_DB_WINOUT  (*(volatile u16 *)0x0400104A)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)

static inline void GXS_SetVisibleWnd(int mask)
{
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0xe000) | ((u32)mask << 13);
}

static inline void G2S_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}

static inline void G2S_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WININ & ~0x3f00) | ((u32)wnd << 8));
    if (effect) {
        tmp |= (0x20 << 8);
    }
    reg_G2S_DB_WININ = (u16)tmp;
}

static inline void G2S_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2S_DB_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}

static inline void G2S_BlendNone(void)
{
    func_0207D658((u32)&reg_G2S_DB_BLDCNT, 0, 0);
}

void func_02204C48(void *a0, int *c)
{
    GXS_SetVisibleWnd(0);
    G2S_SetWnd0InsidePlane(0, 0);
    G2S_SetWnd1InsidePlane(0, 0);
    G2S_SetWndOutsidePlane(0, 0);
    G2S_BlendNone();
    func_0220687C((void *)c[0], a0);
}
