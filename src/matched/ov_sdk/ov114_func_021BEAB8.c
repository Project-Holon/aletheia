/*
 * function: NHTTPi_ControlConnectionList
 * address:  0x021BEAB8
 * packet:   pkt_ov114_021BEAB8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_ControlConnectionList (libnhttp.TWL.HYB.a(d_nhttp_common.o))
 *
 * symbols:
 *   NHTTPi_lockReqList 0x021BEFCC arm ov114
 *   NHTTPi_unlockReqList 0x021BEFD8 arm ov114
 *   gNHTTPModuleGlobals 0x021CF984 data
 *   g_021CF984_hdr 0x021CF984 data
 */

#include "../include/G_Conn.h"

typedef struct Conn Conn;

extern struct Conn *gNHTTPModuleGlobals;
extern struct Conn *g_021CF984_hdr;

extern void NHTTPi_lockReqList(void);
extern void NHTTPi_unlockReqList(void *mutexInfo_p);

Conn *NHTTPi_ControlConnectionList(void *mutexInfo_p, Conn *handle_p, unsigned long order)
{
    Conn *ret_p = 0;
    Conn **connection_pp;
    Conn *connection_p;

    NHTTPi_lockReqList();
    if (order == 3) {
        ret_p = handle_p;
        handle_p->next = gNHTTPModuleGlobals;
        gNHTTPModuleGlobals = handle_p;
    } else {
        connection_pp = &g_021CF984_hdr;
        connection_p = gNHTTPModuleGlobals;
        while (connection_p != 0) {
            switch (order) {
            case 0:
                if (connection_p == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 1:
                if (connection_p->f10 == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 2:
                if (connection_p->f14 == handle_p) {
                    ret_p = connection_p;
                }
                break;
            case 4:
                if (connection_p == handle_p) {
                    ret_p = *connection_pp;
                    *connection_pp = ret_p->next;
                }
                break;
            }
            if (ret_p != 0) {
                break;
            }
            connection_pp = &(*connection_pp)->next;
            connection_p = *connection_pp;
        }
    }
    NHTTPi_unlockReqList(mutexInfo_p);
    return ret_p;
}
