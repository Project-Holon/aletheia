/*
 * function: func_021B68E0
 * address:  0x021B68E0
 * packet:   pkt_ov071_021B68E0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02025470  0x02025470  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020254BC  0x020254BC  thumb
 *   func_02049238  0x02049238  arm
 */

void func_021B68E0(int *p)
{
    int func_020490F4(int, int);
    int func_02025470(int, int, int, int, int, int, int);
    int func_0204A6C8(int, int, int, int, int);
    int func_0204AF28(int, int, int, int);
    int func_020254BC(int, int, int, int, int, int, int);
    void func_02049238(int);
    int tmp;
    int i;
    int flag;
    int *e;

    tmp = func_020490F4(0x17, 0x61);
    for (i = 0; i < 2; i++) {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        e = p + i * 4;
        e[16] = func_02025470(p[0], p[1], p[12], 3, flag, 3, 0x61);
        e[17] = func_0204A6C8(p[12], 0, 1, flag, 0x61);
        e[18] = func_0204AF28(p[12], 1, 2, 0x61);
        e[19] = func_020254BC(p[0], p[1], tmp, 5, flag, 1, 0x61);
    }
    func_02049238(tmp);
}
