/*
 * function: func_02189108
 * address:  0x02189108
 * packet:   pkt_ov021_02189108
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005C8C  0x02005C8C  thumb
 *   func_0216CD78  0x0216CD78  thumb  ov010
 *   func_021C6470  0x021C6470  thumb  ov021
 *   func_0204A648  0x0204A648  arm
 *   func_021D31AC  0x021D31AC  thumb  ov021
 */

int func_02005C8C(void);
void func_0216CD78(int h);
void func_021C6470(int h);
void func_0204A648(void);
void func_021D31AC(int h);

void func_02189108(int unused, unsigned char *p)
{
    if (func_02005C8C() == 0) {
        if (*(int *)(p + 0x38) != 0)
            func_0216CD78(*(int *)(p + 0x38));
        if (*(int *)(p + 0x130) != 0)
            func_021C6470(*(int *)(p + 0x130));
    }
    func_0204A648();
    if (*(int *)(p + 0x14C) != 0)
        func_021D31AC(*(int *)(p + 0x14C));
}
