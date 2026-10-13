/*
 * function: PMS_WORDLIST_MoveByKeys
 * address: 0x021BF208
 * packet: pkt_ov110_021BF208
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_WORDLIST_GetSelectedIndex 0x021BEDD0 thumb ov110
 *   PMS_WORDLIST_PageUp 0x021BF338 thumb ov110
 *   PMS_WORDLIST_PageDown 0x021BF360 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PMS_WORDLIST_GetSelectedIndex(u8 *);
extern int PMS_WORDLIST_PageUp(u8 *p);
extern u32 PMS_WORDLIST_PageDown(u8 *);
int PMS_WORDLIST_MoveByKeys(u8 *p, u32 keys)
{
    u32 r;
    if (keys & 0x80) {
        if (*(u16 *)(p + 0xC) != 0)
            return 4;
        if (p[7] < 5) {
            p[7]++;
            r = PMS_WORDLIST_GetSelectedIndex(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            if (r == (u32)*(u16 *)(p + 4) - 2) {
                if (r & 1) {
                    p[6] = 0;
                    return 1;
                }
                p[7]--;
                return 4;
            }
            p[7]--;
            return 4;
        }
        if (*(u16 *)p < *(u16 *)(p + 2)) {
            *(u32 *)(p + 8) = 1;
            *(u16 *)p = *(u16 *)p + 1;
            r = PMS_WORDLIST_GetSelectedIndex(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 2;
            p[6] = 0;
            return 3;
        }
        return 4;
    }
    if (keys & 0x40) {
        if (*(u16 *)(p + 0xC) != 0) {
            *(u16 *)(p + 0xC) = 0;
            return 1;
        }
        if (p[7] != 0) {
            p[7]--;
            return 1;
        }
        if (*(u16 *)p != 0) {
            *(int *)(p + 8) = -1;
            *(u16 *)p = *(u16 *)p - 1;
            return 2;
        }
        return 4;
    }
    if (keys & 0x20) {
        if (p[6] == 1) {
            p[6] ^= 1;
            r = PMS_WORDLIST_GetSelectedIndex(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x10) {
        if (p[6] == 0) {
            p[6] ^= 1;
            r = PMS_WORDLIST_GetSelectedIndex(p);
            if (r < (u32)*(u16 *)(p + 4) - 2)
                return 1;
            p[6] ^= 1;
        }
        return 4;
    }
    if (keys & 0x200)
        return PMS_WORDLIST_PageUp(p);
    if (keys & 0x100)
        return PMS_WORDLIST_PageDown(p);
    return 0;
}
