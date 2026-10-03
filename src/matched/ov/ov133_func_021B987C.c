/*
 * function: func_021B987C
 * address: 0x021B987C
 * packet: pkt_ov133_021B987C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B9C90 0x021B9C90 thumb ov133
 */
typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v); extern void func_021B9C90(unsigned char *);
void func_021B987C(unsigned char *p) {*(unsigned int *)(p+0x183c)=0;*(unsigned int *)(p+12)=1;func_0204B3DC(*(void **)(p+0x1854),0);func_021B9C90(p);}
