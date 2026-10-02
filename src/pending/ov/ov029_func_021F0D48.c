/*
 * function: func_021F0D48
 * address: 0x021F0D48
 * packet: pkt_ov029_021F0D48
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: func_02189A48, ov021 owner leaf, lacks an outside code witness.
 * interface: 0201210C returns the full word at +0x20; it is passed directly
 * to 02189A48, whose ov021 body reads the full word at +0x144. No value lost.
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_0207D55C 0x0207D55C arm
 *   func_0201210C 0x0201210C thumb
 *   func_02189A48 0x02189A48 thumb ov021
 */
extern unsigned int func_020221A4(void);
extern int func_0207D55C(unsigned short *);
extern unsigned int func_0201210C(void *);
extern int func_02189A48(unsigned int);
int func_021F0D48(char *p)
{
    if (!func_020221A4()) return 0;
    if (func_0207D55C((unsigned short *)0x0400106c)) return 0;
    if (!func_02189A48(func_0201210C(*(void **)(p + 0x1c)))) return 1;
    return 0;
}
