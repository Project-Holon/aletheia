/*
 * function: GFL_NET_STATE_StartParent
 * address:  0x0203B258
 * packet:   pkt_0203B258
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_SYSTEM_StartParent  0x02037894  arm
 *   GFL_NET_STATE_ChangeStateDebug  0x0203AD80  arm
 *   unk_0203B228   0x0203B228  data
 *   unk_0203B22C   0x0203B22C  arm
 *
 * Starts a 0x200-entry transfer over channel 1 and reports through
 * GFL_NET_STATE_ChangeStateDebug at line 517 when the start call answers zero.  The line comes
 * out as `add r3, r4, #5` because r4 already holds the 0x200 argument, the
 * same constant-rematerialisation the consecutive-`__LINE__` idiom records.
 *
 * Both callback addresses (0x0203B22C and 0x0203B228, the two `bx lr` filler
 * words in the pool of GFL_NET_STATE_Main) are declared as symbols: written as
 * plain integer literals this compiler folds the pair into one pool word plus
 * a `sub r1, r4, #4`, which is four bytes short of the original's two pool
 * words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_StartParent.c \
 *       --func GFL_NET_STATE_StartParent --addr 0x0203B258 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *GFL_NET_GetInitParam(void);
extern u32   GFL_NET_SYSTEM_StartParent(int a0, int a1, int a2, int a3);
typedef unsigned short u16;
struct NetState;
extern void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line);
extern char  unk_0203B228[];
extern char  unk_0203B22C[];

void GFL_NET_STATE_StartParent(void)
{
    GFL_NET_GetInitParam();
    if (GFL_NET_SYSTEM_StartParent(1, 0x200, 1, (int)unk_0203B22C) != 0)
        GFL_NET_STATE_ChangeStateDebug((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)unk_0203B228, 0, 0x205);
}
