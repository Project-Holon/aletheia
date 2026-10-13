/*
 * function: WIFICLUBACTOR_TickBlinkFrame
 * address:  0x021BA674
 * packet:   pkt_ov099_021BA674
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_GetBlinkColors  0x021BA764  thumb  ov099
 *   func_02061CA4  0x02061CA4  arm
 *   d_021C2878     0x021C2878  data  ov099  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    char pad00[8];
    u8  f8;
    u8  f9;
    s16 fa;
} S;

extern const u16 d_021C2878[];
extern u16 *WIFICLUBACTOR_GetBlinkColors(S *s, int i);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

void WIFICLUBACTOR_TickBlinkFrame(S *s)
{
    int i;
    int k;

    s->fa = s->fa - 1;
    if (s->fa <= 0) {
        k = 2;
        s->f9 = (s->f9 + 1) % 2;
        s->fa = d_021C2878[s->f9];
        if (s->f9 != 1) {
            k = 1;
        }
        for (i = 0; i < 4; i++) {
            if (s->f8 & (1 << i)) {
                func_02061CA4((void *)0xf, (i + 1) * 2 + 0xe0, (u32)WIFICLUBACTOR_GetBlinkColors(s, k), 2);
            }
        }
    }
}
