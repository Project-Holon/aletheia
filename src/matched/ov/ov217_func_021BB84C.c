/*
 * function: func_021BB84C
 * address: 0x021BB84C
 * packet: pkt_ov217_021BB84C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: DISPCNT read at 021BB8FA and write at 021BB900.
 * arity: C09E0/C09EC overwrite r1 before their indexed targets; BD3A4 overwrites r1=300; BCC58/BCB60 overwrite r1/r2 before 02040DA8. Omit only unused legacy trailing inputs, retain each visibly supplied context and BB910 r1=14.
 * symbols:
 *   func_021BC688 0x021BC688 thumb ov217
 *   func_021BD5E0 0x021BD5E0 thumb ov217
 *   func_021BD56C 0x021BD56C thumb ov217
 *   func_021BD520 0x021BD520 thumb ov217
 *   func_021C09E0 0x021C09E0 thumb ov217
 *   func_021C09EC 0x021C09EC thumb ov217
 *   func_021BD4CC 0x021BD4CC thumb ov217
 *   func_021BD370 0x021BD370 thumb ov217
 *   func_021BD458 0x021BD458 thumb ov217
 *   func_021BD3A4 0x021BD3A4 thumb ov217
 *   func_021BD05C 0x021BD05C thumb ov217
 *   func_021BCF98 0x021BCF98 thumb ov217
 *   func_021BCE5C 0x021BCE5C thumb ov217
 *   func_021BCF20 0x021BCF20 thumb ov217
 *   func_021BCD90 0x021BCD90 thumb ov217
 *   func_021BCC58 0x021BCC58 thumb ov217
 *   func_021BCBCC 0x021BCBCC thumb ov217
 *   func_021BCC3C 0x021BCC3C thumb ov217
 *   func_021BCB60 0x021BCB60 thumb ov217
 *   func_021BCB44 0x021BCB44 thumb ov217
 *   func_021BCAC0 0x021BCAC0 thumb ov217
 *   func_021BC924 0x021BC924 thumb ov217
 *   func_021BC8D8 0x021BC8D8 thumb ov217
 *   func_021BB940 0x021BB940 thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 */
typedef unsigned char u8;
extern void func_021BC688(char *);
extern void func_021BD5E0(unsigned);
extern void func_021BD56C(int *);
extern void func_021BD520(int *);
extern void func_021C09E0(unsigned);
extern void func_021C09EC(unsigned);
extern unsigned func_021BD4CC(unsigned);
extern void func_021BD370(int *);
extern void func_021BD458(int *);
extern void func_021BD3A4(u8 *);
extern void func_021BD05C(int *);
extern void func_021BCF98(int *);
extern unsigned func_021BCE5C(unsigned);
extern unsigned func_021BCF20(unsigned);
extern void func_021BCD90(u8 *);
extern void func_021BCC58(unsigned);
extern void func_021BCBCC(u8 *);
extern void func_021BCC3C(u8 *);
extern void func_021BCB60(unsigned);
extern void func_021BCB44(u8 *);
extern unsigned func_021BCAC0(u8 *);
extern void func_021BC924(int *);
extern void func_021BC8D8(u8 *);
extern void func_021BB940(void *, unsigned);
extern void func_021BB91C(void *);
extern void func_021BB910(u8 *, unsigned);
void func_021BB84C(u8 *p)
{
    func_021BC688((char *)p);
    func_021BD5E0((unsigned)p);
    func_021BD56C((int *)p);
    func_021BD520((int *)p);
    func_021C09E0(*(unsigned *)p);
    func_021C09EC(*(unsigned *)p);
    func_021BD4CC((unsigned)p);
    func_021BD370((int *)p);
    func_021BD458((int *)p);
    func_021BD3A4(p);
    func_021BD05C((int *)p);
    func_021BCF98((int *)p);
    func_021BCE5C((unsigned)p);
    func_021BCF20((unsigned)p);
    func_021BCD90(p);
    func_021BCC58((unsigned)p);
    func_021BCBCC(p);
    func_021BCC3C(p);
    func_021BCB60((unsigned)p);
    func_021BCB44(p);
    func_021BCAC0(p);
    func_021BC924((int *)p);
    func_021BC8D8(p);
    func_021BB940(p, 0);
    func_021BB91C(p);
    func_021BB910(p, 14);
    *(unsigned *)(p + 0x164) = 1;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
}
