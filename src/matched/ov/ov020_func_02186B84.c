/*
 * function: FIELD_WFBC_DATA_LOCAL_InitNewPerson
 * address: 0x02186B84
 * packet: pkt_ov020_02186B84
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: assign the low bitfield before the byte fields; a later bitfield store changes scheduling.
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_SetPersonParent 0x0218677C thumb ov020
 */
typedef unsigned char u8;
typedef struct { u8 lo:4; u8 hi:4; u8 b1; u8 b2; u8 b3; } T;
extern void FIELD_WFBC_DATA_LOCAL_SetPersonParent(u8 *p, void *src);
void FIELD_WFBC_DATA_LOCAL_InitNewPerson(T *p, int a, int b, int c, int d)
{
    p->lo = 1;
    p->b1 = a;
    p->b3 = 7;
    p->b2 = c;
    if (d) FIELD_WFBC_DATA_LOCAL_SetPersonParent((u8 *)p, (void *)b);
}
