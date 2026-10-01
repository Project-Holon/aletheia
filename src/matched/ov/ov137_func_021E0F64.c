/*
 * function: func_021E0F64
 * address: 0x021E0F64
 * packet: pkt_ov137_021E0F64
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef struct { int active, state, x, y, key; } Entry;
void func_021E0F64(char *p, int key)
{
    int i;
    Entry *entry;
    Entry *base = (Entry *)(p + 0xb98);
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
