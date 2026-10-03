/*
 * function: func_0215610C
 * address:  0x0215610C
 * packet:   pkt_ov009_0215610C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_0216B838  0x0216B838  arm  ov009
 *   func_0216B94C  0x0216B94C  arm  ov009
 *   func_02176DEC  0x02176DEC  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern char *g_021A8264;
extern unsigned char func_0216B838(void);
extern int func_0216B94C(u8);
extern int func_02176DEC(u8);

int func_0215610C(void)
{
    int i;
    int found = 0;
    for (i = 0; i < *(int *)(g_021A8264 + 0x764); i++) {
        if (i != func_0216B838() && func_0216B94C(i)) {
            found = 1;
            if (func_02176DEC(i) == 0) {
                return 0;
            }
        }
    }
    return found;
}
