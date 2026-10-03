/*
 * function: func_021D8358
 * address: 0x021D8358
 * packet: pkt_ov120_021D8358
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02027778(TextConfig *,void *);
extern void func_02045808(struct U16Vec *vec);
void *func_021D8358(char *p,int n)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=*(u16 *)(p+0xc8);
    config.count=2;
    config.entries=p+0xa8;
    switch(n) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=func_020457B0(100,*(u16 *)(p+0xc8));
    *(void **)(p+0xa8)=text;
    func_02045CAC(*(void **)(p+0xc),27,text);
    *(u16 *)(p+0xac)=0x39e0;
    *(int *)(p+0xb0)=0;
    text=func_020457B0(100,*(u16 *)(p+0xc8));
    *(void **)(p+0xb4)=text;
    func_02045CAC(*(void **)(p+0xc),33,text);
    *(u16 *)(p+0xb8)=0x39e0;
    *(int *)(p+0xbc)=0;
    result=func_02027778(&config,*(void **)(p+0xc0));
    func_02045808(*(void **)(p+0xa8));
    func_02045808(*(void **)(p+0xb4));
    return result;
}
