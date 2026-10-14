/*
 * function: BTLV_INPUT_DrawMessageText
 * address:  0x02205340
 * packet:   pkt_ov094_02205340
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_020498F4  0x020498F4  arm
 *   BTLV_INPUT_GetTextBlockSize  0x02204C98  thumb  ov094
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

typedef struct Main {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x224 - 0x4C];
    int o224;
    unsigned char pad228[0x22c - 0x228];
    int o22c;
    unsigned char pad230[0x240 - 0x230];
    u16 h240;
    unsigned char pad242[0x25a - 0x242];
    u8 b25a;
    u8 b25b;
} Main;

typedef unsigned int   u32;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
struct StrObj;
extern void BTLV_INPUT_GetTextBlockSize(struct StrObj *a, int b, int *outn, int *outq);

void BTLV_INPUT_DrawMessageText(Main *m, const int *c)
{
    int w;
    int h;

    GF_FONT_SetTextColor(1, 2, 0);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)c[0], m->o224, &w, &h);
    PRINTSYS_Print((void *)m->o22c, 0x80 - w / 2, 0x10, (void *)c[0], (void *)m->o224);
    BTLV_INPUT_GetTextBlockSize((struct StrObj *)c[1], m->o224, &w, &h);
    PRINTSYS_Print((void *)m->o22c, 0x80 - w / 2, 0x40, (void *)c[1], (void *)m->o224);
    m->b25a = 1;
    m->b25b = 1;
    func_020498F4((void *)m->f48, 0x6b, 5, 0, 0, 0, m->h240);
}
