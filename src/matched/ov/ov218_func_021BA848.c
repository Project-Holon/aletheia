/*
 * function: func_021BA848
 * address: 0x021BA848
 * packet: pkt_ov218_021BA848
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: BLDCNT04000050/04001050 writes A870-A872; DISPCNT04000000/04001000 reread and masked A876-A884.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BA980 0x021BA980 thumb ov218
 *   func_021BAA24 0x021BAA24 thumb ov218
 *   func_021BAA94 0x021BAA94 thumb ov218
 *   func_021BA96C 0x021BA96C thumb ov218
 *   func_020056A0 0x020056A0 thumb
 *   d_021BB094 0x021BB094 data a1
 *   d_021BAEF8 0x021BAEF8 data a4
 */
struct DispVram;
extern const struct DispVram d_021BAEF8;
extern const char d_021BB094[];
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, int, int);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BA980(char *, unsigned);
extern void func_021BAA24(unsigned char *, int, int);
extern void func_021BAA94(unsigned **, unsigned);
extern void func_021BA96C(void *, char *);
extern void *func_020056A0(unsigned, unsigned, unsigned);
char *func_021BA848(unsigned swap, unsigned heap)
{
    char *p;
    p = func_02030734(heap, 16, 0, d_021BB094, 436);
    func_02082BCC(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    func_0204335C(0);
    func_020433E0(&d_021BAEF8);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BA980(p, heap);
    func_021BAA24((unsigned char *)(p + 4), (int)&d_021BAEF8, heap);
    func_021BAA94((unsigned **)(p + 8), heap);
    *(void **)(p + 12) = func_020056A0((unsigned)func_021BA96C, (unsigned)p, 0);
    return p;
}
