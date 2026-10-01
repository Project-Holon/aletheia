/*
 * function: func_0204B09C
 * address:  0x0204B09C
 * packet:   pkt_0204B09C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled arm9 leaf (the label at 0x0204B09C also spans the next leaf at
 * 0x0204B0C8); witness for ov021 func_021A87A8. Writes a 16-bit x/y pair,
 * scaled to fx32, into entry idx (0x48 bytes each) of the table at +0x98.
 */

typedef short s16;

typedef struct {
    int x;
    int y;
    char pad[0x40];
} Entry;

typedef struct {
    char pad[0x98];
    Entry *entries;
} Owner;

typedef struct {
    s16 x;
    s16 y;
} Vec16;

void func_0204B09C(Owner *o, int idx, Vec16 *v)
{
    int x = v->x;
    int y = v->y;
    Entry *e = &o->entries[idx];
    e->x = x << 12;
    e->y = y << 12;
}
