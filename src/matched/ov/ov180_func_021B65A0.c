/*
 * function: func_021B65A0
 * address: 0x021B65A0
 * packet: pkt_ov180_021B65A0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PM_VOICE_GetPerapVoiceSave 0x02006CAC thumb
 *   PM_VOICE_Prepare 0x020069D4 thumb
 */
#include "../include/Obj04568.h"
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern int PM_VOICE_Prepare(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
void func_021B65A0(char *p) {
 unsigned value;
 if(((struct Obj04568 *)p)->f9158==441) {
  PM_VOICE_GetPerapVoiceSave((void **)(&value));
  ((struct Obj04568 *)p)->f9184=PM_VOICE_Prepare(((struct Obj04568 *)p)->f9158,(unsigned char)p[0x915C],64,0,0,0,0,(int)(&value));
 } else ((struct Obj04568 *)p)->f9184=PM_VOICE_Prepare(((struct Obj04568 *)p)->f9158,(unsigned char)p[0x915C],64,0,0,0,0,0);
}
