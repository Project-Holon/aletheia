/*
 * file:     un_select_graphic.c
 * unit:     yes
 * function: func_021BA848, func_021BA8F0, func_021BA94C, func_021BA960, func_021BA96C, func_021BA980, func_021BA9E0, func_021BAA18, func_021BAA1C, func_021BAA24, func_021BAA64, func_021BAA80, func_021BAA88, func_021BAA94
 * address:  0x021BA848
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021BB094 0x021BB094 data a1
 *   d_021BAEF8 0x021BAEF8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BAB00 0x021BAB00 thumb ov218
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BAEAC 0x021BAEAC data a4
 *   d_021BAF28 0x021BAF28 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_021BA7A4 0x021BA7A4 thumb ov218
 *   d_021BAE94 0x021BAE94 data a4
 *   d_021BAE88 0x021BAE88 data a4
 *   d_021BAEA0 0x021BAEA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 */
#include "../../matched/include/Obj26049.h"
#include "../../matched/include/Obj26050.h"
#include "../../matched/include/Obj14774.h"
#include "../../matched/include/Obj26051.h"

struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef struct Record { unsigned bg; unsigned config[8]; unsigned type, enable; } Record;

typedef struct Vec3 { unsigned x, y, z; } Vec3;

extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, int, int);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_021BAB00(int *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u8);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021BA7A4(void);
extern void func_02046440(unsigned, unsigned, unsigned, unsigned, unsigned short, unsigned, void (*)(void));
extern unsigned *func_02048A24(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const Vec3 *, const Vec3 *, const Vec3 *, unsigned);
char *func_021BA848(unsigned swap, unsigned heap);
void func_021BA8F0(char *ctx);
void func_021BA94C(char *p);
u32 func_021BA960(char *p);
void func_021BA96C(void *unused, char *p);
void func_021BA980(char *ctx, unsigned heap);
void func_021BA9E0(void *p);
void func_021BAA18(void *a0);
void func_021BAA1C(void *a0);
void func_021BAA24(unsigned char *p, int a, int b);
void func_021BAA64(char *p);
void func_021BAA80(void *p);
void func_021BAA88(void *p);
u32 func_021BAA90(u32 *p);
void func_021BAA94(unsigned **out, unsigned heap);
extern const struct DispVram d_021BAEF8;
extern const char d_021BB094[];
extern const unsigned d_021BAEAC[];
extern const Record d_021BAF28[];
extern const Vec3 d_021BAE94, d_021BAE88, d_021BAEA0;
extern const short d_020A1EB8[];

char *func_021BA848(unsigned swap, unsigned heap)
{
    char *p;
    p = func_02030734(heap, 16, 0, d_021BB094, 436);
    func_02082BCC(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    func_0204335C(0);
    func_020433E0(&d_021BAEF8);
    func_0204363C(swap);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BA980(p, heap);
    func_021BAA24((unsigned char *)(p + 4), (int)&d_021BAEF8, heap);
    func_021BAA94((unsigned **)(p + 8), heap);
    ((struct Obj26049 *)p)->fC = func_020056A0((unsigned)func_021BA96C, (unsigned)p, 0);
    return p;
}

/*
 * volatile: display registers 04000050/04001050 are cleared at A916/A91C; 04000000/04001000 read and masked at A91E-A92C.
 */
void func_021BA8F0(char *ctx)
{
    func_02030EAC(((struct Obj26050 *)ctx)->fC);
    func_021BAB00((int *)(ctx + 8));
    func_021BAA64(ctx + 4);
    func_021BA9E0(ctx);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000u;
    *(volatile unsigned *)0x04001000 &= ~0xe000u;
    func_02082BCC(ctx, 0, 16);
    func_020307B0(ctx);
}


/*
 * Destructor pair: tears down the tail field then the head.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA94C(char *p)
{
    func_021BAA80(p + 4);
    func_021BAA18(p);
}

u32 func_021BA960(char *p){return func_021BAA90((u32 *)(p+4));}


void func_021BA96C(void *unused, char *p)
{
    func_021BAA1C(p);
    func_021BAA88(p + 4);
}

/*
 * prototype: heap extern parameters widened where original forwards r5 without truncation; BG and flag callee parameters narrowed to u8 where A9AC-A9CE shows explicit shifts. 414AC visibly receives BG input despite its legacy asm void prototype.
 */
void func_021BA980(char *ctx, unsigned heap)
{
    unsigned i;
    const Record *record;
    unsigned bg;
    func_02082BCC(ctx, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021BAEAC);
    for (i = 0; i < 7; i++) {
        record = &d_021BAF28[i];
        bg = record->bg;
        func_0203FCA0((unsigned char)bg, (const struct BgTemplate *)record->config, (unsigned char)record->type);
        func_020414AC(bg);
        func_02040588(bg, record->enable);
    }
}

void func_021BA9E0(void *p){u32 base=(u32)d_021BAF28;u32 i;for(i=0;i<7;i++)func_020403F4(*(const u32 *)(base+i*44));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}

/*
 * extent: 2 zero alignment bytes at 021BAA1A.
 */
void func_021BAA18(void *a0) {}

void func_021BAA1C(void *a0) {func_020419E4();}


void func_021BAA24(unsigned char *p, int a, int b)
{
    func_02082BCC(p, 0, 4);
    func_0204A48C((const struct Cfg *)0x021BAEBC, a, b);
    ((struct Obj14774 *)p)->f0 = (int)func_0204B100(0x80, 0, b);
    func_0204B270((void *)((struct Obj14774 *)p)->f0);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BAA64(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26051 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}

void func_021BAA80(void *p){func_0204A600();}

void func_021BAA88(void *p){func_0204A648();}

u32 func_021BAA90(u32 *p){return *p;}

void func_021BAA94(unsigned **out, unsigned heap)
{
    func_02046440(0, 1, 0, 1, 0, heap, func_021BA7A4);
    *out = func_02048A24(0, d_020A1EB8[6], d_020A1EB8[7], 5461, 0, 4096, 4194304, 0, &d_021BAE94, &d_021BAE88, &d_021BAEA0, heap);
}
