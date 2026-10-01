/*
 * function: func_021FF88C
 * address: 0x021FF88C
 * packet: pkt_ov186_021FF88C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02157170 0x02157170 thumb ov009
 *   func_02006210 0x02006210 thumb
 *   func_0200F7DC 0x0200F7DC thumb
 */
extern int func_02157170(int, int);
extern void func_02006210(void);
extern void func_0200F7DC(void);
int func_021FF88C(char *p)
{
    if (!p) return 0;
    switch (func_02157170(1, 0)) {
    case 1: func_02006210(); return 1;
    case 2: func_02006210(); *(int *)(p + 0x5dc) = 1; return 2;
    case 3: func_02006210(); func_0200F7DC(); break;
    }
    return 0;
}
