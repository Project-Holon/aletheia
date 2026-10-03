/*
 * function: func_021719A4
 * address:  0x021719A4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_HandleMatchCommandError: dispatches to the server-browsing or command error handler.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02173D9C  0x02173D9C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 */

extern int func_02175F3C(void);
extern int func_02173D9C(int error);
extern int func_02173D28(int error);

int func_021719A4(int error)
{
    if (*(unsigned char *)(func_02175F3C() + 0x15) == 0) {
        return func_02173D9C(error);
    }
    return func_02173D28(error);
}
