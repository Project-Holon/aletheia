/*
 * function: GetAuthMode
 * address:  0x0205B7B0
 * packet:   pkt_02040000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlDWC libdwcac connect.o.
 */
typedef struct {
    unsigned char pad[0x14bb];
    unsigned char powerMode:2;
    unsigned char authMode:2;
} ACWORK;

unsigned long GetAuthMode(ACWORK *wk)
{
    return wk->authMode == 1 ? 0xc0000 : 0x80000;
}
