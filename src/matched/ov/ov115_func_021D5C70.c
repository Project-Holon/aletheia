/*
 * function: func_021D5C70
 * address: 0x021D5C70
 * packet: pkt_ov115_021D5C70
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028484 0x02028484 thumb
 *   func_0201CE48 0x0201CE48 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct Blk {u8 first,pad[3]; u32 flags;} Blk;
extern int func_02028484(Blk *,void *);
struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
int func_021D5C70(u8 *p) { int result=1; if(*(void **)(p+56)) { result=func_02028484((Blk *)(p+60),*(void **)(p+56)); if(result) { func_0201CE48(*(void **)(p+56)); *(void **)(p+56)=0; } } return result; }
