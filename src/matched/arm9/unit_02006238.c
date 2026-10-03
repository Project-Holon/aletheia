/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006238
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02006238, sub_02006254, sub_02006268, sub_020062BC,
 *           sub_020062D8, sub_020062EC, sub_02006300
 *
 * symbols:
 *   sub_02006238_Table   0x020AA294  data
 *   sub_02006300_State   0x020AA260  data
 *   sub_02006300_Thread  0x020AA354  data
 *   sub_02006300_Stack   0x020AA9B4  data
 *   sub_02006224         0x02006224  thumb
 *   sub_02006368         0x02006368  thumb
 *   func_02072EE0        0x02072EE0  arm
 *   func_02072F34        0x02072F34  arm
 *   func_02073018        0x02073018  arm
 *   func_02073038        0x02073038  arm
 *   func_02073098        0x02073098  arm
 *   func_020853C0        0x020853C0  arm
 *   func_02074AC4        0x02074AC4  arm
 *   func_02085868        0x02085868  arm
 *
 * The two thread bodies and the routine that starts one.  sub_020062D8 and
 * sub_020062EC carry no label: both are six instructions with no prologue
 * that dereference the thread argument, read one field of the state block
 * and tail call func_02074AC4 with a different constant, and the only
 * references to them in the image are the two pool words of sub_02006300
 * immediately below.  That is why the three have to be one byte range:
 * outside it neither thread body has a witness, and inside it both are
 * `local`.
 *
 * sub_02006300's call to func_020853C0 is an OS thread creation: the thread
 * object at 0x020AA354, the entry point, the argument, the stack at
 * 0x020AA9B4, and 0x400 and 0x11 on the stack for the stack size and the
 * priority.  The argument, 0x020AA26C, is the address of the state block's
 * own `unk0C` field, which is the word sub_02006300 has just written, so it
 * reaches the relocation as the state symbol with an addend of 0xC rather
 * than as an object of its own.
 */

typedef unsigned int u32;

struct Sub02006300State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
};

struct Sub02006238Entry {
    void *unk00;
    u32   unk04;
};

extern struct Sub02006300State sub_02006300_State;
extern struct Sub02006238Entry sub_02006238_Table[];
extern u32 sub_02006300_Thread[];
extern u32 sub_02006300_Stack[];

extern int sub_02006224(u32 a0);
extern void sub_02006368(void);
extern int  func_02072EE0(u32 a);
extern void func_02072F34(u32 *req, u32 level);
extern void func_02073018(u32 *req, u32 a, u32 b);
extern void func_02073038(u32 *req, u32 a, u32 b);
extern void func_02073098(u32 *req, u32 a);
extern u32 func_02074AC4(u32 a, u32 b, u32 c);
extern void func_020853C0(u32 *thread, void (*entry)(void *), void *arg,
                          u32 *stack, u32 size, u32 prio);
extern void func_02085868(u32 *thread);

void sub_020062D8(u32 *arg);
void sub_020062EC(u32 *arg);

int sub_02006238(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (sub_02006224(i) == 1) {
            return 1;
        }
    }
    return 0;
}

int sub_02006254(u32 a)
{
    if (func_02072EE0(a) != 0) {
        return 1;
    }
    return 0;
}

void sub_02006268(int i, u32 a, u32 b, u32 c)
{
    if (a != -1) {
        func_02073098(&sub_02006238_Table[i].unk04, a);
    }
    if (b != -1) {
        func_02073018(&sub_02006238_Table[i].unk04, 0xFFFF, b);
    }
    if (c != -1) {
        func_02073038(&sub_02006238_Table[i].unk04, 0xFFFF, c);
    }
}

void sub_020062BC(int i, u32 level)
{
    if (level > 0x7F) {
        level = 0x7F;
    }
    func_02072F34(&sub_02006238_Table[i].unk04, level);
}

void sub_020062D8(u32 *arg)
{
    func_02074AC4(*arg, 3, sub_02006300_State.unk10);
}

void sub_020062EC(u32 *arg)
{
    func_02074AC4(*arg, 4, sub_02006300_State.unk10);
}

void sub_02006300(u32 a, int mode)
{
    sub_02006300_State.unk0C = a;
    sub_02006368();
    switch (mode) {
    case 0:
        func_020853C0(sub_02006300_Thread, (void (*)(void *))sub_020062D8,
                      &sub_02006300_State.unk0C, sub_02006300_Stack,
                      0x400, 0x11);
        break;
    case 1:
        func_020853C0(sub_02006300_Thread, (void (*)(void *))sub_020062EC,
                      &sub_02006300_State.unk0C, sub_02006300_Stack,
                      0x400, 0x11);
        break;
    }
    func_02085868(sub_02006300_Thread);
    sub_02006300_State.unk14 = (u32)sub_02006300_Thread;
}
