/*
 * function: func_021736EC
 * address: 0x021736EC
 * packet: pkt_ov011_021736EC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_02039338 0x02039338 arm
 *   func_020399A8 0x020399A8 arm
 *   func_021736E0 0x021736E0 thumb ov011
 *   func_0203D3A8 0x0203D3A8 arm
 * The fifth argument to 021736E0 is visibly written to the outgoing stack slot.
 */
extern int func_021736D8(void);
typedef unsigned short u16;
extern u16 func_02039338(void);
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_021736E0(int, int, int, char *, unsigned int);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
int func_021736EC(char *p)
{
    unsigned int n;
    if (func_021736D8() == 0) {
        n = func_02039338();
        func_021736E0(n, 0, 0, p, (unsigned int)func_020399A8());
        return 1;
    }
    return func_0203D3A8((struct Entry *)((unsigned int)func_020399A8()), 0x200, 0, 0);
}
