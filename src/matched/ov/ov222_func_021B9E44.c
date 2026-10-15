/*
 * function: ZENKOKU_ZUKAN_AWARD_IsActorIdle
 * address: 0x021B9E44
 * packet: pkt_ov222_021B9E44
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: zero-initialized result set conditionally retains zero-first boolean materialization.
 * symbols:
 *   func_02040804 0x02040804 arm
 */
#include "../include/Obj26081.h"
#include "../include/Obj26082.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned func_02040804(unsigned);
int ZENKOKU_ZUKAN_AWARD_IsActorIdle(char *p) { int flag;int result;if(((struct Obj26082 *)(*(char * *)&((struct Obj26081 *)p)->f4))->f4!=0)return 1;flag=1;if(func_02040804(1)!=0)flag=0;result=0;if(flag!=0)result=1;return result; }
