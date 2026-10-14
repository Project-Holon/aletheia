/*
 * function: WORLDTRADE_ENTER_StateAbortConnect
 * address:  0x021F8F5C
 * packet:   pkt_021F8F5C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 * Every concrete byte is reproduced.  The one wildcard is the BLX at +0002 to
 * func_021C8658, which has no independent witness outside 021F8F5C..021F8F66;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Same blocker as WORLDTRADE_SERVER_StateCheckAsyncEnd
 * and WORLDTRADE_SEARCH_StateStartWipeOutDisconnect/WORLDTRADE_SERVER_StateStartWipeOutDisconnect: naming one of those eight regions would be
 * a guess, so the site stays parked until the region that owns 0x021C8658 is
 * established.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C8658(u8 *p);

u32 WORLDTRADE_ENTER_StateAbortConnect(u8 *p)
{
    func_021C8658(p);
    return 0;
}
