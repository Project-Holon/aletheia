/*
 * function: WIFICLUB_UpdatePeerActors
 * address:  0x021BF280
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * symbols:
 *   WIFICLUB_SyncPresenceLists  0x021BF084  thumb  ov099
 *   WIFICLUB_RequestSelectionRefresh  0x021BF24C  thumb  ov099
 *   WIFICLUB_DropActorsOfMissingPeers  0x021BF1CC  thumb  ov099
 *
 * Three-step update of the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUB_SyncPresenceLists(char *p);
extern void WIFICLUB_RequestSelectionRefresh(u8 *p, int v);
extern void WIFICLUB_DropActorsOfMissingPeers(char *p);

void WIFICLUB_UpdatePeerActors(void *a, void *b)
{
    WIFICLUB_SyncPresenceLists(a);
    WIFICLUB_RequestSelectionRefresh(a, (int)b);
    WIFICLUB_DropActorsOfMissingPeers(a);
}
