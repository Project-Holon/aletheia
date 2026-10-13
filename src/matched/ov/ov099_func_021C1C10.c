/*
 * function: WIFICLUB_IsSlotPanelDismissed
 * address:  0x021C1C10
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHBAR_Update  0x021B63D0  thumb  ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone  0x021B6448  thumb  ov067
 */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    char pad[0x8ef];
    u8 f8ef;                /* 0x8ef */
    char pad8f0[0xbc];
    void *f9ac;             /* 0x9ac */
} Work;

struct S;
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *p);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);

int WIFICLUB_IsSlotPanelDismissed(Work *w)
{
    if (w->f8ef == 3)
        return 0;
    if (w->f9ac != 0) {
        TOUCHBAR_Update(w->f9ac);
        if (TOUCHBAR_GetPressedButtonIdIfDone(w->f9ac) == 1)
            return 1;
    }
    if ((KEY_GetCont() & 0xf0) || (KEY_GetTrg() & 0x403))
        return 1;
    return 0;
}
