/*
 * function: func_021F1930
 * address: 0x021F1930
 * packet: pkt_ov107_021F1930
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {void *f00;u16 f04;u32 f08;} Entry;
typedef struct {u32 f00;u8 f04;Entry *f08;u32 f0C;u8 f10,f11,f12,f13;} Config;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02027778(Config *,void *);
extern void func_02045808(struct U16Vec *vec);
void func_021F1930(char *p,int kind)
{
    Entry entries[2];
    Config config;
    entries[0].f00=func_02045EC0(*(void **)(p+0x1C),18);
    entries[1].f00=func_02045EC0(*(void **)(p+0x1C),19);
    entries[0].f04=0x39E3;entries[1].f04=0x39E3;
    entries[0].f08=0;entries[1].f08=0;
    config.f00=*(u16 *)p;config.f04=2;config.f08=entries;config.f0C=0;
    switch(kind){
    case 0:config.f10=24;config.f11=6;break;
    case 1:config.f10=24;config.f11=12;break;
    case 2:config.f10=24;config.f11=18;break;
    }
    config.f12=8;config.f13=3;
    *(void **)(p+0x3C)=func_02027778(&config,*(void **)(p+0x40));
    func_02045808(entries[0].f00);func_02045808(entries[1].f00);
}
