/*
 * function: func_020582CC
 * address:  0x020582CC
 * packet:   pkt_020582CC
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Handler row 0 of the 3D-rig table searched by BUTTON_MAN_FindRowData: adds the three
 * s16 components of o to dst[0..2].  Same compiler as its sibling
 * func_02058204 (1.1p1 merges the first two loads into an ldm).  The middle
 * argument is unused but kept for the handler signature func_02058204 has.
 */

typedef short s16;

struct Obj {
    s16 v0;
    s16 v1;
    s16 v2;
};

void func_020582CC(struct Obj *o, void *s, int *dst)
{
    dst[0] = dst[0] + o->v0;
    dst[1] = dst[1] + o->v1;
    dst[2] = dst[2] + o->v2;
}
