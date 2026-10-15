/*
 * function: FIELD_MSGBG_InitBgTwoLayerTalk
 * address:  0x02192BD0
 * packet:   pkt_ov021_02192BD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-layer twin of FIELD_MSGBG_InitBgOneLayer, plus TALKMSGWIN_LoadTexture on the new handle.
 *
 * symbols:
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   FIELD_MSGBG_LoadWindowGraphicsAll  0x02192FA4  thumb  ov021
 *   TALKMSGWIN_Create  0x02194670  thumb  ov021
 *   TALKMSGWIN_LoadTexture  0x02194704  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021D3E98     0x021D3E98  data  a4
 *   d_021D3E78     0x021D3E78  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00952.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int w[8]; } B32;
typedef struct { u16 a; int b; int c; u16 d; int e; u8 f; u8 g; } Req;

extern const B32 d_021D3E98;
extern const B32 d_021D3E78;
struct BgTemplate;
extern void BG_SYS_InitBgLayer(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
typedef unsigned int   u32;
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void FIELD_MSGBG_LoadWindowGraphicsAll(int, int);
extern void *TALKMSGWIN_Create(u16 *a);
extern void TALKMSGWIN_LoadTexture(void);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);

void FIELD_MSGBG_InitBgTwoLayerTalk(char *p, int flag)
{
    B32 tmp1;
    B32 tmp2;
    Req r;

    ((struct Obj00952 *)p)->f2 = 1;
    tmp1 = d_021D3E98;
    BG_SYS_InitBgLayer(((struct Obj00952 *)p)->f2 & 0xff, (const struct BgTemplate *)(&tmp1), 0);
    ((struct Obj00952 *)p)->f4 = 2;
    tmp2 = d_021D3E78;
    BG_SYS_InitBgLayer(((struct Obj00952 *)p)->f4 & 0xff, (const struct BgTemplate *)(&tmp2), 0);
    BG_SYS_Init(((struct Obj00952 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj00952 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(((struct Obj00952 *)p)->f4 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj00952 *)p)->f2 & 0xff);
    func_020409B4(((struct Obj00952 *)p)->f4 & 0xff);
    if (flag)
        FIELD_MSGBG_LoadWindowGraphicsAll(((struct Obj00952 *)p)->f2, ((struct Obj00952 *)p)->f0);
    if (((struct Obj00952 *)p)->f168 != 0) {
        r.a = ((struct Obj00952 *)p)->f0;
        r.b = ((struct Obj00952 *)p)->f168;
        r.c = ((struct Obj00952 *)p)->f8;
        r.d = 0xb;
        r.e = 1;
        r.f = 0xc;
        r.g = 0xb;
        ((struct Obj00952 *)p)->f15C = (int)TALKMSGWIN_Create((u16 *)(&r));
        TALKMSGWIN_LoadTexture();
    }
    func_0207D63C(0x04000050, 4, 0x1b, 0x10, 4);
    func_02040588(((struct Obj00952 *)p)->f2 & 0xff, 1);
    func_02040588(((struct Obj00952 *)p)->f4 & 0xff, 1);
    ((struct Obj00952 *)p)->f6 = 0xe;
}
