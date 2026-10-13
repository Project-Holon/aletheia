/*
 * function: func_021B9FBC
 * address:  0x021B9FBC
 * packet:   pkt_ov093_021B9FBC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 */

void *BTL_MAIN_GetCompetitor(void ***p);
typedef unsigned int   u32;
typedef unsigned char  u8;
int func_021BA1A8(char **p, int m);
u32 BTL_MAIN_GetRule(void **p);
int func_021B9F70(u8 *p, int i);

int func_021B9FBC(char *p, int i)
{
    if (BTL_MAIN_GetCompetitor((void ***)p) == 0) {
        i = 8;
        if (func_021BA1A8((char **)p, i)) {
            return i << 8;
        }
        if (BTL_MAIN_GetRule((void **)p) == 1) {
            return 0x80;
        }
    } else {
        if (func_021B9F70((u8 *)p, i)) {
            return *(int *)(p + i * 0x28 + 0x2c);
        }
    }
    return 0;
}
