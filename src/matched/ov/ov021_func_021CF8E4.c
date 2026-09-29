/*
 * function: func_021CF8E4
 * address:  0x021CF8E4
 * packet:   pkt_ov021_021CF8E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Counts the party members whose value func_021CFA04 accepts.
 *
 * symbols:
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021CFA04  0x021CFA04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02012934(void *p);
extern int   func_0201AA18(void *party);
extern void *func_0201AB28(void *party, int i);
extern u32   func_02017E1C(void *p, u32 id, u32 v);
extern int   func_021CFA04(void *a, u32 b, int c);

int func_021CF8E4(void *a, void *src, int c)
{
    void *party = func_02012934(src);
    int cnt = func_0201AA18(party);
    int n = 0;
    int i;

    for (i = 0; i < cnt; i++) {
        void *p = func_0201AB28(party, i);
        if (func_02017E1C(p, 0x4c, 0) == 0) {
            u32 v = func_02017E1C(p, 7, 0);
            if (func_021CFA04(a, v, c) != 0) {
                n++;
            }
        }
    }
    return n;
}
