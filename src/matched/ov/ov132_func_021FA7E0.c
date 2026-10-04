/*
 * function: func_021FA7E0
 * address: 0x021FA7E0
 * packet: pkt_ov132_021FA7E0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 021FA99A zero halfword is alignment padding before labelled 021FA99C.
 * ABI: B294 forwards an address-valued u32 payload and returns the actor in r0; ABF0 tail-forwards AC18's index despite void declaration.
 * symbols:
 *   func_021F9E0C 0x021F9E0C thumb ov132
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021FA99C 0x021FA99C thumb ov132
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {s16 x,y,index;u8 a,b;} Params;
extern u8 *func_021F9E0C(char *),*func_021F4F54(u8 *,int);
extern int func_021F4F70(int *);
extern void *func_0204B100(int,u8,u32),*func_020490F4(u32,u16);
struct Obj;
extern void func_0204B270(void *),func_02049238(void *),func_0204B3DC(void *,u32),func_0204B92C(struct Obj *,u32);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16),func_0204A6C8(void *,u32,u32,u32,u16),func_0204AF28(void *,u32,u32,u32),func_0204ABF0(void *,u32,u32,u32,u16);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_021FA99C(u8 *,unsigned,int,int);
void func_021FA7E0(char *p)
{
    Params configs[2];
    u8 *table;
    void *narc;
    u8 i=0;
    int format;
    table=func_021F9E0C(*(char **)(p+4));
    *(void **)(p+0x18)=func_0204B100(5,0,*(u16 *)p);
    func_0204B270(*(void **)(p+0x18));
    narc=func_020490F4(47,*(u16 *)p);
    *(int *)(p+0x1c)=func_0204AC18(narc,0,1,0,0,2,*(u16 *)p);
    *(int *)(p+0x28)=func_0204A6C8(narc,6,0,1,*(u16 *)p);
    *(int *)(p+0x34)=func_0204AF28(narc,18,21,*(u16 *)p);
    *(int *)(p+0x20)=func_0204AC18(narc,1,1,64,0,1,*(u16 *)p);
    *(int *)(p+0x2c)=func_0204A6C8(narc,7,0,1,*(u16 *)p);
    *(int *)(p+0x38)=func_0204AF28(narc,19,22,*(u16 *)p);
    func_02049238(narc);
    narc=func_020490F4(46,*(u16 *)p);
    *(int *)(p+0x24)=func_0204ABF0(narc,0,1,96,*(u16 *)p);
    *(int *)(p+0x30)=func_0204A6C8(narc,26,0,1,*(u16 *)p);
    *(int *)(p+0x3c)=func_0204AF28(narc,18,22,*(u16 *)p);
    func_02049238(narc);
    for(i=0;i<2;i++) {
        if(*(u16 *)(p+i*2+0x48)!=255) {
            format=func_021F4F70((int *)func_021F4F54(table,*(u16 *)(p+i*2+0x48)));
            if(i==0) configs[1].x=32;
            else configs[1].x=224;
            configs[1].y=160;
            configs[1].index=i;
            configs[1].a=10;
            configs[1].b=0;
            *(void **)(p+i*4+0x4c)=func_0204B294((void *)*(u32 *)(p+0x18),*(u32 *)(p+0x28),*(u32 *)(p+0x1c),*(u32 *)(p+0x34),&configs[1],1,*(u16 *)p);
            configs[1].index=0;
            *(void **)(p+i*4+0x54)=func_0204B294((void *)*(u32 *)(p+0x18),*(u32 *)(p+0x2c),*(u32 *)(p+0x20),*(u32 *)(p+0x38),&configs[1],1,*(u16 *)p);
            func_0204B3DC(*(void **)(p+i*4+0x4c),0);
            func_0204B3DC(*(void **)(p+i*4+0x54),0);
            func_021FA99C((u8 *)p,i,*(u16 *)(p+i*2+0x48),format);
        }
    }
    configs[0].x=128; configs[0].y=96; configs[0].index=0;configs[0].a=0;configs[0].b=0;
    *(void **)(p+0x5c)=func_0204B294((void *)*(u32 *)(p+0x18),*(u32 *)(p+0x30),*(u32 *)(p+0x24),*(u32 *)(p+0x3c),&configs[0],1,*(u16 *)p);
    func_0204B3DC(*(void **)(p+0x5c),0);
    func_0204B92C(*(void **)(p+0x5c),1);
}
