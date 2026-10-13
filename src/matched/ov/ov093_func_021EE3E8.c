/*
 * function: BTLV_SCU_StepBallWindowOpen
 * address:  0x021EE3E8
 * packet:   pkt_ov093_021EE3E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_DrawFrame 0x020454E0 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BTL_MSG_BuildBallStatusOpen 0x021EF71C thumb ov093
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02040618 0x02040618 arm
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct C {
    u8 pad00[8];
    void *f08;
    int f0c;
    u32 f10;
    u8 pad14[0x10];
    int f24;
    u8 pad28[0xc];
    u32 f34;
    u8 pad38[0x138];
    u16 f170, f172, f174, f176, f178, f17a, f17c;
};
struct Cfg;
struct Descriptor;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_DrawFrame(struct Cfg *cfg, u16 base, u32 pal);
typedef signed short   s16;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void BTL_MSG_BuildBallStatusOpen(u32, u32, u32, u32, u32, u32, u32);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020061E4(u32 a);
int BTLV_SCU_StepBallWindowOpen(int *st, struct C *c)
{
    switch (*st) {
    case 0:
        GF_FONT_SetTextColor(1, 9, 12);
        BMP_WIN_MakeScreen(c->f08);
        BMP_WIN_DrawFrame(c->f08, c->f10, 3);
        BMP_Clear((struct CharBuf *)c->f0c, 12);
        func_020409B4(func_02045730(c->f08));
        (*st)++;
        break;
    case 1:
        BTL_MSG_BuildBallStatusOpen(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        PRINTSYS_Print((void *)c->f0c, 0, 0, (void *)c->f34, (void *)c->f24);
        (*st)++;
        break;
    case 2:
        BMP_WIN_TransferChars(c->f08);
        (*st)++;
        break;
    case 3:
        func_02040618(3, 0, 0);
        func_02040618(3, 3, 0x100);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
