/*
 * file:     unit_02184D30_p05.c
 * unit:     yes
 * function: func_02185854, func_02185880
 * address:  0x02185854
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021857F4 0x021857F4 thumb ov023
 *   func_021861C4 0x021861C4 thumb ov023
 *   func_02186444 0x02186444 thumb ov023
 *   func_02185354 0x02185354 thumb ov023
 *   func_021862B0 0x021862B0 thumb ov023
 *   func_020399A8 0x020399A8 arm
 *   func_0203A424 0x0203A424 arm
 */
#include "../../matched/include/Obj20354.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

extern void func_021857F4(char *, int, int);
extern void func_021861C4(u8 *, unsigned int, int);
extern void func_02186444(char *, unsigned int);
extern void func_02185354(char *);
extern int func_021862B0(char *);
extern struct Entry *func_020399A8(void);
extern void func_0203A424(char *p, int a, int b, int c);
int func_02185854(char *p, int a);
int func_02185880(char *p, int a);

int func_02185854(char *p, int a)
{
    func_021857F4(p, 0, 0);
    func_021861C4((u8 *)p, 3, 1);
    func_02186444(p, 0x13);
    func_02185354(p);
    return a;
}

/*
 * extent: two zero padding bytes follow the return at 0x021858B4.
 * Original narrows r3 to u16 before func_0203A424, retained in the call prototype.
 */
int func_02185880(char *p, int a)
{
    if (func_021862B0(p)) {
        func_02186444(p, 0x14);
        func_0203A424((char *)func_020399A8(), 0xc8, 0x29, (u16)((struct Obj20354 *)p)->f1B0);
    }
    func_02185354(p);
    return a;
}
