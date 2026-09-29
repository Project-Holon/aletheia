/*
 * function: func_021F2DC8
 * address:  0x021F2DC8
 * packet:   pkt_ov029_021F2DC8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2DA8  0x021F2DA8  thumb  ov029
 *   func_021F05B4  0x021F05B4  thumb  ov029
 *   func_021F0F28  0x021F0F28  thumb  ov029
 */

extern int func_021F2DA8(char *p);
extern int func_021F05B4(char *p);
extern void func_021F0F28(char *p, int a);

void func_021F2DC8(char *p)
{
    if (func_021F2DA8(p) == 0 && *(unsigned char *)(p + 0x465) != 0) {
        *(unsigned char *)(p + 0x466) += 1;
        if (*(unsigned char *)(p + 0x466) >= 8) {
            if (func_021F05B4(p) != 0)
                func_021F0F28(p, 1);
            else
                func_021F0F28(p, 0);
            *(unsigned char *)(p + 0x465) = 0;
        }
    }
}
