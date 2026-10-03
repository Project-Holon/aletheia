/*
 * function: func_021D8304
 * address: 0x021D8304
 * packet: pkt_ov123_021D8304
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D580C 0x021D580C thumb ov123
 *   func_021D5890 0x021D5890 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8270 0x021D8270 thumb ov123
 */
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern int func_021D580C(char *);
extern void *func_021D5890(char *, int);
extern void func_021D6EE0(char *, int, int);
extern void func_021D8270(char *p);
void func_021D8304(char *p)
{
    if (*(int *)(p + 0x64) % 110 == 0) func_020061E4(0x659);
    (*(int *)(p + 0x64))++;
    if (func_021D580C(*(char **)(p + 0x18))) {
        *(void **)(p + 0x1c) = func_021D5890(*(char **)(p + 0x18), 0);
        func_021D6EE0(p, (int)func_021D8270, 0x632);
    }
}
