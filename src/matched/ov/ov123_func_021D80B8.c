/*
 * function: func_021D80B8
 * address: 0x021D80B8
 * packet: pkt_ov123_021D80B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021D6EBC 0x021D6EBC thumb ov123
 *   func_021D6EA4 0x021D6EA4 thumb ov123
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D59E4 0x021D59E4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7F9C 0x021D7F9C thumb ov123
 */
extern int func_021D6E70(char *);
extern int func_021D6EBC(char *);
extern int func_021D6EA4(char *);
extern int func_021B95D4(int, void *);
extern int func_021B9748(void *);
extern void func_021D5950(char *, int);
extern void func_021D59E4(char *);
extern void func_021D6EE0(char *, int, int);
extern void func_021D7F9C(void);
void func_021D80B8(char *p)
{
    if (func_021D6E70(p) && !func_021D6EBC(p)) {
        if (func_021B95D4(2, *(void **)(p + 0x10)) && !func_021B9748(*(void **)(p + 0x10))) {
            func_021D6EE0(p, (int)func_021D7F9C, 0x59d);
            return;
        }
    } else {
        if (func_021D6EA4(p)) {
            *(int *)(p + 0x74) = 0;
            func_021D5950(*(char **)(p + 0x18), 42);
            func_021D59E4(*(char **)(p + 0x18));
        } else {
            *(int *)(p + 0x74) = 0x42e;
        }
        func_021D6EE0(p, (int)func_021D7F9C, 0x5aa);
    }
}
