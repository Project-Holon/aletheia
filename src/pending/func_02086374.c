/*
 * function: func_02086374
 * address:  0x02086374
 * packet:   pkt_02086368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  one concrete byte: the `bl` mwccarm emits for func_02005438
 *           where the linker wrote `blx` (its ISA is only known at link
 *           time), plus thirteen callees that are each called from exactly
 *           one site in the image, this function's, so `label` refuses them.
 *           Fifteen of the eighteen `bl`s do resolve.  See
 *           docs/notes/pkt_02086368.c.txt section 3.
 *
 * A straight-line driver: eighteen calls in a fixed order, two of them
 * gated on func_02085D3C() reporting exactly 1.  Nothing here sets an
 * argument register, so every callee is called with no arguments.
 */

extern void func_02088498(void);
extern void func_020863E0(void);
extern void func_02084B90(void);
extern void func_020864FC(void);
extern void func_0208475C(void);
extern void func_020849F4(void);
extern void func_02086DD8(void);
extern void func_0208361C(void);
extern void func_02087578(void);
extern void func_02087EA8(void);
extern void func_02085264(void);
extern void func_02087B78(void);
extern void func_02005438(void);
extern void func_02075CAC(void);
extern void func_02082198(void);
extern int  func_02085D3C(void);
extern void func_0208C960(void);
extern void func_0208B8B0(void);
extern void func_02086348(void);
extern void func_020883D4(void);

void func_02086374(void)
{
    func_02088498();
    func_020863E0();
    func_02084B90();
    func_020864FC();
    func_0208475C();
    func_020849F4();
    func_02086DD8();
    func_0208361C();
    func_02087578();
    func_02087EA8();
    func_02085264();
    func_02087B78();
    func_02005438();
    func_02075CAC();
    func_02082198();
    if (func_02085D3C() == 1)
        func_0208C960();
    func_0208B8B0();
    func_02086348();
    if (func_02085D3C() != 1)
        return;
    func_020883D4();
}
