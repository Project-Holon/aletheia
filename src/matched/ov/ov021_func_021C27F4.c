/*
 * function: func_021C27F4
 * address:  0x021C27F4
 * packet:   pkt_ov021_021C27F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020124F0  0x020124F0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021C2918  0x021C2918  thumb  ov021
 *   func_020437AC  0x020437AC  arm
 *   func_020307B0  0x020307B0  arm
 */

int func_020124F0(int a);
int func_020124E8(int a);
int func_020124E4(int a);
void *func_0201210C(void *p);
void func_021C2918(int a);
void func_020437AC(int a);
void func_020307B0(int a);

int func_021C27F4(int a, int *b)
{
    char *p;

    p = *(char **)func_020124E8(func_020124F0(a));
    func_0201210C(func_020124E4(a));
    switch (*b) {
    case 0:
        func_021C2918((int)p);
        (*b)++;
        break;
    case 1:
        func_020437AC(*(int *)(p + 0x90));
        func_020307B0(*(int *)(p + 0x94));
        func_020307B0(*(int *)(p + 0x98));
        (*b)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
