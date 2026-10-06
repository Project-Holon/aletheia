/*
 * function: func_021BD634
 * address: 0x021BD634
 * packet: pkt_ov091_021BD634
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: minute and second are u8 locals: widening the explicit byte casts
 *   to u32 keeps the size but moves the text spill before outgoing stores.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045808 0x02045808 arm
 *   func_021BA4F8 0x021BA4F8 thumb ov091
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_020A1B38 0x020A1B38 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct Descriptor;
struct CharBuf;
struct StrObj;
struct PrintSys;
struct Cfg;
extern s16 d_020A1B38[];
extern struct U16Vec *func_020457B0(u32,u32);
extern struct WordSet *func_0201EC64(u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *);
extern void func_021BA4F8(u8 *);
extern u32 func_0201C6C4(struct PrintSys *,void *);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
extern int func_02061CA4(void *,u32,u32,int);
#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
#define T (*(u16 *)((u8 *)P(0x280)+0x60))
void func_021BD634(u8 *p)
{
    u32 width;
    u8 minute;
    u8 second;
    void *text;
    struct U16Vec *buf;
    struct WordSet *words;
    u16 timer;
    struct Descriptor *window;
    u8 amount;
    u8 i;
    u8 red;
    u8 green;
    u8 blue;
    u16 color;
    int value;
    timer=T;
    if(p[0x20d]!=timer) {
        minute=(u8)(timer/60);
        second=(u8)(timer%60);
        buf=func_020457B0(32,H(0));
        words=func_0201EC64(H(0));
        if(minute==0) {
            text=func_02045EC0(P(0x134),175);
            func_0201EFA4(words,1,second,2,1,1);
        } else {
            text=func_02045EC0(P(0x134),174);
            func_0201EFA4(words,0,minute,2,1,1);
            func_0201EFA4(words,1,second,2,2,1);
        }
        func_02043B5C(func_02045770(P(0x200)),0);
        func_0201F250(words,buf,text);
        width=func_0201D304((struct StrObj *)buf,W(0x138),0);
        func_0201C724(P(0x140),(u32)func_02045770(P(0x200)),(s16)(36-width),4,(u32)buf,W(0x138),0x3c40);
        func_0201ED04(words);
        func_02045808(buf);
        func_02045808(text);
        W(0x208)=1;
        p[0x20d]=T;
    }
    if(T==0) func_021BA4F8(p);
    if(W(0x208)==1) {
        if(func_0201C6C4(P(0x140),func_02045770(P(0x200)))==0) {
            W(0x208)=0;
            window=P(0x200);
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if(W(0x204)==1) {
        if(func_0201C6C4(P(0x140),func_02045770(P(0x1fc)))==0) {
            W(0x204)=0;
            window=P(0x1fc);
            func_02045334(window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730(window));
        }
    }
    if(T<=10) {
        amount=(d_020A1B38[(((H(0x24e)<<16)/60)>>4)*2+1]+4096)*32/8192;
        for(i=0;i<16;i++) {
            color=*(u16 *)(p+(u32)i*2+0x20e);
            green=(color&0x3e0)>>5;
            blue=(color&0x7c00)>>10;
            red=color&31;
            value=red+amount;
            if(value>31) value=31;
            red=value;
            *(u16 *)(p+(u32)i*2+0x22e)=(blue<<10)|(red|(green<<5));
        }
        func_02061CA4((void *)31,64,(u32)(p+0x22e),32);
        H(0x24e)++;
        if(H(0x24e)>=60) H(0x24e)=0;
    }
}
