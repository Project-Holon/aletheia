/*
 * unit: yes
 * function: PDWACC_STATE_HandleHttpError, PDWACC_STATE_SetState, PDWACC_STATE_ChangeState
 * address: 0x021D9FD4
 * packet: pkt_ov123_021D9FD4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead with store-and-return follower 021DA030 and tailcall follower 021DA034.
 * symbols:
 *   PDWACC_STATE_StatePrintError 0x021DA1EC thumb ov123
 */
#include "../include/Obj03804.h"
#include "../include/Obj22984.h"
extern void PDWACC_STATE_StatePrintError(char *p);
void PDWACC_STATE_SetState(char *, int, int);
void PDWACC_STATE_ChangeState(char *, int, int);
int PDWACC_STATE_HandleHttpError(char *p, int n)
{
    switch (n) {
    case 503:
        ((struct Obj03804 *)p)->f70=0xfff1;
        PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintError,0x99);
        return 1;
    case 502:
        ((struct Obj03804 *)p)->f70=0xfff2;
        PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintError,0x9d);
        return 1;
    default:
        if (n>=400) {
            ((struct Obj03804 *)p)->f70=0xfff3;
            PDWACC_STATE_ChangeState(p,(int)PDWACC_STATE_StatePrintError,0xa3);
            return 1;
        }
        return 0;
    }
}
void PDWACC_STATE_SetState(char *p, int n, int unused)
{
    ((struct Obj22984 *)p)->f30=n;
}
void PDWACC_STATE_ChangeState(char *p, int n, int unused)
{
    PDWACC_STATE_SetState(p,n,unused);
}
