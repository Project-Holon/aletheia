/*
 * function: func_021DA7A4
 * address: 0x021DA7A4
 * packet: pkt_ov131_021DA7A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA84A.
 * symbols:
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021D9EF0 0x021D9EF0 thumb ov131
 *   func_021DB964 0x021DB964 thumb ov131
 *   func_0204B878 0x0204B878 arm
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021DB468 0x021DB468 thumb ov131
 */
typedef unsigned char u8;
extern void func_020410D0(unsigned,int,int,int,int,void *,int,int,int,int);
extern void func_02041B6C(unsigned);
extern void func_021D9EF0(u8 *,u8 *);
extern void func_021DB964(u8 *,void *,u8 *);
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021D5A9C(u8 *,int);
extern void func_021DB468(u8 *,u8 *,u8,int);
void func_021DA7A4(u8 *a,u8 *b) {
    u8 i;
    func_020410D0(2,0,0,32,24,*(u8 **)(b+52)+12,0,0,32,32);
    func_02041B6C(2);
    func_021D9EF0(a,b);
    for(i=0;i<b[43];i++) func_021DB964(a,b,b+176+i*24);
    func_0204B878(*(void **)(a+380),4);
    if(b[43]==5) b[41]=4;else b[41]=0;
    func_021D5A9C(a,0);
    func_021DB468(a,b,b[41],0);
}
