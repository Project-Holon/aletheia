/*
 * function: func_021E0A88
 * address: 0x021E0A88
 * packet: pkt_ov183_021E0A88
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: 0204B294 r0 consumed after call; pointer request passed as the unchanged u32 fifth payload.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021E0D00 0x021E0D00 thumb ov183
 *   func_021E0D38 0x021E0D38 thumb ov183
 *   func_021E0CE8 0x021E0CE8 thumb ov183
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u16 a,b,c;u8 flag,pad;} Params;
extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);
extern void func_0204B688(void *,u32);
extern void func_0204B878(void *,u16);
extern void func_0204B92C(void *,u32);
extern void func_021E0D00(char *,int);
extern void func_021E0D38(void *,int);
extern int func_021E0CE8(char *,int,int);
void func_021E0A88(char *p)
{
    int base,zero;
    u32 owner;
    Params params;
    base=0x25c;owner=*(u32 *)(p+base);zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    *(u32 *)(p+base-0xc8)=func_0204B294(owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),(u32)&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xc8),1);
    *(u32 *)(p+base-0xac)=func_0204B294(owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),(u32)&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xac),1);
    *(u32 *)(p+base-0x90)=func_0204B294(owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),(u32)&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0x90),1);
    func_021E0D00(p,0);
    func_0204B878(*(void **)(p+base-0xc8),0);func_0204B92C(*(void **)(p+base-0xc8),1);
    *(u16 *)(p+base-0xa4)=zero;*(u16 *)(p+base-0xa2)=zero;*(u32 *)(p+base-0xb8)=1;
    func_021E0D38(p,0);
    func_0204B878(*(void **)(p+base-0xac),*(u32 *)(p+base-0xb8));
    func_0204B92C(*(void **)(p+base-0xac),1);func_0204B688(*(void **)(p+base-0xac),1);
    *(u16 *)(p+base-0x88)=zero;*(u16 *)(p+base-0x86)=zero;*(u32 *)(p+base-0x9c)=1;
    func_021E0D38(p,zero);
    func_0204B878(*(void **)(p+base-0x90),*(u32 *)(p+base-0x9c));
    func_0204B688(*(void **)(p+base-0x90),1);func_0204B92C(*(void **)(p+base-0x90),1);
    func_021E0CE8(p,1,zero);func_021E0CE8(p,2,zero);
}
