/*
 * function: func_021B9E44
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern unsigned func_02040804(unsigned);
int func_021B9E44(char *p) { int flag;int result;if(*(int *)(*(char **)(p+4)+4)!=0)return 1;flag=1;if(func_02040804(1)!=0)flag=0;result=0;if(flag!=0)result=1;return result; }
