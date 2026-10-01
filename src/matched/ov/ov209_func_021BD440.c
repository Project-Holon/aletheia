/*
 * function: func_021BD440
 * address: 0x021BD440
 * packet: pkt_ov209_021BD440
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BD486 two-byte alignment padding before 021BD488.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 */
typedef unsigned short u16;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern void func_02045808(struct U16Vec *);
extern void func_021B6AE4(unsigned char *, unsigned, u16, u16, unsigned, unsigned, u16, unsigned);
void func_021BD440(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0(*(struct MsgBank **)(p + 60), msg);
    func_021B6AE4((unsigned char *)(p + 32 + index * 8), *(unsigned *)(p + 72), x, y, (unsigned)text, *(unsigned *)(p + 56), color, mode);
    func_02045808(text);
}
