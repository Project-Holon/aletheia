/*
 * function: func_021D9634
 * address: 0x021D9634
 * packet: pkt_ov123_021D9634
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 */
extern void func_0202F038(void *);
extern void func_0201F7A8(void *,int);
extern void func_020456F8(void *);
extern void func_02041B6C(int);
extern void func_020452E8(void *);
void func_021D9634(char *p) { if(*(void **)(p+0x90)) { func_0202F038(*(void **)(p+0x90)); *(void **)(p+0x90)=0; } if(*(void **)(p+0x48)) { func_0201F7A8(*(void **)(p+0x48),2); func_020456F8(*(void **)(p+0x48)); func_02041B6C(5); func_020452E8(*(void **)(p+0x48)); *(void **)(p+0x48)=0; } }
