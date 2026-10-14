/*
 * function: GURU2_MAIN_ActivatePlayerRecord
 * address: 0x021E078C
 * packet: pkt_ov137_021E078C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_ActivatePlayerUnit 0x021E0B14 thumb ov137
 *   GURU2_MAIN_ActivateCardUnit 0x021E0BA4 thumb ov137
 */
#include "../include/Obj23777.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_ActivatePlayerUnit(char *,char *);
extern void GURU2_MAIN_ActivateCardUnit(char *,char *);
void GURU2_MAIN_ActivatePlayerRecord(char *p,char *q) { ((struct Obj23777 *)q)->f4=1; GURU2_MAIN_ActivatePlayerUnit(p,q); GURU2_MAIN_ActivateCardUnit(p,q); }
