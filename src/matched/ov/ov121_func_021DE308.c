/*
 * function: MYSTERY_NET_SetAction
 * address: 0x021DE308
 * packet: pkt_ov121_021DE308
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_NET_IsHandler 0x021DEEAC thumb ov121
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_NoopHandler 0x021DE618 thumb ov121
 *   MYSTERY_NET_StartSession 0x021DE61C thumb ov121
 *   MYSTERY_NET_PollWihStatus 0x021DE6F8 thumb ov121
 *   MYSTERY_NET_StopSession 0x021DE690 thumb ov121
 *   MYSTERY_NET_RunNdDownload 0x021DE958 thumb ov121
 *   MYSTERY_NET_EndDownload 0x021DEDC8 thumb ov121
 *   MYSTERY_NET_StartBeacon 0x021DE70C thumb ov121
 *   MYSTERY_NET_DeleteBeacon 0x021DE7BC thumb ov121
 *   MYSTERY_NET_StartIrc 0x021DE830 thumb ov121
 *   MYSTERY_NET_DeleteIrc 0x021DE8D0 thumb ov121
 */
#include "../include/Obj22912.h"
extern int MYSTERY_NET_IsHandler(int *p, int value);
typedef unsigned int   u32;
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
extern void MYSTERY_NET_NoopHandler(void);
extern void MYSTERY_NET_StartSession(void *, int *, char *);
extern void MYSTERY_NET_PollWihStatus(int, int, char *);
extern void MYSTERY_NET_StopSession(void *, int *, char *), MYSTERY_NET_RunNdDownload(void *, int *, char *), MYSTERY_NET_EndDownload(void *, int *, char *);
extern void MYSTERY_NET_StartBeacon(void *, int *, char *), MYSTERY_NET_DeleteBeacon(void *, int *, char *), MYSTERY_NET_StartIrc(void *, int *, char *), MYSTERY_NET_DeleteIrc(void *, int *, char *);
void MYSTERY_NET_SetAction(char *p, unsigned action)
{
    switch (action) {
    case 1:
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_NoopHandler)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StartSession);
        break;
    case 3:
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_PollWihStatus)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StopSession);
        break;
    case 4:
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_NoopHandler)) MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_RunNdDownload);
        break;
    case 5:
        if (MYSTERY_NET_IsHandler((int *)p, (int)MYSTERY_NET_RunNdDownload)) ((struct Obj22912 *)p)->f76C = 1;
        break;
    case 6: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_EndDownload); break;
    case 7: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StartBeacon); break;
    case 9: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_DeleteBeacon); break;
    case 10: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_StartIrc); break;
    case 12: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_DeleteIrc); break;
    case 0: MYSTERY_NET_SetHandler((u32 *)p, MYSTERY_NET_NoopHandler); break;
    }
}
