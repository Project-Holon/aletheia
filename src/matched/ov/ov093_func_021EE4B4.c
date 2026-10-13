/*
 * function: BTLV_SCU_StepBallWindowRefresh
 * address:  0x021EE4B4
 * packet:   pkt_ov093_021EE4B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_ReadStatsFromMon  0x021D590C  thumb  ov093
 *   BTL_MSG_BuildBallStatusRefresh  0x021EF7AC  thumb  ov093
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct C {
    u8 pad00[0x8];
    int f08;
    int f0c;
    u8 pad10[0x14];
    int f24;
    u8 pad28[0xc];
    int f34;
    u8 pad38[0x134];
    int f16c;
    u16 f170;
    u16 f172;
    u16 f174;
    u16 f176;
    u16 f178;
    u16 f17a;
    u16 f17c;
};

typedef signed short   s16;
struct CharBuf;
extern void BTL_POKEPARAM_ReadStatsFromMon(void **p, u16 *out);
extern void BTL_MSG_BuildBallStatusRefresh(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_020061E4(u32 a);

int BTLV_SCU_StepBallWindowRefresh(int *st, struct C *c)
{
    switch (*st) {
    case 0:
        BTL_POKEPARAM_ReadStatsFromMon((void **)c->f16c, &c->f170);
        BTL_MSG_BuildBallStatusRefresh(c->f34, c->f172, c->f174, c->f176, c->f178, c->f17a, c->f17c);
        BMP_Clear((struct CharBuf *)c->f0c, 12);
        PRINTSYS_Print((void *)c->f0c, 0, 0, (void *)c->f34, (void *)c->f24);
        (*st)++;
        break;
    case 1:
        BMP_WIN_TransferChars((struct Descriptor *)c->f08);
        func_020061E4(0x547);
        (*st)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
