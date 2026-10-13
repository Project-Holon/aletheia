/*
 * function: NHTTPi_WaitForCompletion
 * address:  0x021BEA64
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
 *   OS_SleepThread  0x020857B0  arm  arm9
 *
 *
 * Drains the +0x0c queue of `p` by releasing the +0x1c resource each time.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetStaticResource(void);
extern void OS_SleepThread(void *);

void NHTTPi_WaitForCompletion(u8 *p)
{
    u8 *q = NHTTPi_GetStaticResource();
    while (*(u32 *)(p + 0xc) != 0)
        OS_SleepThread(q + 0x1c);
}
