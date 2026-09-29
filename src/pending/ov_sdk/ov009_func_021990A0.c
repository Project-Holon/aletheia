/*
 * function: func_021990A0
 * address:  0x021990A0
 * packet:   pkt_ov009_021990A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (one instruction: mvn r1,#0x80000000 vs compiled sub r1,r0,#0x80000002)
 *
 * sdk:      GetClientUniqueID (natify.o)
 *
 * w4_nm tried: K&R and unsigned prototypes, 0x7fffffffu, ~0x80000000, ~0u>>1, long
 * args: the high bound is always built from r0 == 1 (sub) instead of mvn.
 *
 * symbols:
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217F790  0x0217F790  arm  ov009
 *   func_0217F7AC  0x0217F7AC  arm  ov009
 *   g_021AE698  0x021AE698  data
 */

typedef struct {
    int pad0[5];
    int clientID;
} NegotiateState;

extern NegotiateState g_021AE698;
extern unsigned int func_0217F264(void);
extern void func_0217F790(unsigned long seed);
extern int func_0217F7AC(int low, int high);

int func_021990A0(void)
{
    if (g_021AE698.clientID)
        return g_021AE698.clientID;
    func_0217F790(func_0217F264());
    g_021AE698.clientID = func_0217F7AC(1, 0x7fffffff);
    return g_021AE698.clientID;
}
