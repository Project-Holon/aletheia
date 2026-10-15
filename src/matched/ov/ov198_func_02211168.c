/*
 * function: B_PLIST_MAIN_BeginMode8
 * address: 0x02211168
 * packet: pkt_ov198_02211168
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_ApplyMode 0x02210C88 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int B_PLIST_MAIN_ApplyMode(u8 *, unsigned);
int B_PLIST_MAIN_BeginMode8(u8 *p)
{
    int mode = 8;
    if (B_PLIST_MAIN_ApplyMode(p, mode) == 0) {
        p[0x2498] = (*(u8 **)p)[0x20];
        return 0x13;
    }
    return mode;
}
