/*
 * file:     nhttp_list.c
 * unit:     yes
 * function: NHTTPi_InitListInfo, NHTTPi_setReqQueue, NHTTPi_findReqQueue, NHTTPi_freeReqQueue, NHTTPi_allFreeReqQueue, NHTTPi_popReqQueue
 * address:  0x021BACEC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * ov114 tail-call thunk via `ldr ip,pool; bx ip`.
 *
 * symbols:
 *   NHTTPi_alloc  0x021ba820 arm
 *   NHTTPi_Request2Connection    0x021bebe0 arm
 *   NHTTPi_destroyRequestObject  0x021bb934 arm
 *   NHTTPi_free                  0x021ba850 arm
 *   NHTTPi_CompleteCallback      0x021bee1c arm
 *   NHTTPi_DeleteConnection      0x021bf1b0 arm
 *   NHTTPi_freeReqQueue  0x021BADE0  arm  ov114
 *   NHTTPi_getHdrFromList  0x021BABF4  arm  ov114
 */
#include "nhttp_types.h"

#include "nhttp_bgnend.h"
#include "d_nhttp_common.h"
#include "nhttp_request.h"
#include "d_nhttp_private.h"
struct _NHTTPi_DATALIST;
#include "nhttp_control.h"
void NHTTPi_InitListInfo(NHTTPListInfo *listInfo_p);
int NHTTPi_setReqQueue(NHTTPListInfo *listInfo_p, NHTTPReq *req_p);
NHTTPi_REQLIST *NHTTPi_findReqQueue(NHTTPListInfo *listInfo_p, int id);
int NHTTPi_freeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p, int id);
void NHTTPi_allFreeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p);
NHTTPi_REQLIST *NHTTPi_popReqQueue(NHTTPListInfo *listInfo_p);



/*
 * Empties the request queue and restarts the id counter.
 */
void NHTTPi_InitListInfo(NHTTPListInfo *listInfo_p)
{
    listInfo_p->head = 0;
    listInfo_p->nextId = 0;
}



int NHTTPi_setReqQueue(NHTTPListInfo *listInfo_p, NHTTPReq *req_p)
{
    NHTTPi_REQLIST *list_p;
    int id;

    id = -1;
    list_p = NHTTPi_alloc(sizeof(*list_p), 4);
    if (list_p != 0) {
        if (listInfo_p->head == 0) {
            list_p->next = list_p;
            list_p->prev = list_p;
            listInfo_p->head = list_p;
        } else {
            list_p->next = listInfo_p->head->next;
            list_p->prev = listInfo_p->head;
            listInfo_p->head->next->prev = list_p;
            listInfo_p->head->next = list_p;
        }
        id = listInfo_p->nextId;
        listInfo_p->nextId++;
        list_p->id = id;
        list_p->req_p = req_p;
        list_p->socket = -1;
        if (listInfo_p->nextId < 0)
            listInfo_p->nextId = 0;
    }
    return id;
}



NHTTPi_REQLIST *NHTTPi_findReqQueue(NHTTPListInfo *listInfo_p, int id)
{
    NHTTPi_REQLIST *listRet_p = 0;
    NHTTPi_REQLIST *head_p = listInfo_p->head;
    NHTTPi_REQLIST *list_p;

    if (head_p != 0) {
        if (head_p->id == id)
            listRet_p = head_p;
        else {
            list_p = head_p->prev;
            if (list_p != head_p) {
                do {
                    if (list_p->id == id) {
                        listRet_p = list_p;
                        break;
                    }
                    list_p = list_p->prev;
                } while (list_p != head_p);
            }
        }
    }
    return listRet_p;
}



int NHTTPi_freeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p, int id)
{
    NHTTPi_REQLIST *list_p;
    NHTTPConnection *connection_p;
    int rc = 0;

    list_p = NHTTPi_findReqQueue(listInfo_p, id);
    if (list_p != 0) {
        if (listInfo_p->head != listInfo_p->head->next) {
            list_p->next->prev = list_p->prev;
            list_p->prev->next = list_p->next;
            if (listInfo_p->head == list_p)
                listInfo_p->head = list_p->prev;
        } else {
            listInfo_p->head = 0;
        }
        connection_p = NHTTPi_Request2Connection(mutexInfo_p, list_p->req_p);
        NHTTPi_destroyRequestObject(mutexInfo_p, list_p->req_p);
        NHTTPi_free(list_p);
        if (connection_p != 0) {
            connection_p->nhttpError = 8;
            NHTTPi_CompleteCallback(mutexInfo_p, connection_p);
            NHTTPi_DeleteConnection(connection_p);
        }
        rc = 1;
    }
    return rc;
}



void NHTTPi_allFreeReqQueue(NHTTPListInfo *listInfo_p, NHTTPMutexInfo *mutexInfo_p)
{
    NHTTPi_REQLIST *node_p = listInfo_p->head;
    while (node_p != 0) {
        NHTTPi_freeReqQueue(listInfo_p, mutexInfo_p, node_p->id);
        node_p = listInfo_p->head;
    }
}


NHTTPi_REQLIST *NHTTPi_popReqQueue(NHTTPListInfo *listInfo_p)
{
    return (struct _NHTTPi_REQLIST *)NHTTPi_getHdrFromList((struct _NHTTPi_DATALIST **)(&listInfo_p->head));
}
