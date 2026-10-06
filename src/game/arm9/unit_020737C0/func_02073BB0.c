/*
 * function: func_02073BB0
 * address:  0x02073BB0
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E8E8       0x214E8E8  data
 *
 * EXACT* only because the follower at 0x02073BE0 carries no func_ label in the
 *  * generated listing (it saves no lr), so the inferred extent runs 64 bytes
 *  * instead of the 48 this unit reproduces. No byte of the 48 differs. The
 *  * follower is an unlabelled ARM routine whose words the listing prints as
 *  * `.word` data; seeding 0x02073BE0 in layout/function_starts.txt is the
 *  * integrator's call, not this lane's.
 *  *
 *  * `x->f2c &= ~1` is the bic spelling: the masked-assignment form is what this
 *  * front end turns into `bic r0, r0, #1` without a materialised mask.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct X { u8 pad00[0x2c]; u32 f2c; u8 pad2[0x48 - 0x30]; u32 f48; };
extern char g_0214E8E8[];
extern void func_02072A08(u32);
struct DList;
extern void func_020605B4(volatile struct DList *list, void *elem);

void func_02073BB0(struct X *x)
{
    func_02072A08(x->f48);
    func_020605B4((volatile struct DList *)g_0214E8E8, x);
    x->f2c &= ~1;
}
