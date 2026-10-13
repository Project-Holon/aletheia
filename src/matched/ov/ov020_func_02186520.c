/*
 * function: FIELD_WFBC_DATA_LOCAL_InsertPersonForCity
 * address: 0x02186520
 * packet: pkt_ov020_02186520
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_InsertPerson 0x02186AC8 thumb ov020
 */
#include "../include/Obj19457.h"
extern void FIELD_WFBC_DATA_LOCAL_InsertPerson(char *, int, char *, int);
void FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(char *p, int b, char *c) { if (((struct Obj19457 *)p)->f2 == 0) FIELD_WFBC_DATA_LOCAL_InsertPerson(p,b,c,1); else FIELD_WFBC_DATA_LOCAL_InsertPerson(p,b,c,0); }
