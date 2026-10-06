/*
 * unit:     no
 * function: func_0203D1C0
 * address:  0x0203D1C0
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203996C  0x0203996C  arm
 *   func_020399B8  0x020399B8  arm
 *
 * TU: net.c (named by the assert site at 0x0203D2EC, which passes the
 * string at 0x020A7CA0, "net.c").
 *
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with func_0203996C and ask func_020399B8 about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1C0.c \
 *       --func func_0203D1C0 --addr 0x0203D1C0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct NetEntry;

extern void       *func_0203D788(void);
typedef signed int     s32;
typedef unsigned char  u8;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_020399B8(u8 *p);

u32 func_0203D1C0(u32 index)
{
    if (func_0203D788() == 0) {
        return 0;
    }
    return func_020399B8((u8 *)func_0203996C(index));
}
