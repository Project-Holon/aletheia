/*
 * function: DWCi_ARClRelease
 * address:  0x021D4C68
 * packet:   pkt_ov016_021D4C68
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ARClRelease (libdwcutil.TWL.HYB.a(archive.o))
 *
 * symbols:
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 *   gMemArchive  0x021DE66C  data
 */

#include "../include/G_MemArc.h"

extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_QUElPushBack(void *que, void *elem);
extern struct MemArc *gMemArchive;

void DWCi_ARClRelease(void *file)
{
	DWCi_HEAPlFree_(&file);
	DWCi_QUElPushBack(*(void **)(((char *)gMemArchive) + 0x84), file);
}
