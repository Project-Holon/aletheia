/*
 * function: TOUCHPANEL_HitContSys
 * address:  0x02035B58
 * packet:   pkt_02035ADC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   TOUCHPANEL_GetWork 0x02035750  arm
 *   TOUCHPANEL_ReadCont 0x020357A0  arm
 *   TOUCHPANEL_ReadPointX 0x02035760  arm
 *   TOUCHPANEL_ReadPointY 0x02035780  arm
 *   TOUCHPANEL_SearchHitTable 0x02035ADC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int TOUCHPANEL_GetWork(void);
typedef unsigned short u16;
struct Kind;
extern int TOUCHPANEL_ReadCont(struct Kind *p);
extern u16 TOUCHPANEL_ReadPointX(struct Kind *p);
extern u16 TOUCHPANEL_ReadPointY(struct Kind *p);
struct R;
extern int TOUCHPANEL_SearchHitTable(struct R *p, u32 x, u32 y);

int TOUCHPANEL_HitContSys(u32 a, u32 b)
{
    u32 x;
    u32 y;

    TOUCHPANEL_GetWork();
    if (TOUCHPANEL_ReadCont((struct Kind *)a) == 0) {
        return -1;
    }
    x = TOUCHPANEL_ReadPointX((struct Kind *)a);
    y = TOUCHPANEL_ReadPointY((struct Kind *)a);
    return TOUCHPANEL_SearchHitTable((struct R *)b, x, y);
}
