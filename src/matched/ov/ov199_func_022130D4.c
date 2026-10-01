/*
 * function: func_022130D4
 * address: 0x022130D4
 * packet: pkt_ov199_022130D4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02213808 0x02213808 thumb ov199
 */
extern void func_020307B0(void *);
extern void func_02213808(char *, int);
int func_022130D4(char *a, char *work, char *p)
{
    int state = *(int *)(work + 8);
    func_020307B0(work);
    if (*(int *)(p + 0x1c) == 1) {
        switch (state) {
        case 0: func_02213808(a, 3); break;
        case 2: *(int *)(p + 0x1c0) = 1; func_02213808(a, 0); break;
        }
    } else {
        switch (state) {
        case 0: func_02213808(a, 3); break;
        case 1: *(int *)(p + 0x220) = 1; func_02213808(a, 4); break;
        case 3: *(int *)(p + 0x20) = 2; func_02213808(a, 1); break;
        }
    }
    return 1;
}
