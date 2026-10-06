/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x0200616C
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200616C, sub_020061A4, sub_020061E4, sub_020061F0,
 *           sub_020061F8, sub_02006210
 *
 * symbols:
 *   sub_0200616C_Table  0x020AA294  data
 *   sub_02005CE0        0x02005CE0  thumb
 *   sub_02006148        0x02006148  thumb
 *   sub_020062BC        0x020062BC  thumb
 *   func_020755A8       0x020755A8  arm
 *   func_02072E7C       0x02072E7C  arm
 *   func_02075560       0x02075560  arm
 *
 * Registering and tearing down the five entries of the table at 0x020AA294,
 * and three forwarders over sub_020061A4.  sub_020061E4 and sub_020061F0
 * both tail call it through the same pool word, the first supplying a -1 for
 * the second argument and the second passing both of its own straight
 * through, which is four bytes of code and one relocation each.
 */

typedef unsigned int u32;

struct Sub0200616CEntry {
    void *unk00;
    u32   unk04;
};

extern struct Sub0200616CEntry sub_0200616C_Table[];

extern int  sub_02005CE0(void *arg);
extern int  sub_02006148(u32 a);
extern void sub_020062BC(int i, u32 b);
extern u32 func_020755A8(u32 a, int b, int c, int d, u32 e);
extern void func_02072E7C(void **r0, int fadeFrame);
extern u32 func_02075560(u32 a, u32 b);

void sub_020061A4(u32 a, u32 b);
void sub_020061F8(int i);

void sub_0200616C(void *arg, int i)
{
    if (sub_02005CE0(arg) == 0) {
        return;
    }
    sub_0200616C_Table[i].unk00 = 0;
    if (func_020755A8((u32)(&sub_0200616C_Table[i].unk04), i + 1, -1, -1, (u32)arg) == 1) {
        sub_0200616C_Table[i].unk00 = arg;
    }
}

void sub_020061A4(u32 a, u32 b)
{
    int i;

    if (sub_02005CE0((void *)a) == 0) {
        return;
    }
    i = sub_02006148(a);
    sub_0200616C_Table[i].unk00 = 0;
    if (func_02075560((u32)(&sub_0200616C_Table[i].unk04), a) != 1) {
        return;
    }
    sub_0200616C_Table[i].unk00 = (void *)a;
    if (b < 0x80) {
        sub_020062BC(i, b);
    }
}

void sub_020061E4(u32 a)
{
    sub_020061A4(a, -1);
}

void sub_020061F0(u32 a, u32 b)
{
    sub_020061A4(a, b);
}

void sub_020061F8(int i)
{
    func_02072E7C((void **)(&sub_0200616C_Table[i].unk04), 0);
}

void sub_02006210(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        sub_020061F8(i);
    }
}
