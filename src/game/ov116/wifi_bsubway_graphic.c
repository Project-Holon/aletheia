/*
 * file:     wifi_bsubway_graphic.c
 * unit:     yes
 * function: func_021D72D0, func_021D730C, func_021D7324, func_021D737C, func_021D73D0, func_021D73D4, func_021D73E0, func_021D7420, func_021D7424, func_021D7450, func_021D7550, func_021D77D0, func_021D7A3C, func_021D7A94, func_021D7AA8, func_021D7AC8, func_021D7B00, func_021D7B70, func_021D7C58, func_021D7CF4, func_021D7D0C, func_021D7F54, func_021D7FC4, func_021D8010, func_021D80CC, func_021D8118, func_021D8134, func_021D8168, func_021D8190, func_021D81B4, func_021D81D0, func_021D81EC, func_021D821C, func_021D82AC, func_021D82F8, func_021D8304, func_021D8364
 * address:  0x021D72D0
 * region:   ov116
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0202E4EC 0x0202E4EC thumb
 *   func_020120B4 0x020120B4 thumb
 *   d_021D8574 0x021D8574 data a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   func_0202E54C 0x0202E54C thumb
 *   func_02045A98 0x02045A98 arm
 *   func_02045A90 0x02045A90 arm
 *   d_021D6338 0x021D6338 data ov115 a4
 *   d_021D654C 0x021D654C data ov115 a4
 *   d_021D8580 0x021D8580 data a4
 *   func_021D6EC4 0x021D6EC4 thumb ov116
 *   func_021D6E50 0x021D6E50 thumb ov116
 *   func_021D7060 0x021D7060 thumb ov116
 *   func_021D70B0 0x021D70B0 thumb ov116
 *   func_021D69A8 0x021D69A8 thumb ov116
 *   func_021D69C0 0x021D69C0 thumb ov116
 *   func_021D69EC 0x021D69EC thumb ov116
 *   func_021D6A10 0x021D6A10 thumb ov116
 *   func_021D6A40 0x021D6A40 thumb ov116
 *   func_021D6A44 0x021D6A44 thumb ov116
 *   func_021D6A48 0x021D6A48 thumb ov116
 *   func_021D6A4C 0x021D6A4C thumb ov116
 *   func_021D6A5C 0x021D6A5C thumb ov116
 *   func_021D6AF0 0x021D6AF0 thumb ov116
 *   func_021D6B30 0x021D6B30 thumb ov116
 *   func_021D7278 0x021D7278 thumb ov116
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02167ED8 0x02167ED8 arm ov009
 *   func_021D6998 0x021D6998 thumb ov116
 *   func_02009860 0x02009860 thumb
 *   func_02009CC0 0x02009CC0 thumb
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0205994C 0x0205994C arm
 *   func_021C8F2C 0x021C8F2C arm ov114
 *   func_021C96CC 0x021C96CC arm ov114
 *   func_021D70E4 0x021D70E4 thumb ov116
 *   func_021D70EC 0x021D70EC thumb ov116
 *   func_021C93D0 0x021C93D0 arm ov114
 *   func_021C9634 0x021C9634 arm ov114
 *   func_021C93BC 0x021C93BC arm ov114
 *   func_02157170 0x02157170 thumb ov009
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CA98 0x0203CA98 arm
 *   func_021D7158 0x021D7158 thumb ov116
 *   func_021D7200 0x021D7200 thumb ov116
 *   func_021D7184 0x021D7184 thumb ov116
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02031140 0x02031140 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020310C4 0x020310C4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203FA08 0x0203FA08 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02021F64 0x02021F64 thumb
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   d_021D8560 0x021D8560 data a4
 *   d_021D8560_menu 0x021D8560 data a4
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202EE30 0x0202EE30 thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02030734 0x02030734 arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   d_021D858C 0x021D858C data a1
 *   d_021D83C0 0x021D83C0 data a4
 *   func_021D839C 0x021D839C thumb ov116
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021D83B0 0x021D83B0 data a4
 *   d_021D83F0 0x021D83F0 data a4
 *   g_021D83F0  0x021D83F0  data
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */
#include "../../matched/include/Obj13867.h"
#include "../../matched/include/Obj22624.h"
#include "../../matched/include/Obj10340.h"
#include "../../matched/include/Obj22625.h"
#include "../../matched/include/Obj22626.h"
#include "../../matched/include/Obj00671.h"
#include "../../matched/include/Obj22627.h"
#include "../../matched/include/Obj22628.h"
#include "../../matched/include/Obj22629.h"
#include "../../matched/include/Obj01926.h"
#include "../../matched/include/Obj00494.h"
#include "../../matched/include/Obj00470.h"
#include "../../matched/include/Obj13868.h"
#include "../../matched/include/Obj10342.h"
#include "../../matched/include/Obj01721.h"
#include "../../matched/include/Obj13869.h"
#include "../../matched/include/Obj03252.h"
#include "../../matched/include/Obj05322.h"
#include "../../matched/include/Obj22630.h"
#include "../../matched/include/Obj06418.h"
#include "../../matched/include/Obj22631.h"
#include "../../matched/include/Obj08048.h"
#include "../../matched/include/Obj10343.h"
#include "../../matched/include/Obj10344.h"
#include "../../matched/include/Obj10345.h"
#include "../../matched/include/Obj13870.h"
#include "../../matched/include/Obj10346.h"
#include "../../matched/include/Obj22632.h"
#include "../../matched/include/Obj22633.h"
#include "../../matched/include/Obj10347.h"

