/*
 * function: func_0203D5AC
 * address:  0x0203D5AC
 * packet:   pkt_0203D5AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PROMOTED from src/pending/.  The `bl` to 0x0203A458 was this file's last
 * open site; it now resolves as `matched` against that function's own EXACT
 * shard entry, so the cap is gone.
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

extern void *func_0203D788(void);
extern void *func_0203D798(void);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern void func_0203A458(u8 *a0, u32 a1);

void func_0203D5AC(u32 a)
{
    u8 *p;

    func_0203D788();
    p = func_0203D798();
    p[0x67] = (u8)a;
    func_0203A458((u8 *)func_0203996C(0xff), a);
}
