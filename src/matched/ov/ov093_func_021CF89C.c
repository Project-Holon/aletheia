/*
 * function: func_021CF89C
 * address: 0x021CF89C
 * packet: pkt_ov093_021CF89C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
extern void *func_021EFCE4(char *, int);
extern int func_021D62C4(void *, int);
extern int func_021D59B4(void *, int);
int func_021CF89C(u8 *p, void *q)
{
    if (func_021EFCE4(*(char **)(p+0x34), 7)) return 0;
    if (func_021D62C4(q, 19)) return 0;
    if (func_021D59B4(q, 17) != 103) return 1;
    return 0;
}
