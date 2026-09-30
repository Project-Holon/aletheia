/*
 * function: func_021D74B0
 * address: 0x021D74B0
 * packet: pkt_ov120_021D74B0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8AB0 0x021D8AB0 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B908 0x0204B908 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Table { u32 a[16]; } Table;
extern const Table d_021D8AB0;
extern void *func_020490F4(void *,u16);
extern void func_02049990(void *,u32,u32,u32,u16,u32,u32,u16);
extern void func_02049238(void *);
extern void func_0204B92C(void *,u32);
extern void func_0204B878(void *,u16);
extern void func_0204B908(void *,u32);
extern void func_02041B6C(u32);
void func_021D74B0(u8 *p,int n)
{
    Table a=d_021D8AB0;
    void *t=func_020490F4((void *)144,*(u16 *)(p+0xf4));
    func_02049990(t,15,0,0,*(u32 *)(p+4),0,0,*(u16 *)(p+0xf4));
    func_02049238(t);
    func_0204B92C(*(void **)(p+0x130),0);
    func_0204B878(*(void **)(p+0x130),a.a[n]+11);
    func_0204B908(*(void **)(p+0x130),4);
    func_0204B878(*(void **)(p+0x12c),28);
    func_02041B6C(0);
    *(u32 *)(p+0x110)=0;
    *(u32 *)(p+0x114)=0;
}
