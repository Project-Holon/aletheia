/*
 * function: APP_TASKMENU_WIN_CreateExNoScreen
 * address:  0x0202804C
 * packet:   pkt_02027FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   APP_TASKMENU_WIN_CreateCore  0x02028084  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 *APP_TASKMENU_WIN_CreateCore(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                          u32 a7, u32 a8);
struct Cfg;
struct Descriptor;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

u32 *APP_TASKMENU_WIN_CreateExNoScreen(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7,
                   u16 a8)
{
    u32 *p = APP_TASKMENU_WIN_CreateCore(a0, a1, a2, a3, a4, a5, a6, a7, a8);

    BMP_WIN_MakeScreen((void *)p[0]);
    func_02041B6C(BMP_WIN_GetBgLayer((void *)p[0]));
    return p;
}
