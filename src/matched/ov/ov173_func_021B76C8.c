/*
 * function: func_021B76C8
 * address: 0x021B76C8
 * packet: pkt_ov173_021B76C8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021B789E; the next function starts at 0x021B78A0.
 * abi: ABF0 and 185F0 returns are consumed; 185F0 preserves the passed r0 pointer. D7C8's three legacy trailing inputs are neither read nor forwarded to its zero-argument D060 and two-argument 490F4 callees, and this caller supplies only heap in r0.
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027618 0x02027618 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_020275F8 0x020275F8 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_020275E8 0x020275E8 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_02049238 0x02049238 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_0202D934 0x0202D934 thumb
 *   func_0202D8D0 0x0202D8D0 thumb
 *   func_0202D9A4 0x0202D9A4 thumb
 *   func_02017DE4 0x02017DE4 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020275E4(void);
extern void *func_020490F4(u32,u16);
extern u32 func_02027618(void);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern u32 func_020275F8(u32);
extern u32 func_02027614(void);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern u32 func_020275E8(void);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern int func_0204AF28(void *,u32,u32,u32);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern void func_02049238(void *);
extern int func_0202D7C8(int);
extern void *func_020185F0(void *);
extern u32 func_02017DBC(void *);
extern int func_0202D934(int,void *,int,int,u16);
extern int func_0202D8D0(int,void *,int,int,u16,u16);
extern u32 func_0202D9A4(u32,u32,u32,u32,u16);
extern u32 func_02017DE4(void *,u32);
void func_021B76C8(char *p,void *other)
{
    void *bank;
    u32 i;
    u32 first;
    int second;
    void *mon;
    u32 save;
    bank=func_020490F4(func_020275E4(),79);
    *(int *)(p+0x70)=func_0204A6C8(bank,func_02027618(),0,1,79);
    *(int *)(p+0x74)=func_0204A6C8(other,17,0,1,79);
    *(int *)(p+0x78)=func_0204A6C8(other,26,0,1,79);
    for(i=4;i<8;i++) *(int *)(p+i*4+0x70)=func_0204A6C8(bank,func_020275F8(0),0,0,79);
    *(int *)(p+0x7c)=func_0204A6C8(other,23,0,1,79);
    *(int *)(p+0x94)=func_0204AC18(bank,func_02027614(),1,0,0,4,79);
    *(int *)(p+0x98)=func_0204AC18(other,5,1,128,0,1,79);
    *(int *)(p+0x9c)=func_0204AC18(bank,func_020275E8(),1,192,0,3,79);
    *(int *)(p+0xa0)=func_0204ABF0(bank,func_020275E8(),0,0,79);
    first=func_0202761C(1);
    *(int *)(p+0xb8)=func_0204AF28(bank,first,func_02027620(1),79);
    *(int *)(p+0xbc)=func_0204AF28(other,7,8,79);
    first=func_020275FC(1);
    *(int *)(p+0xc0)=func_0204AF28(bank,first,func_02027600(1),79);
    *(int *)(p+0xc4)=func_0204AF28(other,24,25,79);
    *(int *)(p+0xc8)=func_0204AF28(other,27,28,79);
    func_02049238(bank);
    second=func_0202D7C8(79);
    mon=func_020185F0(**(void ***)p);
    save=func_02017DBC(mon);
    *(int *)(p+0x90)=func_0202D934(second,mon,0,0,79);
    *(int *)(p+0xa4)=func_0202D8D0(second,mon,0,0,128,79);
    *(u32 *)(p+0xcc)=func_0202D9A4((u32)mon,0,1,0,79);
    func_02017DE4(mon,save);
    func_02049238((void *)second);
}
