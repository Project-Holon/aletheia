/*
 * function: func_02069D14
 * address:  0x02069D14
 * packet:   pkt_020694D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  020A8234; 020A8238; 020A823C
 * symbols:
 *   g_020A823C      0x020A823C  data
 *   g_020A8238      0x020A8238  data
 *   g_020A8234      0x020A8234  data
 */

extern int g_020A823C;
extern int g_020A8238;
extern int g_020A8234;
extern void func_02082A7C(int v, void *dst, int n);
void func_02069D14(char *p, int a1)
{
    func_02082A7C(0, p, 0x54);
    *(int *)(p + 0xc) = g_020A823C;
    *(int *)(p + 0x14) = g_020A8238;
    *(int *)(p + 0x1c) = g_020A8234;
    *(int *)(p + 4) = a1;
}
