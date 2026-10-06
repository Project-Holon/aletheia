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
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;
struct Obj;
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021E0D00(char *,int);
struct Coordinates;
extern void func_021E0D38(struct Coordinates *p, int index);
extern void func_021E0CE8(char *,int,int);
void func_021E0A88(char *p)
{
    int base,zero;
    u32 owner;
    Params params;
    base=0x25c;owner=*(u32 *)(p+base);zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    *(u32 *)(p+base-0xc8)=(u32)func_0204B294((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xc8),1);
    *(u32 *)(p+base-0xac)=(u32)func_0204B294((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0xac),1);
    *(u32 *)(p+base-0x90)=(u32)func_0204B294((void *)owner,*(u32 *)(p+base+0x18),*(u32 *)(p+base+0xc),*(u32 *)(p+base+0x30),&params,1,*(u16 *)(p+base+0xf0));
    func_0204B688(*(void **)(p+base-0x90),1);
    func_021E0D00(p,0);
    func_0204B878(*(void **)(p+base-0xc8),0);func_0204B92C(*(void **)(p+base-0xc8),1);
    *(u16 *)(p+base-0xa4)=zero;*(u16 *)(p+base-0xa2)=zero;*(u32 *)(p+base-0xb8)=1;
    func_021E0D38((struct Coordinates *)p,0);
    func_0204B878(*(void **)(p+base-0xac),*(u32 *)(p+base-0xb8));
    func_0204B92C(*(void **)(p+base-0xac),1);func_0204B688(*(void **)(p+base-0xac),1);
    *(u16 *)(p+base-0x88)=zero;*(u16 *)(p+base-0x86)=zero;*(u32 *)(p+base-0x9c)=1;
    func_021E0D38((struct Coordinates *)p,zero);
    func_0204B878(*(void **)(p+base-0x90),*(u32 *)(p+base-0x9c));
    func_0204B688(*(void **)(p+base-0x90),1);func_0204B92C(*(void **)(p+base-0x90),1);
    func_021E0CE8(p,1,zero);func_021E0CE8(p,2,zero);
}
