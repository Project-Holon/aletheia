/*
 * function: FIELD_WFBC_DATA_LOCAL_ValidatePerson
 * address:  0x021866F8
 * packet:   pkt_ov020_021866F8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry  0x02161E78  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct S {
    u8 lo : 4;
    u8 hi : 4;
};

extern u16 STRBUF_GetEosChar(void);
extern void EVENT_FIELD_PROCLINK_ClearReturnEntry(void *a0);

void FIELD_WFBC_DATA_LOCAL_ValidatePerson(char *p)
{
    int i;
    int found;
    u16 v;

    v = STRBUF_GetEosChar();
    if ((u8)p[1] >= 0x1e)
        EVENT_FIELD_PROCLINK_ClearReturnEntry(p);
    if ((u8)p[2] > 0x64)
        EVENT_FIELD_PROCLINK_ClearReturnEntry(p);
    if (((struct S *)p)->hi != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (v == *(u16 *)(p + 4 + i * 2))
                found = 1;
        }
        if (found == 0)
            EVENT_FIELD_PROCLINK_ClearReturnEntry(p);
    }
}
