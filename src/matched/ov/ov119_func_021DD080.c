/*
 * function: func_021DD080
 * address: 0x021DD080
 * packet: pkt_ov119_021DD080
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_02039C68 0x02039C68 arm
 */
extern int func_021D8A24(void *);
extern void func_02039C68(void *, void *, int);
void func_021DD080(void *a, void *b, void *c)
{
    if (func_021D8A24(c))
        func_02039C68(a, b, 8);
}
