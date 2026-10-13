/*
 * function: FLDMMDL_RAIL_GetDirListOfKind
 * address:  0x0219EA40
 * packet:   pkt_ov021_0219EA40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D84E8  0x021D84E8  data
 */

typedef struct { int key; int val; } Entry;
extern Entry d_021D84E8[];

int FLDMMDL_RAIL_GetDirListOfKind(int key)
{
    Entry *e = d_021D84E8;
    int k = 0;
    do {
        if (k == key) {
            return e->val;
        }
        e++;
        k = e->key;
    } while (k != 11);
    return 0;
}