#define P(k) (*(void **)(p + (k)))
#define I(k) (*(u32_021D8010 *)((char *)p+(k)))
struct IcaAnime;
struct Param;
struct Obj0202E54C;
struct U16Vec;
struct Blk1AC;
struct BlkB90;
struct Stamp;
struct Sub020097BCObj;
struct Sub0200852CObj;
struct DWCstAccUserData;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct Rec3;
struct S02031140;
struct Tcbl;
struct Node;
struct WinDat;
struct BmpMenu;
struct DispVram;
struct BgTemplate;
struct DispConfig;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed char s8;

typedef int s32_021D7420;

typedef struct { void (*f[3])(int **, int); } Tbl;

typedef signed int     s32_021D7450;

typedef signed int     s32_021D7550;

typedef signed int     s32_021D77D0;

typedef unsigned long long u64;

typedef unsigned int   u32_021D7C58;

typedef unsigned int u32_021D7CF4;

typedef unsigned int u32_021D7D0C;

struct Arc { int f0; int f4; int f8; u8 *fC; };

typedef unsigned int   u32_021D7F54;

typedef unsigned int u32_021D7FC4;

typedef unsigned u32_021D8010;

typedef unsigned int u32_021D80CC;

typedef unsigned int u32_021D8118;

typedef unsigned int u32_021D8134;

typedef unsigned int u32_021D8168;

typedef unsigned int u32_021D8190;

typedef unsigned int u32_021D81B4;

typedef unsigned int u32_021D81D0;

typedef unsigned int u32_021D81EC;

typedef unsigned int   u32_021D821C;

typedef unsigned int   u32_021D82AC;

typedef unsigned int   u32_021D8304;

typedef unsigned int u32_021D8364;

