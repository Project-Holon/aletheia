/*
 * file:     psel_graphic.c
 * unit:     yes
 * function: func_021BB450, func_021BB508, func_021BB520, func_021BB540, func_021BB62C, func_021BB630, func_021BB7A4, func_021BB840, func_021BB844, func_021BB944, func_021BB954, func_021BB964, func_021BB974, func_021BB9A4, func_021BB9DC, func_021BB9E0, func_021BBA78, func_021BBADC, func_021BBB28, func_021BBC6C, func_021BBCBC, func_021BBCF0, func_021BBD74, func_021BBDE0, func_021BC274, func_021BC2CC, func_021BC30C, func_021BC348, func_021BC34C, func_021BC3F0, func_021BC498, func_021BC4F4, func_021BC508, func_021BC514, func_021BC520, func_021BC52C, func_021BC538, func_021BC54C, func_021BC5AC, func_021BC5E4, func_021BC5E8, func_021BC5F0, func_021BC630, func_021BC64C, func_021BC654, func_021BC65C, func_021BC660, func_021BC6CC, func_021BC6DC, func_021BC6F0
 * address:  0x021BB450
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027858 0x02027858 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_02061CA4 0x02061CA4 arm
 *   d_021BC73C 0x021BC73C data a1
 *   d_021BC6FC 0x021BC6FC data a1
 *   d_021BC708 0x021BC708 data a1
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9740 0x021B9740 thumb ov223
 *   func_021B9830 0x021B9830 thumb ov223
 *   func_021BAAB8 0x021BAAB8 thumb ov223
 *   func_021BAE00 0x021BAE00 thumb ov223
 *   func_021BB38C 0x021BB38C thumb ov223
 *   func_02040EBC 0x02040EBC arm
 *   func_021B9854 0x021B9854 thumb ov223
 *   func_021BAB78 0x021BAB78 thumb ov223
 *   func_021BAC0C 0x021BAC0C thumb ov223
 *   func_021BB2A4 0x021BB2A4 thumb ov223
 *   func_0207D63C 0x0207D63C arm
 *   func_021B9914 0x021B9914 thumb ov223
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021BB35C 0x021BB35C thumb ov223
 *   func_021BAC6C 0x021BAC6C thumb ov223
 *   func_021BABFC 0x021BABFC thumb ov223
 *   func_021B98F4 0x021B98F4 thumb ov223
 *   func_0204363C 0x0204363C arm
 *   func_021B99A0 0x021B99A0 thumb ov223
 *   func_021B9D9C 0x021B9D9C thumb ov223
 *   func_021BA984 0x021BA984 thumb ov223
 *   func_021BAC70 0x021BAC70 thumb ov223
 *   func_021BAD80 0x021BAD80 thumb ov223
 *   func_021B9D4C 0x021B9D4C thumb ov223
 *   func_021BA2B4 0x021BA2B4 thumb ov223
 *   func_021B9A8C 0x021B9A8C thumb ov223
 *   func_021BA8D0 0x021BA8D0 thumb ov223
 *   func_021BAFC4 0x021BAFC4 thumb ov223
 *   func_021BA878 0x021BA878 thumb ov223
 *   func_021BB0B0 0x021BB0B0 thumb ov223
 *   func_021BA8BC 0x021BA8BC thumb ov223
 *   func_021BAA5C 0x021BAA5C thumb ov223
 *   func_021BAA84 0x021BAA84 thumb ov223
 *   func_021B9C90 0x021B9C90 thumb ov223
 *   func_021BA81C 0x021BA81C thumb ov223
 *   func_02035C08 0x02035C08 arm
 *   func_021BB3BC 0x021BB3BC thumb ov223
 *   func_021BB414 0x021BB414 thumb ov223
 *   func_021BB424 0x021BB424 thumb ov223
 *   func_021BB404 0x021BB404 thumb ov223
 *   func_02041B6C 0x02041B6C arm
 *   func_021BB440 0x021BB440 thumb ov223
 *   func_021B9AE4 0x021B9AE4 thumb ov223
 *   func_021B9B80 0x021B9B80 thumb ov223
 *   func_021B9B4C 0x021B9B4C thumb ov223
 *   func_020355D8 0x020355D8 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021BB134 0x021BB134 thumb ov223
 *   func_021B9C00 0x021B9C00 thumb ov223
 *   func_021B9C58 0x021B9C58 thumb ov223
 *   func_021BB274 0x021BB274 thumb ov223
 *   func_021BB18C 0x021BB18C thumb ov223
 *   func_02006984 0x02006984 thumb
 *   d_021BC75C 0x021BC75C data a4
 *   d_021BC794 0x021BC794 data a2
 *   d_021BC710 0x021BC710 data a2
 *   func_021BADFC 0x021BADFC thumb ov223
 *   func_021BAD68 0x021BAD68 thumb ov223
 *   func_021BAA30 0x021BAA30 thumb ov223
 *   func_021BA050 0x021BA050 thumb ov223
 *   func_021B9A6C 0x021B9A6C thumb ov223
 *   func_021BB3AC 0x021BB3AC thumb ov223
 *   func_021BAEE0 0x021BAEE0 thumb ov223
 *   func_021BAB74 0x021BAB74 thumb ov223
 *   func_021B9848 0x021B9848 thumb ov223
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BC960 0x021BC960 data a4
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204361C 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   d_021BCB08 0x021BCB08 data a1
 *   d_021BC980 0x021BC980 data a4
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BC6F8 0x021BC6F8 thumb ov223
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BC934 0x021BC934 data a4
 *   d_021BC9B0 0x021BC9B0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_02043598  0x02043598  arm
 *   d_021BC944     0x021BC944  data  a4
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   d_021BC928 0x021BC928 data a4
 *   d_021BC91C 0x021BC91C data a4
 *   d_021BC910 0x021BC910 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *   func_02047964  0x02047964  arm
 *   func_02048AD0    0x02048AD0  arm
 *   func_020479D8    0x020479D8  arm
 *   func_02047970 0x02047970 arm
 */
