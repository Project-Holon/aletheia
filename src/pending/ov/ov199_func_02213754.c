/*
 * function: func_02213754
 * address:  0x02213754
 * packet:   pkt_02213754
 * region:   ov199
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   veneer_02031330  0x02031330  arm
 *   veneer_02031348  0x02031348  arm
 *
 * blocker: codegen only, same 172-byte size, 73 concrete bytes differ, both
 *   relocations resolve. Inlining the case-1 e/v temporaries into the veneer
 *   arguments drops the extra callee-saved register and reproduces the
 *   original `push {r4, lr}` frame (was `push {r3, r4, r5, lr}`, 82 bytes
 *   diff). The remaining difference is the dense-switch dispatch register:
 *   the original computes the table index in r1, mwccarm in r0. Per
 *   docs/idioms/a-void-return-frees-r0-for-the-switch-dispatch-index.md that
 *   is r0/r1 liveness at the dispatch, not a spelling; hoisting the switch
 *   value into a named local, casting it and a trailing return do not move it.
 *   The arms would have to leave r0 live across the dispatch to reach r1.
 *
 * 2026-10-04: the whole body is one register up (original uses r1/r2/r3 for arm
 *   temporaries and never r0), so r0 is reserved for the whole function, not only at the
 *   dispatch. Tried a `next` state local stored once after the switch (tail merge lost,
 *   180 bytes, worse); the existing shape (store per arm, merged by the compiler) keeps
 *   172 bytes. Still open: what keeps r0 reserved.
 */

/*
 * 2026-10-04 (wave D2 lane05): DIFF, now 168 bytes vs 172, all callee-saved
 * regs and the dispatch in r1 now match. Fix found: the two indirect callees
 * take the object as first argument (r0 = s stays live from entry, which is
 * what kept r0 reserved): r(s, s->f8, s->fc), h(s, s->f4, s->fc).
 * Case 3 uses `break` for the failed-callback path (shares the final
 * `movs r0,#0; pop`). Residue: the original has a lone `b next` (0x22137E2,
 * jump to the following instruction) after `s->f4 = 0` in case 3, plus the
 * case 1 veneer-argument order (original: lsls r3,r0,#4; ldr r1,[r2,r3];
 * adds r2,r2,r3; ldr r0,[r4]; ldr r2,[r2,#4]; mine computes the sum first).
 * Tried for the b: explicit empty else, nested if/else with break in else,
 * goto to a label, repeating s->f1b=4 per arm, `h && h()==0` plus re-test.
 */

typedef struct S {
    int f0;
    int f4;
    unsigned short f8;
    int fc;
    char *f10;
    int f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1a;
    unsigned char f1b;
    int f1c;
} S;

extern int veneer_02031330(int);
extern int veneer_02031348(int, int, int, int);

int func_02213754(S *s)
{
    switch (s->f1b) {
    case 0:
        s->f18 = s->f1a;
        s->f1a = s->f19;
        s->f1b = 1;
        break;
    case 1: {
        int (*r)(S *, int, int);
        r = *(int (**)(S *, int, int))((char *)s->f10 + (s->f1a << 4) + 8);
        if (r)
            s->f4 = r(s, s->f8, s->fc);
        else
            s->f4 = 0;
        veneer_02031348(s->f0,
                        *(int *)((char *)s->f10 + (s->f1a << 4)),
                        *(int *)((char *)s->f10 + (s->f1a << 4) + 4),
                        s->f4);
        s->f1b = 2;
        break;
    }
    case 2:
        s->f1c = veneer_02031330(s->f0);
        if (s->f1c == 0)
            s->f1b = 3;
        break;
    case 3: {
        int (*h)(S *, int, int);
        h = *(int (**)(S *, int, int))((char *)s->f10 + (s->f1a << 4) + 0xc);
        if (h) {
            if (h(s, s->f4, s->fc) == 0)
                break;
            s->f4 = 0;
        }
        s->f1b = 4;
        break;
    }
    case 4:
        if (s->f19 == 0xff)
            s->f1b = 5;
        else
            s->f1b = 0;
        break;
    case 5:
        return 1;
    }
    return 0;
}
