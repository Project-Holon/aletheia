/*
 * function: func_021DD24C
 * address: 0x021DD24C
 * packet: pkt_ov119_021DD24C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E2984 0x021E2984 thumb ov119
 *   func_021E2A80 0x021E2A80 thumb ov119
 *   func_021D89CC 0x021D89CC thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 */
extern void *func_021E2984(char *p, int a);
extern int func_021E2A80(void *);
extern void func_021D89CC(char *p);
extern void func_021D8E84(void *, int);
extern void func_021D9434(void *);
int func_021DD24C(char *p)
{
    if (*(int *)(p + 0x118c) == 3) {
        if (*(int *)(p + 0x648) == 0) func_021E2984(p, 0x9a);
        if (func_021E2A80(p)) {
            func_021D89CC(p);
            func_021D8E84(p, (int)func_021D9434);
            return 1;
        }
    }
    return 0;
}
