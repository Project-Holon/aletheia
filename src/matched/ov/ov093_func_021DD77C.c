/*
 * function: func_021DD77C
 * address: 0x021DD77C
 * packet: pkt_ov093_021DD77C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *func_021C7CF4(void *, int);
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern int func_021DDEA4(void *, int, unsigned int);
extern void func_021DD044(void *, void *, int);

void func_021DD77C(int a, void *b, int c, int *d)
{
    if (*d == 0 && func_021D62C4(func_021C7CF4(b, c), 15) == 0 && func_021DDEA4(b, c, 2) != 0) func_021DD044((void *)a, b, c);
}
