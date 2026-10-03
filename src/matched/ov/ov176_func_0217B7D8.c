/*
 * function: func_0217B7D8
 * address: 0x0217B7D8
 * packet: pkt_ov176_0217B7D8
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: following 0217B924 and 0217B930 tail-call stubs already have separate matched shards; lead only.
 * lever: descriptor assignments in member order fix constant scheduling; coordinates are u8, height u32 with logical shift and no outgoing truncation.
 * abi: E88B0 height widened from its narrow body spelling because original stores the full computed register into the outgoing slot.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_021E88B0 0x021E88B0 thumb ov177
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 f00,f04,f08,option0,option1,f14,f18,count;
    u16 f20,f22,f24,f26;
    u32 f28;
    u16 f2c,f2e;
} Menu;
extern unsigned func_02012EBC(void *);
extern void *func_0200B358(void *);
extern void *func_0200B1D4(void *,int);
extern void func_02082BCC(void *,int,u32);
extern void *func_021E88B0(Menu *,u8,u8,u8,u32,int);
static inline void selected(Menu *rec,void *base,int index)
{
    char *mon;
    mon=func_0200B1D4(base,index);
    rec->option0=7;
    rec->option1=5;
    if((u8)(s8)(*(s8 *)(mon+0x15b)-1)<=1) rec->f14=13;
    else rec->f14=4;
    rec->f18=6;
    rec->count=4;
    rec->f28=1;
    rec->f2c=3;
}
void func_0217B7D8(char *p,int index)
{
    Menu rec;
    void *base;
    int layout;
    u8 x,y,width;
    u32 height;
    base=func_0200B358((void *)func_02012EBC(*(void **)(p+0x30)));
    func_02082BCC(&rec,0,48);
    rec.f00=*(u32 *)(p+0x20);
    rec.f04=*(u32 *)(p+0x1c);
    rec.f08=*(u32 *)(p+0x24);
    switch(index) {
    case 0:
        rec.option0=2;rec.option1=3;rec.f14=5;rec.f18=6;rec.count=4;rec.f28=1;rec.f2c=3;layout=0;break;
    case 1: selected(&rec,base,0);layout=0;break;
    case 2: selected(&rec,base,1);layout=0;break;
    case 3:
        rec.option0=11;rec.option1=12;rec.count=2;layout=1;rec.f28=1;rec.f2c=1;break;
    }
    rec.f20=0;rec.f22=15;rec.f24=13;rec.f26=1;
    switch(layout) {
    case 0: width=28;height=(rec.count&127)*2;x=2;y=9-(height>>1);break;
    case 1: width=12;height=(rec.count&127)*2;x=19;y=17-height;break;
    }
    *(void **)(p+4)=func_021E88B0(&rec,x,y,width,height,*(u16 *)(p+0x34));
    *(int *)(p+8)=index;
}
