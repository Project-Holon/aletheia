/*
 * function: EVENT_FIELD_PROCLINK_GetEventdataEntry
 * address:  0x02161DC4
 * packet:   pkt_ov010_02161DC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb
 */

typedef unsigned char u8;

extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(char *);

char *EVENT_FIELD_PROCLINK_GetEventdataEntry(char *p, int id, unsigned mode)
{
    int i;
    char *b;
    char *a;
    unsigned m1;

    m1 = mode - 1;
    a = p + 8;
    i = 0;
    b = p + 0xF8;

    for (; i < 10; i++) {
        if (mode == 0 || mode == 2) {
            if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(a + i * 0x18) != 0 && (u8)p[i * 0x18 + 9] == id)
                return p + 8 + i * 0x18;
        }
        if (m1 <= 1) {
            if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(b + i * 0x18) != 0 && (u8)p[i * 0x18 + 0xF9] == id)
                return p + 0xF8 + i * 0x18;
        }
    }
    return 0;
}
