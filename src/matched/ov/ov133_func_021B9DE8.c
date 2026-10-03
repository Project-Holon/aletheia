/*
 * function: func_021B9DE8
 * address: 0x021B9DE8
 * packet: pkt_ov133_021B9DE8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: B294 leaves the forwarded result live in r0; request address is the unchanged fifth word.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B688 0x0204B688 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {s16 x,y,index;u8 a,b;} Params;
extern void *func_0204B294(u32,u32,u32,u32,u32,u16,u16);
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021B9DE8(u8 *p)
{
    Params configs[2];
    int a,b,c,d,e,f,g,h;
    u8 i;
    i=0;
    a=0x1848;a=0x1860;
    b=0x1848;b=0x186c;
    c=0x1848;c=0x1878;
    d=0x1848;d=0x1890;
    e=0x1848;e=0x1890;
    f=0x1848;f=0x1890;
    g=0x1848;g=0x1890;
    h=0x1848;h=0x18b8;
    do {
        configs[1].x=0;configs[1].y=0;configs[1].index=0;configs[1].a=0;configs[1].b=0;
        *(void **)(p+(unsigned)i*4+d)=func_0204B294(*(u32 *)(p+0x1848),*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),(u32)&configs[1],1,*(u16 *)p);
        func_0204B3DC(*(void **)(p+(unsigned)i*4+e),1);
        func_0204B92C(*(void **)(p+(unsigned)i*4+f),1);
        func_0204B688(*(void **)(p+(unsigned)i*4+g),0);
        p[(unsigned)i+h]=0;
        ++i;
    } while(i<8);
    configs[0].x=128;configs[0].y=96;configs[0].index=0;configs[0].a=0;configs[0].b=0;
    *(void **)(p+0x18b0)=func_0204B294(*(u32 *)(p+0x1848),*(u32 *)(p+0x185c),*(u32 *)(p+0x1868),*(u32 *)(p+0x1874),(u32)&configs[0],0,*(u16 *)p);
    func_0204B3DC(*(void **)(p+0x18b0),0);
    func_0204B92C(*(void **)(p+0x18b0),1);
    configs[0].index=2;
    *(void **)(p+0x18b4)=func_0204B294(*(u32 *)(p+0x1848),*(u32 *)(p+0x185c),*(u32 *)(p+0x1868),*(u32 *)(p+0x1874),(u32)&configs[0],0,*(u16 *)p);
    func_0204B3DC(*(void **)(p+0x18b4),0);
    func_0204B92C(*(void **)(p+0x18b4),1);
}
