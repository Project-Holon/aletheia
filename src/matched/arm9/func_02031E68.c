/*
 * function: BACKUP_SYSTEM_GetWrittenSize
 * address:  0x02031E68
 * packet:   pkt_02031E68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj15878.h"

int BACKUP_SYSTEM_GetWrittenSize(const char *ptr)
{
    return *(const int *)&((struct Obj15878 *)ptr)->f144;
}
