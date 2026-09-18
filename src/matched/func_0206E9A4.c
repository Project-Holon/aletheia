/*
 * function: func_0206E9A4
 * address:  0x0206E9A4
 * packet:   pkt_0206E9A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E9A4.c \
 *       --func func_0206E9A4 --addr 0x0206E9A4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 *func_0206E9A4(u8 *p, u32 idx)
{
    u8 *q;
    u8 *h;
    u32 off;

    if (p == 0)
        goto ret0;
    q = p + *(u32 *)(p + *(u16 *)(p + 0xC));
    h = q + 8;
    if (h == 0)
        goto fail;
    if (idx >= *(u8 *)(q + 9))
        goto fail;
    off = *(u16 *)(q + 0xE);
    idx = *(u16 *)(h + off) * idx + ((u32)h + off + 4);
    goto end;
fail:
    idx = 0;
end:
    if (idx != 0)
        return q + *(u32 *)idx;
ret0:
    return 0;
}
