/*
 * function: func_021D9D94
 * address: 0x021D9D94
 * packet: pkt_ov131_021D9D94
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
typedef unsigned int u32;
extern void func_021DB9FC(void *,void *,u8 *);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_020409B4(u32);
extern void func_02041570(u32,u32);
extern void func_02041B6C(u32);
extern void func_0204B3DC(void *,int);
extern void func_0204B878(void *,int);
void func_021D9D94(u8 *a,u8 *p)
{
    u8 i;
    for(i=0;i<p[0x2b];i++) func_021DB9FC(a,p,p+0xb0+i*24);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    func_02041570(4,0);
    func_02041B6C(4);
    func_0204B3DC(*(void **)(p+0x90),0);
    func_0204B3DC(*(void **)(p+0x94),0);
    func_0204B3DC(*(void **)(a+0x198),0);
    func_0204B3DC(*(void **)(a+0x19c),0);
    func_0204B878(*(void **)(a+0x17c),1);
}
