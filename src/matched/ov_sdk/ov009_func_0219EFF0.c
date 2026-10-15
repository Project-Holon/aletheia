/*
 * function: ServerBrowserHalt
 * address:  0x0219EFF0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Prepares the block 0x60 bytes in and then the object itself.
 *
 * symbols:
 *   SBServerListDisconnect  0x021A02E0  arm  ov009
 *   SBEngineHaltUpdates  0x0219D8E0  arm  ov009
 */

struct SBL;
extern void SBServerListDisconnect(struct SBL *slist);
extern void SBEngineHaltUpdates(char *p);

void ServerBrowserHalt(char *p)
{
    SBServerListDisconnect((struct SBL *)(p + 0x60));
    SBEngineHaltUpdates(p);
}

