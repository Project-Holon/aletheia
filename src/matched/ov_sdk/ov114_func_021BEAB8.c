/*
 * function: func_021BEAB8
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
 *   func_021BEFCC 0x021BEFCC arm ov114
 *   func_021BEFD8 0x021BEFD8 arm ov114
 *   g_021CF984 0x021CF984 data
 *   g_021CF984_hdr 0x021CF984 data
 */

typedef struct Conn {
    char pad[0x10];
    void *f10;
    void *f14;
    char pad2[8];
    struct Conn *next;
} Conn;

extern Conn *g_021CF984;
extern Conn *g_021CF984_hdr;

extern void func_021BEFCC(void);
extern void func_021BEFD8(void *mutexInfo_p);

Conn *func_021BEAB8(void *mutexInfo_p, Conn *handle_p, unsigned long order)
{
    Conn *ret_p = 0;
    Conn **connection_pp;
    Conn *connection_p;

    func_021BEFCC();
    if (order == 3) {
        ret_p = handle_p;
        handle_p->next = g_021CF984;
        g_021CF984 = handle_p;
    } else {
        connection_pp = &g_021CF984_hdr;
        connection_p = g_021CF984;
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
    func_021BEFD8(mutexInfo_p);
    return ret_p;
}
