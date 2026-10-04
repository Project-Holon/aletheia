/*
 * function: func_02185880
 * address: 0x02185880
 * packet: pkt_ov023_02185880
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return at 0x021858B4.
 * symbols:
 *   func_021862B0 0x021862B0 thumb ov023
 *   func_02186444 0x02186444 thumb ov023
 *   func_02185354 0x02185354 thumb ov023
 *   func_020399A8 0x020399A8 arm
 *   func_0203A424 0x0203A424 arm
 * Original narrows r3 to u16 before func_0203A424, retained in the call prototype.
 */
typedef unsigned short u16;
extern int func_021862B0(char *);
extern void func_02186444(char *, unsigned int);
extern void func_02185354(char *);
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_0203A424(char *p, int a, int b, int c);
int func_02185880(char *p, int a)
{
    if (func_021862B0(p)) {
        func_02186444(p, 0x14);
        func_0203A424((char *)func_020399A8(), 0xc8, 0x29, (u16)*(int *)(p + 0x1b0));
    }
    func_02185354(p);
    return a;
}