#include "../../matched/include/Obj00084.h"
#include "../../matched/include/Obj06727.h"
#include "../../matched/include/Obj26099.h"
#include "../../matched/include/Obj06728.h"
#include "../../matched/include/Obj14793.h"
#include "../../matched/include/Obj00739.h"
#include "../../matched/include/Obj06729.h"
#include "../../matched/include/Obj01594.h"
#include "../../matched/include/Obj00792.h"
#include "../../matched/include/Obj05570.h"
#include "../../matched/include/Obj00211.h"
#include "../../matched/include/Obj26100.h"
#include "../../matched/include/Obj00738.h"
#include "../../matched/include/Obj05571.h"
#include "../../matched/include/Obj26103.h"

struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct GfFont;
struct Main;
struct Node;
struct PrintSys;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Cfg;
struct Light;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Obj Obj;

struct Item { void *text; u16 color; unsigned value; };

struct TaskMenuTmpl {
    unsigned heapId;
    u8 count;
    u8 pad05[3];
    const void *unk08;
    unsigned unk0c;
    u8 pad10[2];
    u8 unk12;
    u8 unk13;
};

typedef unsigned int u32;

struct Ent { u8 a, b, c, d, e; };

typedef struct {
    u16 src[16];
    u16 dst[16];
    u16 out[16];
    u16 state;
    u16 step;
    u8 pad[0x30];
} Fade;

typedef struct {
    u8 head[0x74];
    Fade f[3];
} Ctx;

struct Colors {u16 b2,g2,r2,b1,g1,r1;};

enum Offset {OffsetZero=0};

typedef enum { BIT8=8, BIT32=32 } Bits;

typedef signed int     s32;

typedef enum { TOON, HIGHLIGHT } Shading;

struct Entry { unsigned id; char fields[32]; unsigned a,b; };

