/*
 * function: COMM_ENTRY_ScanParents
 * address:  0x021CEE48
 * packet:   pkt_ov021_021CEE48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * COMM_ENTRY_AddParent takes three arguments: the entry itself is the third, which
 * is why the 0203CF10 result lives in r2 and is copied to r1 for the +0x20
 * address.  (The earlier two-argument prototype left it in r1.)
 *
 * symbols:
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   COMM_ENTRY_AddParent  0x021CEE78  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GFL_NET_GetScanResult(u32 a);
extern void COMM_ENTRY_AddParent(u8 *p, u8 *a, u32 b);

typedef struct Sub021CEE48 {
    u8 pad0[6];
    u16 id;
} Sub021CEE48;

typedef struct Ent021CEE48 {
    u8 pad0[0x20];
    Sub021CEE48 sub;
} Ent021CEE48;

void COMM_ENTRY_ScanParents(u8 *p)
{
    int i;
    Ent021CEE48 *e;

    for (i = 0; i < 0x10; i++) {
        e = (Ent021CEE48 *)GFL_NET_GetScanResult(i);
        if (e != 0 && e->sub.id == 0x3a0b) {
            COMM_ENTRY_AddParent(p, (u8 *)&e->sub, (u32)e);
        }
    }
}
