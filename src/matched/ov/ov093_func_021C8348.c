/*
 * function: func_021C8348
 * address: 0x021C8348
 * packet: pkt_ov093_021C8348
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the 42-byte function.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 */
typedef unsigned char u8;
extern int func_021B9934(char *, int);
extern u8 func_021D69AC(u8 *, int);
int func_021C8348(u8 *p, int i)
{
    u8 n = func_021D69AC((u8 *)func_021B9934(*(char **)(p + 8), i), 4);
    if (n != 0) {
        n--;
        if (n < 24) goto done;
    }
    n = 31;
done:
    if (n != 31) return 1;
    return 0;
}
