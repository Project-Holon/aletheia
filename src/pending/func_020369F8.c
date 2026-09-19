/*
 * function: func_020369F8
 * address:  0x020369F8
 * packet:   pkt_020369F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  str_020A79EC (string) -- no witness outside 020369F8..02036A50;
 *           the file string at 0x020A79C4 is not NUL-terminated immediately
 *           before this message, so the `string` class refuses. Every concrete
 *           byte of the body reproduces.
 * symbols:
 *   str_020A79C4  0x020A79C4  data
 *   str_020A79EC  0x020A79EC  data
 *   func_02034714 0x02034714  arm
 *   func_020366FC 0x020366FC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A79C4[];
extern const u8 str_020A79EC[];
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern u32 func_020366FC(u8 *p);

void func_020369F8(u8 *p)
{
    if (*(u32 *)(p + 0x10) != 0) {
        *(u32 *)(p + 0x10) = 0;
        return;
    }
    if (func_020366FC(p) != 0) {
        return;
    }
    if (func_020366FC(p + 8) != 0) {
        return;
    }
    func_02034714(str_020A79C4, 0x12f, str_020A79EC);
}
