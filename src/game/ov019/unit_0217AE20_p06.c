/*
 * file:     unit_0217AE20_p06.c
 * unit:     yes
 * function: func_0217B9CC, func_0217B9F4, func_0217BA10, func_0217BA48, func_0217BA6C, func_0217BAA8
 * address:  0x0217B9CC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_02034714 0x02034714 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021807E4 0x021807E4 data a1
 *   func_0217B908 0x0217B908 thumb ov019
 *   func_0217B974 0x0217B974 thumb ov019
 *   func_0201A364 0x0201A364 thumb
 *   func_0200AEE8 0x0200AEE8 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 *   func_0217B9BC  0x0217B9BC  thumb  ov019
 */
#include "../../matched/include/Obj19401.h"
#include "../../matched/include/Obj19402.h"
#include "../../matched/include/Obj09409.h"
#include "../../matched/include/Obj19403.h"

struct Big;
struct Reg;
struct BigObj;
typedef unsigned int   u32;

typedef signed int     s32;

extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern unsigned int func_0200BBA8(void *);
extern void *func_0200BAF4(int, int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020307B0(void *p);
extern int func_0217B908(int);
extern int func_0217B974(int);
extern void func_0201A364(int a, unsigned int b);
extern void func_0200AEE8(struct Reg *p, u32 id, s32 value);
extern void *func_02012934(const struct BigObj *p);
extern int func_0201A090(void *, void *, unsigned int *);
extern int func_0217B9BC(unsigned int x);
void *func_0217B9CC(char *p);
void func_0217B9F4(void *p);
void func_0217BA10(char *p, int x);
int func_0217BA48(char *p, unsigned int *mask);
int func_0217BA6C(char *p, unsigned int *mask);
int func_0217BAA8(int a, int b, int *p, int *q);
extern const char d_021807E4[];

/*
 * Return from the legacy void tail forwarder 0200BAC8 is used by this caller.
 */
void *func_0217B9CC(char *p)
{
    void *a;
    a = func_0200BAC8(func_02012EBC(((struct Obj19402 *)(*(char * *)&((struct Obj19401 *)p)->f0))->f8));
    if (func_0200BBA8(a) == 0) return 0;
    return func_0200BAF4((int)a, 65);
}

void func_0217B9F4(void *p)
{
    if (!p) func_02034714(d_021807E4, 0, d_021807E4);
    func_020307B0(p);
}

/*
 * Interface evidence: stub at 0201A364 moves r0 to r2, r1 to r0,
 * sets r1=0x69, then jumps through pool 02048F4C. Ilias owns it.
 */
void func_0217BA10(char *p, int x)
{
    func_0201A364(func_0217B908(x), (unsigned int)(*(void **)(p + 0x352c)));
    if (func_0217B974(x) == 1) func_0200AEE8(*(void **)(p + 0x352c), 13, 1);
    else func_0200AEE8(*(void **)(p + 0x352c), 13, 0);
}

int func_0217BA48(char *p, unsigned int *mask)
{
    void *party;
    *mask = 0;
    party = func_02012934(((struct Obj19403 *)(*(char * *)&((struct Obj09409 *)p)->f0))->f8);
    return func_0201A090(((struct Obj09409 *)p)->f352C, party, mask);
}

int func_0217BA6C(char *p, unsigned int *mask)
{
    void *party;
    int result;
    party = func_0217B9CC(p);
    *mask = 0;
    if (party != 0) {
        result = func_0201A090(((struct Obj09409 *)p)->f352C, party, mask);
        func_0217B9F4(party);
    } else {
        *mask = -1;
        result = 5;
    }
    return result;
}


int func_0217BAA8(int a, int b, int *p, int *q)
{
    int r, t;
    *p = 0;
    *q = 0;
    if (func_0217B9BC(b) == 0)
        return 1;
    func_0217BA10((char *)a, b);
    r = func_0217BA48((char *)a, (unsigned int *)p);
    t = func_0217BA6C((char *)a, (unsigned int *)q);
    if (r == 0 || t == 0)
        return 1;
    return 0;
}
