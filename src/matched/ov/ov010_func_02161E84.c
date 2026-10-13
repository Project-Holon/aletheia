/*
 * function: EVENT_FIELD_PROCLINK_IsReturnEntryAllowed
 * address:  0x02161E84
 * packet:   pkt_ov010_02161E84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
    u8 b1;
    u8 b2;
    u8 pad;
    u16 ids[8];
} T;

extern u16 STRBUF_GetEosChar(void);

int EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(T *p)
{
    int id = STRBUF_GetEosChar();
    int i;
    int found;
    if (p->b1 >= 30) return 0;
    if (p->b2 > 100) return 0;
    if (p->hi != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (id == p->ids[i]) found = 1;
        }
        if (found == 0) return 0;
    }
    return 1;
}
