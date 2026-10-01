/*
 * function: func_021EE9F4
 * address: 0x021EE9F4
 * packet: pkt_ov170_021EE9F4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE408 0x021EE408 thumb ov170
 *   func_021EE754 0x021EE754 thumb ov170
 */
extern void func_020260E4(void *, unsigned char);
extern void func_021EE408(char *, int);
extern void func_021EE754(unsigned char *, unsigned);
#define WORK(p) (*(char **)((p) + 0x2c))
void func_021EE9F4(char *p, unsigned r)
{
    if (r - 0x25 <= 1) {
        func_020260E4(*(void **)(WORK(p) + 0x70), 0x24);
        r = 0x24;
    } else if (r - 0x28 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), *(unsigned *)(WORK(p) + 0xa168));
        r = *(unsigned *)(WORK(p) + 0xa168);
    } else {
        func_021EE408(p, r);
    }
    func_021EE754((unsigned char *)p, r);
    *(unsigned *)(WORK(p) + 0xa168) = r;
}
