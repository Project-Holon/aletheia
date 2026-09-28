/*
 * function: GetPowerMode
 * address:  0x0205B790
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcac connect.o.
 * Two 2-bit bitfields in the byte at 0x14bb.
 */
typedef struct {
    unsigned char pad[0x14bb];
    unsigned char powerMode:2;
    unsigned char authMode:2;
} ACWORK;

unsigned long GetPowerMode(ACWORK *wk)
{
    return wk->powerMode == 1 ? 0x30000 : 0x20000;
}
