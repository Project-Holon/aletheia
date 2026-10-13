/*
 * function: TOUCHPANEL_GetContSys
 * address:  0x02035C20
 * packet:   pkt_02035C20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetWork   0x02035750  arm
 *   TOUCHPANEL_ReadCont   0x020357A0  arm
 */

extern int TOUCHPANEL_GetWork(void);
struct Kind;
extern int TOUCHPANEL_ReadCont(struct Kind *p);

int TOUCHPANEL_GetContSys(const void *p)
{
    TOUCHPANEL_GetWork();
    return TOUCHPANEL_ReadCont((struct Kind *)p);
}
