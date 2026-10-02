/*
 * function: func_021DEB30
 * address: 0x021DEB30
 * packet: pkt_ov093_021DEB30
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: remaining two bytes are zero alignment padding.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern void func_021DD044(void *,void *,int);
void func_021DEB30(int a,int b,int c,int *p) { if(c==func_021D775C(2)) { if(*p) { func_021DD044((void *)a,(void *)b,c); *p=0; } } }
