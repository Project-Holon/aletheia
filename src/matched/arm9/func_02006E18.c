/*
 * function: func_02006E18
 * address:  0x02006E18
 * packet:   pkt_02006E18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006E2C  0x02006E2C  thumb
 *   func_02007BD0  0x02007BD0  thumb
 */

extern void *func_02006E2C(void);
typedef signed char    s8;
struct PerapVoice;
extern void func_02007BD0(struct PerapVoice *p, const s8 *src);

void func_02006E18(void *a0)
{
    void *res = func_02006E2C();
    func_02007BD0(a0, res);
}
