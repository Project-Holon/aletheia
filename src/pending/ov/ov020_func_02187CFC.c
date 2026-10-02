/*
 * function: func_02187CFC
 * address: 0x02187CFC
 * packet: pkt_ov020_02187CFC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH*
 * blocker: unlabelled ov021 func_02189A50 at 0x02189A50, owned by Ilias;
 * sole setter body stores r1 at [r0 + 0x144], then returns. No code-start
 * witness. No owner source or ARM9/SDK matching performed.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_02189A50 0x02189A50 thumb ov021
 *   func_02187914 0x02187914 thumb ov020
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02040588(int, int);
extern void func_02189A50(void *, int);
extern void func_02187914(char *);
void func_02187CFC(char *p)
{
    func_02040588(3, 0);
    if (*(void **)(p + 4) != 0) func_02189A50(*(void **)(p + 4), 0);
    func_02187914(p);
}
