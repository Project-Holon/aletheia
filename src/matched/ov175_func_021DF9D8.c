/*
 * function: func_021DF9D8
 * address:  0x021DF9D8
 * packet:   pkt_ov175_021DF9D8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: scInitialize (TwlDWC/libdwcgssc.TWL.HYB.a, scimain.o),
 * ov175.  Create and initialise the SCI interface, then bind the owning
 * object into it and publish the handle.
 *
 * symbols:
 *   func_021DF7FC  0x021DF7FC  arm  ov175
 *   func_021DF884  0x021DF884  arm  ov175
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021DF7FC(void **);
extern int func_021DF884(void *);

int func_021DF9D8(u32 *p, u32 *out)
{
    int r;
    u8 *h = 0;

    if (out == 0)
        return 2;
    *out = 0;
    if ((r = func_021DF7FC((void **)&h)) != 0)
        return r;
    if ((r = func_021DF884(h)) != 0)
        return r;
    *(u32 *)(h + 0x4c) = (u32)p;
    *out = (u32)h;
    return 0;
}
