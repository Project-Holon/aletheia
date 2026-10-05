/*
 * function: func_021FF384
 * address: 0x021FF384
 * packet: pkt_ov135_021FF384
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 recoup (wave P10 lane Y3): original is 238 B (240 with the pad). Plain literal 0x440
 *   and the local form compile the same (248 B, 181 B differ). Callees checked: func_021F91A0/91DC return int
 *   (matched), func_02045EC0 returns a pointer, func_02045808 is void (its tail callee 020307B0 is void).
 *   Residue: the image pools 0x440 in r7 and rematerialises the stack zero (movs r0,#0; str r0,[sp]) per call;
 *   the build pools the zero in r7 and rematerialises 0x440 (movs/lsls). KEY FINDING: if ONE of the six stack
 *   zeros is changed to 1 (not a valid source), the build is 238 B with 1 B differing, so color then wins r7
 *   and the schedule is exactly the image. So the zero and the color tie at 6 uses and the zero wins; the
 *   original has some sixth zero that does not merge with the other five (or a seventh use of 0x440).
 *   Tried, no change: color as u32 or u16 local, const local, static const u16, sixth parameter u32 or u16,
 *   e as int, u8, void pointer or u16 for the 91DC calls, e as a void pointer for the 91A0 calls, a named zero local on the last
 *   call, one scratch string local, six pragmas (opt_lifetimes, opt_propagation, opt_common_subs, scheduling,
 *   peephole, opt_dead_assignments each off), static inline helpers (272 B). Enum color (stand-in) is 238 B
 *   with 19 B differing: the color is built at entry, not after the first call.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021F91A0 0x021F91A0 thumb
 *   func_021F91DC 0x021F91DC thumb
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
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern int func_021F91DC(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);

void func_021FF384(void **win, void **win2, void *bank, void *g)
{
    void *s1;
    void *s2;
    void *s3;
    void *s4;
    void *s5;
    void *s6;
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
