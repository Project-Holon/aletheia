#ifndef GAME_OV107_MB_COMMON_H
#define GAME_OV107_MB_COMMON_H

/* Public functions of mb_common.c, prototypes copied from their definitions. */

int MBi_BlockHeaderEnd(int body_len, u16 pollbmp, u32 *sendbuf);
u16 MBi_calc_cksum(u16 *buf, int length);

#endif
