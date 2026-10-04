/*
 * function: func_0202B5D4
 * address:  0x0202B5D4
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 0202B6AC, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 * status:   EXACT
 * closed:   blocker func_0202B6AC.c is now a manifest entry (matched class)

 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0202B66C(struct Obj *o);
extern void func_0202B67C(u8 *p);
extern void func_0202B68C(int a0);
extern void func_0202B69C(int a0);
extern void func_0202B6AC(u8 *p);
extern void func_0202B6BC(int a0);

void func_0202B5D4(u32 a)
{
    func_0202B66C((struct Obj *)a);
    func_0202B67C((u8 *)a);
    func_0202B68C(a);
    func_0202B69C(a);
    func_0202B6AC((u8 *)a);
    func_0202B6BC(a);
}
