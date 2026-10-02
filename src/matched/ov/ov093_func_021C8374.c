/*
 * function: func_021C8374
 * address: 0x021C8374
 * packet: pkt_ov093_021C8374
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C8348 0x021C8348 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
typedef unsigned char u8;
struct Unk021D62A8;
extern int func_021C8348(u8 *, int);
extern int func_021B9934(char *, int);
extern int func_021D62C4(struct Unk021D62A8 *, int);
int func_021C8374(u8 *p, int i)
{
    if (func_021C8348(p, i)) return 1;
    if (func_021D62C4((struct Unk021D62A8 *)func_021B9934(*(char **)(p + 8), i), 33)) return 1;
    return 0;
}
