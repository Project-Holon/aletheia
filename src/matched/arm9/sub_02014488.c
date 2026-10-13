/*
 * function: FIELD_STATUS_FieldCloseEvent
 * address:  0x02014488
 * packet:   pkt_02014488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c) in a
 *           fresh process after the evidence rules widened twice: still
 *           MATCH*, 3 of 5 sites resolved, no change to the C.  The two
 *           blockers were re-checked against the overlay listings by hand
 *           and are CLOSED AT THE BOTTOM, not merely unfiled: neither
 *           0x02188BD8 nor 0x0215FA44 is a function start in ANY candidate
 *           overlay, so no `thumb ovNNN` region hint on the symbols: line
 *           can resolve them.  0x02188BD8 falls mid-instruction in ov009
 *           (inside `bl func_02193734`) and in ov096, and lands on plain
 *           .word data in ov021 and ov230; 0x0215FA44 falls inside a `str`
 *           in ov009 and on .word data in ov010.  A region hint only picks
 *           between labelled candidates; it cannot create a label.  This
 *           row therefore needs a decompiled overlay, not a better hint.
 *
 * blocking: unresolved: 02188BD8 (thumb, from header) has no witness outside 02014488..02014; unresolved: 0215FA44 (thumb, from header) has no witness outside 02014488..02014
 *
 * symbols:
 *   sub_020120F0   0x020120F0  thumb
 *   sub_02012A30   0x02012A30  thumb
 *   sub_020289B8   0x020289B8  thumb
 *   SCRCMD_NETWORK_UnloadOv020  0x0215FA44  thumb  ov010
 *   FIELDMAP_RequestClose  0x02188BD8  thumb  ov021
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
#include "../include/Obj05792.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct BigObj;
extern u32 sub_02012A30(const struct BigObj *p);
struct Ctx;
struct Sys;
extern u32 sub_020120F0(const struct Ctx *p);
extern u32 sub_020289B8(struct Sys *s);
extern void SCRCMD_NETWORK_UnloadOv020(void);
extern void FIELDMAP_RequestClose(u8 *obj);

int FIELD_STATUS_FieldCloseEvent(void *a0, u32 *a1, u8 *a2)
{
    void *v = (void *)((struct Obj05792 *)a2)->f8;
    void *w = (void *)((struct Obj05792 *)a2)->f0;
    void *x = (void *)((struct Obj05792 *)a2)->f4;
    void *y;

    y = (void *)sub_02012A30(v);
    switch (*a1) {
    case 0:
        FIELDMAP_RequestClose(x);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (sub_020120F0(w) != 0) {
            break;
        }
        if (sub_020289B8(y) == 1) {
            break;
        }
        if (((struct Obj05792 *)a2)->fC != 0) {
            SCRCMD_NETWORK_UnloadOv020();
        }
        return 1;
    }
    return 0;
}
