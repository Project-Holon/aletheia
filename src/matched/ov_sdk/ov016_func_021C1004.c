/*
 * function: func_021C1004
 * address:  0x021C1004
 * packet:   pkt_ov016_021C1004
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MSGlRelease (libdwcutil.TWL.HYB.a message.o)
 *
 * symbols:
 *   func_021D4C68  0x021D4C68  arm  ov016
 *   func_021D546C  0x021D546C  arm  ov016
 *   g_021DE58C     0x021DE58C  data
 */

#include "../include/G_MemMsg.h"

typedef struct MemMsg MemMsg;

extern void func_021D4C68(void *file);
extern void func_021D546C(void *queue, void *data);
extern struct MemMsg *g_021DE58C;

void func_021C1004(void *msg)
{
    func_021D4C68(((void **)msg)[2]);
    func_021D546C(g_021DE58C->queue, msg);
}
