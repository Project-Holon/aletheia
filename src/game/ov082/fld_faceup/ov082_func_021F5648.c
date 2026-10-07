/*
 * function: func_021F5648
 * address:  0x021F5648
 * packet:   pkt_ov082_021F5648
 * region:   ov082
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: BG3CNT 0x0400000E read-modify-written by the SDK inline G2_SetBG3ControlText; BLDCNT 0x04000050 store
 * symbols:
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_020414AC  0x020414AC  arm
 *   func_021BC5D4  0x021BC5D4  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904D0  0x021904D0  thumb  ov021
 *   func_021F56E4  0x021F56E4  thumb  ov082
 *   func_021F56FC  0x021F56FC  thumb  ov082
 *   func_020307B0  0x020307B0  arm
 *   func_02189A60  0x02189A60  thumb  ov021
 */
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    char pad[8];
    u16 b0 : 2;
    u16 a : 4;
    u16 b6 : 1;
    u16 c : 1;
    u16 b : 5;
    u16 b13 : 1;
    u16 d : 2;
} Cfg;

typedef unsigned char  u8;
extern u32 func_02188D20(u8 *p);
extern void func_020414AC(int a);
extern void func_021BC5D4(u8 *p);
extern u32 func_02188C54(u8 *p);
extern void func_021904D0(u8 *p);
extern void func_021F56E4(u8 *p);
extern void func_021F56FC(int *p);
extern u32 func_020307B0(void *p);
extern u32 *func_02189A60(int a);

#define reg_G2_BG3CNT  (*(volatile u16 *)0x0400000E)
#define reg_G2_BLDCNT  (*(volatile u16 *)0x04000050)

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;
typedef enum { GX_BG_COLORMODE_16 = 0 } GXBGColorMode;
typedef enum { GX_BG_SCRBASE_0x0000 = 0 } GXBGScrBase;
typedef enum { GX_BG_CHARBASE_0x00000 = 0 } GXBGCharBase;

static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode,
                                        GXBGScrBase screenBase, GXBGCharBase charBase)
{
    reg_G2_BG3CNT = (u16)((reg_G2_BG3CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}

void func_021F5648(int a0, Cfg *p)
{
    int t = func_02188D20((u8 *)a0);

    func_020414AC(2);
    G2_SetBG3ControlText(p->d, p->c, p->b, p->a);
    func_021BC5D4((u8 *)t);
    func_021904D0((u8 *)func_02188C54((u8 *)a0));
    reg_G2_BLDCNT = 0;
    func_021F56E4((u8 *)p);
    func_021F56FC((int *)p);
    func_020307B0(p);
    *func_02189A60(a0) = 0;
}
