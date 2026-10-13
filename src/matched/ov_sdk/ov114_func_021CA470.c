/*
 * function: DWCi_EncSessionGetAsync
 * address:  0x021CA470
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EncSessionGetPrivateAsync  0x021CA240  arm  ov114
 *
 *
 * Forwards five arguments and a zero tail to DWCi_EncSessionGetPrivateAsync.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int DWCi_EncSessionGetPrivateAsync(char *url, long pid, void *data, u32 size, int (*cb)(u32 *, int), int reuseHash);

int DWCi_EncSessionGetAsync(void *a, u32 b, void *c, u32 d, u32 e)
{
    return DWCi_EncSessionGetPrivateAsync((char *)a, b, (void *)c, d, (int (*)(u32 *, int))e, 0);
}
