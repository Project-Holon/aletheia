/*
 * function: WIFICLUBACTOR_StartBlinkScript
 * address:  0x021BA794
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_EndBlinkScript  0x021BA770  thumb  ov099
 *   WIFICLUBACTOR_RequestBlinkRestart  0x021BA78C  thumb  ov099
 *
 * Records the bit selector at +0x0C and toggles it in the byte mask at +0x08;
 * releases the previous holder through WIFICLUBACTOR_EndBlinkScript first when +0x0D is set,
 * and always finishes through WIFICLUBACTOR_RequestBlinkRestart.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUBACTOR_EndBlinkScript(void *p);
extern void WIFICLUBACTOR_RequestBlinkRestart(void *p);

void WIFICLUBACTOR_StartBlinkScript(u8 *p, u8 b)
{
    if (p[0xD] != 0) {
        WIFICLUBACTOR_EndBlinkScript(p);
    }

    p[0xC] = b;
    p[0x8] ^= (u8)(1 << b);
    WIFICLUBACTOR_RequestBlinkRestart(p);
}
