/*
 * unit:     no
 * function: BACKUP_SYSTEM_WriteFlash
 * address:  0x02033478
 * packet:   pkt_0203331C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FLASH_ACCESS_Write  0x020335AC  arm
 */

typedef unsigned int   u32;
extern u32 FLASH_ACCESS_Write(u32 a, u32 b, u32 c, u32 d);
void BACKUP_SYSTEM_WriteFlash(int a0, int a1, int a2){ FLASH_ACCESS_Write((int)a0, (int)a1, (int)a2, (int)*(int *)(((char *)(*(int *)((char *)(0x2146994))) + 520))); }
