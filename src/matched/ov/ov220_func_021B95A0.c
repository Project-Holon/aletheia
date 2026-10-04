/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov220_021B95A0
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02043588 has no resolved witness; Ilias unit src/matched/arm9/unit_02043570.c contains its body but omits func_02043588 from its function value. No ARM9 source/shard filed. Standalone scratch one fixed flags ARM EXACT (16 bytes, 2/2): extern void func_02043558(void),func_02043570(void); void func_02043588(void) { func_02043558();func_02043570(); }
 * checks: 1 owner files/readers retained; 2 ov220 neighbours read, no resource twin; 3 u16 variant unchanged47; nonconst resources47->MATCH; 4 enum/hardware/const-record/table-field idioms read; 5 directory/neighbours reread. TU --suggest-split MATCH, no viable piece, sole ARM9 blocker retained.
 * lever: enum counter with unsigned do-while retains the original single-iteration BG loop; nonconst Resources extern keeps outgoing stack stores before the three resource loads (const gave47 concrete bytes).
 * volatile: 021B965C BLDCNT write; 021B9660/966A hardware DISPCNT reads.
 * prototype: 0203159C's allocator return remains live in r0 and is used as the new buffer despite its void owner declaration; 020414AC asm passes r0 twice, original caller truncates layer/type IDs to u8.
 * symbols:
 * func_0203064C 0x0203064C arm
 * func_0203159C 0x0203159C arm
 * func_02082BCC 0x02082BCC arm
 * func_021BA0D8 0x021BA0D8 thumb ov220
 * func_0201D7EC 0x0201D7EC thumb
 * func_0201C440 0x0201C440 thumb
 * func_0204047C 0x0204047C arm
 * func_020056A0 0x020056A0 thumb
 * func_021B995C 0x021B995C thumb ov220
 * func_021BA068 0x021BA068 thumb ov220
 * func_021B9960 0x021B9960 thumb ov220
 * func_021B99DC 0x021B99DC thumb ov220
 * func_021B9B64 0x021B9B64 thumb ov220
 * func_021B9CBC 0x021B9CBC thumb ov220
 * func_02043588 0x02043588 arm
 * func_0207D518 0x0207D518 arm
 * func_02043558 0x02043558 arm
 * func_0203FCA0 0x0203FCA0 arm
 * func_020414AC 0x020414AC arm
 * func_02040588 0x02040588 arm
 * func_02043598 0x02043598 arm
 * func_020490F4 0x020490F4 arm
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02049238 0x02049238 arm
 * func_020409B4 0x020409B4 arm
 * func_0204E720 0x0204E720 arm
 * func_0203D34C 0x0203D34C arm
 * func_02005E30 0x02005E30 thumb
 * bgtable 0x021BA370 data a4
 * resources 0x021BA4E0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { LOOP_ZERO=0 } Loop;
struct BgTemplate;
struct Row {u32 id;u8 body[32];u32 kind,on;};
struct Resources {u32 a,b,c;};
extern const struct Row bgtable[];
extern struct Resources resources[];
extern void func_0203064C(void*,u32,u32);
extern char *func_0203159C(void*,u32,u32);
extern void func_02082BCC(void*,u32,u32);
extern void *func_021BA0D8(u32,u32),*func_0201D7EC(int,int,int,int,u32);
extern u32 func_0201C440(void*);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,u32,u32);
extern void func_021B995C(void);
extern u8 func_021BA068(u32);
extern void func_021B9960(u16*),func_021B99DC(char*),func_021B9B64(char*),func_021B9CBC(char*);
extern void func_02043588(void),func_02043558(void),func_0207D518(int);
extern void func_0203FCA0(u8,const struct BgTemplate*,u8),func_020414AC(u8),func_02040588(u8,u8);
extern void func_02043598(u32,u32),func_020409B4(u32),func_0203D34C(u32,u32),func_02005E30(u32);
extern void *func_020490F4(u32,u16);
extern void func_02049B68(void*,u32,u32,u32,u32,u16),func_02049658(void*,u32,u32,u32,u32,u32,u16),func_020498F4(void*,u32,u32,u32,u32,u32,u16),func_02049238(void*),func_0204E720(u32,int,int,int);
int func_021B95A0(void *host,void *unused,void *args)
{
    char *p;
    char *desc;
    Loop i;
    u16 variant;
    void *owner;
    u16 heap;
    func_0203064C((void *)1,131,0x50000);
    p=func_0203159C(host,0xB4,131);
    func_02082BCC(p,0,0xB4);
    *(u16 *)p=131;
    *(void **)(p+4)=args;
    *(void **)(p+8)=func_021BA0D8(1,*(u16 *)p);
    *(void **)(p+0xC)=func_0201D7EC(23,0,0,0,*(u16 *)p);
    *(u32 *)(p+0x10)=func_0201C440((void *)(u32)*(u16 *)p);
    func_0204047C(1,2);func_0204047C(2,1);func_0204047C(3,0);
    *(void **)(p+0x14)=func_020056A0((u32)func_021B995C,(u32)p,1);
    if (*(u32 *)(*(char **)(p+4)+8)) desc=*(char **)(*(char **)(p+4)+4)+0x14;
    else desc=*(char **)(*(char **)(p+4)+4);
    if (!*(u8 *)desc) *(u32 *)(p+0xB0)=7;
    else *(u32 *)(p+0xB0)=func_021BA068(*(u16 *)(desc+2));
    func_021B9960((u16*)p);func_021B99DC(p);func_021B9B64(p);func_021B9CBC(p);
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 |= 0x10000;
    func_02043588();func_0207D518(0);func_02043558();
    i=0;
    do {
        const struct Row *r=(const struct Row *)((u32)bgtable+i*44);
        u32 layer=r->id;
        func_0203FCA0(layer,(const struct BgTemplate*)r->body,r->kind);
        func_020414AC(layer);func_02040588(layer,r->on);
    } while ((u32)++i<1);
    func_02043598(16,1);
    heap=*(u16 *)p;
    variant=1;
    if (*(u8 *)*(char **)(p+4)!=1) variant=0;
    owner=func_020490F4(30,heap);
    func_02049B68(owner,resources[variant].a,4,0,0,heap);
    func_02049658(owner,resources[variant].b,4,0,0,0,heap);
    func_020498F4(owner,resources[variant].c,4,0,0,0,heap);
    func_02049238(owner);func_020409B4(4);func_0204E720(3,16,16,0);func_0203D34C(0,*(u16 *)p);
    if (*(u32 *)(*(char **)(p+4)+0xC) && *(u32 *)(p+0xB0)!=7) func_02005E30(6);
    return 1;
}
