/*
 * file:     mb_util_msg_p02.c
 * unit:     yes
 * function: func_021F1898, func_021F18D8, func_021F18EC, func_021F1900, func_021F1918, func_021F1930
 * address:  0x021F1898
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02194A34  0x02194A34  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../../matched/include/Obj22304.h"
#include "../../matched/include/Obj06379.h"

struct CharBuf;
struct Descriptor;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    unsigned char pad08[8];
    void *f10;
    unsigned char pad14[0x40];
    void *f54;
    unsigned char pad58[4];
    void *f5C;
} Ov107Ctx_021F1898;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    unsigned short f00;
    unsigned char pad02[0x22];
    void *f24;
} Ov107Ctx_021F18D8;

typedef struct {
    unsigned char pad00[0x24];
    void *f24;
} Ov107Ctx_021F18EC;

typedef struct {
    unsigned char pad00[0x24];
    void *f24;
} Ov107Ctx_021F1900;

typedef unsigned short u16;

typedef struct {void *f00;u16 f04;u32 f08;} Entry;

typedef struct {u32 f00;u8 f04;Entry *f08;u32 f0C;u8 f10,f11,f12,f13;} Config;

void *func_02045770(struct Descriptor *p);
void func_02043B5C(struct CharBuf *buf, u8 value);
int func_02194A34(void *, void *);
void func_020409B4(u32 index);
void func_0201F7A8(void *desc, u32 kind);
void func_0202F038(u8 *p);
struct WordSet *func_0201EC64(u32 heap);
u32 func_0201ED04(struct WordSet *p);
void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02045808(struct U16Vec *vec);
void func_021F1898(Ov107Ctx_021F1898 *p);
void func_021F18D8(Ov107Ctx_021F18D8 *p);
void func_021F18EC(Ov107Ctx_021F18EC *p);
void func_021F1900(Ov107Ctx_021F1900 *p, int a, int b, int c);
void func_021F1918(unsigned char *a,int b,int c,int d);
void func_021F1930(char *p,int kind);


void func_021F1898(Ov107Ctx_021F1898 *p)
{
    func_02043B5C(func_02045770(p->f10), 0);
    if (p->f04 == 8) {
        func_02194A34(p->f54, p->f10);
        func_020409B4(p->f02);
    } else {
        func_0201F7A8(p->f10, 1);
    }
    if (p->f5C != 0) {
        func_0202F038(p->f5C);
        p->f5C = 0;
    }
}


void func_021F18D8(Ov107Ctx_021F18D8 *p)
{
    if (p->f24 == 0) {
        p->f24 = func_0201EC64(p->f00);
    }
}


void func_021F18EC(Ov107Ctx_021F18EC *p)
{
    if (p->f24 != 0) {
        func_0201ED04(p->f24);
        p->f24 = 0;
    }
}


void func_021F1900(Ov107Ctx_021F1900 *p, int a, int b, int c)
{
    func_0201EFA4(p->f24, a, b, c, 0, 1);
}

/*
 * Two-byte zero alignment padding follows the compiled function.
 */
void func_021F1918(unsigned char *a,int b,int c,int d) { func_0201EFA4(((struct Obj22304 *)a)->f24,b,c,d,2,1); }

void func_021F1930(char *p,int kind)
{
    Entry entries[2];
    Config config;
    entries[0].f00=func_02045EC0(((struct Obj06379 *)p)->f1C,18);
    entries[1].f00=func_02045EC0(((struct Obj06379 *)p)->f1C,19);
    entries[0].f04=0x39E3;entries[1].f04=0x39E3;
    entries[0].f08=0;entries[1].f08=0;
    config.f00=((struct Obj06379 *)p)->f0;config.f04=2;config.f08=entries;config.f0C=0;
    switch(kind){
    case 0:config.f10=24;config.f11=6;break;
    case 1:config.f10=24;config.f11=12;break;
    case 2:config.f10=24;config.f11=18;break;
    }
    config.f12=8;config.f13=3;
    ((struct Obj06379 *)p)->f3C=func_02027778((struct TaskMenuTmpl *)(&config),((struct Obj06379 *)p)->f40);
    func_02045808(entries[0].f00);func_02045808(entries[1].f00);
}