extern void *func_02045EC0(struct MsgBank *, unsigned);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *, void *);
extern void func_02045808(struct U16Vec *);
extern void func_02027858(struct TaskMenu *);
extern void func_02027974(Obj *);
extern unsigned func_020279E8(struct TaskMenu *);
extern u8 func_02027A04(const u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern int func_02061CA4(void *, unsigned, unsigned, int);
extern struct GfFont *func_0201D7EC(int, int, int, int, unsigned);
extern unsigned func_0201C440(void *);
extern void func_0204047C(int, u16);
extern void *func_020056A0(void (*)(void *, char *), void *, int);
extern void func_021B9740(void *, char *);
extern void func_021B9830(char *);
extern void func_021BAAB8(u16 *p);
extern void func_021BAE00(char *p);
extern void func_021BB38C(char *p);
extern void func_02040EBC(unsigned, unsigned);
extern void func_021B9854(u8 *p);
extern void func_021BAB78(u16 *p);
extern void func_021BAC0C(unsigned short *);
extern void func_021BB2A4(char *p);
extern void func_0207D63C(void *, unsigned, unsigned, unsigned, unsigned);
extern void func_021B9914(char *p);
extern void func_0204E720(unsigned, int, int, int);
extern int func_0204E804(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_020061E4(u32);
extern void func_021BB35C(char *p);
extern void func_021B98F4(char *p);
extern void func_021BAC6C(unsigned char *);
extern int func_021BABFC(unsigned char *);
extern void func_0204363C(u32 swap);
extern void func_021B99A0(char *);
extern void func_021B9D9C(char *);
extern void func_021BA984(char *);
extern void func_021BAC70(const u16 *p);
extern void func_021BAD80(u16 *p);
extern void func_021B9C58(char *);
extern void func_021B9A8C(char *p);
extern void func_021B9D4C(char *);
extern void func_021BA2B4(struct Main *p);
extern void func_021BA8D0(char *);
extern void func_021BAFC4(char *p, int idx);
extern void func_021BA878(char *);
extern int func_021BB0B0(char *),func_021BA8BC(char *);
extern void func_021BAA5C(char *,int);
extern void func_021BAA84(char *);
extern void func_021B9C90(char *,u32);
extern void func_021BA81C(char *,u32);
extern int func_02035C08(const void *);
extern void func_021BB3BC(char *),func_021BB414(char *),func_021BB424(char *),func_021BB404(char *),func_02041B6C(u32);
extern u32 func_021BB440(char *);
extern void func_021B9AE4(char *,int,int),func_021B9B80(char *);
extern int func_021B9B4C(char *);
extern void func_020355D8(u32);
extern void func_021BB134(char *);
extern void func_021B9C00(char *,u32);
extern void func_021BB274(char *);
extern void func_021BB18C(char *p, int idx);
extern u8 func_020355C4(void);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_021BADFC(char *);
extern void func_021BAD68(char *);
extern void func_021BAA30(char *);
extern void func_021BA050(char *);
extern void func_021B9A6C(char *);
extern int func_021BB3AC(int *);
extern void func_021BAEE0(char *p);
extern void func_021BAB74(int *);
extern void func_021B9848(int *);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(unsigned short,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204361C(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void func_0201DD68(void);
extern unsigned func_021BC6F8(unsigned char *);
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02046440(int,int,int,int,int,int,void (*)(void));
extern int func_02048A24(int,int,int,int,int,int,int,int,const int *,const int *,const int *,int);
extern u32 func_02048AC4(void *ptr);
extern int func_02046788(int);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_02047970(void);
void func_021BB450(char *p);
void func_021BB4D8(char *p);
void func_021BB4E8(char *p);
unsigned func_021BB4F8(char *p);
int func_021BB508(int *p);
void func_021BB520(int v, unsigned short *a, unsigned short *b, unsigned short *c);
void func_021BB540(u8 *p);
void func_021BB62C(void *a0);
void func_021BB630(Ctx *p);
void func_021BB7A4(char *p);
void func_021BB840(void *a0);
void func_021BB844(char *p);
void func_021BB944(char *p);
void func_021BB954(char *p);
void func_021BB964(char *p);
void func_021BB974(unsigned char *p,unsigned index,int cmd);
void func_021BB9A4(unsigned char *p,int value);
int func_021BB9DC(void);
int func_021BB9E0(char *p);
int func_021BBA78(char *p);
int func_021BBADC(char *p, int *state);
int func_021BBB28(char *p,u32 *state);
int func_021BBC6C(char *p, int *state);
int func_021BBCBC(unsigned char *p);
int func_021BBCF0(char *p);
int func_021BBD74(char *p,unsigned *state);
int func_021BBDE0(char *p,u32 *state);
int func_021BC274(char *p,unsigned *state);
int func_021BC2CC(char *p);
int func_021BC30C(int *p);
int func_021BC348(void);
void func_021BC34C(void);
void *func_021BC3F0(int a,int heap);
void func_021BC498(unsigned *p);
void func_021BC4F4(char *p);
void func_021BC508(unsigned char *p);
void func_021BC514(unsigned char *p);
unsigned func_021BC520(unsigned char *p);
unsigned func_021BC52C(unsigned char *p);
void func_021BC538(void *unused, char *p);
void func_021BC54C(void *p,int heap);
void func_021BC5AC(void *p);
void func_021BC5E4(void *a0);
void func_021BC5E8(void *a0);
void func_021BC5F0(int *out, int a, int b);
void func_021BC630(char *p);
void func_021BC64C(void *a0);
void func_021BC654(void *a0);
u32 func_021BC65C(const u32 *p);
void func_021BC660(int *p,int heap);
void func_021BC6CC(int *p);
void func_021BC6DC(int *p);
void func_021BC6F0(unsigned char *unused);
extern const struct Ent d_021BC73C[3];
extern const u8 d_021BC6FC[];
extern const u8 d_021BC708[];
extern const u8 d_021BC75C[];
extern const u16 d_021BC794[],d_021BC710[];
extern char d_021BC960[];
extern char d_021BCB08[];
extern unsigned d_021BC980[];
extern const unsigned d_021BC934[];
extern const struct Entry d_021BC9B0[];
extern int d_021BC944;
extern const short d_020A1EB8[];
extern int d_021BC91C[],d_021BC910[],d_021BC928[];






/*
 * Lead EXACT* ends at BB4D8; three 16-byte load/tail-call followers
 * complete the extent. Parent cleared these starts. The value local
 * assigns zero then conditionally one; a boolean expression reverses
 * the compare polarity. Template precedes items in declaration order.
 */
void func_021BB450(char *p)
{
    struct TaskMenuTmpl tmpl;
    struct Item items[2];
    unsigned i;
    for (i = 0; i < 2; i++) {
        unsigned value;
        items[i].text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00084 *)p)->f234, i + 22);
        items[i].color = 0x39E3;
        value = 0;
        if (i != 0)
            value = 1;
        items[i].value = value;
    }
    tmpl.heapId = ((struct Obj00084 *)p)->f0;
    tmpl.count = 2;
    tmpl.unk0c = 1;
    tmpl.pad10[0] = 32;
    tmpl.pad10[1] = 17;
    tmpl.unk12 = 9;
    tmpl.unk13 = 3;
    tmpl.unk08 = items;
    *(struct TaskMenu * *)&((struct Obj00084 *)p)->f264 = func_02027778(&tmpl, ((struct Obj00084 *)p)->f25C);
    for (i = 0; i < 2; i++)
        func_02045808(items[i].text);
}






void func_021BB4D8(char *p)
{
    func_02027858(*(struct TaskMenu * *)&((struct Obj00084 *)p)->f264);
}






void func_021BB4E8(char *p)
{
    func_02027974(*(Obj * *)&((struct Obj00084 *)p)->f264);
}






unsigned func_021BB4F8(char *p)
{
    return func_020279E8(*(struct TaskMenu * *)&((struct Obj00084 *)p)->f264);
}







int func_021BB508(int *p)
{
    return func_02027A04((const u8 *)p[0x99]) == 0;
}






void func_021BB520(int v, unsigned short *a, unsigned short *b, unsigned short *c)
{
    *a = v & 0x1f;
    *b = (v & 0x3e0) >> 5;
    *c = (v & 0x7c00) >> 10;
}






void func_021BB540(u8 *p)
{
    void *object = func_020490F4(205, *(u16 *)p);
    u8 i;
    for (i = 0; i < 3; i++) {
        u8 *out;
        void *buffer = func_02049F78(object, d_021BC73C[i].b, (u32)&out, *(u16 *)p);
        func_02082D44(*(u8 **)(out + 0xC), p + 0x74 + i * 0x94, 0x20);
        func_020307B0(buffer);
        buffer = func_02049F78(object, d_021BC73C[i].e, (u32)&out, *(u16 *)p);
        func_02082D44(*(u8 **)(out + 0xC), p + 0x94 + i * 0x94, 0x20);
        func_020307B0(buffer);
    }
    func_02049238(object);
    for (i = 0; i < 3; i++) {
        *(u16 *)(p + 0xD4 + i * 0x94) = 2;
        *(u16 *)(p + 0xD6 + i * 0x94) = 0x10;
    }
    for (i = 0; i < 3; i++) {
        func_02082D44(p + 0x94 + i * 0x94, p + 0xB4 + i * 0x94, 0x20);
        func_02061CA4((void *)0x1E, d_021BC6FC[i] << 5, (u32)(p + 0xB4 + i * 0x94), 0x20);
    }
}






void func_021BB62C(void *a0){}






/*
 * note (2026-10-05, wave D4 lane 06): EXACT. Three 0x94-byte fade slots at p+0x74 modelled as a
 *   struct array (src/dst/out palettes, state, step); inner loop indexes p->f[i] directly (no element
 *   pointer); step changes written as ++/-- (the read-modify-write form reloads the step); signed
 *   /16 via an int weight t; dst[j] read into a local before the first split call; colour packed
 *   as A << 10 | (B | C << 5).
 */
void func_021BB630(Ctx *p)
{
    u8 i;
    for (i = 0; i < 3; i++) {
        int go = 0;
        switch (p->f[i].state) {
        case 1:
            if (p->f[i].step == 0x10) {
                p->f[i].state = 2;
            } else {
                p->f[i].step++;
                p->f[i].step = 0x10;
                go = 1;
            }
            break;
        case 3:
            if (p->f[i].step == 0) {
                p->f[i].state = 0;
            } else {
                p->f[i].step--;
                go = 1;
            }
            break;
        }
        if (go) {
            if (p->f[i].state == 1 || p->f[i].state == 3) {
                u8 j;
                u16 w[6];
                for (j = 0; j < 0x10; j++) {
                    int t = p->f[i].step;
                    u16 c = p->f[i].dst[j];
                    func_021BB520(p->f[i].src[j], &w[5], &w[4], &w[3]);
                    func_021BB520(c, &w[2], &w[1], &w[0]);
                    p->f[i].out[j] =
                        (u16)((w[3] * (16 - t) + w[0] * t) / 16) << 10 | ((u16)((w[5] * (16 - t) + w[2] * t) / 16) | (u16)((w[4] * (16 - t) + w[1] * t) / 16) << 5);
                }
            }
            func_02061CA4((void *)0x1E, d_021BC6FC[i] << 5, (u32)p->f[i].out, 0x20);
        }
    }
}






void func_021BB7A4(char *p)
{
    void *object = func_020490F4(205, ((struct Obj06727 *)p)->f0);
    u8 i;
    for (i = 0; i < 4; i++) {
        char *out;
        void *buffer = func_02049F78(object, d_021BC708[i], (u32)(&out), ((struct Obj06727 *)p)->f0);
        func_02082D44(*(char * *)&((struct Obj26099 *)out)->fC + 256, p + 0x26A + i * 256, 256);
        func_020307B0(buffer);
    }
    func_02049238(object);
    ((struct Obj06727 *)p)->f86C = 0;
    ((struct Obj06727 *)p)->f870 = 16;
    ((struct Obj06727 *)p)->f871 = 3;
    func_02082D44(p + 0x56A, p + 0x76A, 256);
    func_02061CA4((void *)31, 256, (unsigned)(p + 0x76A), 256);
}






void func_021BB840(void *a0){}






void func_021BB844(char *p)
{
    int active=0;
    enum Offset which;
    u8 i;
    u8 weight;
    struct Colors colors;
    u32 q;
    int next;
    u16 red,green,blue;
    u32 tmp;
    if(((struct Obj06728 *)p)->f86C!=1) goto done;
    {
        if(*(volatile u8 *)&((struct Obj06728 *)p)->f870==16) ((struct Obj06728 *)p)->f86C=0;
        else {++*(volatile u8 *)&((struct Obj06728 *)p)->f870;active=1;}
    }
    if(active) {
        which=0x870;
        i=0;
        which+=1;
        for(;i<128;i++) {
            weight=((struct Obj06728 *)p)->f870;
            next=*(u16 *)(p+(*(u8 *)(p+which))*256+i*2+0x26a);
            tmp=(u32)p+i*2;
            q=tmp;
            func_021BB520(((struct Obj14793 *)q)->f66A,&colors.r1,&colors.g1,&colors.b1);
            func_021BB520(next,&colors.r2,&colors.g2,&colors.b2);
            blue=(colors.b1*(16-weight)+colors.b2*weight)/16;
            red=(colors.r1*(16-weight)+colors.r2*weight)/16;
            green=(colors.g1*(16-weight)+colors.g2*weight)/16;
            ((struct Obj14793 *)q)->f76A=red|(green<<5)|(blue<<10);
        }
        func_02061CA4((void *)31,256,(u32)(p+0x76a),256);
    }
done:;
}







/*
 * Addresses are Black-image addresses.
 */
void func_021BB944(char *p)
{
    func_021BB540((u8 *)p);
    func_021BB7A4(p);
}







void func_021BB954(char *p)
{
    func_021BB62C(p);
    func_021BB840(p);
}







void func_021BB964(char *p)
{
    func_021BB630((Ctx *)p);
    func_021BB844(p);
}






void func_021BB974(unsigned char *p,unsigned index,int cmd){switch(cmd){case 0:if(*(unsigned short *)((unsigned)p+212+index*148)!=0)*(unsigned short *)((unsigned)p+212+index*148)=3;break;case 2:if(*(unsigned short *)((unsigned)p+212+index*148)!=2)*(unsigned short *)((unsigned)p+212+index*148)=1;break;}}






/*
 * extent: copy helper followed by unlabelled return-one stub at 021BB9DC.
 */
void func_021BB9A4(unsigned char *p,int value){if(p[2161]!=value){((struct Obj00084 *)p)->f86C=1;p[2160]=0;p[2161]=value;func_02082D44(p+1898,p+1642,256);}}






int func_021BB9DC(void){return 1;}






int func_021BB9E0(char *p)
{
    ((struct Obj00739 *)p)->f14 = func_021BC3F0(1, ((struct Obj00739 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00739 *)p)->f18 = func_0201D7EC(23, 0, 0, 0, ((struct Obj00739 *)p)->f0);
    ((struct Obj00739 *)p)->f1C = func_0201C440((void *)(unsigned)((struct Obj00739 *)p)->f0);
    func_0204047C(0, 2);
    func_0204047C(1, 3);
    func_0204047C(2, 1);
    func_0204047C(3, 0);
    func_0204047C(4, 3);
    func_0204047C(5, 2);
    func_0204047C(6, 1);
    func_0204047C(7, 0);
    ((struct Obj00739 *)p)->f20 = func_020056A0(func_021B9740, p, 1);
    ((struct Obj00739 *)p)->f24 = 0;
    func_021B9830(p);
    func_021BAAB8((u16 *)p);
    func_021BAE00(p);
    func_021BB38C(p);
    return 2;
}






int func_021BBA78(char *p)
{
    func_02040EBC(0, 0x2F3B);
    func_02040EBC(4, 0x2F3B);
    func_021B9854((u8 *)p);
    func_021BAB78((u16 *)p);
    func_021BAC0C((unsigned short *)p);
    func_021BB2A4(p);
    ((struct Obj06729 *)p)->f24 |= 2;
    ((struct Obj06729 *)p)->f268 = 0;
    func_0207D63C((void *)0x04000050, 5, 63,
                 ((struct Obj06729 *)p)->f268, 16 - ((struct Obj06729 *)p)->f268);
    ((struct Obj06729 *)p)->f10 = 0;
    return 3;
}






int func_021BBADC(char *p, int *state)
{
    if (*(unsigned *)&((struct Obj01594 *)p)->f10 >= 1)
        func_021B9914(p);
    switch (*state) {
    case 0:
        func_0204E720(3, 16, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0) {
            ((struct Obj01594 *)p)->f10 = 0;
            return 4;
        }
        break;
    }
    (((struct Obj01594 *)p)->f10)++;
    return 3;
}





/*
 * ABI: 02035C60 return consumed at BB B2, as in matched BB0B0, despite own void forwarding declaration.
 */
int func_021BBB28(char *p,u32 *state)
{
    int changed=0;
    switch(*state) {
    case 0: func_021B9914(p);if(((struct Obj00792 *)p)->f50==134) ++*state;break;
    case 1:
        if(((struct Obj00792 *)p)->f268<8) {++((struct Obj00792 *)p)->f268;changed=1;}
        func_021B9914(p);if(((struct Obj00792 *)p)->f50==138) ++*state;break;
    case 2:
        if(((struct Obj00792 *)p)->f268<8) {++((struct Obj00792 *)p)->f268;changed=1;}
        else {((struct Obj00792 *)p)->f24|=1;++*state;}
        break;
    case 3: ++*state;break;
    case 4:
        if((func_020362DC()&3)!=0||func_02035C60()!=0) {
            if((func_020362DC()&3)!=0) ((struct Obj00792 *)p)->f8=0;
            else ((struct Obj00792 *)p)->f8=1;
            func_020061E4(1356);++*state;
        }
        break;
    case 5:
        ((struct Obj00792 *)p)->f24|=2;
        if(((struct Obj00792 *)p)->f268!=0) {--((struct Obj00792 *)p)->f268;changed=1;}
        ++*state;break;
    case 6:
        if(((struct Obj00792 *)p)->f268!=0) {--((struct Obj00792 *)p)->f268;changed=1;}
        if(((struct Obj00792 *)p)->f268==4) ++*state;break;
    case 7:
        if(((struct Obj00792 *)p)->f268!=0) {--((struct Obj00792 *)p)->f268;changed=1;}
        func_021B9914(p);
        if(((struct Obj00792 *)p)->f50==180) func_020061E4(1956);
        if(((struct Obj00792 *)p)->f50==199) {((struct Obj00792 *)p)->f10=0;return 5;}
        break;
    }
    if(changed) func_0207D63C((void *)0x04000050, 5, 63, ((struct Obj00792 *)p)->f268, 16-((struct Obj00792 *)p)->f268);
    ++((struct Obj00792 *)p)->f10;
    return 4;
}





/*
 * Preserve the original 9914 call's visible r1=258 and r2=frame inputs;
 * the full callee body reads only entry r0.
 */
int func_021BBC6C(char *p, int *state)
{
    if (((struct Obj01594 *)p)->f50 != 258)
        func_021B9914(p);
    switch (*state) {
    case 0:
        func_0204E720(12, 0, 16, 3);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0) {
            ((struct Obj01594 *)p)->f10 = 0;
            return 6;
        }
        break;
    }
    (((struct Obj01594 *)p)->f10)++;
    return 5;
}





int func_021BBCBC(unsigned char *p){*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;func_021BB35C((char *)p);func_021BAC6C(p);func_021BABFC(p);func_021B98F4((char *)p);((struct Obj05570 *)p)->f10=0;return 7;}





static inline void setbit(char *p,Bits b) { ((struct Obj26100 *)p)->f24|=b; }





int func_021BBCF0(char *p)
{
    func_0204363C(0);
    func_02040EBC(0,0x2f3b); func_02040EBC(4,0x2f3b);
    func_021B99A0(p); func_021B9D9C(p); func_021BA984(p); func_021BAC70((const u16 *)p); func_021BAD80((u16 *)p); func_021BB944(p);
    setbit(p,BIT8); setbit(p,BIT32);
    func_0207D63C((void *)0x04000050, 5, 63, 8, 8); func_0207D63C((void *)0x04001050, 4, 63, 8, 8);
    ((struct Obj00211 *)p)->f10=0;
    return 8;
}





int func_021BBD74(char *p,unsigned *state)
{
    if(((struct Obj00738 *)p)->f10>=16) func_021B9A8C(p);
    if(((struct Obj00738 *)p)->f10==15) func_020061E4(1957);
    func_021B9D4C(p); func_021BA2B4((struct Main *)p); func_021BB964(p);
    switch(*state) {
    case 0: func_0204E720(12,16,0,2); (*state)++; break;
    case 1: if(!func_0204E804()) { ((struct Obj00738 *)p)->f10=0; return 9; } break;
    }
    (((struct Obj00738 *)p)->f10)++;
    return 8;
}





/*
 * ABI: A A84 unused legacy r1 omitted: full own body reads no second input, original has no setup; BB9A4 r1 truncated to u8 at BE C6/CA and parallel sites; 355D8 widened to observed full word without pre-call truncation. 35C60 return consumed as in own-overlay BB0B0.
 */
int func_021BBDE0(char *p,u32 *state)
{
    int dirty=0;
    int choice,changed;
    u32 selected;
    func_021B9D4C(p);func_021BA2B4((struct Main *)p);func_021BA8D0(p);func_021BB964(p);
    switch(*state) {
    case 0:func_021B9A8C(p);if(((struct Obj00084 *)p)->f50==78)*state=1;break;
    case 1:((struct Obj00084 *)p)->f24|=4;func_021BAFC4(p,(u32)19);*state=2;func_021BA878(p);break;
    case 2:if(func_021BB0B0(p)&&func_021BA8BC(p)){*state=3;((struct Obj00084 *)p)->f8=1;}break;
    case 3:
        if(((struct Obj00084 *)p)->f8==0){
            if(*(int *)&((struct Obj00084 *)p)->f228==4){dirty=1;*(int *)&((struct Obj00084 *)p)->f228=1;}
            func_021BAA5C(p,1);func_020061E4(1352);func_021BAA84(p);
            func_021B9C90(p,((struct Obj00084 *)p)->f228);func_021BA81C(p,((struct Obj00084 *)p)->f228);
            selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);
        }else{func_021BAA5C(p,0);func_021B9C90(p,4);func_021BA81C(p,4);func_021BB9A4((u8 *)p,(u8)3);dirty=1;}
        *state=4;break;
    case 4:
        if(((struct Obj00084 *)p)->f8==0){
            if(func_020362DC()!=0){
                changed=0;
                if(func_020362DC()&1){func_020061E4(1356);func_021BAA5C(p,0);*state=8;}
                else if(func_020362DC()&32){if(*(int *)&((struct Obj00084 *)p)->f228>0){--*(int *)&((struct Obj00084 *)p)->f228;changed=1;}}
                else if(func_020362DC()&16){if(*(int *)&((struct Obj00084 *)p)->f228<2){++*(int *)&((struct Obj00084 *)p)->f228;changed=1;}}
                if(changed){func_020061E4(1352);func_021BAA84(p);func_021B9C90(p,((struct Obj00084 *)p)->f228);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);dirty=1;}
            }else if(func_02035C60()!=0){choice=func_02035C08(d_021BC75C);if(choice>=0&&choice<=2){if(*(int *)&((struct Obj00084 *)p)->f228!=choice)dirty=1;func_020061E4(1352);func_021BAA5C(p,0);*(int *)&((struct Obj00084 *)p)->f228=choice;func_021B9C90(p,choice);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);((struct Obj00084 *)p)->f8=1;*state=5;}}
        }else{
            if(func_020362DC()!=0){((struct Obj00084 *)p)->f8=0;*state=3;}
            else if(func_02035C60()!=0){choice=func_02035C08(d_021BC75C);if(choice>=0&&choice<=2){func_020061E4(1352);*(int *)&((struct Obj00084 *)p)->f228=choice;func_021B9C90(p,choice);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);dirty=1;*state=5;}}
        }break;
    case 5:func_021BB3BC(p);*state=6;break;
    case 6:
        func_021BB414(p);
        if(func_020362DC()!=0){((struct Obj00084 *)p)->f8=0;if(func_020362DC()&1){func_020061E4(1356);func_021BB424(p);*state=7;}else{func_021BB404(p);func_02041B6C(3);*state=3;}}
        else if(func_02035C60()!=0){choice=func_02035C08(d_021BC75C);if(choice==3){func_020061E4(1356);func_021BB424(p);*state=7;}else if(choice>=0&&choice<=2&&*(int *)&((struct Obj00084 *)p)->f228!=choice){func_020061E4(1352);*(int *)&((struct Obj00084 *)p)->f228=choice;func_021B9C90(p,choice);func_021BA81C(p,((struct Obj00084 *)p)->f228);selected=((struct Obj00084 *)p)->f228;if(selected==4)selected=3;func_021BB9A4((u8 *)p,(u8)selected);dirty=1;}}break;
    case 7:func_021BB414(p);if(func_021BB440(p)){func_021BB404(p);func_02041B6C(3);*state=8;}break;
    case 8:func_021BAFC4(p,(u32)20);func_021B9AE4(p,*(int *)&((struct Obj00084 *)p)->f228,0);*state=9;break;
    case 9:func_021B9B80(p);if(func_021BB0B0(p)&&func_021B9B4C(p))*state=10;break;
    case 10:func_020355D8(*(u32 *)&((struct Obj00084 *)p)->f8);func_021BB450(p);*state=11;break;
    case 11:func_021BB4E8(p);if(func_021BB4F8(p)){choice=func_021BB508((int *)p);func_021BB4D8(p);*(u32 *)&((struct Obj00084 *)p)->f8=func_020355C4();if(choice){((struct Obj00084 *)p)->f24|=8;func_021BB134(p);*state=14;}else{func_021BAFC4(p,(u32)19);*state=12;}}break;
    case 12:func_021B9AE4(p,*(int *)&((struct Obj00084 *)p)->f228,1);*state=13;break;
    case 13:func_021B9B80(p);if(func_021B9B4C(p))*state=3;break;
    case 14:func_021B9C00(p,((struct Obj00084 *)p)->f228);func_020061E4(1976);*state=15;break;
    case 15:func_021B9C58(p);if(((struct Obj00084 *)p)->f4C==(int)*(const u16 *)((const u8 *)d_021BC794+((struct Obj00084 *)p)->f44*10)-2)*state=16;break;
    case 16:func_021B9C58(p);*(int *)&((struct Obj00084 *)p)->f10=0;return 10;
    }
    if(dirty){((struct Obj00084 *)p)->f24|=32;func_021BB274(p);}
    else if(((struct Obj00084 *)p)->f230!=0){((struct Obj00084 *)p)->f24|=16;func_021BB18C(p,(u32)(((struct Obj00084 *)p)->f228));func_02006984(d_021BC710[((struct Obj00084 *)p)->f228],0,64,0,0,0,0,0);}
    ((struct Obj00084 *)p)->f230=0;++((struct Obj00084 *)p)->f10;return 9;
}




