/*
 * function: func_021CF940
 * address:  0x021CF940
 * packet:   pkt_ov021_021CF940
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Counts the 30 slots whose value func_021CFA04 accepts.
 *
 * symbols:
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   func_020079BC  0x020079BC  thumb
 *   func_021CFA04  0x021CFA04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);
extern int func_021CFA04(int a, int v, void *l);

int func_021CF940(void *a, void *src, void *b, int *c)
{
    void *h = (void *)GAME_DATA_GetBoxManager(src);
    int n = 0;
    int i;

    for (i = 0; i < 30; i++) {
        if (func_020079BC(h, (u32)b, i, 0xa9, 0) != 0) {
            if (func_020079BC(h, (u32)b, i, 0x4c, 0) == 0) {
                u32 v = func_020079BC(h, (u32)b, i, 7, 0);
                if (func_021CFA04((int)a, v, (void *)c) != 0) {
                    n++;
                }
            }
        }
    }
    return n;
}
