/*
 * function: GURU2_MAIN_AddWobbleEffect
 * address: 0x021E1090
 * packet: pkt_ov137_021E1090
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { int active, state, x, y, z, key; } Entry;
void GURU2_MAIN_AddWobbleEffect(char *p, int key)
{
    int i;
    Entry *entry;
    Entry *base = (Entry *)(p + 0xbfc);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}
