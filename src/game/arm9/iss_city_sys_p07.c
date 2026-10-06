/*
 * file:     iss_city_sys_p07.c
 * unit:     yes
 * function: func_0202AE9C, func_0202AEB8, func_0202AEBC
 * address:  0x0202AE9C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj15818.h"
#include "../../matched/include/Obj16761.h"

struct Rec44;
struct Vec12;
typedef unsigned int u32;

extern int func_0202AD78(int a0);
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern void func_0202AF34(int a, u32 b);
void func_0202AE9C(void *p);
void sub_0202AEB8(void *obj, u32 value);
int func_0202AEBC(int a0);


/*
 * Blocked: call target func_0202AF34 is unlabelled and unmatched (it lives in
 * another lane's packet, pkt_0202AF34). Every concrete byte reproduces.
 */
void func_0202AE9C(void *p)
{
    int a = func_0202AD78((int)p);

    func_0202AF34(a, (u32)func_02012AA0((struct Rec44 *)(((struct Obj15818 *)p)->f0)));
}


/*
 * A plain word setter at offset 0xc. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202AEB8.c \
 *       --func sub_0202AEB8 --addr 0x0202AEB8 --cc 1.1p1 --thumb
 */
void sub_0202AEB8(void *obj, u32 value)
{
    ((struct Obj16761 *)obj)->fC = value;
}

int func_0202AEBC(int a0){ int t0, t1; t0 = func_0202AED0(a0); t1 = func_02005F24((int)(3 << 8), (int)(t0 + 0)); return t1; }
