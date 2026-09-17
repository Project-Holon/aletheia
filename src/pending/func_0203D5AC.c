/*
 * function: func_0203D5AC
 * address:  0x0203D5AC
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Sets the net context's +0x67 byte to the argument (after forcing the
 * context through func_0203D788), then updates the channel with
 * func_0203996C(0xff) and func_0203A458.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D5AC.c \
 *       --func func_0203D5AC --addr 0x0203D5AC --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8  *func_0203D788(void);
extern u8  *func_0203D798(void);
extern u32  func_0203996C(u32 v);
extern void func_0203A458(u32 a, u32 b);

void func_0203D5AC(u32 a)
{
    u8 *p;

    func_0203D788();
    p = func_0203D798();
    p[0x67] = (u8)a;
    func_0203A458(func_0203996C(0xff), a);
}
