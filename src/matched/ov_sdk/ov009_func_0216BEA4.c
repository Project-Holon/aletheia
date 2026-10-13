/*
 * function: DWCi_CloseConnectionHard
 * address:  0x0216BEA4
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_CloseConnectionHard: closes an aid's connection, or runs the closed path for a node with none.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   func_02059F38  0x02059F38  arm
 *   DWCi_GetGT2Connection  0x0216BAF4  arm  ov009
 *   func_02176410  0x02176410  arm  ov009
 *   DWCi_GT2ClosedProcess  0x0216C230  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern int func_02059F38(void);
struct GTI2Connection;
extern int DWCi_GetGT2Connection(int aid);
extern char *func_02176410(unsigned char aid);
extern void DWCi_GT2ClosedProcess(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
extern void func_02195DC4(int conn);

int DWCi_CloseConnectionHard(unsigned char aid)
{
    int conn;
    unsigned char *node;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || func_02059F38() != 0 ||
        (*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 4 &&
         *(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 5)) {
        return -1;
    }
    conn = DWCi_GetGT2Connection(aid);
    if (conn == 0) {
        node = (unsigned char *)func_02176410(aid);
        if (node == 0) {
            return -2;
        }
        DWCi_GT2ClosedProcess(0, 0, 1, node[0x16]);
        return 0;
    }
    func_02195DC4(conn);
    return 0;
}
