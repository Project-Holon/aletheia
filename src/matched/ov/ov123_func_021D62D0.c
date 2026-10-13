/*
 * function: func_021D62D0
 * address:  0x021D62D0
 * packet:   pkt_021D62D0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ApplyActorAnimCommand  0x0204BA00  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Actor;
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);

void func_021D62D0(u8 *p, int i, int v)
{
    CLACT_ApplyActorAnimCommand(*(void **)(p + i * 4 + 0x74), (const struct Cmd *)v);
}
