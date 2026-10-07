/*
 * file:     unit_021DF7FC_p01.c
 * unit:     yes
 * function: func_021DF884, func_021DF8D4
 * address:  0x021DF884
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E06DC  0x021E06DC  arm
 *   func_020923B0  0x020923B0  arm
 *   func_021E0730  0x021E0730  arm
 */
typedef int s32;

typedef unsigned int u32;

typedef unsigned char u8;

extern s32 func_021E06DC(char *p, u32 v);
extern void *func_020923B0(void *p, int c, u32 n);
extern void func_021E0730(char *p);
s32 func_021DF884(char *p);
void func_021DF8D4(char *p);


/*
 * Activation probe: func_021E06DC reports on the owner, and a report is
 * returned as-is.  Otherwise clear the two 0x28-byte parameter blocks and
 * mark the owner live at +0x50.
 */
s32 func_021DF884(char *p)
{
    s32 e = func_021E06DC(p, (u32)p);

    if (e != 0)
        return e;
    func_020923B0(p + 0x5c, 0, 0x28);
    func_020923B0(p + 0x84, 0, 0x28);
    *(u32 *)(p + 0x50) = 1;
    return 0;
}


/*
 * Reset the owner: release it, blank the two 0x28-byte parameter blocks, put
 * the 0xadde signature on the front of each and clear the live flag.
 */
void func_021DF8D4(char *p)
{
    u32 z = 0;
    u32 n = 0x28;

    func_021E0730(p);
    func_020923B0(p + 0x5c, z, n);
    func_020923B0(p + 0x84, z, n);
    *(u8 *)(p + 0x5c) = 0xde;
    *(u8 *)(p + 0x5d) = 0xad;
    *(u8 *)(p + 0x84) = 0xde;
    *(u8 *)(p + 0x85) = 0xad;
    *(u32 *)(p + 0x50) = z;
}
