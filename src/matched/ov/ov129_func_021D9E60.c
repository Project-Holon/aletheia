/*
 * function: func_021D9E60
 * address: 0x021D9E60
 * packet: pkt_ov129_021D9E60
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Load actor into a local before the current-index store.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { s16 x,y; } Pair;
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, unsigned int space);
extern void func_0204B404(void *,Pair *,u32);
void func_021D9E60(u8 *p,int n) { Pair s; void *actor; actor=*(void **)(p+n*28+12); *(int *)(p+0x188)=n; func_0204B454(actor,(struct PtS *)&s,0); s.y+=16; func_0204B404(*(void **)(p+0x194),&s,0); }
