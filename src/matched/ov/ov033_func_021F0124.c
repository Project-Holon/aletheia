/*
 * function: func_021F0124
 * address:  0x021F0124
 * packet:   pkt_ov033_021F0124
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFEE4 0x021EFEE4 thumb ov033
 *   func_021F0C0C 0x021F0C0C thumb ov033
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F0A90 0x021F0A90 thumb ov033
 *   func_021F08EC 0x021F08EC thumb ov033
 *   func_021F07DC 0x021F07DC thumb ov033
 *   func_021F0738 0x021F0738 thumb ov033
 */

extern void func_021EFEE4(unsigned);
extern void func_021F0C0C(void *);
extern void func_02030EAC(unsigned);
extern void func_020307B0(void *);
extern void func_021F0A90(void *);
extern void func_021F08EC(void *);
extern void func_021F07DC(void *);
extern void func_021F0738(void *);

void func_021F0124(char *p)
{
    *(volatile unsigned short *)0x04001050 = 0;
    func_021EFEE4(*(unsigned *)(p + 0xD0));
    func_021F0C0C(p);
    func_02030EAC(*(unsigned *)(p + 0xA8));
    func_020307B0(*(void **)(p + 0x60));
    func_021F0A90(p);
    func_021F08EC(p);
    func_021F07DC(p);
    func_021F0738(p);
    func_020307B0(p);
}
