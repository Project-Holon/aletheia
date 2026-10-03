/*
 * function: func_021F8140
 * address: 0x021F8140
 * packet: pkt_ov112_021F8140
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5414 0x021F5414 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F5414(void *,int);
void func_021F8140(int a,u8 *p,int b) { *(int *)(p+8)=b; func_021F5414(*(void **)(p+0x58),b); *(int *)(p+4)=1; }
