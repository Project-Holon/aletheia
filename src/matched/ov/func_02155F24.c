/*
 * function: MUSICAL_EVENT_CreateLocalPerformer
 * address:  0x02155F24
 * packet:   pkt_02155F24
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  compiled 38 bytes; every concrete byte reproduces and the two
 * trailing bytes of the 40-byte listing extent (0x02155F4A `movs r0,r0`)
 * are alignment padding.  The single unresolved relocation is the bl at
 * +0018 to 0x021FD904 (thumb): four overlays overlap that address (ov094,
 * ov132, ov135, ov186) and none traces a func_/sub_ start there, so
 * `label` and `sole-ref/code` both refuse -- there is no traced entry to
 * branch to.  A `symbols:` region hint does not help: tested against each
 * of the four, the site stays wildcarded.  In ov132 the bytes are an
 * unlabelled leaf accessor emitted as a .word run (0x47706C80 =
 * ldr r0,[r0,#0x48]; bx lr); in ov094/ov135 the address is interior to a
 * function, in ov186 it is a data word.  The two other image-wide call
 * sites (0x02155B38, 0x02156C78, both in ov010 and outside this range) are
 * the same shape and are not a usable `label` witness for want of the same
 * traced entry.  No literal pool word anywhere names 0x021FD904 and no
 * EXACT `matched` entry covers it, so the site is evidence-starved.
 * evidence class: `label` / `sole-ref/code` refused (target not a traced
 * function start).
 *
 * 2026-10-06: layout/function_starts.txt now seeds the ov132 and ov186
 * heads at 0x021FD904 and 0x021FD938, so both calls resolve; the region
 * hint ov132 (the overlay holding the 021FD904 accessor) picks the
 * 021FD938 witness among the overlapping overlays.
 *
 * symbols:
 *   func_021F675C  0x021F675C  thumb
 *   STA_NET_GetField48  0x021FD904  thumb
 *   STA_NET_SetState12  0x021FD938  thumb  ov132
 */
#include "../include/Obj05850.h"

extern int func_021F675C(int, int);
extern void STA_NET_GetField48(int);
extern void STA_NET_SetState12(char *p);

void MUSICAL_EVENT_CreateLocalPerformer(int *p)
{
    ((struct Obj05850 *)p)->f3C = func_021F675C(((struct Obj05850 *)p)->f18, 4);
    if (((struct Obj05850 *)p)->f14 != 0) {
        STA_NET_GetField48(*(int *)(((struct Obj05850 *)p)->f8 + 4));
        STA_NET_SetState12((char *)(*(int *)(((struct Obj05850 *)p)->f8 + 4)));
    }
}
