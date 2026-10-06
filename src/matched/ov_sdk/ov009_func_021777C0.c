/*
 * function: func_021777C0
 * address:  0x021777C0
 * packet:   pkt_ov009_021777C0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCs_Send (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * symbols:
 *   func_0216BAF4  0x0216BAF4  arm  ov009
 *   func_02176C00  0x02176C00  arm  ov009
 *   gt2Send        0x02195CC0  arm  ov009
 *   func_02176CF8  0x02176CF8  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 */

extern int func_0216BAF4(int aid);
extern int func_02176C00(void);
extern int gt2Send(void *connection, unsigned char *buffer, int size, int reliable);
extern int func_02176CF8(void *connection, unsigned char *buffer, int size);
extern void DWCi_SetError(int kind, int code);

void func_021777C0(unsigned char aid, unsigned char *buffer, int size, int reliable)
{
    void *connection;
    int res;

    connection = (void *)func_0216BAF4(aid);
    if (reliable != 0) {
        if (func_02176C00() != 0) {
            res = gt2Send(connection, buffer, size, reliable);
            if (res == 0)
                return;
        }
        if (func_02176CF8(connection, buffer, size) != 0)
            return;
        DWCi_SetError(6, -0x17D5E);
        return;
    }
    gt2Send(connection, buffer, size, reliable);
}
