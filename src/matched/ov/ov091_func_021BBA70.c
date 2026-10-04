/*
 * function: func_021BBA70
 * address: 0x021BBA70
 * packet: pkt_ov091_021BBA70
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02028618 0x02028618 thumb
 *   func_02045334 0x02045334 arm
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02028618(int,unsigned int,int);
extern void func_02045334(unsigned int);
void func_021BBA70(int a,int b) {func_02028618(*(int *)(b+20),(unsigned int)func_02045770((struct Descriptor *)*(unsigned int *)(b+4)),15);func_02045334(*(unsigned int *)(b+4));}
