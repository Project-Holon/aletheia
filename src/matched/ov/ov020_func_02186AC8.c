/*
 * function: FIELD_WFBC_DATA_LOCAL_InsertPerson
 * address:  0x02186AC8
 * packet:   pkt_ov020_02186AC8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_IsPeopleListFull  0x02186B08  thumb
 *   FIELD_WFBC_DATA_LOCAL_PushPersonFront  0x02186B2C  thumb
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry  0x02161E78  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_SetPersonParent  0x0218677C  thumb
 */

extern int FIELD_WFBC_DATA_LOCAL_IsPeopleListFull(char *);
extern char *FIELD_WFBC_DATA_LOCAL_PushPersonFront(char *, char *);
extern void EVENT_FIELD_PROCLINK_ClearReturnEntry(void *a0);
typedef unsigned char  u8;
extern void FIELD_WFBC_DATA_LOCAL_SetPersonParent(u8 *p, void *src);

void FIELD_WFBC_DATA_LOCAL_InsertPerson(char *p, int b, char *c, int d)
{
    char *q;

    if (FIELD_WFBC_DATA_LOCAL_IsPeopleListFull(p + 8) == 1) {
        FIELD_WFBC_DATA_LOCAL_PushPersonFront(p + 0xF8, p + 0xE0);
        EVENT_FIELD_PROCLINK_ClearReturnEntry(p + 0xE0);
    }
    q = p + 8;
    q = FIELD_WFBC_DATA_LOCAL_PushPersonFront(q, c);
    if (d != 0)
        FIELD_WFBC_DATA_LOCAL_SetPersonParent((u8 *)q, (void *)b);
}
