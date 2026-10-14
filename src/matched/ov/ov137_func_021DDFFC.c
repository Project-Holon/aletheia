/*
 * function: GURU2_RECEIPT_StateTimeout
 * address: 0x021DDFFC
 * packet: pkt_ov137_021DDFFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_GetUnionApp 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj03840.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char  u8;
extern void *GURU2_RECEIPT_GetUnionApp(u8 *p);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateTimeout(char *p, int state) {
    if (((struct Obj03840 *)p)->f481C != 0) {
        if (((struct Obj03840 *)p)->f481C != UNION_APP_GetMemberCount(GURU2_RECEIPT_GetUnionApp((u8 *)p)))
            ((struct Obj03840 *)p)->f481C = 0;
    }
    if (--((struct Obj03840 *)p)->f4818 < 0)
        ((struct Obj03840 *)p)->f481C = 0;
    if (++((struct Obj03840 *)p)->f124 > 60 && ((struct Obj03840 *)p)->f481C == 0) {
        ((struct Obj03840 *)p)->f118 = 0;
        GFL_NET_SYSTEM_GetCurrentAid();
    }
    GURU2_RECEIPT_Noop(p);
    return state;
}
