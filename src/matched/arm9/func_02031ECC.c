/*
 * unit:     no
 * function: BACKUP_SYSTEM_GetCrcTable
 * address:  0x02031ECC
 * packet:   pkt_02031C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj01020.h"

int BACKUP_SYSTEM_GetCrcTable(int p0){ return (*(int *)&((struct Obj01020 *)p0)->f34 + ((*(int *)&((struct Obj01020 *)p0)->f30 - 0x10) - *(int *)&((struct Obj01020 *)p0)->f140)); }
