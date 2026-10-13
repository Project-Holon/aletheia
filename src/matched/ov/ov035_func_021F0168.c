/*
 * function: C_GEAR_POWER_ONOFF_InitWindows
 * address:  0x021F0168
 * packet:   pkt_ov035_021F0168
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_InitWindows 0x021F0168 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_SetDispHeight 0x02045790 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   TCBL_Create 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 */

extern void func_02049B40(int, int, int, int, int, int);
extern void *func_0201F5DC(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct CharBuf;
struct Descriptor;
extern void BMP_WIN_SetDispHeight(struct Descriptor *p, u8 v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern int TCBL_Create(int, int, int, int);
extern int func_02028590(int, int, int, int);

void C_GEAR_POWER_ONOFF_InitWindows(int *p, int a1)
{
    func_02049B40(0x17, 5, 4, 0x20, 0x20, a1);
    p[5] = (int)func_0201F5DC((void *)5, 2, 0, a1);
    p[6] = BMP_WIN_Create(5, 1, 1, 0x1E, 6, 1, 1);
    p[7] = BMP_WIN_Create(5, 1, 0xD, 0x1E, 0xA, 1, 1);
    BMP_WIN_SetDispHeight((struct Descriptor *)p[6], 4);
    BMP_Clear((struct CharBuf *)func_02045770((struct Descriptor *)p[6]), 0xF);
    BMP_WIN_TransferChars((struct Descriptor *)p[6]);
    BMP_WIN_MakeScreen((struct Cfg *)p[6]);
    BMP_Clear((struct CharBuf *)func_02045770((struct Descriptor *)p[7]), 0xF);
    BMP_WIN_TransferChars((struct Descriptor *)p[7]);
    BMP_WIN_MakeScreen((struct Cfg *)p[7]);
    p[8] = TCBL_Create(a1, a1, 1, 4);
    p[0xC] = func_02028590(0xF, 0, 1, a1);
}
