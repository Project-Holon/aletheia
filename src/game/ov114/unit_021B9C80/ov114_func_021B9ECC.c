/*
 * function: func_021B9ECC
 * address:  0x021B9ECC
 * packet:   pkt_ov114_021B9ECC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SocRecv_sub (libnhttp.TWL.HYB.a(nhttp_socket_ntr))
 *
 * symbols:
 *   func_0215F4DC 0x0215F4DC arm
 *   func_021BA100 0x021BA100 arm ov114
 *   func_021BA13C 0x021BA13C arm ov114
 */

typedef struct {
    char pad[0x40];
    char buf[0x8000];
    int pos;
    int size;
} Con;

extern int func_0215F4DC(int s, void *buf, int len, int flags);
extern void func_021BA100(void *dst_p, void *src_p, int size);
extern void func_021BA13C(int a, int b);

int func_021B9ECC(Con *connection_p, int socket, char *buf_p, int len, int flags)
{
    char *tmpBuf_p;
    int ret;
    int rec;
    unsigned long size;

    tmpBuf_p = connection_p->buf;
    ret = 0;
    if (len > 0) {
        if (connection_p->size == 0) {
            rec = func_0215F4DC(socket, tmpBuf_p, 0x8000, flags);
            if (rec <= 0) {
                return rec;
            }
            connection_p->size = rec;
            connection_p->pos = 0;
        }
        size = connection_p->size;
        if (size != 0) {
            if ((unsigned long)len <= size) {
                size = len;
            }
            func_021BA100(buf_p, tmpBuf_p + connection_p->pos, size);
            connection_p->size -= size;
            if (connection_p->size != 0) {
                connection_p->pos += size;
            } else {
                func_021BA13C((int)tmpBuf_p, 0x8000);
                connection_p->pos = 0;
            }
            ret = size;
        }
    }
    return ret;
}
