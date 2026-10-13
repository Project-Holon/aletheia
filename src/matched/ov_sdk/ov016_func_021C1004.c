/*
 * function: DWCi_MSGlRelease
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
 *   DWCi_ARClRelease  0x021D4C68  arm  ov016
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 *   gMessageWork     0x021DE58C  data
 */

#include "../include/G_MemMsg.h"

typedef struct MemMsg MemMsg;

extern void DWCi_ARClRelease(void *file);
extern void DWCi_QUElPushBack(void *queue, void *data);
extern struct MemMsg *gMessageWork;

void DWCi_MSGlRelease(void *msg)
{
    DWCi_ARClRelease(((void **)msg)[2]);
    DWCi_QUElPushBack(gMessageWork->queue, msg);
}
