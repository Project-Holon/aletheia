/*
 * function: sakeSetFileUploadURL
 * address:  0x021DD4B0
 * packet:   pkt_021DD4B0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sFileUploadUrlOverride  0x021E4C08  data
 *
 * Flush gate, second queue: a null destination or source is refused with 0,
 * otherwise the 0x021E4C08 block is released and 1 comes back.
 */

typedef unsigned long u32;

extern u32 sFileUploadUrlOverride[];
extern char *func_02094798(char *dst, const char *src);

int sakeSetFileUploadURL(char *a, char *b)
{
    if (a == 0 || b == 0)
        return 0;
    func_02094798((char *)((u32)sFileUploadUrlOverride), b);
    return 1;
}

