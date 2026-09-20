/*
 * function: func_02005230
 * address:  0x02005230
 * packet:   pkt_0200520C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  0200567C
 */

extern void func_02005430(void);
extern void func_0200567C(void);
void func_02005230(void)
{
    func_02005430();
    func_0200567C();
}
