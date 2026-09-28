/*
 * function: func_02170168
 * address:  0x02170168
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sends a match command to a host through the server browser.
 *
 * symbols:
 *   func_021700C8  0x021700C8  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02198620  0x02198620  arm  ov009
 *   func_0219EF08  0x0219EF08  arm  ov009
 */

typedef struct {
    char id[5];
} MatchId;

typedef struct {
    MatchId id;
    unsigned char pad[3];
    unsigned char command;
    unsigned char len;
    unsigned short port;
    int ip;
    int pid;
    unsigned int data[32];
} MatchCtrl;

extern void func_021700C8(MatchCtrl *ctrl, unsigned char command, const unsigned int *data, int len);
extern char *func_02175F3C(void);
extern char *func_02198620(unsigned int ip, int port, char *buf);
extern int func_0219EF08(void *sb, const char *addr, unsigned short port, void *data, int len);

int func_02170168(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    int i;
    int res;

    func_021700C8(&ctrl, command, data, len);
    for (i = 0; i < 1; i++) {
        res = func_0219EF08(*(void **)(func_02175F3C() + 0x5e0), func_02198620(ip, 0, 0), port, &ctrl, ctrl.len + 0x14);
        if (res == 0) {
            return res;
        }
        if (res != 2) {
            return res;
        }
    }
    return res;
}
