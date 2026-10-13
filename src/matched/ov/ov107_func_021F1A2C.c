/*
 * function: func_021F1A2C
 * address:  0x021F1A2C
 * packet:   pkt_ov107_021F1A2C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 */

typedef struct {
    unsigned char pad00[0x50];
    void *f50;
} Ov107Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 BMP_MENU_ProcessYesNo(u8 *p);

int func_021F1A2C(Ov107Ctx *p)
{
    int r = BMP_MENU_ProcessYesNo(p->f50);
    if (r == 0) {
        p->f50 = 0;
        return 1;
    }
    if (r == -2) {
        p->f50 = 0;
        return 2;
    }
    return 0;
}
