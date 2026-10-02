/*
 * function: func_021F3118
 * address: 0x021F3118
 * packet: pkt_ov029_021F3118
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: caller sets r2=0x1514 despite two-input thunk/leaf; retained
 * in the caller extern to reproduce original argument setup.
 * symbols:
 *   func_021F2130 0x021F2130 thumb ov029
 *   func_021F30EC 0x021F30EC thumb ov029
 *   func_021F30C8 0x021F30C8 thumb ov029
 *   func_021EFEF8 0x021EFEF8 thumb ov029
 *   func_021F2180 0x021F2180 thumb ov029
 */
extern void func_021F2130(void *);
extern int func_021F30EC(void *);
extern void func_021F30C8(void *);
extern void func_021EFEF8(void *, void (*)(void *), int);
extern void func_021F2180(void *);
void func_021F3118(void *p)
{
    func_021F2130(p);
    if (func_021F30EC(p)) {
        func_021F30C8(p);
        func_021EFEF8(p, func_021F2180, 0x1514);
    }
}