int func_021BC274(char *p,unsigned *state)
{
    func_021B9C58(p);
    func_021B9D4C(p); func_021BA2B4((struct Main *)p); func_021BB964(p);
    switch(*state) {
    case 0: func_0204E720(12,0,16,2); (*state)++; break;
    case 1: if(!func_0204E804()) { ((struct Obj00738 *)p)->f10=0; return 11; } break;
    }
    (((struct Obj00738 *)p)->f10)++;
    return 10;
}




int func_021BC2CC(char *p)
{
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_021BB954(p); func_021BADFC(p); func_021BAD68(p);
    func_021BAA30(p); func_021BA050(p); func_021B9A6C(p);
    ((struct Obj05571 *)p)->f10=0;
    return 12;
}




int func_021BC30C(int *p)
{
    func_021BB3AC(p); func_021BAEE0((char *)p); func_021BAB74(p); func_021B9848(p);
    func_02030EAC((void *)p[8]); func_0201C6EC((struct PrintSys *)p[7]); func_0201C4C0((struct PrintSys *)p[7]);
    func_0201D83C((void *)p[6]); func_021BC498((unsigned *)p[5]);
    return 13;
}




/*
 * trailing: parent-cleared Thumb follower 021BC348 is movs r0,#13; bx lr.
 */
