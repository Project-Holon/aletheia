/*
 * function: func_021FF384
 * address:  0x021FF384
 * packet:   pkt_021FF384
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker: register choice for the repeated constants. The image keeps 0x440 in r7
 * and rematerialises the stack zero at each call; this source keeps the zero in r7
 * and rematerialises 0x440. Everything else is byte-identical. Notes in
 * docs/notes/pkt_021FF384.c.txt.
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

extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *p);
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
    u32 color;

    color = 0x440;
    s1 = func_02045EC0(bank, 0x43);
    func_021F91A0(win[0], s1, 0, 0, 0, color, g);
    func_02045808(s1);
    s2 = func_02045EC0(bank, 0x45);
    func_021F91A0(win[2], s2, 0, 0, 0, color, g);
    func_02045808(s2);
    s3 = func_02045EC0(bank, 0x47);
    func_021F91A0(win[4], s3, 0, 0, 0, color, g);
    func_02045808(s3);
    s4 = func_02045EC0(bank, 0xB9);
    func_021F91A0(win2[0], s4, 0, 0, 0, color, g);
    func_02045808(s4);
    s5 = func_02045EC0(bank, 0x49);
    func_021F91DC(win[6], s5, 0, 0, 0, color, g);
    func_02045808(s5);
    s6 = func_02045EC0(bank, 0xFC);
    func_021F91DC(win[7], s6, 0, 0, 0, color, g);
    func_02045808(s6);
}
