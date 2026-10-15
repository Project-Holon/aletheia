/*
 * function: LOCAL_TVT_SYS_ProcExit
 * address: 0x021B6C2C
 * packet: pkt_ov174_021B6C2C
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   LOCAL_TVT_SYS_Delete 0x021B61C4 thumb ov174
 *   GAME_DATA_Delete 0x02012704 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj00681.h"
#include "../include/Obj24204.h"
struct S020315D4;extern void LOCAL_TVT_SYS_Delete(unsigned char *),GAME_DATA_Delete(unsigned char *),func_020307B0(void *),func_020315D4(struct S020315D4 *),GFL_HEAP_DeleteChecked(unsigned int);
int LOCAL_TVT_SYS_ProcExit(struct S020315D4 *a,unsigned unused,int own,unsigned char *p) {LOCAL_TVT_SYS_Delete(p);if(own==0){GAME_DATA_Delete(*(unsigned char * *)&((struct Obj24204 *)(*(char * *)&((struct Obj00681 *)p)->f30))->f4);func_020307B0(((struct Obj00681 *)p)->f30);}func_020315D4(a);GFL_HEAP_DeleteChecked(85);return 1;}
