/*
 * function: FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries
 * address:  0x02186670
 * packet:   pkt_ov020_02186670
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb
 *   FIELD_WFBC_DATA_LOCAL_LoadNpcData  0x02186818  thumb
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb
 */
#include "../include/Obj12540.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int FIELD_WFBC_DATA_LOCAL_CountPeople(char *, int);
typedef unsigned int   u32;
extern int *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int a, int id);
extern char *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(char *p);
extern void FIELD_WFBC_DATA_LOCAL_LoadNpcData(u32 *p, u32 member);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(void **p);

void FIELD_WFBC_DATA_LOCAL_FillPeopleListEntries(char *base, char *out, u16 *cnt, int n, u16 id)
{
    unsigned t;
    unsigned lim;
    int k;
    int num;
    int i;
    int h;
    char *r;
    char *q;

    t = FIELD_WFBC_DATA_LOCAL_CountPeople(base, 0);
    k = n * 2;
    lim = k + 2;
    if (lim > t)
        lim = t;
    num = lim - k;
    i = 0;
    h = (int)FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, id);
    r = FIELD_WFBC_DATA_LOCAL_GetNpcRecord((char *)h);
    *cnt = 0;
    if (num > 0) {
        q = base + k * 0x18;
        do {
            FIELD_WFBC_DATA_LOCAL_LoadNpcData((u32 *)h, (u8)q[i * 0x18 + 9]);
            *(u16 *)(out + *cnt * 8) = ((struct Obj12540 *)r)->f28;
            *(int *)(out + *cnt * 8 + 4) = ((struct Obj12540 *)r)->f2A;
            *cnt = *cnt + 1;
            i++;
        } while (i < num);
    }
    FIELD_WFBC_DATA_LOCAL_CloseNpcData((void **)h);
}
