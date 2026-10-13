/*
 * function: NHTTPi_NotifyCompletion
 * address:  0x021BEA98
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_GetStaticResource  0x021BEA20  arm  ov114
 *   OS_WakeupThread  0x02085800  arm  arm9
 *
 *
 * Clears the +0x0c queue of `p` and re-arms the +0x1c resource.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetStaticResource(void);
extern void OS_WakeupThread(void *, int);

void NHTTPi_NotifyCompletion(u8 *p)
{
    u8 *q = NHTTPi_GetStaticResource();
    *(u32 *)(p + 0xc) = 0;
    OS_WakeupThread(q + 0x1c, 0);
}
