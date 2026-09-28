/*
 * function: NHTTPi_DestroyResponse
 * address:  0x021BBB28
 * packet:   pkt_ov114_021BBB28
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_DestroyResponse (libnhttp.TWL.HYB.a nhttp_response.o)
 *
 * symbols:
 *   NHTTPi_free                     0x021ba850 arm
 *   NHTTPi_Response2Connection      0x021bebf0 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPMutexInfo;
struct _NHTTPConnection {
    char pad_0x00[0x14];
    int field_0x14;
};

struct _NHTTPi_HDRBUFLIST {
    struct _NHTTPi_HDRBUFLIST *field_0x00;
};

struct _NHTTPRes {
    char pad_0x00[0x1c];
    void *field_0x1c;
    void *field_0x20;
    void *field_0x24;
    void *field_0x28;
    char pad_0x2c[0x30 - 0x2c];
    void (*field_0x30)(void *, void *, void *);
    struct _NHTTPi_HDRBUFLIST *field_0x34;
    char pad_0x38[0x438 - 0x38];
    void *field_0x438;
};

extern void NHTTPi_free(void *);
extern struct _NHTTPConnection *NHTTPi_Response2Connection(struct _NHTTPMutexInfo *, struct _NHTTPRes *);

void NHTTPi_DestroyResponse(struct _NHTTPMutexInfo *mutexInfo_p, struct _NHTTPRes *res_p)
{
    struct _NHTTPi_HDRBUFLIST *list_p = res_p->field_0x34;
    struct _NHTTPConnection *connection_p;

    while (list_p != 0) {
        struct _NHTTPi_HDRBUFLIST *next = list_p->field_0x00;
        NHTTPi_free(list_p);
        list_p = next;
        res_p->field_0x34 = list_p;
    }
    if (res_p->field_0x20 != 0)
        NHTTPi_free(res_p->field_0x20);
    if (res_p->field_0x24 != 0)
        NHTTPi_free(res_p->field_0x24);
    if (res_p->field_0x30 != 0) {
        res_p->field_0x30(res_p->field_0x28, (void *)NHTTPi_free, res_p->field_0x438);
        res_p->field_0x28 = 0;
        res_p->field_0x1c = 0;
    }
    connection_p = NHTTPi_Response2Connection(mutexInfo_p, res_p);
    if (connection_p != 0)
        connection_p->field_0x14 = 0;
    NHTTPi_free(res_p);
}