extern struct Param *func_0202E4EC(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void func_0202E54C(struct Obj0202E54C *p);
extern u16 func_02045A98(void);
extern u16 *func_02045A90(struct U16Vec *vec);
extern int func_021D6EC4(u8 *,u8 *,int);
extern void func_021D6E50(u8 *,u8 *,int,int);
extern void func_021D7060(u8 *,u8 *);
extern int func_021D70B0(void *unused, u8 *p);
extern u32 func_0200DBA0(struct Blk1AC *p, s32_021D7450 i, u32 op);
extern u8 func_0200DC08(struct Blk1AC *p);
extern void func_021D69A8(u8 *,u8 *,u16);
extern void func_021D69EC(u8 *,u8 *,u16);
extern int func_021D69C0(u8 *,u8 *);
extern int func_021D6A10(u8 *,u8 *);
extern u16 func_021D6A40(u8 *);
extern u16 func_021D6A44(u8 *);
extern u16 func_021D6A48(u8 *);
extern int func_021D6A4C(unsigned char *p);
extern void func_021D6A5C(u8 *);
extern void func_021D6AF0(u8 *,void *);
extern void func_021D6B30(u8 *,void *);
extern void func_021D7278(u8 *,int);
extern int func_0204E804(void);
extern void func_0204E720(u32 a, s32_021D7550 b, s32_021D7550 c, s32_021D7550 d);
extern int func_02167ED8(void *date, void *time);
extern int func_0200DDD0(struct BlkB90 *p, u8 a, u8 b, const struct Stamp *q);
extern void func_021D6998(void *a);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int func_02009CC0(void *a0);
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern void func_021C8F2C(unsigned a, unsigned b, unsigned c, unsigned mode);
extern void func_021C96CC(void);
extern void func_021D70E4(u8 *p);
extern int func_021D70EC(u8 *, int *);
extern int func_021C93D0(void);
extern void func_021C9634(void);
extern void func_021C93BC(void);
extern int func_02157170(int,int);
extern u32 func_0200FB24(void);
extern u32 func_0203CA98(void);
extern int func_021D7158(u8 *p);
extern int func_021D7200(int *p);
extern int func_021D7184(int *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_0203101C(u32, u32, u32, u32);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_0203D34C(u32, u32);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02031140(struct S02031140 *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32_021D7C58 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201FEF4(u8 *o);
extern u32_021D7C58 func_020452E8(struct Descriptor *d);
extern void func_0201DD68(void);
extern void func_02082BCC(void *,int,int);
extern void func_020310C4(struct Tcbl *p);
extern void *func_020490F4(u32_021D7D0C, u32_021D7D0C);
extern void func_02049B68(void *, int, int, int, int, u32_021D7D0C);
extern u32_021D7D0C func_02049740(void *, int, int, int, int, u32_021D7D0C);
extern void func_02049990(void *, int, int, int, u16, int, int, u32_021D7D0C);
extern void *func_02049F78(void *a0, u32_021D7D0C a1, u32_021D7D0C a2, u32_021D7D0C a3);
extern void func_02049238(void *);
extern int func_02049B40(int, int, int, int, int, u32_021D7D0C);
extern void func_02082D44(const void *, void *, u32_021D7D0C);
extern u32_021D7D0C func_020307B0(void *p);
extern void *func_020056A0(void *, void *, int);
extern void func_020862F0(void *, u32_021D7D0C);
extern void func_0207D63C(void *, int, int, int, int);
extern u32_021D7D0C func_0203FA08(u32_021D7D0C layer, u32_021D7D0C size, u32_021D7D0C top);
extern void *func_0201F5DC(void *a0, u32_021D7D0C a1, u32_021D7D0C a2, u32_021D7D0C a3);
extern void func_02021F64(void *, void *, u16, u8, u16);
extern void func_0207E3D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void func_02040618(u32_021D7F54 layer, u32_021D7F54 a, u32_021D7F54 b);
extern void func_0203FB44(u32_021D7FC4 layer, u32_021D7FC4 offset, u32_021D7FC4 size);
extern void func_02030EAC(struct Node *n);
extern void func_02045CAC(struct MsgBank *bank, u32_021D8010 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201DD78(u32_021D8010 r, u32_021D8010 g, u32_021D8010 b);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(u32_021D8010,int,int,u32_021D8010,u32_021D8010,u32_021D8010,u32_021D8010,int,u16,int);
extern u32_021D80CC func_0201CE30(void *p);
extern u32_021D80CC func_020362DC(void);
extern int func_02035C60(void);
extern void func_0201CE38(void *);
extern void func_0201EFA4(struct WordSet *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b, u32_021D8118 c, u32_021D8118 d);
extern struct BmpMenu *func_0201FDA0(const struct WinDat *,u16,u8,u8,u16);
extern u32_021D8168 func_0201FEBC(u8 *);
extern u32_021D8190 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0202F038(u8 *);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void *func_02030734(u32_021D821C heapId, u32_021D821C size, int clear, const char *site, u16 tag);
extern void func_0204335C(unsigned);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32_021D821C swap);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021D839C(void *);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32_021D8304 bgId, const struct BgTemplate *tmpl, u32_021D8304 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
void func_020403F4(u32_021D8364 i);
void func_020450C8(void);
void func_0203F9B4(void);
void func_021D72D0(u8 *p, u32 heap);
void func_021D730C(u8 *p);
u32 func_021D7324(u8 *p);
void func_021D737C(u8 *p);
void func_021D73D0(void *a0);
int func_021D73D4(u8 *p);
void func_021D73E0(u8 *p);
void func_021D7420(void *a0);
void func_021D7424(int **p, int x);
int func_021D7450(u8 *p,int b);
int func_021D7550(u8 *p,short heap);
int func_021D77D0(u8 *p,short heap);
void func_021D7A3C(u8 *p);
int func_021D7A94(u8 *p);
void func_021D7AA8(u8 *p);
int func_021D7AC8(u8 *p);
int func_021D7B00(u8 *p);
int func_021D7B64(u8 *p);
void func_021D7B70(u8 *p, short heap);
void func_021D7C58(u8 *p);
void func_021D7CF4(u8 *p);
void func_021D7D0C(u8 *p, short heap);
void func_021D7F54(void *unused,u8 *p);
void func_021D7FC4(u8 *p);
void func_021D8010(void *p,u32_021D8010 a);
int func_021D80CC(void *p);
void func_021D8118(u8 *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b);
void func_021D8134(u8 *p);
u32_021D8168 func_021D8168(u8 *p);
void func_021D8190(u8 *p);
void func_021D81B4(u8 *p);
void func_021D81D0(u8 *p);
int func_021D81EC(u8 *p);
void *func_021D821C(int a,unsigned heap);
void func_021D82AC(void *p);
void func_021D82F8(void *a,void *b);
void func_021D8304(void *p,unsigned heap);
void func_021D8364(void *a0);
extern u32 d_021D8574[];
extern u32 d_021DA62C[];
extern u8 ov129_id[];
extern u32 d_021D6338[];
extern u8 ov115_id[];
extern u32 d_021D654C[];
extern const Tbl d_021D8580;
extern u8 d_021D8560[];
extern u8 d_021D8560_menu[];
extern char d_021D858C[];
extern char d_021D83C0[];
extern char d_021D83B0[];
extern char d_021D83F0[];
extern u8 g_021D83F0[];


void func_021D72D0(u8 *p, u32 heap)
{
    void *obj;
    obj = func_0202E4EC(heap, 2, 10, 2, d_021D8574);
    ((struct Obj13867 *)p)->f1840 = obj;
    func_020120B4(((struct Obj22624 *)(*(u8 * *)&((struct Obj13867 *)p)->f0))->f4, (u32)ov129_id, d_021DA62C, obj);
}


void func_021D730C(u8 *p)
{
    if (((struct Obj10340 *)p)->f1840) {
        func_0202E54C(((struct Obj10340 *)p)->f1840);
        ((struct Obj10340 *)p)->f1840 = 0;
    }
}


u32 func_021D7324(u8 *p) {
    u16 end=func_02045A98();
    u16 *s=func_02045A90(((struct Obj22626 *)(*(u8 * *)&((struct Obj22625 *)p)->f1840))->f20);
    u32 value=0;
    u16 i=0;
    while(s[i]!=end) {
        u16 d=(u16)(s[i]-48);
        if(d>=10) d=(u16)(s[i]-0xff10);
        value *= 10;
        value += d;
        i++;
    }
    return value;
}


void func_021D737C(u8 *p) {
    ((struct Obj00671 *)p)->f9B0=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9B4=0;
    ((struct Obj00671 *)p)->f9C8=1;
    ((struct Obj00671 *)p)->f9B8=1;
    ((struct Obj00671 *)p)->f9BC=44;
    ((struct Obj00671 *)p)->f9C0=p+0x9f4;
    func_020120B4(((struct Obj22627 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,d_021D6338,p+0x9b0);
}


/*
 * extent: two-byte zero alignment padding, then already matched getter ov116_func_021D73D4.c.
 */
void func_021D73D0(void *a0) { }


int func_021D73D4(u8 *p) { return ((struct Obj22628 *)p)->f9CC; }


void func_021D73E0(u8 *p) {
    ((struct Obj00671 *)p)->f9D8=*(u32 *)&((struct Obj00671 *)p)->f1844;
    ((struct Obj00671 *)p)->f9DC=0;
    ((struct Obj00671 *)p)->f9E0=1;
    ((struct Obj00671 *)p)->f9E4=1;
    func_020120B4(((struct Obj22629 *)(*(u8 * *)&((struct Obj00671 *)p)->f0))->f4,(u32)ov115_id,d_021D654C,p+0x9d8);
}



void func_021D7420(void *a0) { }


void func_021D7424(int **p, int x)
{
    Tbl t = d_021D8580;
    t.f[**p](p, x);
}


/*
 * ABI: incoming r1 is forwarded as fourth6E50 argument; 81EC reads
 * incoming r0 left intact by the switch. Both inputs are named.
 */
int func_021D7450(u8 *p,int b)
{
    int v;
    switch (((struct Obj01926 *)p)->fB6C) {
    case 0: func_021D8010(p+4,7); ++((struct Obj01926 *)p)->fB6C; break;
    case 1: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 2:
        v=func_021D6EC4(p+0x1610,p+0x182c,0);
        if(v==1) ((struct Obj01926 *)p)->fB6C=5;
        else if(v==2) ((struct Obj01926 *)p)->fB6C=3;
        break;
    case 3: func_021D6E50(p+0x1610,p+0x182c,(int)(p+0x9f4),b); ++((struct Obj01926 *)p)->fB6C; break;
    case 4:
        if(func_021D6EC4(p+0x1610,p+0x182c,1)==1) ((struct Obj01926 *)p)->fB6C=5;
        break;
    case 5: func_021D7060(p+0x1610,p+0x182c); ++((struct Obj01926 *)p)->fB6C; break;
    case 6:
        if(func_021D70B0(p+0x1610,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj01926 *)p)->fB6C;
        break;
    case 7: func_0200DBA0(((struct Obj01926 *)p)->f1858,1,2); func_021D81D0(p); ++((struct Obj01926 *)p)->fB6C; break;
    case 8:
        if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,8); ++((struct Obj01926 *)p)->fB6C; }
        break;
    case 9: if(func_021D80CC(p+4)!=0) ++((struct Obj01926 *)p)->fB6C; break;
    case 10: return 1;
    }
    return 0;
}


int func_021D7550(u8 *p,short heap)
{
    int v,box;
    u32 n;
    u8 extra[12];
    u8 record[16];
    switch(((struct Obj00494 *)p)->fB6C) {
    case 0: func_021D69A8(p+0xb74,p+0x182c,(u32)func_0200DC08(((struct Obj00494 *)p)->f1858)); ++((struct Obj00494 *)p)->fB6C; break;
    case 1: if(func_021D69C0(p+0xb74,p+0x182c)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 2:
        func_021D81B4(p+4); v=func_021D6A48(p+0xb74);
        func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74)); func_021D8010(p+4,0); ++((struct Obj00494 *)p)->fB6C; break;
    case 3: if(func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 4: func_0204E720((int)3,0,16,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 5: if(func_0204E804()==0) { func_021D7C58(p+4); ++((struct Obj00494 *)p)->fB6C; } break;
    case 6: func_021D7278(p,heap); ++((struct Obj00494 *)p)->fB6C; break;
    case 7: ((struct Obj00494 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); func_0204E720((int)3,16,0,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 8:
        if(func_0204E804()==0) {
            box=func_021D6A40(p+0xb74); n=((struct Obj00494 *)p)->fB70; v=func_021D6A48(p+0xb74);
            func_02167ED8(record,extra);
            if(n<1 || n>(u32)v) { ((struct Obj00494 *)p)->fB6C=16; break; }
            if(func_0200DDD0(((struct Obj00494 *)p)->f1854,box,n,(const struct Stamp *)record)!=0) { ((struct Obj00494 *)p)->fB6C=14; break; }
            func_021D69EC(p+0xb74,p+0x182c,((struct Obj00494 *)p)->fB70);
            v=func_021D6A44(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74));
            func_021D8118(p+4,1,func_021D6A40(p+0xb74),(u32)((void *)2)); func_021D8010(p+4,1); func_021D8190(p+4); ++((struct Obj00494 *)p)->fB6C;
        } break;
    case 9: if(func_021D6A10(p+0xb74,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 10: func_021D6A5C(p+0xb74); func_021D6AF0(p+0xb74,((struct Obj00494 *)p)->f1854); func_021D6B30(p+0xb74,((struct Obj00494 *)p)->f1854); func_021D81D0(p); ++((struct Obj00494 *)p)->fB6C; break;
    case 11: if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,3); ++((struct Obj00494 *)p)->fB6C; } break;
    case 12: if(func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 13: return 1;
    case 14: func_021D8010(p+4,2); ++((struct Obj00494 *)p)->fB6C; break;
    case 15: if(func_021D80CC(p+4)!=0) ((struct Obj00494 *)p)->fB6C=2; break;
    case 16: func_021D8010(p+4,4); ++((struct Obj00494 *)p)->fB6C; break;
    case 17: if(func_021D80CC(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 18: func_021D8134(p+4); ++((struct Obj00494 *)p)->fB6C; break;
    case 19: v=(int)func_021D8168(p+4); if(v==0) return 2; if(v==-2) ((struct Obj00494 *)p)->fB6C=2; break;
    }
    return 0;
}


int func_021D77D0(u8 *p,short heap)
{
    int v;
    u32 n;
    switch(((struct Obj00470 *)p)->fB6C) {
    case 0: func_021D81B4(p+4); func_021D8010(p+4,5); ++((struct Obj00470 *)p)->fB6C; break;
    case 1: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 2: func_0204E720(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 3: if(func_0204E804()==0) { func_021D7C58(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 4: func_021D72D0(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 5: ((struct Obj00470 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); func_0204E720(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 6:
        if(func_0204E804()==0) {
            n=((struct Obj00470 *)p)->fB70;
            if(n>=1 && n<=10) {
                func_021D69A8(p+0xb74,p+0x182c,n); func_021D8010(p+4,26); func_021D8190(p+4); ++((struct Obj00470 *)p)->fB6C;
            } else ((struct Obj00470 *)p)->fB6C=19;
        } break;
    case 7:
        if(func_021D69C0(p+0xb74,p+0x182c)!=0) {
            func_021D81B4(p+4); v=func_021D6A48(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74)); func_021D8010(p+4,6); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 8: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 9: func_0204E720(3,0,16,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 10: if(func_0204E804()==0) { func_021D7C58(p+4); ++((struct Obj00470 *)p)->fB6C; } break;
    case 11: func_021D7278(p,heap); ++((struct Obj00470 *)p)->fB6C; break;
    case 12: ((struct Obj00470 *)p)->fB70=func_021D7324(p); func_021D730C(p); func_021D7B70(p+4,heap); func_0204E720(3,16,0,1); ++((struct Obj00470 *)p)->fB6C; break;
    case 13:
        if(func_0204E804()==0) {
            v=func_021D6A48(p+0xb74); n=((struct Obj00470 *)p)->fB70;
            if(n<1 || n>(u32)v) { ((struct Obj00470 *)p)->fB6C=19; break; }
            func_021D69EC(p+0xb74,p+0x182c,n);
            v=func_021D6A44(p+0xb74); func_021D8118(p+4,0,v,(u32)func_021D6A4C(p+0xb74));
            func_021D8118(p+4,1,func_021D6A40(p+0xb74),(u32)((void *)2)); func_021D8010(p+4,1); func_021D8190(p+4); ++((struct Obj00470 *)p)->fB6C;
        } break;
    case 14: if(func_021D6A10(p+0xb74,p+0x182c)!=0 && func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 15: func_021D6A5C(p+0xb74); func_021D6B30(p+0xb74,((struct Obj00470 *)p)->f1854); func_021D81D0(p); ++((struct Obj00470 *)p)->fB6C; break;
    case 16: if(func_021D81EC(p)!=0) { func_021D81B4(p+4); func_021D8010(p+4,3); ++((struct Obj00470 *)p)->fB6C; } break;
    case 17: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 18: return 1;
    case 19: func_021D8010(p+4,9); ++((struct Obj00470 *)p)->fB6C; break;
    case 20: if(func_021D80CC(p+4)!=0) ++((struct Obj00470 *)p)->fB6C; break;
    case 21: func_021D8134(p+4); ++((struct Obj00470 *)p)->fB6C; break;
    case 22: v=func_021D8168(p+4); if(v==0) return 2; if(v==-2) { func_021D6998(p+0xb74); ((struct Obj00470 *)p)->fB6C=0; } break;
    }
    return 0;
}


void func_021D7A3C(u8 *p) {
    void *a=func_02009860(((struct Obj00671 *)p)->f184C);
    void *b;
    u64 value;
    func_02008540(((struct Obj00671 *)p)->f1850,(u32)func_02009CC0(((struct Obj00671 *)p)->f184C));
    b=(void *)func_0200853C(((struct Obj00671 *)p)->f1850);
    value=func_0205994C(a);
    func_021C8F2C((unsigned int)b,(u32)value,(u32)(value>>32),0);
    func_021C96CC();
    func_021D70E4(p+0x182c);
    ((struct Obj00671 *)p)->fB68=1;
}


int func_021D7A94(u8 *p)
{
    int result;
    return func_021D70EC(p + 0x182c, &result);
}


/*
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 (pengy overlay, no witness).
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Only open relocation: func_021C93D0 (ov114 ARM, SDK-side
 *   libext code, no witness). Nothing source-side to change.
 */
void func_021D7AA8(u8 *p)
{
    if (func_021C93D0() == 0) {
        func_021C9634();
        func_021D70E4(p + 0x182c);
    }
}


int func_021D7AC8(u8 *p)
{
    int result;
    if (((struct Obj13868 *)p)->fB68 == 0) return 1;
    if (func_021D70EC(p + 0x182c, &result)) {
        func_021C93BC();
        ((struct Obj13868 *)p)->fB68 = 0;
        return 1;
    }
    return 0;
}


int func_021D7B00(u8 *p) {
    int yes=1;
    int no=0;
    if(func_02157170(1,0)!=0) return no;
    if(func_0200FB24()!=0) {
        func_0203CA98();
        return no;
    }
    if(func_021D7158(p+0x182c)!=0) {
        int v;
        if(func_021D7200((int *)(p+0x182c))!=0) return no;
        v=func_021D7184((int *)(p+0x182c));
        func_021D81B4(p+4);
        func_021D8010(p+4,v);
        return yes;
    }
    return no;
}


int func_021D7B64(u8 *p) { return func_021D80CC(p+4); }


/*
 * evidence: incoming heap in r1 is forwarded unchanged to 021D821C.
 * evidence: 0203101C's second parameter is wide here: original 021D7C26
 * copies full r6 to r1 with no truncation; its definition stores the low halfword.
 */
void func_021D7B70(u8 *p, short heap)
{
    P(8) = func_021D821C(1, heap);
    ((struct Obj10342 *)p)->f4 = heap;
    func_021D7D0C(p, heap);
    P(0x97c) = (void *)func_020450F0(1, 1, 19, 30, 4, 12, 1);
    func_0201F73C(P(0x97c), 1, (u16)(((struct Obj10342 *)p)->f984), 13);
    func_02043B5C(func_02045770(P(0x97c)), 15);
    func_02045374(P(0x97c));
    func_02045334(P(0x97c));
    func_02041B6C(1);
    P(0x990) = func_02045B38(0, 2, 206, heap);
    P(0x994) = func_0201EC64(heap);
    P(0x998) = func_0201D7EC(23, 0, 0, 0, heap);
    P(0x99c) = func_020457B0(128, heap);
    P(0x9a0) = func_020457B0(128, heap);
    P(0x9a8) = func_0203101C(heap, heap, 1, 0);
    ((struct Obj10342 *)p)->f0 = 1;
    func_020434DC(16, 1);
    func_02043598(16, 1);
    func_0203D34C(1, heap);
}


void func_021D7C58(u8 *p) {
    if(((struct Obj01721 *)p)->f0!=0) {
        if(((struct Obj01721 *)p)->f9A4) func_0201CE48(((struct Obj01721 *)p)->f9A4);
        func_02031140(((struct Obj01721 *)p)->f9A8);
        func_02045C04(((struct Obj01721 *)p)->f990);
        func_0201ED04(((struct Obj01721 *)p)->f994);
        func_0201D83C(((struct Obj01721 *)p)->f998);
        func_02045808(((struct Obj01721 *)p)->f99C);
        func_02045808(((struct Obj01721 *)p)->f9A0);
        func_021D7FC4(p);
        func_021D81B4(p);
        if(((struct Obj01721 *)p)->f980) {
            func_0201FEF4(((struct Obj01721 *)p)->f980);
            ((struct Obj01721 *)p)->f980=0;
        }
        func_020452E8(((struct Obj01721 *)p)->f97C);
        func_021D82AC(((struct Obj01721 *)p)->f8);
        func_0201DD68();
        func_02082BCC(p,0,0x9ac);
    }
}


void func_021D7CF4(u8 *p)
{
    if (((struct Obj13869 *)p)->f0 != 0) func_020310C4(((struct Obj13869 *)p)->f9A8);
}


/*
 * lever: 2026-10-05 (wD9r lane92): the heap parameter is a signed 16-bit value (`short heap`). With u32
 *   heap the last call hoisted the heap reload above `str r6,[sp]` (10 bytes, waves D3 to D9r). The
 *   image truncates heap only for func_02049F78 (u16 cast); the other callees take it unchanged.
 */
void func_021D7D0C(u8 *p, short heap) {
    struct Arc *res;
    u8 *pa;
    u8 *pb;
    void *arc;
    int done;
    int t;
    int j;
    int k;
    u8 *q;
    void *blk;
    int m;
    int n;
    int sh;
    u8 *a;
    u8 *b;
    arc = func_020490F4(0x91, heap);
    j = 0;
    func_02049B68(arc, 3, 4, 0, j, heap);
    func_02049990(arc, 6, 4, 0, (u16)func_02049740(arc, 4, 4, 0, j, heap), j, j, heap);
    func_02049B68(arc, 3, 0, 0, j, heap);
    func_02049990(arc, 5, 0, 0, (u16)func_02049740(arc, 4, 0, 0, j, heap), j, j, heap);
    func_02049990(arc, 7, 3, 0, (u16)func_02049740(arc, 4, 3, 0, j, heap), j, j, heap);
    func_02082BCC(p + 0xc, 0, 0x970);
    blk = func_02049F78(arc, 2, (u32_021D7D0C)(&res), (u16)heap);
    func_02082D44(res->fC, p + 0x14, 0x1e0);
    func_02082D44(res->fC, p + 0x1f4, 0x1e0);
    func_020307B0(blk);
    k = 0;
    pa = p + 0x1f4;
    pb = p;
    pb += 0x14;
    for (; k < 15; k++) {
        n = k + 1;
        if (n >= 15) n -= 15;
        t = 0;
        done = 0;
        q = p + n * 32;
        for (;;) {
            a = pb + k * 32;
            sh = t >> 8;
            b = pa + j * 32;
            for (m = 4; m < 11; m++) {
                func_02021F64(a + m * 2, b + m * 2, 1, (u8)sh, *(u16 *)(q + 0x14 + m * 2));
            }
            j++;
            if (done == 1) break;
            t += 0x600;
            if (t >= 0x1000) { t = 0x1000; done = 1; }
        }
    }
    func_020862F0(p + 0x1f4, 0x780);
    *(u32_021D7D0C *)(p + 0x10) = 1;
    *(void **)(p + 0xc) = func_020056A0((void *)func_021D7F54, p + 0xc, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    p[0x978] = 0;
    func_02049238(arc);
    func_0203FA08(1, 0x20, 0);
    func_0203FA08(2, 0x20, 0);
    *(void **)(p + 0x984) = func_0201F5DC((void *)1, 0xd, 0, heap);
    *(void **)(p + 0x988) = func_0201F5DC((void *)2, 0xd, 0, heap);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, heap);
}


void func_021D7F54(void *unused,u8 *p) {
    if(((struct Obj03252 *)p)->f4!=0) {
        p[0x96b]^=1;
        if((p[0x96b]&1)==0) {
            func_0207E3D0(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            func_0207E468(p+0x1f0+(((struct Obj03252 *)p)->f968<<5),40,14);
            (((struct Obj03252 *)p)->f968)++;
            if(((struct Obj03252 *)p)->f968>=60) ((struct Obj03252 *)p)->f968=0;
            func_02040618(p[0x96c],2,7);
        }
    }
}


void func_021D7FC4(u8 *p) {
    u32_021D7FC4 x=((struct Obj05322 *)p)->f984;
    func_0203FB44(1,(u16)x,(u16)(x>>16));
    x=((struct Obj05322 *)p)->f988;
    func_0203FB44(2,(u16)x,(u16)(x>>16));
    if(((struct Obj05322 *)p)->fC) {
        func_02030EAC(((struct Obj05322 *)p)->fC);
        *(u32_021D7FC4 *)&((struct Obj05322 *)p)->fC=0;
        ((struct Obj05322 *)p)->f10=0;
    }
    *(u16 *)0x04000050=0;
}


void func_021D8010(void *p,u32_021D8010 a) {
 if(I(0x9a4)!=0) {func_0201CE48((void *)I(0x9a4)); I(0x9a4)=0;}
 func_02045CAC((struct MsgBank *)I(0x990),a,(void *)I(0x99c));
 func_0201F250((struct WordSet *)I(0x994),(void *)I(0x9a0),(void *)I(0x99c));
 func_02043B5C((struct CharBuf *)((u32_021D8010)func_02045770((struct Descriptor *)I(0x97c))),15);
 func_0201DD78(1,2,15);
 I(0x9a4)=(u32_021D8010)func_0201CCE4(I(0x97c),0,0,I(0x9a0),I(0x998),func_02012FFC(),I(0x9a8),2,((struct Obj22630 *)p)->f4,15);
 func_0201F73C((void *)I(0x97c),1,(u16)I(0x984),13);
 func_02045334((struct Descriptor *)I(0x97c));
}


int func_021D80CC(void *p) {
 int v;
 if(((struct Obj06418 *)p)->f9A4==0) return 1;
 v=func_0201CE30(((struct Obj06418 *)p)->f9A4);
 if(v==2) { func_0201CE48(((struct Obj06418 *)p)->f9A4); ((struct Obj06418 *)p)->f9A4=0; return 1; }
 if(v==1) { if(func_020362DC()==1 || func_02035C60()!=0) func_0201CE38(((struct Obj06418 *)p)->f9A4); }
 return 0;
}


void func_021D8118(u8 *p, u32_021D8118 i, u32_021D8118 a, u32_021D8118 b)
{
    func_0201EFA4(((struct Obj22631 *)p)->f994, i, a, b, 2, 1);
}


/*
 * The duplicated 021D8560 pool words require separate extern names;
 * see the duplicated-pool-word idiom.
 */
void func_021D8134(u8 *p) { *(u16 *)(d_021D8560+4)=((struct Obj08048 *)p)->f988; *(struct BmpMenu * *)&((struct Obj08048 *)p)->f980=func_0201FDA0((const struct WinDat *)d_021D8560_menu,((struct Obj08048 *)p)->f988,13,0,((struct Obj08048 *)p)->f4); }


u32_021D8168 func_021D8168(u8 *p) { u32_021D8168 result=-2; if(*(u8 * *)&((struct Obj10343 *)p)->f980!=0) { result=func_0201FEBC(*(u8 * *)&((struct Obj10343 *)p)->f980); if(result!=-1) *(u32_021D8168 *)&((struct Obj10343 *)p)->f980=0; } return result; }


void func_021D8190(u8 *p) { *(u8 * *)&((struct Obj10344 *)p)->f98C=func_0202EE30((void *)func_020056BC(),((struct Obj10344 *)p)->f97C,15,16,((struct Obj10344 *)p)->f4); }


void func_021D81B4(u8 *p) { if(*(u8 * *)&((struct Obj10345 *)p)->f98C!=0) { func_0202F038(*(u8 * *)&((struct Obj10345 *)p)->f98C); *(u32_021D81B4 *)&((struct Obj10345 *)p)->f98C=0; } }


void func_021D81D0(u8 *p) { func_02012DAC(((struct Obj13870 *)p)->f1844); ((struct Obj13870 *)p)->fB6A=1; }


int func_021D81EC(u8 *p) { if(((struct Obj10346 *)p)->fB6A==0) return 1; if(func_02012DD0(*(u8 * *)&((struct Obj10346 *)p)->f1844)==2) { ((struct Obj10346 *)p)->fB6A=0; return 1; } return 0; }


/*
 * volatile: hardware registers 0x04000050, 0x04001050, 0x04000000, 0x04001000 are read/written at 021D8244..021D8258 or 021D82C4..021D82DA.
 */
void *func_021D821C(int a,unsigned heap) {
 void *p;
 p=func_02030734(heap,16,0,d_021D858C,0x1bc);
 func_02082BCC(p,0,16);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 func_0204335C(0); func_020433E0((const struct DispVram *)d_021D83C0); func_0204363C(a);
 func_0204361C(); func_020434CC(); func_02043588(); func_0201DD60();
 func_021D8304(p,heap);
 ((struct Obj22632 *)p)->fC=func_020056A0((void *)func_021D82F8,p,0);
 return p;
}


void func_021D82AC(void *p) {
 func_02030EAC(((struct Obj22633 *)p)->fC); func_021D8364(p); func_0201DD68();
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 *(volatile unsigned *)0x04000000 &= 0xffff1fff;
 *(volatile unsigned *)0x04001000 &= 0xffff1fff;

 func_02082BCC(p,0,16); func_020307B0(p);
}


void func_021D82F8(void *a,void *b) {func_021D839C(b);}


void func_021D8304(void *p,unsigned heap) {
 unsigned i; char *q; unsigned n;
 func_02082BCC(p,0,4);
 func_0203F8F4(heap); func_02045088(heap); func_0203FC28((struct DispConfig *)d_021D83B0);
 for(i=0;i<8;i++) {
 q=d_021D83F0+i*44; n=((struct Obj10347 *)q)->f0;
 func_0203FCA0((u8)n,(const struct BgTemplate *)(q+4),(u8)(((struct Obj10347 *)q)->f24));
 func_020414AC(n); func_02040588(n,((struct Obj10347 *)q)->f28);
 }
}



void func_021D8364(void *a0)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        func_020403F4((u8)*(u32_021D8364 *)(g_021D83F0 + i * 0x2c));
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(a0, 0, 4);
}
