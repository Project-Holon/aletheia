/*
 * function: func_02067998
 * address:  0x02067998
 * packet:   pkt_02066E30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * OAM affine composer, list driver.  Walks the u16-counted list at `lst`,
 * copying each six-byte row into the global rig's +0x38..+0x3c scratch
 * triple, invoking the caller's optional pre hook (+0x20) and post hook
 * (+0x24) around the composer func_0206775C, which runs only while the
 * rig's +0x30 gate is still set.  The gate is re-armed to 1 at the top of
 * every iteration, so a hook may clear it to skip one row.
 *
 * BYTE-CORRECT: 200 bytes, 0 concrete mismatches.  PARKED, not filed.
 * blocking: label, no outside witness.  The sole wildcard is the +0x0088
 *   PC24 to func_0206775C, whose ONLY branch anywhere in the image is the
 *   `bl` at 0x02067A20 inside this very function (verified by grep over
 *   asm/arm9/).  No cut helps: the site is inside the one function.  It
 *   converts with no edit the moment 0x0206775C has a `matched` entry;
 *   docs/notes/pkt_02066E30.c.txt records how close that row now is.
 *
 * Two levers, both needed:
 *   - the gate store `g_02148B48->gate = 1;` must precede the read of
 *     `lst->rows`, or the row base is loaded first and the first 0x10
 *     bytes of the loop body permute.
 *   - the entry test is `lst->count <= i` on the ZERO counter, not
 *     `count == 0`: the image's `popls` is the unsigned compare of the
 *     loop's own pre-test, hoisted, and `== 0` gives `popeq`.
 *
 * symbols:
 *   g_02148B48    0x02148B48  data
 *   func_0206775C 0x0206775C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Rig {
    u32 pad_00[0x0c];
    u32 gate;        /* 0x30 */
    u32 pad_34;
    u16 row[3];      /* 0x38, 0x3a, 0x3c */
};

struct List {
    u16 count;       /* 0x00 */
    u16 pad_02;
    u16 *rows;       /* 0x04 */
};

struct Hooks {
    u32 pad_00[8];
    void (*pre)(struct Rig *, struct List *, u32);   /* 0x20 */
    void (*post)(struct Rig *, struct List *, u32);  /* 0x24 */
};

extern struct Rig *g_02148B48;

extern void func_0206775C(u16 *row);

void func_02067998(struct Hooks *h, struct List *lst)
{
    struct Rig *rig = g_02148B48;
    u32 i = 0;

    if (lst->count <= i)
        return;

    do {
        u16 *row;

        g_02148B48->gate = 1;
        row = (u16 *)((char *)lst->rows + i * 6);
        rig->row[0] = row[0];
        rig->row[1] = row[1];
        rig->row[2] = row[2];

        if (h->pre != 0)
            h->pre(g_02148B48, lst, i);

        if (g_02148B48->gate != 0)
            func_0206775C(&rig->row[0]);

        if (h->post != 0)
            h->post(g_02148B48, lst, i);

        i = (u16)(i + 1);
    } while (lst->count > i);
}
