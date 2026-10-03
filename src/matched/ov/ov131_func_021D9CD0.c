/*
 * function: func_021D9CD0
 * address: 0x021D9CD0
 * packet: pkt_ov131_021D9CD0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021D9E44 0x021D9E44 thumb ov131
 *   func_021DB964 0x021DB964 thumb ov131
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02041B6C(u32);
extern void func_021D9E44(u8 *,u8 *);
typedef unsigned short u16;
struct Obj;
extern void func_021DB964(u8 *a, void *b, u8 *p);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021D9CD0(u8 *a,u8 *p)
{
    u8 i;
    func_020410D0(2,0,0,32,24,*(u32 *)(p+0x34)+12,0,0,32,32);
    func_02041B6C(2);
    func_021D9E44(a,p);
    for(i=0;i<p[0x2b];i++) func_021DB964(a,p,p+0xb0+i*24);
    func_0204B878(*(void **)(a+0x17c),4);
}
