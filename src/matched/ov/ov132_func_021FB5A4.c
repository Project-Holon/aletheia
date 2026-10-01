/*
 * function: func_021FB5A4
 * address: 0x021FB5A4
 * packet: pkt_ov132_021FB5A4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F80A0 0x021F80A0 thumb ov112
 */
typedef unsigned char u8;
extern int func_0201134C(void *);
extern int func_021FB1F4(char *, int);
extern char *func_021F9DA0(void *);
extern char *func_021F9DA4(void *, int);
extern void func_021F80A0(char *, char *);
int func_021FB5A4(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char **)p;
    mask = func_021FB1F4(p, func_0201134C(*(void **)(p + 4)));
    ctx = func_021F9DA0(*(void **)(obj + 0x34));
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80A0(ctx, func_021F9DA4(*(void **)(obj + 0x34), i));
        }
    }
    return 0;
}
