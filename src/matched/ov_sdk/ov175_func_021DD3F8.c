/*
 * function: sakeSetFileDownloadURL
 * address:  0x021DD3F8
 * packet:   pkt_021DD3F8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sFileDownloadUrlOverride  0x021E4B88  data
 *   strcpy  0x02094798  arm  arm9
 *
 * Flush gate: a null destination or source is refused with 0, otherwise the
 * 0x021E4B88 block is released and 1 comes back.
 */

typedef unsigned long u32;

extern u32 sFileDownloadUrlOverride[];
extern char *strcpy(char *dst, const char *src);

int sakeSetFileDownloadURL(char *a, char *b)
{
    if (a == 0 || b == 0)
        return 0;
    strcpy((char *)((u32)sFileDownloadUrlOverride), b);
    return 1;
}

