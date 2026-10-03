/*
 * function: func_021BD448
 * address: 0x021BD448
 * packet: pkt_ov216_021BD448
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: CE8C signed halfword coordinates match original ldrsh/asr; CE7C and CEA4 u8 arguments match original explicit #24 truncations despite wider own entry types.
 * volatile: original 021BD4C0 reloads just-stored p+0x25e before copying into p+0x25c.
 * symbols:
 *   func_02165AC4 0x02165AC4 thumb ov010
 *   func_02165DAC 0x02165DAC thumb ov010
 *   func_021BCDDC 0x021BCDDC thumb ov216
 *   func_02165CE8 0x02165CE8 thumb ov010
 *   func_021BCED0 0x021BCED0 thumb ov216
 *   func_02165D28 0x02165D28 thumb ov010
 *   func_02165D34 0x02165D34 thumb ov010
 *   func_021BBB48 0x021BBB48 thumb ov072
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BCE8C 0x021BCE8C thumb ov216
 *   func_021BCE7C 0x021BCE7C thumb ov216
 *   func_02043B5C 0x02043B5C arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021BCEA4 0x021BCEA4 thumb ov216
 *   func_021BDA54 0x021BDA54 thumb ov216
 *   func_021BCE04 0x021BCE04 thumb ov216
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Queue;
struct Rec;
struct Bits;
struct S;
struct Obj;
struct CharBuf;
struct WordSet;
struct Descriptor;
struct Cfg;
extern int func_02165AC4(struct Queue *,struct Rec *,u16 *,int);
extern unsigned func_02165DAC(const char *);
extern const u8 *func_021BCDDC(u32);
extern u8 func_02165CE8(struct S *);
extern void func_021BCED0(char *,u32);
extern u16 func_02165D28(const struct Bits *);
extern u16 func_02165D34(const char *);
extern int func_021BBB48(int,int);
extern u16 func_021BBB3C(char *,int,int);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_021BCE8C(void *,s16,s16,int);
extern void func_021BCE7C(void *,u8);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_021BCEA4(char *,u8);
extern void func_021BDA54(char *,char *,u32,u16,u32,u16);
extern void func_021BCE04(void *,void *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_020409B4(u32);
void func_021BD448(char *p)
{
    const u8 *type;
    u32 value;
    int index,high;
    struct Descriptor *d;
    func_02165AC4(*(struct Queue **)(p+36),*(struct Rec **)(p+40),(u16 *)(p+44),*(u8 *)((u32)p+*(u8 *)(p+48)+49));
    type=func_021BCDDC(func_02165DAC(*(const char **)(p+40)));
    func_021BCED0(p,func_02165CE8(*(struct S **)(p+40)));
    value=func_02165D28(*(struct Bits **)(p+40));
    index=func_021BBB48(*(int *)(p+28),func_02165D34(*(const char **)(p+40)));
    if(index==0xffff || func_021BBB3C(*(char **)(p+28),index,16)!=0xffff || value>=427) {
        *(u8 *)(p+0x260)=0;
        *(volatile s16 *)(p+0x25e)=0;
        *(s16 *)(p+0x25c)=*(volatile s16 *)(p+0x25e);
        func_0204B3DC(*(struct Obj **)(p+0x264),0);
        func_0204B3DC(*(struct Obj **)(p+0x268),0);
    } else {
        *(u8 *)(p+0x260)=1;
        *(s16 *)(p+0x25c)=func_021BBB3C(*(char **)(p+28),index,2);
        *(s16 *)(p+0x25e)=func_021BBB3C(*(char **)(p+28),index,3)-16;
        if(*(s16 *)(p+0x25e)<32) *(s16 *)(p+0x25e)=32;
        else if(*(s16 *)(p+0x25e)>152) *(s16 *)(p+0x25e)=152;
        if(*(s16 *)(p+0x25c)<16) *(s16 *)(p+0x25c)=16;
        else if(*(s16 *)(p+0x25c)>240) *(s16 *)(p+0x25c)=240;
        func_021BCE8C(*(void **)(p+0x264),*(s16 *)(p+0x25c),*(s16 *)(p+0x25e),0);
        func_0204B3DC(*(struct Obj **)(p+0x264),1);
        if(type[2]!=0) {
            func_021BCE8C(*(void **)(p+0x268),*(s16 *)(p+0x25c)-24,*(s16 *)(p+0x25e),0);
            func_021BCE7C(*(void **)(p+0x268),type[2]-1);
        }
        func_0204B3DC(*(struct Obj **)(p+0x268),type[2]!=0);
    }
    func_02043B5C(*(struct CharBuf **)(p+0x14c),15);
    high=(u8)(*(u16 *)(p+44)>>8);
    func_0201EFA4(*(struct WordSet **)(p+0x138),0,high,2,0,1);
    func_0201EFA4(*(struct WordSet **)(p+0x138),1,(u8)*(u16 *)(p+44),2,2,1);
    func_021BCEA4(p,(high/12)+13);
    func_021BDA54(p,p+0x148,0,0,*(u32 *)(p+0x140),0x1d0f);
    func_021BCE04(*(void **)(p+40),*(void **)(p+0x138));
    func_021BCEA4(p,type[1]);
    func_021BDA54(p,p+0x148,0,16,*(u32 *)(p+0x140),0x1d0f);
    d=*(struct Descriptor **)(p+0x148);
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_020409B4(func_02045730(d));
}
