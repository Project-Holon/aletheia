/*
 * function: func_021DD240
 * address: 0x021DD240
 * packet: pkt_ov093_021DD240
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021DD338 0x021DD338 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
typedef unsigned char u8;
extern int func_021D775C(int);
extern u8 func_021DD338(void *, int);
extern void func_021DD044(void *, void *, int);
void func_021DD240(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021DD338(b, c) != 4)
            func_021DD044(a, b, c);
    }
}
