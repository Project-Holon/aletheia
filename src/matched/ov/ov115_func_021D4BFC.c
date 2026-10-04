/*
 * function: func_021D4BFC
 * address: 0x021D4BFC
 * packet: pkt_ov115_021D4BFC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 0203159C leaves its allocation in r0, read here despite legacy void.
 * 021D4D38 r2 is explicitly loaded here and retained in the extern.
 * symbols:
 *   d_021D65D0 0x021D65D0 data a1
 *   func_02034714 0x02034714 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D4D38 0x021D4D38 thumb ov115
 *   func_021D5984 0x021D5984 thumb ov115
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201283C 0x0201283C thumb
 *   func_0202208C 0x0202208C thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203C968 0x0203C968 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D497C 0x021D497C thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_02005D90 0x02005D90 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021D65D0[];
extern void func_02034714(const char *,u32,const char *);
extern void func_0203064C(u32,u32,u32);
extern u8 *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,unsigned);
extern u8 *func_021D4D38(u16,u32,int);
struct Big;
struct BigObj;
extern u8 *func_021D5984(u32 heap, u32 bank, u32 mode);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern int func_0203CD98(void);
extern void func_0203CA04(void),func_0203C968(void);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_021D426C(u8 *,u32);
extern void func_021D497C(u8 *);
extern void func_021D5CCC(u8 *,u32);
extern void func_02005D90(int,int);
int func_021D4BFC(void *ctx,int unused,u8 *q)
{
    u8 *p;
    if(*(int *)(q+0xc)==0) func_02034714(d_021D65D0,0,d_021D65D0);
    func_0203064C(1,120,0x18000);
    p=func_0203159C(ctx,72,120);
    func_02082BCC(p,0,72);
    *(u16 *)(p+0xc)=120;
    *(void **)(p+0x44)=*(void **)q;
    *(void **)(p+0x34)=func_021D4D38(*(u16 *)(p+0xc),*(u32 *)(q+4),*(int *)(q+8));
    *(void **)(p+0x38)=func_021D5984(*(u16 *)(p+0xc),232,*(int *)(q+8));
    *(void **)(p+0x2c)=func_02012EBC(*(void **)q);
    *(u32 *)(p+0x3c)=func_0201283C(*(void **)q);
    func_0202208C(0,1,1,0,6,1,*(u16 *)(p+0xc));
    *(u8 **)(p+0x40)=q;
    if(func_0203CD98()) {
        func_0203CA04();
        func_0203C968();
        func_0200FBB0();
        func_0200FBA0();
    }
    func_021D426C(p,(u32)func_021D497C);
    if(*(int *)(*(u8 **)(p+0x40)+4)==0) {
        func_021D5CCC(*(u8 **)(p+0x38),35);
        if(*(int *)(*(u8 **)(p+0x40)+0x18)==0) func_02005D90(1153,65535);
    } else {
        if(*(int *)(*(u8 **)(p+0x40)+0x18)==0) func_02005D90(1155,65535);
    }
    return 1;
}
