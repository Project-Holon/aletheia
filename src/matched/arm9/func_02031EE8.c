/*
 * unit:     no
 * function: BACKUP_SYSTEM_GetFooter
 * address:  0x02031EE8
 * packet:   pkt_02031C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj15879.h"

int BACKUP_SYSTEM_GetFooter(int p0, int p1){ return (p1 + (((struct Obj15879 *)p0)->f30 - 0x10)); }
