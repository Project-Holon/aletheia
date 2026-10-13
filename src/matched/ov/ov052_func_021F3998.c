/*
 * function: FIELD_GIMMICK_BSUBWAY_FindZoneEntry
 * address:  0x021F3998
 * packet:   pkt_ov052_021F3998
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     void return (the callers' prototype) closes the earlier lane's
 *           base/offset register swap; the int-returning spelling was the DIFF.
 *
 * symbols:
 *   sFieldGimmickBsubwayZoneTable     0x021F39DC  data  ov052  a4
 */

typedef struct { int key; int val; } E;
extern E sFieldGimmickBsubwayZoneTable[];

void FIELD_GIMMICK_BSUBWAY_FindZoneEntry(int a0, int *a1, int *a2)
{
    int i;
    for (i = 0; i < 10; i++) {
        if (a0 == sFieldGimmickBsubwayZoneTable[i].key) {
            *a1 = sFieldGimmickBsubwayZoneTable[i].val;
            *a2 = i;
            return;
        }
    }
    *a1 = 0;
    *a2 = 0;
}
