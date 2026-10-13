/*
 * function: DWCi_MSGlRead
 * address:  0x021C0FAC
 * packet:   pkt_ov016_021C0FAC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MSGlRead (libdwcutil.TWL.HYB.a(message.o))
 *
 * symbols:
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   DWCi_ARClReadEx  0x021D4B68  arm  ov016
 *   gMessageWork  0x021DE58C  data
 */

#include "../include/G_MemMsg.h"

typedef struct {
	int a;
	int b;
	int c;
} Info;

extern void *DWCi_QUElPopBack(void *que);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern struct MemMsg *gMessageWork;

void *DWCi_MSGlRead(char *file)
{
	unsigned long size;
	Info *info;
	char *msg;
	int *hdr;

	info = (Info *)DWCi_QUElPopBack(*(void **)(((char *)gMessageWork) + 0x60));
	msg = DWCi_ARClReadEx(file, &size, 4);
	hdr = (int *)(msg + 0x20);
	info->c = (int)msg;
	info->a = (int)(hdr + 4);
	info->b = (int)hdr + hdr[1] + 8;
	return info;
}
