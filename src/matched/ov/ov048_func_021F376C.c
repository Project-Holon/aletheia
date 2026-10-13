/*
 * function: FIELD_GIMMICK_GATE_Update
 * address: 0x021F376C
 * packet: pkt_ov048_021F376C
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetCommonWork 0x021897BC thumb ov021
 *   GIMMICK_OBJ_ELBOARD_Advance 0x021F4784 thumb ov048
 *   FIELDMAP_GetExpObj 0x02188D2C thumb ov021
 *   FLD_EXP_OBJ_UpdateAnimes 0x021BE580 thumb ov021
 *   d_021F50C0 0x021F50C0 data a4
 */

#include "../include/G_T.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int *FIELDMAP_GetCommonWork(char *,int);
extern void GIMMICK_OBJ_ELBOARD_Advance(unsigned char *p, int c);
extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_UpdateAnimes(void *);
extern struct T d_021F50C0;
void FIELD_GIMMICK_GATE_Update(char *a) { int *p; p=FIELDMAP_GetCommonWork(a,0); GIMMICK_OBJ_ELBOARD_Advance((void *)p[5],(*(int *)&d_021F50C0)); FLD_EXP_OBJ_UpdateAnimes((void *)FIELDMAP_GetExpObj((int *)((u32)a))); }
