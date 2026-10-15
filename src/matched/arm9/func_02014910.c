/*
 * function: FIELD_STATUS_CreateSubProcListEvent
 * address:  0x02014910
 * packet:   pkt_02014628
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0028 ABS32 func_02014878          : 02014878 (thumb, from name) has no witness outside 02014910..0201493C
 *           Closed at the bottom, not unfiled: no branch anywhere in the image
 *           reaches 0x02014878, so only a `matched` entry could attest it, and
 *           func_02014878 is itself capped at MATCH by two own-pool words
 *           (0x0000005B at 0x02014900, 0x00000083 at 0x02014908 - each occurs
 *           exactly once in arm9, inside its own compared range).  See
 *           docs/notes/pkt_02014808.c.txt.
 */

typedef unsigned int u32;

struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern u32 func_02014878(u32 a0, u32 *mode, u32 *p);

void *FIELD_STATUS_CreateSubProcListEvent(char *a0, int a1, int a2, int a3)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014878), 0x10);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    return r;
}
