/*
 * function: NHTTPi_GetPostContentlength
 * address:  0x021BC098
 * packet:   pkt_ov114_021BC098
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_GetPostContentlength (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * symbols:
 *   NHTTPi_Request2Connection 0x021BEBE0 arm ov114
 *   NHTTPi_PostSendCallback 0x021BEC74 arm ov114
 *   NHTTPi_getUrlEncodedSize2 0x021BA25C arm ov114
 */

typedef struct {
    int doCancel;
} Req;

typedef struct {
    char pad[0x24];
    char *value;
    unsigned long length;
} Con;

extern Con *NHTTPi_Request2Connection(void *mutexInfo_p, Req *req_p);
struct Conn;
extern int NHTTPi_PostSendCallback(void *mutexInfo_p, struct Conn *connection_p, char *label_p, int offset);
extern int NHTTPi_getUrlEncodedSize2(char *p_p, int len);

int NHTTPi_GetPostContentlength(void *mutexInfo_p, Req *req_p, char *label_p, unsigned long *contentLength, int sendtype)
{
    int offset;
    unsigned long length;
    char *value_p;
    Con *connection_p;

    offset = 0;
    connection_p = NHTTPi_Request2Connection(mutexInfo_p, req_p);
    if (connection_p == 0) {
        return 0;
    }
    connection_p->value = 0;
    while (1) {
        if (req_p->doCancel != 0) {
            return 0;
        }
        connection_p->length = 0;
        if (NHTTPi_PostSendCallback(mutexInfo_p, (struct Conn *)connection_p, label_p, offset) < 0) {
            return 0;
        }
        length = connection_p->length;
        value_p = connection_p->value;
        if (length != 0) {
            if (value_p == 0) {
                return 0;
            }
            offset += length;
            switch (sendtype) {
            case 0:
            case 1:
                *contentLength += length;
                break;
            case 2:
                *contentLength += NHTTPi_getUrlEncodedSize2(value_p, length);
                break;
            }
        } else {
            return 1;
        }
    }
}
