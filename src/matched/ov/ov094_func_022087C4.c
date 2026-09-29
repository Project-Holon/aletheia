/*
 * function: func_022087C4
 * address:  0x022087C4
 * packet:   pkt_ov094_022087C4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Levers: the angle is read into an int local (asrs, not lsrs); the
 * increment goes through a second cast pointer expression so the word is
 * reloaded instead of CSE'd.
 *
 * symbols:
 *   tbl_020A1B38  0x020A1B38  data
 *   func_022079C0 0x022079C0  thumb  ov094
 */

typedef unsigned int u32;
typedef short s16;

typedef struct Ang {
    u32 lo : 5;
    u32 ang : 16;
    u32 hi : 11;
} Ang;

extern s16 tbl_020A1B38[];
extern void func_022079C0(char *obj, int a, s16 *v);

void func_022087C4(char *obj, int a)
{
    s16 v[2];
    Ang *f;
    int i;

    f = (Ang *)(obj + 0x440);
    v[0] = -16;
    i = f->ang;
    v[1] = tbl_020A1B38[2 * (i >> 4)] / 0x800;
    ((Ang *)(obj + 0x440))->ang += 0x400;
    func_022079C0(obj, a, v);
}
