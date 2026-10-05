/*
 * function: func_021FF384
 * address:  0x021FF384
 * packet:   pkt_ov135_021FF384
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note: pass 2 2026-10-06 P2L19: closed from 8 B off (238 B). The print callees func_021F91A0 and
 *   func_021F91DC are declared void here. Their bodies end in a call and never set r0 themselves, so the
 *   image does not decide between int and void, and no caller reads the result. With int, the six stack
 *   zeros and the six 0x440 stores tie and the zero takes r7; with void the colour 0x440 takes r7 and
 *   the zero is rematerialised per call, as in the image. Plain literals, no pragma.
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F91DC  0x021F91DC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *p);
extern void func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern void func_021F91DC(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

void func_021FF384(void **win, void **win2, void *bank, void *g)
{
    void *s1, *s2, *s3, *s4, *s5, *s6;

    s1 = func_02045EC0(bank, 0x43);
    func_021F91A0(win[0], s1, 0, 0, 0, 0x440, g);
    func_02045808(s1);

    s2 = func_02045EC0(bank, 0x45);
    func_021F91A0(win[2], s2, 0, 0, 0, 0x440, g);
    func_02045808(s2);

    s3 = func_02045EC0(bank, 0x47);
    func_021F91A0(win[4], s3, 0, 0, 0, 0x440, g);
    func_02045808(s3);

    s4 = func_02045EC0(bank, 0xB9);
    func_021F91A0(win2[0], s4, 0, 0, 0, 0x440, g);
    func_02045808(s4);

    s5 = func_02045EC0(bank, 0x49);
    func_021F91DC(win[6], s5, 0, 0, 0, 0x440, g);
    func_02045808(s5);

    s6 = func_02045EC0(bank, 0xFC);
    func_021F91DC(win[7], s6, 0, 0, 0, 0x440, g);
    func_02045808(s6);
}