int func_021BC348(void) { return 13; }




static inline void shading(Shading s)
{
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3002)|(s<<1));
}




static inline void priority(int p)
{
    *(volatile unsigned short *)0x04000008=(unsigned short)((*(volatile unsigned short *)0x04000008 & ~3)|p);
}




void func_021BC34C(void)
{
    unsigned i;
    func_020434DC(1,1);
    priority(0);
    shading(HIGHLIGHT);
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|16);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3004;
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|8);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3020;
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((unsigned char)i,(const u16 *)(d_021BC960+i*8));
    func_02046BE0(0,0);
}




void *func_021BC3F0(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_021BCB08,463);
    func_02082BCC(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    func_020433E0((const struct DispVram *)d_021BC980);
    func_0204363C(a);
    func_0204361C();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021BC54C(p,heap);
    func_021BC5F0((int *)(p+1),(int)d_021BC980,heap);
    func_021BC660((int *)(p+2),heap);
    p[3]=(unsigned)func_020056A0(func_021BC538,p,0);
    return p;
}




/*
 * volatile: hardware accesses at 0x021BC4BA-0x021BC4D4.
 */
void func_021BC498(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_021BC6CC((int *)(p+2));
    func_021BC630((char *)(p+1));
    func_021BC5AC(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}





void func_021BC4F4(char *p)
{
    func_021BC64C(p + 4);
    func_021BC5E4(p);
}




void func_021BC508(unsigned char *p){func_021BC6DC((int *)(p+8));}




void func_021BC514(unsigned char *p){func_021BC6F0(p+8);}




unsigned func_021BC520(unsigned char *p){return func_021BC65C((const unsigned *)(p+4));}




unsigned func_021BC52C(unsigned char *p){return func_021BC6F8(p+8);}





void func_021BC538(void *unused, char *p)
{
    func_021BC5E8(p);
    func_021BC654(p + 4);
}


void func_021BC54C(void *p,int heap)
{
    unsigned i;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021BC934);
    for(i=0;i<7;i++) {
        const struct Entry *e=&d_021BC9B0[i];
        unsigned id=e->id;
        func_0203FCA0((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        func_020414AC(id);
        func_02040588(id,e->b);
    }
}




void func_021BC5AC(void *p){unsigned i;for(i=0;i<7;i++)func_020403F4((unsigned char)d_021BC9B0[i].id);func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}




void func_021BC5E4(void *a0){}




void func_021BC5E8(void *a0){func_020419E4();}





void func_021BC5F0(int *out, int a, int b)
{
    func_02082BCC(out, 0, 4);
    func_0204A48C((const struct Cfg *)(&d_021BC944), a, b);
    *out = (int)func_0204B100(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer((void *)*out);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}





void func_021BC630(char *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj26103 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}



void func_021BC64C(void *a0) { func_0204A600(); }



void func_021BC654(void *a0) { func_0204A648(); }



/*
 * extent: tail-call stub followed by unlabelled 021BC65C load-return.
 */
u32 func_021BC65C(const u32 *p) { return *p; }



void func_021BC660(int *p,int heap)
{
    func_02046440(0,1,0,1,4096,heap,func_021BC34C);
    *p=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,0x400000,0,d_021BC91C,d_021BC910,d_021BC928,heap);
}




void func_021BC6CC(int *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}




void func_021BC6DC(int *p)
{
    func_02047964();
    func_02048AD0((struct Light *)(*p));
    func_020479D8();
}



void func_021BC6F0(unsigned char *unused){func_02047970();}
