/*
 * function: func_021DA8BC
 * address: 0x021DA8BC
 * packet: pkt_ov131_021DA8BC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB9FC 0x021DB9FC thumb ov131
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02041570 0x02041570 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
extern void func_021DB9FC(void *,void *,u8 *);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_020409B4(unsigned);
extern void func_02041570(unsigned,int);
extern void func_02041B6C(unsigned);
extern void func_0204B3DC(void *,int);
extern void func_0204B878(void *,int);
void func_021DA8BC(u8 *a,u8 *b) {
    u8 i;
    for(i=0;i<b[43];i++) func_021DB9FC(a,b,b+176+i*24);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    func_02041570(4,0);
    func_02041B6C(4);
    func_0204B3DC(*(void **)(b+144),0);
    func_0204B3DC(*(void **)(b+148),0);
    func_0204B3DC(*(void **)(a+408),0);
    func_0204B3DC(*(void **)(a+412),0);
    func_0204B878(*(void **)(a+380),1);
}
