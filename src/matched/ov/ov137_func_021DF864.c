/*
 * function: func_021DF864
 * address: 0x021DF864
 * packet: pkt_ov137_021DF864
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02048B6C has no witness; owner unit src/matched/arm9/unit_02048AD0.c
 * omits func_02048B6C from function: and its shard. tu --suggest-split leaves caller OUT.
 * blocker: 02048B6C verified EXACT with fixed flags in scratch/blocker48b6c.c:
 * typedef unsigned int u32;
 * void func_02048B6C(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 * symbols:
 *   func_02048B6C 0x02048B6C arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   NNS_G3dGlbLightVector 0x0206AA3C arm
 *   NNS_G3dGlbLightColor 0x0206AA78 arm
 *   func_0206AA8C 0x0206AA8C arm
 *   func_0206AAB0 0x0206AAB0 arm
 *   func_021E0698 0x021E0698 thumb ov137
 *   func_021E05D4 0x021E05D4 thumb ov137
 *   func_021E0848 0x021E0848 thumb ov137
 *   func_02047970 0x02047970 arm
 *   func_0204A600 0x0204A600 arm
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   TIME_ICON_Update 0x0202F0B0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Light;
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void),func_020479D8(void),func_02047970(void),func_0204A600(void);
extern void NNS_G3dGlbLightVector(int,int,int,int),NNS_G3dGlbLightColor(int,u32),func_0206AA8C(u32,u32,u32),func_0206AAB0(u32,u32,u32);
extern void func_021E0698(u8 *),func_021E05D4(u8 *),func_021E0848(u8 *);
struct Descriptor;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
extern void TIME_ICON_Update(u8 *p);
void func_021DF864(u8 *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    func_02048B6C(*(void **)(p+0xd54),&flags);
    func_02047964();
    func_02048AD0(*(void **)(p+0xd54));
    func_020479D8();
    NNS_G3dGlbLightVector(0,0,-4096,0);
    NNS_G3dGlbLightColor(0,0x7fff);
    func_0206AA8C(0x7fff,0x7fff,0);
    func_0206AAB0(0x7fff,0x7fff,0);
    func_021E0698(p);func_021E05D4(p);func_021E0848(p);
    func_02047970();func_0204A600();
    func_0201C4E4(*(void **)(p+0xd38));
    r=*(void **)(p+0xd38);
    if(*(u8 *)(p+0xd0c)) {
        if(!func_0201C6C4(r,func_02045770(*(void **)(p+0xd08)))) {
            func_02045334(*(void **)(p+0xd08));
            *(u8 *)(p+0xd0c)=0;
        }
    }
    for(i=0;i<5;i++) {
        r=*(void **)(p+0xd38);
        if(*(u8 *)(p+i*8+0xd14)) {
            if(!func_0201C6C4(r,func_02045770(*(void **)(p+i*8+0xd10)))) {
                func_02045334(*(void **)(p+i*8+0xd10));
                *(u8 *)(p+i*8+0xd14)=0;
            }
        }
    }
    if(*(void **)(p+0xda8)) TIME_ICON_Update(*(void **)(p+0xda8));
}
