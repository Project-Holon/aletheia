/*
 * function: COMM_PLAYER_SUPPORT_GetRecordFieldPtr
 * address:  0x0202E930
 * packet:   pkt_0202E930
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020084F4  0x020084F4  thumb
 *
 * An unlabelled forwarding leaf after COMM_PLAYER_SUPPORT_FindPeerRecord's pop: a pool-word tail
 * call to func_020084F4 (the u16 pointer accessor), the caller's argument passed through
 * untouched ("ldr r3, [pc]; bx r3").  Called from the overlays only (see
 * layout/function_starts.txt).
 */

typedef unsigned short u16;

extern u16 *func_020084F4(void *p);

u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *p)
{
    return func_020084F4(p);
}
