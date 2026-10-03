/*
 * function: func_021BC454
 * address: 0x021BC454
 * packet: pkt_ov216_021BC454
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: two Config locals preserve separate frame objects; p+i*8+144
 * retains per-iteration base addition, and q=p+i*12 holds the row base.
 * Prototype: 0202DA04's complete legacy body consumes only input0;
 * 0202DA48/0202DA18 leave returned r0 live and this caller stores it.
 * symbols:
 *   configA 0x021BDB28 data a2
 *   configB 0x021BDB34 data a2
 *   func_0202DA04 0x0202DA04 thumb
 *   func_021BC3E4 0x021BC3E4 thumb ov216
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02062A98 0x02062A98 arm
 *   func_02062A00 0x02062A00 arm
 *   func_02049238 0x02049238 arm
 *   func_0202DA48 0x0202DA48 thumb
 *   func_0202DA18 0x0202DA18 thumb
 *   func_0202DA6C 0x0202DA6C thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {unsigned char a,b,c,pad;u16 first,second,third;} Config;
struct ArcFile;struct NitroFileHeader;
extern const Config configA,configB;
extern u32 func_0202DA04(int);
extern void func_021BC3E4(u16 *,int *,const Config *,u32);
extern void *func_020490F4(u32 id, u16 heap);
extern void *func_02049250(struct ArcFile *,u32,u32);
extern int func_02062A98(struct NitroFileHeader *,void **);
extern int func_02062A00(struct NitroFileHeader *,void **);
extern void func_02049238(void *);
extern u32 func_0202DA48(u32,u32,u32,u32);
extern u32 func_0202DA18(u32,u32,u32,u16,u16);
extern int func_0202DA6C(int,int,int,int);
void func_021BC454(char *p,u32 handle)
{
    Config a,b;
    struct ArcFile *arc;
    int i;
    *(u32 *)(p+88)=func_0202DA04(*(u16 *)p);
    a=configA;
    func_021BC3E4((u16 *)p,(int *)(p+92),&a,handle);
    b=configB;
    arc=func_020490F4(32,*(u16 *)(p+2));
    func_021BC3E4((u16 *)p,(int *)(p+128),&b,(u32)arc);
    *(void **)(p+276)=func_02049250(arc,0,*(u16 *)p);
    func_02062A98(*(struct NitroFileHeader **)(p+276),(void **)(p+268));
    *(void **)(p+272)=*(void **)(*(char **)(p+268)+12);
    for(i=0;i<16;i++){
        *(void **)(p+i*8+144)=func_02049250(arc,i+49,*(u16 *)p);
        func_02062A00(*(struct NitroFileHeader **)(p+i*8+144),(void **)(p+140+i*8));
    }
    func_02049238(arc);
    for(i=0;i<2;i++){
        char *q=p+i*12;
        *(u32 *)(q+108)=func_0202DA48(*(u32 *)(p+88),i+2,1,*(u16 *)p);
        *(u32 *)(q+104)=func_0202DA18(*(u32 *)(p+88),i+2,1,(i+8)<<5,*(u16 *)p);
        *(int *)(q+112)=func_0202DA6C(i+2,0,1,*(u16 *)p);
    }
}
