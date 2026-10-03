/*
 * function: func_0200E164
 * address:  0x0200E164
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Runs func_0200E06C, then func_0200E0E8, then the initialiser, returning
 * the middle result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E164.c \
 *       --func func_0200E164 --addr 0x0200E164 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0200E06C(char *p);
struct Slot;
extern u32  func_0200E0E8(const struct Slot *p, int a);
extern void func_0200E024(void *obj);

u32 func_0200E164(u8 *p, u32 a)
{
    func_0200E06C((char *)p);
    {
        u32 r = func_0200E0E8((const struct Slot *)p, (int)a);

        func_0200E024(p);
        return r;
    }
}
