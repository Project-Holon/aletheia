/*
 * function: func_021D80C0
 * address: 0x021D80C0
 * packet: pkt_ov121_021D80C0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8198 0x021D8198 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021D849C 0x021D849C thumb ov121
 *   MYSTERY_ALBUM_Delete 0x021DD980 thumb ov121
 *   func_021DD1FC 0x021DD1FC thumb ov121
 *   func_021DA8B8 0x021DA8B8 thumb ov121
 */
#include "../include/Obj00326.h"
extern void func_021D8198(char *),func_021D8380(char *),func_021D849C(char *),MYSTERY_ALBUM_Delete(char *);
extern void func_021DD1FC(void **);
typedef unsigned int   u32;
extern void func_021DA8B8(u32 *p);
void func_021D80C0(void *p,int n,char *q) {
 func_021D8198(q);func_021D8380(q);func_021D849C(q);
 if(*(char * *)&((struct Obj00326 *)q)->f0) {MYSTERY_ALBUM_Delete(*(char * *)&((struct Obj00326 *)q)->f0);func_021DD1FC(*(void ** *)&((struct Obj00326 *)q)->f4);}
 func_021DA8B8(p);
}
