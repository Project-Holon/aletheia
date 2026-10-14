/*
 * function: GSYNC_STATE_HandleHttpError
 * address: 0x021D6E08
 * packet: pkt_ov123_021D6E08
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 */
#include "../include/Obj00063.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateErrorMessage(char *);
int GSYNC_STATE_HandleHttpError(char *p,int x)
{
    switch (x) {
    case 503:
        ((struct Obj00063 *)p)->f80=0xfff1;
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0xd3);
        return 1;
    case 502:
        ((struct Obj00063 *)p)->f80=0xfff2;
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0xd7);
        return 1;
    }
    if (x>=400) {
        ((struct Obj00063 *)p)->f80=0xfff3;
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateErrorMessage,0xdd);
        return 1;
    }
    return 0;
}
