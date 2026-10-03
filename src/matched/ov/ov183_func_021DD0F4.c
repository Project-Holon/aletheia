/*
 * function: func_021DD0F4
 * address: 0x021DD0F4
 * packet: pkt_ov183_021DD0F4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {int x,y;} Pair;
extern void func_021FD860(char *,u32,const Pair *),func_021FD15C(void *,int);
void func_021DD0F4(char *p) { if(*(int *)(p+224)) { func_021FD860(*(char **)(p+12),0,0); if(*(void **)(p+24)) { func_021FD15C(*(void **)(p+24),*(int *)(*(char **)(p+208)+16)); *(int *)(p+24)=0; } *(int *)(p+224)=0; } }
