/*
 * function: WIFIBATTLEMATCH_NET_SetupGdbRecord
 * address: 0x021DB6A8
 * packet: pkt_ov175_021DB6A8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WIFIBATTLEMATCH_NET_GetDateTime 0x021DA470 thumb ov175
 *   WIFIBATTLEMATCH_NET_GetGsProfileId 0x021DD020 thumb ov175
 *   d_021E2F2C 0x021E2F2C data a4
 *   d_021E2F38 0x021E2F38 data a4
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 */
#include "../include/Obj01171.h"
#include "../include/Obj24341.h"
#include "../include/Obj24342.h"
#include "../include/Obj24343.h"
#include "../include/Obj24344.h"
#include "../include/Obj24345.h"
#include "../include/Obj24346.h"
#include "../include/Obj24347.h"
#include "../include/Obj24348.h"
#include "../include/Obj24349.h"
#include "../include/Obj24350.h"
#include "../include/Obj24351.h"
#include "../include/Obj24352.h"
#include "../include/Obj24353.h"
#include "../include/Obj24354.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void WIFIBATTLEMATCH_NET_GetDateTime(unsigned char *);
extern u32 WIFIBATTLEMATCH_NET_GetGsProfileId(char *obj);
extern char d_021E2F2C[], d_021E2F38[], d_021E2F4C[], d_021E2F60[];
void WIFIBATTLEMATCH_NET_SetupGdbRecord(char *ctx)
{
    void *record;
    record = GAME_DATA_GetMyStatus(((struct Obj01171 *)ctx)->f8);
    *(char * *)&((struct Obj24341 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f0 = d_021E2F2C;
    ((struct Obj24342 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f4 = 8;
    ((struct Obj24343 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f8 = record;
    ((struct Obj24344 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->fC = 32;
    WIFIBATTLEMATCH_NET_GetDateTime((unsigned char *)ctx + 0x38);
    *(char * *)&((struct Obj24345 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f10 = d_021E2F38;
    ((struct Obj24346 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f14 = 8;
    *(char * *)&((struct Obj24347 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f18 = ctx + 0x38;
    ((struct Obj24348 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f1C = 6;
    *(char * *)&((struct Obj24349 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f20 = d_021E2F4C;
    ((struct Obj24350 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f24 = 2;
    ((struct Obj24351 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f28 = ((struct Obj01171 *)ctx)->fC;
    *(char * *)&((struct Obj24352 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f30 = d_021E2F60;
    ((struct Obj24353 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f34 = 2;
    ((struct Obj24354 *)(*(char * *)&((struct Obj01171 *)ctx)->f190))->f38 = WIFIBATTLEMATCH_NET_GetGsProfileId(ctx);
    ((struct Obj01171 *)ctx)->f198 = 4;
}
