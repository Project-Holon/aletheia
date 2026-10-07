/*
 * file:     btl_server_p25.c
 * unit:     yes
 * function: func_021BD4E4, func_021BD518
 * address:  0x021BD4E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9C00 0x021B9C00 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021BD554 0x021BD554 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct S2;
typedef unsigned char u8;

typedef unsigned int u32;

extern char *func_021B9AEC(char *, int);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021BD554(u8 *, u8 *);
void func_021BD4E4(u8 *p, int i, u8 a, u8 b);
void func_021BD518(u8 *p, u8 *m);

void func_021BD4E4(u8 *p, int i, u8 a, u8 b)
{
    u8 *arr;
    u8 *first;
    u8 *second;
    arr = (u8 *)func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, i);
    first = func_021B9C00((struct S2 *)arr, a);
    second = func_021B9C00((struct S2 *)arr, b);
    func_021BD518(p, first);
    func_021BD518(p, second);
}

/*
 * return evidence: func_021CC8D8's matched Lock is one full 32-bit word;
 *   021CC8DA loads it, 021CC900 returns that unchanged word in r0.
 *   This caller saves r0 in r4 and passes it unchanged in r1 to restore.
 *   Scalar u32 return follows matched neighbours 021BD708/021BDA00;
 *   union aggregate spelling gave a spurious 8-byte stack frame (run 1).
 */
void func_021BD518(u8 *p, u8 *m)
{
    u32 old;
    if (func_021D5B68(m) == 0) {
        old = func_021CC8D8(p + 0x1d74, 2697);
        func_021BD554(p, m);
        func_021CC95C((u32 *)(p + 0x1d74), old, 2699);
    }
}
