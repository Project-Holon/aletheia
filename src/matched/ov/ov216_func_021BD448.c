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
#include "../include/Obj00051.h"
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
extern void func_021BCED0(u8 *p, u32 n);
extern u16 func_02165D28(const struct Bits *);
extern unsigned short func_02165D34(const struct Bits *p);
extern int func_021BBB48(int,int);
extern u16 func_021BBB3C(char *,int,int);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_021BCE8C(void *,s16,s16,int);
extern void func_021BCE7C(void *p, unsigned short value);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_021BCEA4(u8 *p, u8 n);
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
    func_02165AC4(*(struct Queue * *)&((struct Obj00051 *)p)->f24,*(struct Rec * *)&((struct Obj00051 *)p)->f28,(u16 *)(p+44),*(u8 *)((u32)p+((struct Obj00051 *)p)->f30+49));
    type=func_021BCDDC(func_02165DAC(*(const char * *)&((struct Obj00051 *)p)->f28));
    func_021BCED0((u8 *)p,func_02165CE8(*(struct S * *)&((struct Obj00051 *)p)->f28));
    value=func_02165D28(*(struct Bits * *)&((struct Obj00051 *)p)->f28);
    index=func_021BBB48(*(int *)&((struct Obj00051 *)p)->f1C,func_02165D34((const struct Bits *)(*(const char * *)&((struct Obj00051 *)p)->f28)));
    if(index==0xffff || func_021BBB3C(*(char * *)&((struct Obj00051 *)p)->f1C,index,16)!=0xffff || value>=427) {
        ((struct Obj00051 *)p)->f260=0;
        *(volatile s16 *)&((struct Obj00051 *)p)->f25E=0;
        ((struct Obj00051 *)p)->f25C=*(volatile s16 *)&((struct Obj00051 *)p)->f25E;
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f264,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f268,0);
    } else {
        ((struct Obj00051 *)p)->f260=1;
        ((struct Obj00051 *)p)->f25C=func_021BBB3C(*(char * *)&((struct Obj00051 *)p)->f1C,index,2);
        ((struct Obj00051 *)p)->f25E=func_021BBB3C(*(char * *)&((struct Obj00051 *)p)->f1C,index,3)-16;
        if(((struct Obj00051 *)p)->f25E<32) ((struct Obj00051 *)p)->f25E=32;
        else if(((struct Obj00051 *)p)->f25E>152) ((struct Obj00051 *)p)->f25E=152;
        if(((struct Obj00051 *)p)->f25C<16) ((struct Obj00051 *)p)->f25C=16;
        else if(((struct Obj00051 *)p)->f25C>240) ((struct Obj00051 *)p)->f25C=240;
        func_021BCE8C(((struct Obj00051 *)p)->f264,((struct Obj00051 *)p)->f25C,((struct Obj00051 *)p)->f25E,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f264,1);
        if(type[2]!=0) {
            func_021BCE8C(((struct Obj00051 *)p)->f268,((struct Obj00051 *)p)->f25C-24,((struct Obj00051 *)p)->f25E,0);
            func_021BCE7C(((struct Obj00051 *)p)->f268,(u8)(type[2]-1));
        }
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f268,type[2]!=0);
    }
    func_02043B5C(*(struct CharBuf * *)&((struct Obj00051 *)p)->f14C,15);
    high=(u8)(((struct Obj00051 *)p)->f2C>>8);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,high,2,0,1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,(u8)((struct Obj00051 *)p)->f2C,2,2,1);
    func_021BCEA4((u8 *)p,(high/12)+13);
    func_021BDA54(p,p+0x148,0,0,*(u32 *)&((struct Obj00051 *)p)->f140,0x1d0f);
    func_021BCE04(((struct Obj00051 *)p)->f28,((struct Obj00051 *)p)->f138);
    func_021BCEA4((u8 *)p,type[1]);
    func_021BDA54(p,p+0x148,0,16,*(u32 *)&((struct Obj00051 *)p)->f140,0x1d0f);
    d=*(struct Descriptor * *)&((struct Obj00051 *)p)->f148;
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_020409B4(func_02045730(d));
}
