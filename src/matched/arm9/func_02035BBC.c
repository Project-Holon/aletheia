/*
 * function: TOUCHPANEL_HitTrgSys
 * address:  0x02035BBC
 * packet:   pkt_02035BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetWork  0x02035750  arm
 *   TOUCHPANEL_ReadTrg  0x020357C0  arm
 *   TOUCHPANEL_ReadPointX  0x02035760  arm
 *   TOUCHPANEL_ReadPointY  0x02035780  arm
 *   TOUCHPANEL_SearchHitTable  0x02035ADC  arm
 */

typedef unsigned int u32;

extern int TOUCHPANEL_GetWork(void);
typedef unsigned short u16;
struct Kind;
extern u16 TOUCHPANEL_ReadTrg(struct Kind *p);
struct R;
extern u16 TOUCHPANEL_ReadPointX(struct Kind *p);
extern u16 TOUCHPANEL_ReadPointY(struct Kind *p);
extern int TOUCHPANEL_SearchHitTable(struct R *p, u32 x, u32 y);

int TOUCHPANEL_HitTrgSys(void *ctx, void *param)
{
    void *a;
    void *b;

    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadTrg(ctx) == 0) {
        return -1;
    }

    a = (void *)TOUCHPANEL_ReadPointX(ctx);
    b = (void *)TOUCHPANEL_ReadPointY(ctx);

    return TOUCHPANEL_SearchHitTable(param, (u32)a, (u32)b);
}
