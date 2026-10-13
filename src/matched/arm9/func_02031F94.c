/*
 * unit:     no
 * function: BACKUP_SYSTEM_SetSaveCount
 * address:  0x02031F94
 * packet:   pkt_02031C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void BACKUP_SYSTEM_SetSaveCount(int *p, int v){ p[10] = v; }
