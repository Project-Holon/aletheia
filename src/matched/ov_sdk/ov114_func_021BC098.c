/*
 * function: func_021BC098
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
 *   func_021BEBE0 0x021BEBE0 arm ov114
 *   func_021BEC74 0x021BEC74 arm ov114
 *   func_021BA25C 0x021BA25C arm ov114
 */

typedef struct {
    int doCancel;
} Req;

typedef struct {
    char pad[0x24];
    char *value;
    unsigned long length;
} Con;

extern Con *func_021BEBE0(void *mutexInfo_p, Req *req_p);
extern int func_021BEC74(void *mutexInfo_p, Con *connection_p, char *label_p, int offset);
extern int func_021BA25C(char *p_p, int len);

int func_021BC098(void *mutexInfo_p, Req *req_p, char *label_p, unsigned long *contentLength, int sendtype)
{
    int offset;
    unsigned long length;
    char *value_p;
    Con *connection_p;

    offset = 0;
    connection_p = func_021BEBE0(mutexInfo_p, req_p);
    if (connection_p == 0) {
        return 0;
    }
    connection_p->value = 0;
    while (1) {
        if (req_p->doCancel != 0) {
            return 0;
        }
        connection_p->length = 0;
        if (func_021BEC74(mutexInfo_p, connection_p, label_p, offset) < 0) {
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
                *contentLength += func_021BA25C(value_p, length);
                break;
            }
        } else {
            return 1;
        }
    }
}
