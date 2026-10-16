/*
 * function: BTL_REC_SEL_StartTimer
 * address: 0x021BA6A0
 * packet: pkt_ov214_021BA6A0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035630 0x02035630 arm
 *   BTL_REC_SEL_DrawCounter 0x021BA794 thumb ov214
 */
struct BtlRecSel {
    unsigned char pad_0[0xAC];
    unsigned int timerA;      /* 0xAC */
    unsigned int timerB;      /* 0xB0 */
    int busy;                 /* 0xB4 */
    int menuOpen;             /* 0xB8 */
    int lastMode;             /* 0xBC */
    unsigned short lastValue; /* 0xC0 */
};
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_02035630(void);
extern void BTL_REC_SEL_DrawCounter(void *, void *, unsigned int);
void BTL_REC_SEL_StartTimer(void *obj, char *p, u32 v)
{
    u32 threshold;
    if (func_02035630() == 30) threshold = 30;
    else threshold = 60;
    ((struct BtlRecSel *)p)->timerA = threshold * (v + 1) - 1;
    ((struct BtlRecSel *)p)->timerB = threshold >> 1;
    ((struct BtlRecSel *)p)->busy = 0;
    ((struct BtlRecSel *)p)->menuOpen = 0;
    ((struct BtlRecSel *)p)->lastMode = 0;
    ((struct BtlRecSel *)p)->lastValue = 0;
    BTL_REC_SEL_DrawCounter(obj, p, v);
}
