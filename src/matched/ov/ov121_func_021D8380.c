/*
 * function: func_021D8380
 * address: 0x021D8380
 * packet: pkt_ov121_021D8380
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_021DA698 0x021DA698 thumb ov121
 */
extern void func_020414EC(unsigned),func_020409B4(unsigned),func_02040588(unsigned,unsigned);
extern void func_021DA698(void *);
void func_021D8380(char *p) {
 if(*(void **)(p+0x270)!=0) {func_020414EC(2);func_020409B4(2);func_02040588(2,0);func_021DA698(*(void **)(p+0x270));*(unsigned *)(p+0x270)=0;}
}
