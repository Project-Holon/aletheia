/*
 * function: func_021B79F4
 * address: 0x021B79F4
 * packet: pkt_ov180_021B79F4
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_02025774 0x02025774 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02008534 0x02008534 thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021B77DC 0x021B77DC thumb ov180
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
struct Bmp; struct Sys; struct Grid; struct CharBuf; struct MsgBank; struct StrObj;
struct WordSet; struct Player; struct PlayTime;
typedef struct { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; } Param;
typedef struct { struct Grid *grid; struct Bmp *bmp; } Holder;
extern struct Bmp *func_02043678(u32,u32,u32,u32);
extern struct Grid *func_020255A0(struct Sys *,const Param *);
extern void func_02025774(u8 *,u32);
extern void func_02043B5C(struct CharBuf *,u8);
extern struct StrObj *func_02045EC0(struct MsgBank *,u32);
extern void func_02045808(struct StrObj *);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u16 func_02008534(const struct Player *),func_0200864C(const struct PlayTime *);
extern u8 func_02008650(const struct PlayTime *);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_021B77DC(char *,int,void *,struct StrObj *,int,int);
void func_021B79F4(char *p) {
    Param d;
    Holder *h;
    struct StrObj *str;
    u32 width;
    d.f8=*(u32 *)(p+0x90f0); d.fc=0; d.f10=4; d.f11=0; d.f12=0xffff;
    h=(Holder *)(p+0x9130); d.f14=0;
    h->bmp=func_02043678(32,2,32,141);
    d.bmp=h->bmp; d.x=0; d.y=16;
    *(struct Grid **)(p+0x9130)=func_020255A0(*(struct Sys **)(p+0x911c),&d);
    func_02025774(*(u8 **)(p+0x9130),0);
    func_02043B5C(*(struct CharBuf **)(p+0x9134),0);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),4);
    width=func_0201D304(str,*(u32 *)(p+0x9030),0);
    func_021B77DC(p,2,*(void **)(p+0x9030),str,(256-width)/2,0);
    func_02045808(str);
    h=(Holder *)(p+0x9138);
    h->bmp=func_02043678(32,2,32,141);
    d.bmp=h->bmp; d.x=0; d.y=160;
    *(struct Grid **)(p+0x9138)=func_020255A0(*(struct Sys **)(p+0x911c),&d);
    func_02025774(*(u8 **)(p+0x9138),0);
    func_02043B5C(*(struct CharBuf **)(p+0x913c),0);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),5);
    func_0201F02C(*(struct WordSet **)(p+0x903c),0,*(void **)(*(char **)p+4));
    func_0201F250(*(struct WordSet **)(p+0x903c),*(void **)(p+0x9040),str);
    func_021B77DC(p,3,*(void **)(p+0x9030),*(struct StrObj **)(p+0x9040),8,0);
    func_02045808(str);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),6);
    func_0201EFA4(*(struct WordSet **)(p+0x903c),0,func_02008534(*(struct Player **)(*(char **)p+4)),5,2,1);
    func_0201F250(*(struct WordSet **)(p+0x903c),*(void **)(p+0x9040),str);
    func_021B77DC(p,3,*(void **)(p+0x9030),*(struct StrObj **)(p+0x9040),92,0);
    func_02045808(str);
    str=func_02045EC0(*(struct MsgBank **)(p+0x9038),7);
    func_0201EFA4(*(struct WordSet **)(p+0x903c),0,func_0200864C(*(struct PlayTime **)(*(char **)p+8)),3,0,1);
    func_0201EFA4(*(struct WordSet **)(p+0x903c),1,func_02008650(*(struct PlayTime **)(*(char **)p+8)),2,2,1);
    func_0201F250(*(struct WordSet **)(p+0x903c),*(void **)(p+0x9040),str);
    func_021B77DC(p,3,*(void **)(p+0x9030),*(struct StrObj **)(p+0x9040),200,0);
    func_02045808(str);
}
