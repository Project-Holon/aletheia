/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005F38
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005F38, sub_02005F5C, sub_02005F70, sub_02005F90,
 *           sub_02005FBC
 *
 * symbols:
 *   sub_02005F38_State  0x020AA260  data
 *   sub_020058D0        0x020058D0  thumb
 *   sub_0200590C        0x0200590C  thumb
 *   sub_02005D90        0x02005D90  thumb
 *   sub_02005FF4        0x02005FF4  thumb
 *   sub_02006368        0x02006368  thumb
 *   func_02072EE0       0x02072EE0  arm
 *   func_02072F34       0x02072F34  arm
 *
 * The setup and teardown of the connection request block at 0x020AA260.
 * The range stops at 0x02005FF4 rather than running on to 0x02006148 for an
 * evidence reason: func_02072F34 is called from five places image wide and
 * four of them are inside sub_02005FF4, so the two files witness each
 * other's calls.
 *
 * sub_02005F5C ends in a tail call to sub_02005F90, which is in this same
 * range, and it still goes through a literal pool and `bx r3` rather than a
 * branch: one section per function means the compiler cannot encode the
 * displacement even to its own neighbour, and the pool word is an ABS32 the
 * linker fills in.  Here that makes the site `local` and costs no image
 * evidence at all.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02005F38State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    int unk2C;
    int unk30;
};

extern struct Sub02005F38State sub_02005F38_State;

extern u16  sub_020058D0(void);
extern u32 *sub_0200590C(void);
extern void sub_02005D90(u32 a, u16 b);
extern void sub_02005FF4(void);
extern void sub_02006368(void);
extern int  func_02072EE0(u16 a);
extern void func_02072F34(u32 *req, int a);

void sub_02005F90(void);

int sub_02005F38(void)
{
    if (sub_020058D0() == 0) {
        return 0;
    }
    if (func_02072EE0(sub_020058D0()) != 0) {
        return 1;
    }
    return 0;
}

void sub_02005F5C(void)
{
    sub_02005F38_State.unk2C = 60;
    sub_02005F38_State.unk30 = 60;
    sub_02005F90();
}

void sub_02005F70(u32 a, u16 b, int c, int d)
{
    sub_02005F38_State.unk26 = b;
    sub_02005F38_State.unk28 = a;
    sub_02005F38_State.unk2C = d;
    sub_02005F38_State.unk30 = c;
    sub_02005F38_State.unk24 = c;
    sub_02006368();
    sub_02005F38_State.unk20 = 0;
    sub_02005F38_State.unk1C = 1;
}

void sub_02005F90(void)
{
    sub_02005F38_State.unk1C = 0;
    sub_02005F38_State.unk26 = 0xFFFF;
    sub_02005F38_State.unk28 = 0;
    sub_02005F38_State.unk24 = 0;
    func_02072F34(sub_0200590C(), 0x7F);
    sub_02005F38_State.unk20 = 0;
    sub_02006368();
}

void sub_02005FBC(void)
{
    u32 id;

    if (sub_02005F38_State.unk1C != 1) {
        return;
    }
    id = sub_020058D0();
    if (id != sub_02005F38_State.unk28) {
        while (sub_02005F38_State.unk20 != 0) {
            sub_02005FF4();
        }
        sub_02005D90(sub_02005F38_State.unk28, sub_02005F38_State.unk26);
    }
    sub_02005F90();
}
