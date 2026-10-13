/*
 * function: BTLV_FINGER_CURSOR_IsActive
 * address:  0x02209C2C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_FINGER_CURSOR_IsActive   0x02209C2C  thumb
 *
 * Returns the word at +0x28 of the object passed in r0.  A bare leaf
 * getter with no prologue.
 */

typedef struct {
    char pad[0x28];
    int  val;
} Obj;

int BTLV_FINGER_CURSOR_IsActive(Obj *o)
{
    return o->val;
}
