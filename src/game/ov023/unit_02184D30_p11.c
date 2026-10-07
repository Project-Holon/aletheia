/*
 * file:     unit_02184D30_p11.c
 * unit:     yes
 * function: func_021868C8, func_02186938
 * address:  0x021868C8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02186878  0x02186878  thumb
 */
#include "../../matched/include/Obj09772.h"

typedef unsigned char u8;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 b5;
} Rec;

typedef struct {
    Rec r[5];
} Grp;

extern int func_02186878(char *p);
void func_021868C8(char *p);
void func_02186938(Rec *p);


/*
 * The second loop indexes ((Grp *)p)[idx].r[j] in full and lets the
 * compiler hoist p + idx*30 itself: a named group pointer puts the 30*idx
 * temporary in r1 instead of r2.
 * Byte 6 of Rec (b5) exists only to make sizeof(Rec) == 6 so `r[i]` is `muls #6`.
 */
void func_021868C8(char *p)
{
    int i;
    int n;
    int m;
    Rec *r;

    n = 0;
    m = 0;
    i = 0;
    r = ((Grp *)p)[*(int *)(p + 0xBBC)].r;

    for (; i < 5; i++) {
        if (r[i].mid == 0) {
            n++;
        }
    }
    if (n == 5) {
        int idx = func_02186878(p);
        int j;
        for (j = 0; j < 5; j++) {
            if (((Grp *)p)[idx].r[j].mid == 0) {
                m++;
            }
        }
    }
    if (m != 5) {
        ((struct Obj09772 *)p)->fBBC += 1;
        if (((struct Obj09772 *)p)->fBBC >= 100) {
            ((struct Obj09772 *)p)->fBBC = 0;
        }
    }
}

/*
 * extent: trailing two-byte zero alignment padding at 0x02186956.
 */
void func_02186938(Rec *p)
{
    int i;
    for (i = 0; i < 5; i++) p[i].mid = 0;
}
