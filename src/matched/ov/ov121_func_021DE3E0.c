/*
 * unit: yes
 * function: MYSTERY_NET_GetAction, MYSTERY_NET_GetResult
 * address: 0x021DE3E0
 * packet: pkt_ov121_021DE3E0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_NET_IsHandler 0x021DEEAC thumb ov121
 *   MYSTERY_NET_NoopHandler 0x021DE618 thumb ov121
 *   MYSTERY_NET_StartSession 0x021DE61C thumb ov121
 *   MYSTERY_NET_PollWihStatus 0x021DE6F8 thumb ov121
 *   MYSTERY_NET_StopSession 0x021DE690 thumb ov121
 *   MYSTERY_NET_RunNdDownload 0x021DE958 thumb ov121
 *   MYSTERY_NET_EndDownload 0x021DEDC8 thumb ov121
 *   MYSTERY_NET_StartBeacon 0x021DE70C thumb ov121
 *   MYSTERY_NET_RunBeacon 0x021DE7FC thumb ov121
 *   MYSTERY_NET_DeleteBeacon 0x021DE7BC thumb ov121
 *   MYSTERY_NET_StartIrc 0x021DE830 thumb ov121
 *   MYSTERY_NET_RunIrc 0x021DE910 thumb ov121
 *   MYSTERY_NET_DeleteIrc 0x021DE8D0 thumb ov121
 */
#include "../include/Obj22913.h"
extern int MYSTERY_NET_IsHandler(int *p, int value);
extern void MYSTERY_NET_NoopHandler(void);
extern void MYSTERY_NET_StartSession(void *, int *, char *);
extern void MYSTERY_NET_PollWihStatus(int, int, char *);
extern void MYSTERY_NET_StopSession(void *, int *, char *), MYSTERY_NET_RunNdDownload(void *, int *, char *), MYSTERY_NET_EndDownload(void *, int *, char *);
extern void MYSTERY_NET_StartBeacon(void *, int *, char *);
extern void MYSTERY_NET_RunBeacon(void *a, int b, char *p);
extern void MYSTERY_NET_DeleteBeacon(void *, int *, char *);
extern void MYSTERY_NET_StartIrc(void *, int *, char *), MYSTERY_NET_RunIrc(void *, int *, char *), MYSTERY_NET_DeleteIrc(void *, int *, char *);
int MYSTERY_NET_GetAction(void *p)
{
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_NoopHandler)) return 0;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StartSession)) return 1;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_PollWihStatus)) return 2;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StopSession)) return 3;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_RunNdDownload)) return 4;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_EndDownload)) return 6;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StartBeacon)) return 7;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_RunBeacon)) return 8;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_DeleteBeacon)) return 9;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_StartIrc)) return 10;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_RunIrc)) return 11;
    if (MYSTERY_NET_IsHandler(p, (int)MYSTERY_NET_DeleteIrc)) return 12;
    return 0;
}
void *MYSTERY_NET_GetResult(char *p)
{
    return ((struct Obj22913 *)p)->f54;
}
