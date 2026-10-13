/*
 * function: NHTTPi_destroyCommThread
 * address:  0x021B9BD4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_kickCommThread  0x021B9C08  arm  ov114
 *   OS_JoinThread  0x02085710  arm  arm9
 *
 *
 * Seeds a work record at +0x18, registers it, then arms the +0x2c timer.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void NHTTPi_kickCommThread(int);
extern void OS_JoinThread(void *);

void NHTTPi_destroyCommThread(int a, u8 *p)
{
    *(u32 *)(p + 0x18) = 1;
    NHTTPi_kickCommThread(a);
    OS_JoinThread((char *)a + 0x2c);
}
