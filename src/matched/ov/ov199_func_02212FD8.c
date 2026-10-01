/*
 * function: func_02212FD8
 * address: 0x02212FD8
 * packet: pkt_ov199_02212FD8
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02213D04 0x02213D04 data a1 ov199
 */
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, int, int);
extern const char d_02213D04[];
int *func_02212FD8(int unused, unsigned heap, char *ctx)
{
    int zero = 0;
    int *p = func_02030734(heap, 0x28, zero, d_02213D04, 0x588);
    func_02082BCC(p, zero, 0x28);
    p[0] = *(int *)(ctx + 4);
    p[1] = zero;
    p[2] = 1;
    p[4] = (int)(ctx + 0x40);
    if (*(int *)(ctx + 0xc) == 0) p[3] = 0x24;
    else p[3] = 0x34;
    if (*(int *)(ctx + 0x220)) {
        *(int *)(ctx + 0x220) = zero;
        p[5] = 1;
    } else p[5] = zero;
    return p;
}
