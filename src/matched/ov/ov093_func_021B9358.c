/*
 * function: func_021B9358
 * address: 0x021B9358
 * packet: pkt_ov093_021B9358
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D54F4 0x021D54F4 thumb ov093
 */
struct Work;
extern int func_021B9934(char *, int);
extern void func_021D54F4(struct Work *, struct Work *);
void func_021B9358(char *p, int i)
{
    int dst = func_021B9934(p + 0x1b0, i);
    int src = func_021B9934(p + 0xc8, i);
    func_021D54F4((struct Work *)src, (struct Work *)dst);
}
