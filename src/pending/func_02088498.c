/*
 * function: func_02088498
 * address:  0x02088498
 * packet:   pkt_02088498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  ABS32 func_020884A4 at +0x08: the callee is the next function and nothing outside branches to it
 */

extern void func_020884A4(void);
void func_02088498(void)
{
    func_020884A4();
}
