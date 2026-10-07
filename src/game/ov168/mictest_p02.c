/*
 * file:     mictest_p02.c
 * unit:     yes
 * function: func_02184138, func_02184144, func_0218414C, func_021841C8, func_021841F4, func_021841F8, func_021842B4, func_021842BC, func_02184360, func_02184398, func_02184408
 * address:  0x02184138
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A648 0x0204A648 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02040588 0x02040588 arm
 *   d_02184878 0x02184878 data a4
 *   d_02184964 0x02184964 data a1
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049624 0x02049624 arm
 *   func_0204989C 0x0204989C arm
 *   func_020419E4 0x020419E4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045180 0x02045180 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02184888 0x02184888 data a1
 *   d_02184868 0x02184868 data a2
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_02030734 0x02030734 arm
 *   func_02006CBC 0x02006CBC thumb
 *   func_02034F84 0x02034F84 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02006D94 0x02006D94 thumb
 *   d_02184A20 0x02184A20 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_02006D44  0x02006D44  thumb
 *   func_02034FB8  0x02034FB8  arm
 */
#include "../../matched/include/Obj23820.h"
#include "../../matched/include/Obj23821.h"
#include "../../matched/include/Obj03845.h"
#include "../../matched/include/Obj14260.h"
#include "../../matched/include/Obj23822.h"

struct Bank;
struct CharBuf;
struct Descriptor;
struct Rec;
struct Node;
struct Blk37;
struct DispConfig;
struct GfFont;
struct BgTemplate;
struct MsgBank;
struct Cfg;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A648(void);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(unsigned);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u16 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 v);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_020419E4(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern unsigned int func_02045180(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, unsigned int offset);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_020456F8(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02006CBC(u16 heap);
extern void func_02034F84(u32 v);
extern void func_02082BCC(void *p, int v, u32 n);
extern u32 func_02006D94(void);
extern unsigned int func_020307B0(void *p);
extern void func_02006D44(void);
extern void func_02034FB8(u32 v);
void func_02184138(char *p);
void func_02184144(void *p);
void func_0218414C(char *p, int heap);
void func_021841C8(void *a0);
void func_021841F4(char *a0);
void func_021841F8(void *p, int heap);
void func_021842B4(void *p);
void func_021842BC(void **p, int heap);
void func_02184360(char *p);
void func_02184398(u8 *p, int heap, u32 b, u32 c);
void func_02184408(int *p);
extern int d_02184878[];
extern u8 d_02184964[];
extern const u8 d_02184888[];
extern u16 d_02184868[];
extern char d_02184A20[];

void func_02184138(char *p) { func_0204B1CC(*(struct Bank * *)&((struct Obj23820 *)p)->f1C); }

void func_02184144(void *p) { func_0204A648(); }

void func_0218414C(char *p, int heap)
{
    unsigned i;
    unsigned bg;
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_02184878);
    ((struct Obj23821 *)p)->f10 = func_0201D7EC(23, 0, 0, 0, (u16)heap);
    for (i = 0; i < 5; i++) {
        bg = d_02184964[i * 0x24 + 0x20];
        func_0203FCA0(bg, (const struct BgTemplate *)(d_02184964 + i * 0x24), d_02184964[i * 0x24 + 0x21]);
        func_020414EC(bg);
        func_02040B94(bg, 32, 0, (u16)heap);
        func_02040588(bg, 1);
    }
}


void func_021841C8(void *a0)
{
    u32 i;

    for (i = 0; i < 5; i++)
        func_020403F4(d_02184964[i * 0x24 + 0x20]);
    func_020450C8();
    func_0203F9B4();
}


void func_021841F4(char *a0) {  }

void func_021841F8(void *p, int heap)
{
    func_02049B40(106, 0, 0, 0, 32, heap);
    func_02049B40(106, 1, 4, 0, 32, heap);
    func_02049B40(23, 5, 0, 416, 32, heap);
    func_02049B40(23, 5, 4, 416, 32, heap);
    func_02049624((void *)106, (void *)4, (void *)5, 0, 0, 0, heap);
    func_0204989C(106, 5, 5, 0, 0, 0, heap);
    func_02049624((void *)106, (void *)2, (void *)1, 0, 0, 0, heap);
    func_0204989C(106, 3, 1, 0, 0, 0, heap);
}

void func_021842B4(void *p) { func_020419E4(); }

void func_021842BC(void **p, int heap)
{
    int i;
    const u8 *row;
    void *a;
    void *b;
    void *s;
    p[3] = func_02045B38((int)0,(int)2,(int)65,(u16)heap);
    for (i=0;i<3;i++) {
        row = d_02184888+i*12;
        p[i] = (void *)func_02045180((int)row[0],(int)row[1],(int)row[2],(int)row[3],row[4],row[5],(int)(((struct Obj03845 *)row)->f6));
        a = func_02045770(p[i]);
        func_02043B5C(a,0);
        func_020456F8(p[i]);
        b = func_02045EC0(p[3],i);
        func_0201C7D0(a,row[8],0,b,p[4],d_02184868[i]);
        func_02045808(b);
        s = p[i];
        func_02045334(s);
        func_02045374(s);
        func_020409B4(func_02045730(s));
    }
}

void func_02184360(char *p) { int i; for(i=0;i<3;i++) {func_02043B5C(func_02045770(*(void **)(p+i*4)),0);func_020456F8(*(struct Descriptor **)(p+i*4));func_020452E8(*(struct Descriptor **)(p+i*4));} func_02045C04(*(struct Rec * *)&((struct Obj14260 *)p)->fC);func_0201D83C(((struct Obj14260 *)p)->f10); }

/*
 * 2026-10-05 (wD8 lane06): closed with plain literals (no size local). mwcc keeps one constant of the
 *   block in a callee-saved register and derives the others from it: with the 0x100 store written right
 *   after the aligned-pointer store, 0x120 wins r6 and 0x100 becomes `subs r6,#0x20`. With the 0x100 store
 *   last, 1 wins and 0x100 becomes `adds r0,#0xff` (108 bytes). Earlier lanes needed an enum local here.
 */
void func_02184398(u8 *p, int heap, u32 b, u32 c)
{
    u8 *buf;
    func_02006CBC(heap);
    func_02034F84(8);
    buf = func_02030734((u16)heap, 0x120, 0, d_02184A20, 0x603);
    func_02082BCC(buf, 0, 0x120);
    *(u8 **)(p + 0x1c) = buf;
    *(u32 *)p = 0;
    *(u32 *)(p + 4) = ((u32)buf + 0x1f) & ~0x1f;
    *(u32 *)(p + 8) = 0x100;
    *(u32 *)(p + 0xc) = 0x1001;
    *(u32 *)(p + 0x10) = 1;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x18) = c;
    *(u32 *)(p + 0x34) = func_02006D94();
}


void func_02184408(int *p)
{
    func_020307B0((void *)(((struct Obj23822 *)p)->f1C));
    func_02006D44();
    func_02034FB8(8);
}
