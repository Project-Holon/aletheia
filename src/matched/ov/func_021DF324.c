/*
 * function: func_021DF324
 * address:  0x021DF324
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Clamp p[0x16] to 0x1e below the limit of the p+0xc object's
 *   byte 0xf, then hand the object to the SDK.  The callee argument is the
 *   re-read expression, not the local, which is why the image re-loads it.
 */


extern void func_020307B0(void *p);
int func_021DF324(char *p)
{
    int q = *(int *)(p + 0xc);
    if (*(unsigned char *)(p + 0x18) == 0) {
        if (*(unsigned char *)(p + 0x16) < 0x1e)
            *(unsigned char *)(p + 0x16) = *(unsigned char *)(q + 0xf);
        else
            *(unsigned char *)(p + 0x16) = *(unsigned char *)(q + 0xf) + 0x1e;
    }
    func_020307B0((void *)(*(int *)(p + 0xc)));
    return 0;
}
