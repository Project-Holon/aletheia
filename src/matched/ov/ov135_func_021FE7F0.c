/*
 * function: func_021FE7F0
 * address: 0x021FE7F0
 * packet: pkt_ov135_021FE7F0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02006210 0x02006210 thumb
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   func_021FF474 0x021FF474 thumb ov135
 */
extern void func_02006210(void);
extern void func_021FFB20(char *, int, int);
extern void func_021FF474(void *, void *, int, void *);
int func_021FE7F0(char *p)
{
    if (*(int *)(p + 0x12e8) == 0) {
        func_02006210();
        func_021FFB20(p, *(int *)(p + 0xd0), 1);
        if (*(int *)(p + 0xd0) == 0)
            func_021FF474(*(void **)(p + 0xdb0), *(void **)(p + 0xb6c), 0, p + 0xfa0);
        else
            func_021FF474(*(void **)(p + 0xdb0), *(void **)(p + 0xb6c), 1, p + 0xfa0);
        *(int *)(p + 0x28) = 20;
    }
    return 2;
}
