/*
 * function: FIELD_MSGBG_SubMsgWinMain
 * address:  0x021919C8
 * packet:   pkt_ov021_021919C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE30  0x0201CE30  thumb  arm9
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   TALKMSGWIN_IsShown  0x02194974  thumb  ov021
 *   TALKMSGWIN_GetPrintStream  0x02194984  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

extern int TALKMSGWIN_IsShown(u8 *p, int i);
extern u32 TALKMSGWIN_GetPrintStream(u32 a, u32 b);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u32 func_0201CE30(void *p);

int FIELD_MSGBG_SubMsgWinMain(Q *q)
{
    if (TALKMSGWIN_IsShown((u8 *)q->f0c, (int)q->f08) == 0)
        return 0;
    func_020362DC();
    func_0203630C();
    switch (func_0201CE30((void *)TALKMSGWIN_GetPrintStream(q->f0c, (u32)q->f08))) {
    case 0:
    case 1:
        break;
    case 2:
        return 1;
    }
    return 0;
}
