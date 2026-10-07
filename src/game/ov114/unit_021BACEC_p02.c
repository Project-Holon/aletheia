/*
 * file:     unit_021BACEC_p02.c
 * unit:     yes
 * function: func_021BADE0, func_021BAE90
 * address:  0x021BADE0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NHTTPi_findReqQueue          0x021bad94 arm
 *   NHTTPi_Request2Connection    0x021bebe0 arm
 *   NHTTPi_destroyRequestObject  0x021bb934 arm
 *   NHTTPi_free                  0x021ba850 arm
 *   NHTTPi_CompleteCallback      0x021bee1c arm
 *   NHTTPi_DeleteConnection      0x021bf1b0 arm
 *   func_021BADE0  0x021BADE0  arm  ov114
 */
struct _NHTTPMutexInfo;
struct _NHTTPReq;
typedef unsigned char u8;

typedef unsigned int u32;

struct _NHTTPi_REQLIST {
    struct _NHTTPi_REQLIST *field_0x00;
    struct _NHTTPi_REQLIST *field_0x04;
    int field_0x08;
    struct _NHTTPReq *field_0x0c;
    int field_0x10;
};

struct _NHTTPListInfo {
    struct _NHTTPi_REQLIST *field_0x00;
    int field_0x04;
};

struct _NHTTPConnection {
    int field_0x00;
    int field_0x04;
};

extern struct _NHTTPi_REQLIST *NHTTPi_findReqQueue(struct _NHTTPListInfo *, int);
extern struct _NHTTPConnection *NHTTPi_Request2Connection(struct _NHTTPMutexInfo *, struct _NHTTPReq *);
extern int NHTTPi_destroyRequestObject(struct _NHTTPMutexInfo *, struct _NHTTPReq *);
extern void NHTTPi_free(void *);
extern void NHTTPi_CompleteCallback(struct _NHTTPMutexInfo *, struct _NHTTPConnection *);
extern int NHTTPi_DeleteConnection(struct _NHTTPConnection *);
extern void func_021BADE0(void *, int, int);
int NHTTPi_freeReqQueue(struct _NHTTPListInfo *listInfo_p, struct _NHTTPMutexInfo *mutexInfo_p, int id);
void func_021BAE90(u32 **p, int v);


int NHTTPi_freeReqQueue(struct _NHTTPListInfo *listInfo_p, struct _NHTTPMutexInfo *mutexInfo_p, int id)
{
    struct _NHTTPi_REQLIST *list_p;
    struct _NHTTPConnection *connection_p;
    int rc = 0;

    list_p = NHTTPi_findReqQueue(listInfo_p, id);
    if (list_p != 0) {
        if (listInfo_p->field_0x00 != listInfo_p->field_0x00->field_0x00) {
            list_p->field_0x00->field_0x04 = list_p->field_0x04;
            list_p->field_0x04->field_0x00 = list_p->field_0x00;
            if (listInfo_p->field_0x00 == list_p)
                listInfo_p->field_0x00 = list_p->field_0x04;
        } else {
            listInfo_p->field_0x00 = 0;
        }
        connection_p = NHTTPi_Request2Connection(mutexInfo_p, list_p->field_0x0c);
        NHTTPi_destroyRequestObject(mutexInfo_p, list_p->field_0x0c);
        NHTTPi_free(list_p);
        if (connection_p != 0) {
            connection_p->field_0x04 = 8;
            NHTTPi_CompleteCallback(mutexInfo_p, connection_p);
            NHTTPi_DeleteConnection(connection_p);
        }
        rc = 1;
    }
    return rc;
}


void func_021BAE90(u32 **p, int v)
{
    u32 *n = *p;
    while (n != 0) {
        func_021BADE0(p, v, n[2]);
        n = *p;
    }
}
