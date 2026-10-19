/*
 * function: WIFIBATTLEMATCH_NET_StepGdbEnsureRecord
 * address: 0x021DA054
 * packet: pkt_ov175_021DA054
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_GdbRequest 0x021DB3A4 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbGetMyRecords 0x021DB478 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbClearRecord 0x021DBFA4 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbCreateRecord 0x021DBFB4 thumb ov175
 */
#include "../include/Obj00629.h"
extern void WIFIBATTLEMATCH_NET_GdbRequest(char *, unsigned long, int, unsigned long);
extern int WIFIBATTLEMATCH_NET_GdbGetMyRecords(char *);
extern void WIFIBATTLEMATCH_NET_GdbClearRecord(char *);
extern int WIFIBATTLEMATCH_NET_GdbCreateRecord(char *);
int WIFIBATTLEMATCH_NET_StepGdbEnsureRecord(char *ctx)
{
    int result;
    switch (((struct Obj00629 *)ctx)->f128) {
    case 0:
        WIFIBATTLEMATCH_NET_GdbRequest(ctx, -1, 2, *(unsigned long *)&((struct Obj00629 *)ctx)->f1464);
        ((struct Obj00629 *)ctx)->f128 = 1;
        break;
    case 1:
        result = WIFIBATTLEMATCH_NET_GdbGetMyRecords(ctx);
        if (result == 1) {
            if (**(int * *)&((struct Obj00629 *)ctx)->f1464 != 0) ((struct Obj00629 *)ctx)->f128 = 4;
            else ((struct Obj00629 *)ctx)->f128 = 2;
        } else if (result == 2) return 2;
        break;
    case 2:
        WIFIBATTLEMATCH_NET_GdbClearRecord(ctx);
        ((struct Obj00629 *)ctx)->f128 = 3;
        break;
    case 3:
        result = WIFIBATTLEMATCH_NET_GdbCreateRecord(ctx);
        if (result == 1) ((struct Obj00629 *)ctx)->f128 = 4;
        else if (result == 2) return 2;
        break;
    case 4: return 1;
    }
    return 0;
}
