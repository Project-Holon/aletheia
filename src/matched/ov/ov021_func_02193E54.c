/*
 * function: FIELD_WFBC_CopyPeopleToSaveData
 * address:  0x02193E54
 * packet:   pkt_ov021_02193E54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_ClearPeopleList  0x0218609C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList  0x021860B8  thumb  ov020
 *   FIELD_WFBC_PEOPLE_StorePerson  0x02193FD4  thumb  ov021
 */
#include "../include/Obj07441.h"
#include "../include/Obj12617.h"

typedef unsigned short u16;
extern void FIELD_WFBC_DATA_LOCAL_ClearPeopleList(char *p);
extern void FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList(char *p);
extern void FIELD_WFBC_PEOPLE_StorePerson(u16 *a, void *b);

void FIELD_WFBC_CopyPeopleToSaveData(unsigned char *p, unsigned char *q)
{
    int i;

    ((struct Obj12617 *)q)->f0 = 1;
    ((struct Obj12617 *)q)->f2 = p[0];
    if (p[1] == 0) {
        FIELD_WFBC_DATA_LOCAL_ClearPeopleList((char *)q);
        q += 8;
        for (i = 0; i < 10; i++)
            FIELD_WFBC_PEOPLE_StorePerson((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    } else {
        FIELD_WFBC_DATA_LOCAL_ClearBackPeopleList((char *)q);
        q += 0xf8;
        for (i = 0; i < 10; i++)
            FIELD_WFBC_PEOPLE_StorePerson((u16 *)(*(unsigned char * *)&((struct Obj07441 *)p)->f4 + i * 0x50), q + i * 0x18);
    }
}
