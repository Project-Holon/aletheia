/*
 * function: FIELD_WFBC_DATA_LOCAL_PickNpcByWeight
 * address:  0x021869E0
 * packet:   pkt_ov020_021869E0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb
 *   FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId  0x02186A2C  thumb
 *   FIELD_WFBC_DATA_LOCAL_LoadNpcData  0x02186818  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern char *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(char *p);
extern int FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId(char *p, int id);
extern void FIELD_WFBC_DATA_LOCAL_LoadNpcData(u32 *p, u32 member);

char *FIELD_WFBC_DATA_LOCAL_PickNpcByWeight(char *a, int limit, char *h, int *out)
{
    char *q;
    int i;
    u32 sum;
    int r;

    sum = 0;
    q = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(h);
    for (i = 0; i < 30; i++) {
        r = FIELD_WFBC_DATA_LOCAL_GetNthAbsentNpcId(a, i);
        FIELD_WFBC_DATA_LOCAL_LoadNpcData((u32 *)h, r);
        sum += *(u16 *)(q + 0x2C);
        if (sum > limit) {
            *out = r;
            return q;
        }
    }
    return q;
}
