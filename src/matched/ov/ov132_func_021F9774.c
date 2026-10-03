/*
 * function: func_021F9774
 * address: 0x021F9774
 * packet: pkt_ov132_021F9774
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: returning (u32)p+0xfc+i*4 keeps base and scaled index apart across the call; p+i*4+0xfc hoists their common base and is four bytes short.
 * symbols:
 *   func_021F7A80 0x021F7A80 thumb ov112
 */
typedef unsigned int u32;
extern int func_021F7A80(char *,char *);
int func_021F9774(char *p,u32 i){if(func_021F7A80(*(char **)(p+0x40),*(char **)((u32)p+i*4+0x44))==1)return 1;return *(int *)((u32)p+0xfc+i*4);}
