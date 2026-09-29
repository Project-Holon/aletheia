/*
 * function: func_021BA230
 * address:  0x021BA230
 * packet:   pkt_ov088_021BA230
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB840  0x021BB840  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 */

extern int func_021BB840(void *, int);
extern void func_021BB810(void *, int, int, int);

int func_021BA230(char *p)
{
    switch (*(unsigned char *)(p + 0x12d)) {
    case 0:
    case 2:
        if (*(unsigned char *)(p + 0x12e) == 0) {
            func_021BB810(p, *(unsigned char *)(p + *(unsigned char *)(p + 0x128) + 0x120),
                          func_021BB840(p, *(signed char *)(p + 0x12f)), 3);
            *(unsigned char *)(p + 0x12e) = 4;
            *(unsigned char *)(p + 0x12d) = *(unsigned char *)(p + 0x12d) + 1;
        } else {
            *(unsigned char *)(p + 0x12e) -= 1;
        }
        break;
    case 1:
    case 3:
        if (*(unsigned char *)(p + 0x12e) == 0) {
            func_021BB810(p, *(unsigned char *)(p + *(unsigned char *)(p + 0x128) + 0x120),
                          func_021BB840(p, *(signed char *)(p + 0x12f)), 1);
            *(unsigned char *)(p + 0x12e) = 4;
            *(unsigned char *)(p + 0x12d) = *(unsigned char *)(p + 0x12d) + 1;
        } else {
            *(unsigned char *)(p + 0x12e) -= 1;
        }
        break;
    case 4:
        return *(int *)(p + 0x140);
    }
    return 3;
}
