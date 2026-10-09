/*
 * file:     net_state_p28.c
 * unit:     yes
 * function: func_0203C5C8, func_0203C5EC
 * address:  0x0203C5C8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203C554  0x0203C554  arm
 *   unk_021469DC   0x021469DC  data
 *   g_021469DC  0x021469DC  data
 */
typedef unsigned char u8;

typedef unsigned int  u32;

struct Card0203C5EC {
    unsigned char pad[0x4a];
    unsigned char f4a;
};

extern void func_0203C554(u32 a);
void func_0203C5C8(void);
int func_0203C5EC(void);
extern u32  unk_021469DC;
extern struct Card0203C5EC *g_021469DC;


/*
 * Arms the sequence: the slot call with a literal 1, then the same 1 into the
 * object's byte at +0x4A.  The 1 lives in r4 across the call, which is why the
 * function pushes r4 at all.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C5C8.c \
 *       --func func_0203C5C8 --addr 0x0203C5C8 --cc 1.1p1 --arm
 */
void func_0203C5C8(void)
{
    func_0203C554(1);
    ((u8 *)unk_021469DC)[0x4A] = 1;
}


/*
 * Unlabelled ARM leaf: byte at +0x4a of the card task object.
 */
int func_0203C5EC(void)
{
    return g_021469DC->f4a;
}
