/*
 * function: func_0217BA10
 * address: 0x0217BA10
 * packet: pkt_ov019_0217BA10
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0201A364 has no witness outside this caller range.
 * Interface evidence: stub at 0201A364 moves r0 to r2, r1 to r0,
 * sets r1=0x69, then jumps through pool 02048F4C. Ilias owns it.
 * symbols:
 *   func_0217B908 0x0217B908 thumb ov019
 *   func_0217B974 0x0217B974 thumb ov019
 *   func_0201A364 0x0201A364 thumb
 *   func_0200AEE8 0x0200AEE8 thumb
 */
extern int func_0217B908(int);
extern int func_0217B974(int);
extern void func_0201A364(int, void *);
extern void func_0200AEE8(void *, unsigned int, int);
void func_0217BA10(char *p, int x)
{
    func_0201A364(func_0217B908(x), *(void **)(p + 0x352c));
    if (func_0217B974(x) == 1) func_0200AEE8(*(void **)(p + 0x352c), 13, 1);
    else func_0200AEE8(*(void **)(p + 0x352c), 13, 0);
}
