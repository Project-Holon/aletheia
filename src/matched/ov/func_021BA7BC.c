/*
 * function: WIFICLUBACTOR_RestartBlinkScript
 * address:  0x021BA7BC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUBACTOR_RequestBlinkRestart  0x021BA78C  thumb
 *
 * When the byte at +0x0D is set, runs the reset at WIFICLUBACTOR_RequestBlinkRestart on the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x0D];
    u8 f0D;
} S;

extern void WIFICLUBACTOR_RequestBlinkRestart(S *s);

void WIFICLUBACTOR_RestartBlinkScript(S *s)
{
    if (s->f0D != 0) {
        WIFICLUBACTOR_RequestBlinkRestart(s);
    }
}
