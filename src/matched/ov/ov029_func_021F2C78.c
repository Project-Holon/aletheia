/*
 * function: func_021F2C78
 * address:  0x021F2C78
 * packet:   pkt_ov029_021F2C78
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2E68  0x021F2E68  thumb  ov029
 *   func_021F2E8C  0x021F2E8C  thumb  ov029
 */

extern void func_021F2E68(char *a, int b);
extern int func_021F2E8C(char *a);

int func_021F2C78(char *p)
{
    switch (*(unsigned char *)(p + 0x455)) {
    case 0:
        switch (*(unsigned char *)(p + 0x416)) {
        case 3:
            func_021F2E68(p + 0x21c, 0x1c0);
            break;
        case 4:
            func_021F2E68(p + 0x21c, 0x200);
            break;
        }
        *(unsigned char *)(p + 0x455) += 1;
        break;
    case 1:
        if (func_021F2E8C(p + 0x21c) != 0)
            return 1;
        break;
    }
    return 0;
}
