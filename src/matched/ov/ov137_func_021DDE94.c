/*
 * function: GURU2_RECEIPT_StateSetSyncToken
 * address: 0x021DDE94
 * packet: pkt_ov137_021DDE94
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GURU2_RECEIPT_GetJoinedBits 0x021DE37C thumb ov137
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj08212.h"
typedef unsigned short u16;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned GURU2_RECEIPT_GetJoinedBits(void *p);
extern void GFL_NET_HANDLE_SetUserInfo(char *p, int a, int b, int c);
extern void GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateSetSyncToken(char *p, int state) {
    GFL_NET_HANDLE_GetCurrentHandle();
    ((struct Obj08212 *)p)->f4814 = ((struct Obj08212 *)p)->f480C ^ GURU2_RECEIPT_GetJoinedBits(p);
    GFL_NET_HANDLE_SetUserInfo((char *)GFL_NET_HANDLE_GetCurrentHandle(), 0xcf, 0x28, (u16)(((struct Obj08212 *)p)->f4814));
    ((struct Obj08212 *)p)->f118 = 0x10;
    GURU2_RECEIPT_Noop(p);
    return state;
}
