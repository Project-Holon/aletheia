/*
 * file:     intro_cmd.c
 * unit:     yes
 * function: func_021BE328, func_021BE360, func_021BE374, func_021BE398, func_021BE3A4, func_021BE3B8, func_021BE3CC, func_021BE3DC, func_021BE3EC, func_021BE420, func_021BE430, func_021BE44C, func_021BE460, func_021BE478, func_021BE4AC, func_021BE4B8, func_021BE510, func_021BE524, func_021BE54C, func_021BE560, func_021BE578, func_021BE61C, func_021BE6A4, func_021BE6B4, func_021BE6E8, func_021BE6F8, func_021BE708, func_021BE770, func_021BE78C, func_021BE7A8, func_021BE838, func_021BE864, func_021BE874, func_021BE884, func_021BE898, func_021BE970, func_021BE984, func_021BEB00, func_021BEBEC, func_021BED6C, func_021BEDB8, func_021BEE5C, func_021BEEF0, func_021BEF08, func_021BEF20, func_021BEF74, func_021BEF88, func_021BF00C, func_021BF030, func_021BF080, func_021BF094, func_021BF0A0, func_021BF1A4, func_021BF204, func_021BF228, func_021BF23C, func_021BF2D4, func_021BF2E0, func_021BF2F4, func_021BF374, func_021BF384, func_021BF4E8, func_021BF528, func_021BF538, func_021BF55C, func_021BF560, func_021BF580, func_021BF594, func_021BF5E0, func_021BF610, func_021BF624
 * address:  0x021BE328
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_02023EF4 0x02023EF4 thumb
 *   func_02024004 0x02024004 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02006148 0x02006148 thumb
 *   func_020062BC 0x020062BC thumb
 *   func_02006268 0x02006268 thumb
 *   func_020061F8 0x020061F8 thumb
 *   d_021C09D4 0x021C09D4 data a4
 *   func_021BF67C 0x021BF67C thumb ov204
 *   func_021BF7CC 0x021BF7CC thumb ov204
 *   d_021BFFE4 0x021BFFE4 data a1
 *   func_021BF720 0x021BF720 thumb ov204
 *   func_021BF744 0x021BF744 thumb ov204
 *   func_021BF77C 0x021BF77C thumb ov204
 *   func_021BF788 0x021BF788 thumb ov204
 *   func_021BF804 0x021BF804 thumb ov204
 *   func_021BF794 0x021BF794 thumb ov204
 *   func_021BD2B0 0x021BD2B0 thumb
 *   func_021BD368 0x021BD368 thumb ov088
 *   func_021BD380 0x021BD380 thumb ov088
 *   func_021BD374 0x021BD374 thumb ov088
 *   func_021BD39C 0x021BD39C thumb ov088
 *   func_021BD3A0 0x021BD3A0 thumb ov088
 *   func_020083EC 0x020083EC thumb
 *   func_0200854C 0x0200854C thumb
 *   func_02006238  0x02006238  thumb
 *   func_02006A64  0x02006A64  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_021BF864  0x021BF864  thumb ov204
 *   func_0207D63C 0x0207D63C arm
 *   func_021BFCE8 0x021BFCE8 thumb ov204
 *   func_021BFAE4 0x021BFAE4 thumb
 *   func_021BFBC8 0x021BFBC8 thumb
 *   func_021BFA40 0x021BFA40 thumb ov204
 *   func_021BFAE8 0x021BFAE8 thumb ov204
 *   func_021BFB2C 0x021BFB2C thumb ov204
 *   func_020362DC 0x020362DC arm
 *   func_021BFBA0 0x021BFBA0 thumb ov204
 *   func_020411E8 0x020411E8 arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02008550 0x02008550 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021BDD78 0x021BDD78 thumb ov204
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   init 0x021BFFCC data a2
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B6E4 0x0204B6E4 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_02030734 0x02030734 arm
 *   d_021C0AAC 0x021C0AAC data a1
 *   func_020307B0 0x020307B0 arm
 *   d_021C09D8 0x021C09D8 data a4
 *   d_021C0AB8 0x021C0AB8 data a4
 *   site 0x021C0AE4 data a1
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0203101C 0x0203101C arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02028590 0x02028590 thumb
 *   func_0202EF60 0x0202EF60 thumb
 *   func_02028604 0x02028604 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C  0x0203630C  arm
 *   func_02035C38  0x02035C38  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F898 0x0201F898 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02020D10 0x02020D10 thumb
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_020200CC 0x020200CC thumb
 *   func_020056BC 0x020056BC thumb
 *   func_0202EF98 0x0202EF98 thumb
 *   func_0202F038 0x0202F038 thumb
 *   site_021C0AF0 0x021C0AF0 data ov204
 *   func_02016024 0x02016024 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *   func_02015BA4 0x02015BA4 thumb
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02014C08 0x02014C08 thumb
 *   func_02014D2C 0x02014D2C thumb
 *   defaultPos 0x021C08F0 data ov204
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 *   func_02015CAC 0x02015CAC thumb
 */
#include "../../matched/include/Obj25350.h"
#include "../../matched/include/Obj14608.h"
#include "../../matched/include/Obj25352.h"
#include "../../matched/include/Obj10874.h"
#include "../../matched/include/Obj25353.h"
#include "../../matched/include/Obj25354.h"
#include "../../matched/include/Obj25355.h"
#include "../../matched/include/Obj25357.h"
#include "../../matched/include/Obj25359.h"
#include "../../matched/include/Obj04609.h"
#include "../../matched/include/Obj05529.h"
#include "../../matched/include/Obj25360.h"
#include "../../matched/include/Obj14612.h"
#include "../../matched/include/Obj25361.h"
#include "../../matched/include/Obj25362.h"
#include "../../matched/include/Obj05530.h"
#include "../../matched/include/Obj25363.h"
#include "../../matched/include/Obj25365.h"
#include "../../matched/include/Obj25366.h"
#include "../../matched/include/Obj08382.h"
#include "../../matched/include/Obj25369.h"
#include "../../matched/include/Obj25370.h"
#include "../../matched/include/Obj25372.h"
#include "../../matched/include/Obj25374.h"
#include "../../matched/include/Obj03920.h"
#include "../../matched/include/Obj25376.h"
#include "../../matched/include/Obj00550.h"
#include "../../matched/include/Obj06672.h"
#include "../../matched/include/Obj08383.h"
#include "../../matched/include/Obj14616.h"
#include "../../matched/include/Obj14617.h"
#include "../../matched/include/Obj25378.h"
#include "../../matched/include/Obj14618.h"
#include "../../matched/include/Obj03921.h"
#include "../../matched/include/Obj25381.h"
#include "../../matched/include/Obj25382.h"
#include "../../matched/include/Obj06673.h"
#include "../../matched/include/Obj14620.h"
#include "../../matched/include/Obj01008.h"
#include "../../matched/include/Obj01292.h"
#include "../../matched/include/Obj08384.h"
#include "../../matched/include/Obj14621.h"
#include "../../matched/include/Obj02540.h"
#include "../../matched/include/Obj25385.h"
#include "../../matched/include/Obj25386.h"
#include "../../matched/include/Obj03358.h"
#include "../../matched/include/Obj14622.h"
#include "../../matched/include/Obj10880.h"
#include "../../matched/include/Obj14623.h"
#include "../../matched/include/Obj14624.h"
#include "../../matched/include/Obj25387.h"
#include "../../matched/include/Obj25389.h"
#include "../../matched/include/Obj14625.h"
#include "../../matched/include/Obj14626.h"
#include "../../matched/include/Obj14627.h"
#include "../../matched/include/Obj25390.h"

struct Sub0200852CObj;
struct Obj;
struct Actor;
struct WordSet;
struct Q021BF00C;
struct S021BF00C;
struct State;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
struct U16Vec;
struct S02031140;
struct Rec3;
struct PrintSys;
struct Rec;
struct MsgBank;
struct Ctx;
struct Slot;
struct Src;
struct McssSys;
struct Sub150;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef enum { B_FALSE, B_TRUE } Bool;

struct S { u8 pad[0xA8]; u8 data[4096]; };

typedef struct {u16 v[12];} Init;

typedef signed int     s32;

typedef struct Row { unsigned tag; unsigned data[5]; } Row;

struct S021BF00C
{
    char pad[0x20];
    void *slots[8];
};

struct Q021BF00C
{
    char pad[0x14];
    unsigned char b : 1;
};

typedef struct Command { unsigned tag; unsigned data[5]; } Command;

typedef struct Slot { unsigned data[3]; } Slot;

typedef struct State { char pad[0x20]; Command *commands[8]; Slot slots[8]; } State;

typedef struct {
    void *arr,*b,*c,*obj;
    u16 count,rows;
    u8 f14,f15,f16;
    u8 f17lo:4,f17hi:4;
    u8 f18lo:4,f18hi:4;
    u8 f19;
    u16 f1Alo:3,f1Amid:4,f1Apad:2,f1Amid2:6,f1Atop:1;
    u32 f1c;
    u16 f20,f22;
    u32 f24;
    void *f28,*f2c,*f30;
} Config;

struct Vec { int v[3]; };

extern void func_0204E720(unsigned,int,int,int);
extern int func_0204E804(void);
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02023EF4(int, int, int, int, int);
extern int func_02024004(int a);
extern void func_02005D90(u32, u32);
extern int func_02005F38(void);
extern void func_02005E30(u32 a);
extern void func_02005DF8(u32 a);
extern void func_020061E4(unsigned),func_020062BC(int,unsigned),func_02006268(int,unsigned,unsigned,unsigned);
extern int func_02006148(unsigned);
extern void func_020061F8(int);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);
extern void func_021BF7CC(u8 *p, u8 index, int flag);
extern void func_021BF720(u8 *p, int flag, u8 index);
extern void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v);
extern unsigned func_021BF77C(char *,unsigned char);
extern void func_021BF788(u8 *p, u8 index);
extern int func_021BF804(char *p, unsigned int i, int step, int limit);
extern void func_021BF794(u8 *p, u8 index, u32 alpha);
extern void func_021BD2B0(int);
extern void func_021BD368(unsigned char *);
extern int func_021BD380(unsigned char *);
extern void func_021BD374(unsigned char *p);
extern void func_021BD39C(int);
extern int func_021BD3A0(unsigned char *p);
extern void func_020083EC(u16*,u32);
extern void func_0200854C(struct Sub0200852CObj*,u32);
extern void func_020061E4(u32);
extern int  func_02006238(void);
extern int func_02006A64(u32 idx);
extern u32 func_02006BD0(u32 i);
extern int func_021BF864(char *p, int delta, int limit);
extern void func_0207D63C(volatile void *, int, int, int, int);
extern void func_021BFCE8(u32*,u32,u32,u32);
extern void func_021BFAE4(char *p, int v);
extern void func_021BFBC8(char *p, unsigned value);
extern int func_021BFA40(char*);
extern void func_021BFAE8(char *,u32);
extern int func_021BFB2C(char *);
extern int func_021BFBA0(int *p);
extern void func_020411E8(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041B6C(u32);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void *func_020490F4(u32 id, u32 heap);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_021BDD78(char *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B688(struct Actor *actor, u32 value);
extern u32 func_0204B6E4(const struct Actor *actor);
extern void func_0201F02C(struct WordSet*,u32,void*);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02028590(u32,u32,u32,u32);
extern struct Obj *func_0202EF60(u32 heap);
extern int func_02028604(int);
extern void func_02045808(struct U16Vec *);
extern unsigned int func_0201D83C(void *ptr);
extern void func_0201CE48(struct Rec3 *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_02031140(struct S02031140 *);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_020310C4(struct Tcbl*);
extern u32 func_0201C4E4(struct PrintSys*);
extern signed char func_02012FFC(void);
extern void func_0201DD78(unsigned int, unsigned int, unsigned int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_0201CCE4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);
extern void func_0201F73C(void *, int, int, int);
extern void func_0201F7A8(void*,u32);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern unsigned int func_0203630C(void);
extern int func_02035C38(void);
extern void *func_02082BCC(void *,int,u32);
extern void *func_0201F81C(u32,u32);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern void func_02020CF8(struct Obj *p, int heap);
extern void func_020409B4(u32 index);
extern void func_02020D10(u8 *p, u32 v);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern int func_020200CC(struct Obj *);
extern u32 func_020056BC(void);
extern void func_0202EF98(u8 *,u32,u32,u8,u8);
extern void func_0202F038(u8 *);
extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *, unsigned int);
extern void func_02016024(char *p, unsigned int v);
extern void func_02015BF0(void *);
extern void func_02015BA4(void *,void *);
extern void func_02014BA8(u8 *);
extern void func_02014C08(char *);
extern void func_02014D2C(struct McssSys *);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015CAC(void *p, u32 *src);
extern void func_021BF7F0(u8 *p);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);
int func_021BE328(char *p,int *state,int *q);
u32 func_021BE360(u32 a, u32 b, u32 *c);
int func_021BE374(int a0, int a1, int *src);
int func_021BE398(void);
u32 func_021BE3A4(u32 a, u32 b, u32 *c);
u32 func_021BE3B8(void);
int func_021BE3CC(int a, int b, int *p);
int func_021BE3DC(int a, int b, int *p);
int func_021BE3EC(char *p,int *state,unsigned *q);
int func_021BE420(int a, int b, int *p);
u32 func_021BE430(void);
int func_021BE44C(char *p,int *state,unsigned *q);
int func_021BE460(char *p,int *state,int *q);
int func_021BE478(char *p,int *state,unsigned *q);
int func_021BE4AC(char *p,int *state,int *q);
int func_021BE4B8(char *p, int unused, unsigned *q);
int func_021BE510(char *p,int *state,int *q);
int func_021BE524(char *p,int *state,unsigned *q);
unsigned func_021BE53C(char *p,int *state,unsigned *q);
int func_021BE54C(char *p,int *state,unsigned *q);
int func_021BE560(char *p,int *state,int *q);
int func_021BE578(char *p, int *state, unsigned *q);
int func_021BE61C(char *p, int *state, unsigned *q);
int func_021BE6A4(char *a);
int func_021BE6B4(char *p,int *state,unsigned *q);
int func_021BE6E8(char *a);
int func_021BE6F8(char *a);
int func_021BE708(char *p, int *state);
int func_021BE770(u8*p,u32 unused,u32*q);
int func_021BE78C(u8*p,u32 unused,u32*q);
int func_021BE7A8(u8 *p, u32 *q);
int func_021BE838(u8*p,u32 unused,u32*q);
int func_021BE864(char *a, int b, int *p);
int func_021BE874(char *a, int b, int *p);
int func_021BE884(u8*p);
int func_021BE898(char *p,u32 *q);
int func_021BE970(u8*p);
int func_021BE984(struct S *p,u32 *q);
int func_021BEB00(void *p,u32 *q);
int func_021BEBEC(char *p);
int func_021BED6C(char *p);
int func_021BEDB8(char *p, unsigned *state, unsigned *q);
int func_021BEE5C(char *p, unsigned *state, unsigned *q);
int func_021BEEF0(u8*p);
void func_021BEF08(u8*p,u32 a);
char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap);
void func_021BEF74(u8*p);
int func_021BEF88(char *p);
int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q);
int func_021BF030(State *p);
void func_021BF080(char *p, u8 i);
Row *func_021BF094(u32 n);
char *func_021BF0A0(u16 heap);
void func_021BF1A4(char *p);
void func_021BF204(char *p, unsigned a, unsigned short b);
void func_021BF228(u8*p);
void func_021BF23C(char *p, void *a, int flag);
void func_021BF2D4(u8*p);
u32 func_021BF2E0(u8*p);
int func_021BF2F4(char *a);
int *func_021BF374(char *p, int v);
void func_021BF384(char *p,u32 *entries,u32 count,int flag);
void func_021BF4E8(char *p);
void func_021BF528(u8 *p);
int func_021BF538(u8 *p,int *out);
int func_021BF55C(u8 *p);
void func_021BF560(u8 *p);
void func_021BF580(u8 *p);
void *func_021BF594(unsigned int heap, int kind);
void func_021BF5E0(u8 *p);
void func_021BF610(u8 *p);
void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);
extern const char d_021BFFE4[];
extern const Init init;
extern const char d_021C0AAC[];
extern const u32 d_021C0AB8[];
extern const char site[];
extern const char site_021C0AF0[];
extern const struct Vec defaultPos;




int func_021BE328(char *p,int *state,int *q){switch(*state){case 0:func_0204E720(q[0],q[1],q[2],q[3]);(*state)++;break;case 1:if(func_0204E804()==0)return 1;break;}return 0;}





/*
 * Addresses are Black-image addresses.
 */
u32 func_021BE360(u32 a, u32 b, u32 *c)
{
    func_02023F60((s16)*c, 0x1d, 1);
    return 1;
}





int func_021BE374(int a0, int a1, int *src)
{
    func_02023EF4((unsigned char)src[0], (short)src[1], (short)src[2], 0x1d, 1);
    return 1;
}




int func_021BE398(void) {func_02024004(1);return 1;}





u32 func_021BE3A4(u32 a, u32 b, u32 *c)
{
    func_02005D90(*c, 0xffff);
    return 1;
}





u32 func_021BE3B8(void)
{
    if (func_02005F38() != 0) {
        return 1;
    }
    return 0;
}





int func_021BE3CC(int a, int b, int *p)
{
    func_02005E30((unsigned short)*p);
    return 1;
}





int func_021BE3DC(int a, int b, int *p)
{
    func_02005DF8((unsigned short)*p);
    return 1;
}




int func_021BE3EC(char *p,int *state,unsigned *q){int i;func_020061E4(q[0]);i=func_02006148(q[0]);if(q[1])func_020062BC(i,q[1]);if(q[2])func_02006268(i,-1,-1,q[2]);return 1;}





int func_021BE420(int a, int b, int *p)
{
    func_020061F8(func_02006148(*p));
    return 1;
}





u32 func_021BE430(void)
{
    if (func_02035C60() != 0 || func_020362DC() != 0) {
        return 1;
    }
    return 0;
}




int func_021BE44C(char *p,int *state,unsigned *q){func_021BF204(*(char * *)&((struct Obj25350 *)p)->f18,q[0],q[1]);return 1;}




extern int (*const d_021C09D4[])(char *,int);




int func_021BE460(char *p,int *state,int *q){d_021C09D4[q[0]](p,q[1]);return 1;}




int func_021BE478(char *p,int *state,unsigned *q){switch(*state){case 0:func_021BF23C(*(char * *)&((struct Obj14608 *)p)->f18,(void *)q[0],q[1]);(*state)++;break;case 1:if(func_021BF2F4(*(char * *)&((struct Obj14608 *)p)->f18))return 1;break;}return 0;}




int func_021BE4AC(char *p,int *state,int *q){func_021BF2D4((u8 *)(*(char * *)&((struct Obj25352 *)p)->f18));return 1;}




int func_021BE4B8(char *p, int unused, unsigned *q)
{
    if (q[1] == 0) {
        func_021BF624(((struct Obj10874 *)p)->f8, q[2], q[3], 0, (void *)d_021BFFE4, q[0]);
        func_021BF7CC(((struct Obj10874 *)p)->f8, q[0], 1);
    } else {
        func_021BF67C(((struct Obj10874 *)p)->f8, q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}




int func_021BE510(char *p,int *state,int *q){func_021BF720(((struct Obj25353 *)p)->f8,q[1],q[0]);return 1;}




/*
 * follower: tail-call stub 0x021BE53C included; function_starts seed.
 */
int func_021BE524(char *p,int *state,unsigned *q){func_021BF744(*(char * *)&((struct Obj25354 *)p)->f8,(unsigned char)q[0],q[1],q[2]);return 1;}




unsigned func_021BE53C(char *p,int *state,unsigned *q){return func_021BF77C(*(char * *)&((struct Obj25355 *)p)->f8,q[0]);}




int func_021BE54C(char *p,int *state,unsigned *q){func_021BF788((u8 *)(*(char * *)&((struct Obj25357 *)p)->f8),q[0]);return 1;}




int func_021BE560(char *p,int *state,int *q){return func_021BF804(*(char * *)&((struct Obj25359 *)p)->f8,(unsigned char)q[0],q[1],q[2]);}




int func_021BE578(char *p, int *state, unsigned *q)
{
    switch (*state) {
    case 0:
        if (q[1] != 0)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)1);
        else
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
        func_021BF720(((struct Obj04609 *)p)->f8, 1, q[0]);
        state[1] = 31;
        ++*state;
        break;
    case 1:
        state[1] -= 2;
        if (state[1] <= 0) {
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
            func_021BF720(((struct Obj04609 *)p)->f8, q[1], q[0]);
            return 1;
        }
        if (q[1] == 1)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)(31 - state[1]));
        else if (q[1] == 0)
            func_021BF794(((struct Obj04609 *)p)->f8, q[0], (unsigned char)state[1]);
        break;
    }
    return 0;
}




int func_021BE61C(char *p, int *state, unsigned *q)
{
    unsigned index = q[0];
    unsigned other = q[1];
    switch (*state) {
    case 0:
        func_021BF23C(((struct Obj05529 *)p)->f18, (void *)index, q[2]);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(((struct Obj05529 *)p)->f18) != 0) {
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, 1);
            return 1;
        }
        switch (func_021BF2E0(((struct Obj05529 *)p)->f18)) {
        case 1:
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, 1);
            state[1] = 0;
            break;
        case 0:
            func_021BF7CC(((struct Obj05529 *)p)->f8, other, state[1] % 12 < 6 ? 1 : 0);
            state[1]++;
            break;
        case 2:
            break;
        }
        break;
    }
    return 0;
}





int func_021BE6A4(char *a)
{
    func_021BD2B0(((struct Obj25360 *)a)->fA4);
    return 1;
}




int func_021BE6B4(char *p,int *state,unsigned *q){switch(*state){case 0:func_021BD368(*(unsigned char * *)&((struct Obj14612 *)p)->fA4);(*state)++;break;case 1:if(func_021BD380(*(unsigned char * *)&((struct Obj14612 *)p)->fA4)==1)return 1;break;}return 0;}





int func_021BE6E8(char *a)
{
    func_021BD374((unsigned char *)(((struct Obj25361 *)a)->fA4));
    return 1;
}





/*
 * UNBLOCKED: 0x021BD39C is now an EXACT entry in layout/matched/ov088 (the
 * only overlay in the window that does not overlap the caller's ov204), so
 * the bl site resolves as matched and the verdict promoted to EXACT.
 */
int func_021BE6F8(char *a)
{
    func_021BD39C(((struct Obj25362 *)a)->fA4);
    return 1;
}




int func_021BE708(char *p, int *state)
{
    switch (*state) {
    case 0:
        if (func_021BD3A0(((struct Obj05530 *)p)->fA4) == 1)
            return 1;
        func_021BF23C(((struct Obj05530 *)p)->f18, (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(((struct Obj05530 *)p)->f18) == 1) {
            func_021BF560(((struct Obj05530 *)p)->f18);
            ++*state;
        }
        break;
    case 2:
        if (func_021BD3A0(((struct Obj05530 *)p)->fA4) == 1) {
            func_021BF580(((struct Obj05530 *)p)->f18);
            return 1;
        }
        break;
    }
    return 0;
}




int func_021BE770(u8*p,u32 unused,u32*q){u16*obj=*(u16* *)&((struct Obj25365 *)(*(u8* *)&((struct Obj25363 *)p)->f4))->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_020083EC(obj,flag);return 1;}




/*
 * prototype: 0200854C widened to u32: original has no byte truncation; its u8 prototype added a shift pair.
 */
int func_021BE78C(u8*p,u32 unused,u32*q){struct Sub0200852CObj*obj=**(struct Sub0200852CObj** *)&((struct Obj25366 *)p)->f4;Bool flag;if(*q==0)flag=B_FALSE;else flag=B_TRUE;func_0200854C(obj,flag);return 1;}





int func_021BE7A8(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (q[1] == 3) {
            q[1] = 0;
            (*q)++;
        } else {
            q[1] = q[1] + 1;
        }
        break;
    case 1:
        if (func_021BF864((char *)(((struct Obj08382 *)p)->f8), 0x1000, 0xFFFF4800) == 1) {
            func_020061E4(0x7F5);
            (*q)++;
        }
        break;
    case 2:
        if (func_02006238() == 0) {
            func_021BF744((char *)(((struct Obj08382 *)p)->f8), 1, 0, 1);
            func_02006A64(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10));
            (*q)++;
        }
        break;
    case 3:
        if (func_02006BD0(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10)) == 0) {
            *q = 0;
            return 1;
        }
        break;
    }
    return 0;
}




int func_021BE838(u8*p,u32 unused,u32*q){func_0207D63C((void*)0x04000050,1,9,0,0);func_021BFCE8(*(u32* *)&((struct Obj25369 *)p)->f10,q[0],q[1],0);return 1;}





int func_021BE864(char *a, int b, int *p)
{
    func_021BFAE4((char *)(((struct Obj25370 *)a)->fC), *p);
    return 1;
}





int func_021BE874(char *a, int b, int *p)
{
    func_021BFBC8((char *)(((struct Obj25372 *)a)->fC), *p);
    return 1;
}




int func_021BE884(u8*p){if(func_021BFA40(*(char* *)&((struct Obj25374 *)p)->fC))return 1;return 0;}




/*
 * lever: load the case-2 object once before q[1]'s comparison and reuse
 *   it in both arms; repeated arm loads gave 220 bytes/80 different.
 */
int func_021BE898(char *p,u32 *q)
{
    void *obj;
    switch (*q) {
    case 0:
        func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,0);
        *q=4;
        break;
    case 1:
        if (func_020362DC()&16) {
            if (q[1]!=1) {
                func_020061E4(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,2);
                q[1]=1;
                *q=4;
            }
        } else if (func_020362DC()&32) {
            if (q[1]!=0) {
                func_020061E4(0x548);
                func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,1);
                q[1]=0;
                *q=4;
            }
        } else if (func_020362DC()&1) {
            func_020061E4(0x54D);
            (*q)++;
        }
        break;
    case 2:
        obj=**(void ** *)&((struct Obj03920 *)p)->f4;
        if (q[1]==0) {
            func_0200854C(obj,0);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,3);
        } else {
            func_0200854C(obj,1);
            func_021BFAE8(*(char * *)&((struct Obj03920 *)p)->fC,4);
        }
        (*q)++;
        break;
    case 3:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) return 1;
        break;
    case 4:
        if (func_021BFB2C(*(char * *)&((struct Obj03920 *)p)->fC)!=0) *q=1;
        break;
    }
    return 0;
}





int func_021BE970(u8*p){if(func_021BFBA0((int *)(*(char* *)&((struct Obj25376 *)p)->fC)))return 1;return 0;}





/*
 * lever: unsigned integer p+0xA8 at the first paired call, member address
 *   at the second, keeps equivalent addresses apart; pointer-only was 364
 *   bytes/275 different, this spelling EXACT380 (existing distinct-arithmetic idiom).
 */
int func_021BE984(struct S *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02040588(2,1);
        func_020411E8(2,0,8,64,2,(u32)p->data,0,8,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        func_020411E8(2,0,7,64,1,(u32)p+0xA8,0,7,64,32);
        func_020411E8(2,0,10,64,1,(u32)p->data,0,10,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        func_020411E8(2,0,6,64,1,(u32)p+0xA8,0,6,64,32);
        func_020411E8(2,0,11,64,1,(u32)p->data,0,11,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        func_020411E8(2,0,5,64,1,(u32)p+0xA8,0,5,64,32);
        func_020411E8(2,0,12,64,1,(u32)p->data,0,12,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_020411E8(2,0,4,64,1,(u32)p+0xA8,0,4,64,32);
        func_020411E8(2,0,13,64,1,(u32)p->data,0,13,64,32);
        func_02041B6C(2);
        *q=0;
        return 1;
    }
    return 0;
}





/*
 * extent: two bytes of zero alignment at 0x021BEBEA.
 */
int func_021BEB00(void *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02041300(2,0,0,7,64,1,0);
        func_02041300(2,0,0,16,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        func_02041300(2,0,0,8,64,1,0);
        func_02041300(2,0,0,15,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        func_02041300(2,0,0,6,64,1,0);
        func_02041300(2,0,0,14,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        func_02041300(2,0,0,5,64,1,0);
        func_02041300(2,0,0,13,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_02040588(2,0);
        *q=0;
        return 1;
    }
    return 0;
}





int func_021BEBEC(char *p)
{
    Init local;
    void *arc;
    u32 i;
    char *row;
    arc=func_020490F4(170,((struct Obj00550 *)p)->f0);
    if(func_02008550(**(void ** *)&((struct Obj00550 *)p)->f4)==0){
        ((struct Obj00550 *)p)->f10B4=(void *)func_0204A6C8(arc,6,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)func_0204ABF0(arc,7,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)func_0204AF28(arc,5,4,((struct Obj00550 *)p)->f0);
    }else{
        ((struct Obj00550 *)p)->f10B4=(void *)func_0204A6C8(arc,10,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)func_0204ABF0(arc,11,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)func_0204AF28(arc,9,8,((struct Obj00550 *)p)->f0);
    }
    ((struct Obj00550 *)p)->f10B8=(void *)func_0204A6C8(arc,17,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C4=(void *)func_0204ABF0(arc,18,0,32,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D0=(void *)func_0204AF28(arc,16,15,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10BC=(void *)func_0204A6C8(arc,21,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C8=(void *)func_0204ABF0(arc,22,0,64,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D4=(void *)func_0204AF28(arc,20,19,((struct Obj00550 *)p)->f0);
    func_02049238(arc);
    local=init;
    for(i=0;i<3;i++){
        row=p+i*4;
        ((struct Obj06672 *)row)->f10A8=func_0204B294((void *)func_021BDD78(((struct Obj00550 *)p)->f14),(unsigned int)((struct Obj06672 *)row)->f10B4,(unsigned int)((struct Obj06672 *)row)->f10C0,(unsigned int)((struct Obj06672 *)row)->f10CC,(char *)&local+i*8,0,((struct Obj00550 *)p)->f0);
        func_0204B3DC(((struct Obj06672 *)row)->f10A8,0);
    }
    return 1;
}





int func_021BED6C(char *p)
{
    unsigned i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        func_0204A8D4(((struct Obj08383 *)q)->f10B4);
        func_0204ADA4(((struct Obj08383 *)q)->f10C0);
        func_0204AFD8(((struct Obj08383 *)q)->f10CC);
        func_0204B3B4(((struct Obj08383 *)q)->f10A8);
    }
    return 1;
}





static inline void change_alpha(int a, int b)
{
    *(volatile unsigned short *)0x04000052 = (unsigned short)(a | (b << 8));
}





int func_021BEDB8(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 0, 16);
        func_0204B688(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        func_0204B3DC(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            if (func_0204B6E4(((struct Obj14616 *)row)->f10A8) == 1)
                func_0204B688(((struct Obj14616 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(*state, 16 - *state);
        break;
    }
    return 0;
}





/*
 * volatile: hardware BLDALPHA write at 021BEEDC.
 */
int func_021BEE5C(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 16, 0);
        for (i = 0; i < 3; i++)
            func_0204B688(*(void **)(p + 0x10a8 + i * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            func_0204B688(((struct Obj14617 *)row)->f10A8, 0);
            func_0204B3DC(((struct Obj14617 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(16 - *state, *state);
        break;
    }
    return 0;
}





int func_021BEEF0(u8*p){if(!func_02008550(**(struct Sub0200852CObj** *)&((struct Obj25378 *)p)->f4))return 1;return 0;}





void func_021BEF08(u8*p,u32 a){struct WordSet*q=(struct WordSet *)func_021BF55C(*(u8* *)&((struct Obj14618 *)p)->f18);func_0201F02C(q,a,**(void** *)&((struct Obj14618 *)p)->f4);}





char *func_021BEF20(void *a, unsigned b, unsigned c, char *d, unsigned e, unsigned short heap)
{
    char *p = func_02030734(heap, 0x10d8, 1, d_021C0AAC, 0x6f2);
    ((struct Obj03921 *)p)->f0 = heap;
    *(char * *)&((struct Obj03921 *)p)->f4 = d;
    ((struct Obj03921 *)p)->f8 = c;
    ((struct Obj03921 *)p)->fC = a;
    ((struct Obj03921 *)p)->f10 = b;
    ((struct Obj03921 *)p)->f14 = e;
    ((struct Obj03921 *)p)->fA4 = ((struct Obj25381 *)d)->fC;
    ((struct Obj03921 *)p)->f18 = func_021BF0A0(heap);
    return p;
}





void func_021BEF74(u8*p){func_021BF1A4(*(char* *)&((struct Obj25382 *)p)->f18);func_020307B0(p);}





extern int (*const d_021C09D8[])(void *, void *, void *);





int func_021BEF88(char *p)
{
    func_021BF228(((struct Obj06673 *)p)->f18);
    if (func_021BF030((struct State *)p) == 0) {
        char *base = p;
        int i;
        base += 0x40;
        for (i = 0; i < 9; i++) {
            Row *row = func_021BF094(((struct Obj06673 *)p)->f1C) + ((struct Obj06673 *)p)->fA0;
            if (row->tag == 1) {
                d_021C09D8[row->tag](p, base + i * 12, row->data);
                row = func_021BF094(((struct Obj06673 *)p)->f1C);
            }
            if (row->tag == 0x34)
                return 0;
            ++((struct Obj06673 *)p)->fA0;
            if (!func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)row))
                break;
        }
    }
    return 1;
}






int func_021BF00C(struct S021BF00C *p, struct Q021BF00C *q)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (p->slots[i] == 0)
        {
            p->slots[i] = q;
            break;
        }
    }
    return q->b;
}



extern int (*const d_021C09D8[])(void *, void *, void *);



int func_021BF030(State *p)
{
    int result = 0;
    int i;
    for (i = 0; i < 8; i++) {
        Command *q = p->commands[i];
        if (q) {
            if (!d_021C09D8[q->tag](p, &p->slots[i], q->data)) result = 1;
            else func_021BF080((char *)p, i);
        }
    }
    return result;
}




void func_021BF080(char *p, u8 i)
{
    char *q;

    *(int *)(p + i * 4 + 0x20) = 0;
    q = p + i * 0xC;
    ((struct Obj14620 *)q)->f40 = 0;
    ((struct Obj14620 *)q)->f44 = 0;
}



Row *func_021BF094(u32 n){return *(Row **)((u32)d_021C0AB8+n*4);}



char *func_021BF0A0(u16 heap)
{
    char *p;
    void *obj;
    p=func_02030734(heap,72,1,site,129);
    ((struct Obj01008 *)p)->f0=heap;
    ((struct Obj01008 *)p)->f8=func_0201EC64(heap);
    ((struct Obj01008 *)p)->f4=(void *)func_0201C440((void *)heap);
    ((struct Obj01008 *)p)->f18=func_0203101C(((struct Obj01008 *)p)->f0,((struct Obj01008 *)p)->f0,2,0);
    func_02049B40(23,5,0,320,32,heap);
    func_0201F5BC(1,7,9,0,heap);
    func_0201F5BC(1,16,8,1,heap);
    ((struct Obj01008 *)p)->f10=func_0201D7EC(23,0,1,0,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f3C=func_020457B0(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f40=func_020457B0(1600,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f38=(void *)func_020450F0(1,22,13,9,4,10,1);
    func_02043B5C(func_02045770(((struct Obj01008 *)p)->f38),0);
    obj=((struct Obj01008 *)p)->f38;
    func_02045334(obj);func_02045374(obj);func_02041B6C(func_02045730(obj));
    ((struct Obj01008 *)p)->f1C=(void *)func_020450F0(1,1,19,30,4,10,1);
    ((struct Obj01008 *)p)->f20=func_02028590(15,1,1,((struct Obj01008 *)p)->f0);
    ((struct Obj01008 *)p)->f44=func_0202EF60(((struct Obj01008 *)p)->f0);
    return p;
}



void func_021BF1A4(char *p)
{
    func_021BF580((u8 *)p);
    func_02028604(((struct Obj01292 *)p)->f20);
    func_02045808(*(struct U16Vec * *)&((struct Obj01292 *)p)->f3C);
    func_02045808(*(struct U16Vec * *)&((struct Obj01292 *)p)->f40);
    func_0201D83C(((struct Obj01292 *)p)->f10);
    if (((struct Obj01292 *)p)->f14 != 0)
        func_0201CE48((struct Rec3 *)(((struct Obj01292 *)p)->f14));
    func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f1C);
    if (((struct Obj01292 *)p)->f38)
        func_020452E8(*(struct Descriptor * *)&((struct Obj01292 *)p)->f38);
    func_02031140(*(struct S02031140 * *)&((struct Obj01292 *)p)->f18);
    func_0201C4C0(((struct Obj01292 *)p)->f4);
    if (((struct Obj01292 *)p)->fC)
        func_02045C04(((struct Obj01292 *)p)->fC);
    func_0201ED04(((struct Obj01292 *)p)->f8);
    func_020307B0(p);
}



void func_021BF204(char *p, unsigned a, unsigned short b)
{
    if (((struct Obj08384 *)p)->fC != 0)
    {
        func_02045C04(((struct Obj08384 *)p)->fC);
    }
    ((struct Obj08384 *)p)->fC = func_02045B38(a, 2, b, ((struct Obj08384 *)p)->f0);
}


void func_021BF228(u8*p){func_020310C4(*(struct Tcbl* *)&((struct Obj14621 *)p)->f18);func_0201C4E4(*(struct PrintSys* *)&((struct Obj14621 *)p)->f4);}



/*
 * Caller consumes 0201CCE4's live r0 result; return declared pointer despite callee's void source.
 */
void func_021BF23C(char *p, void *a, int flag)
{
    unsigned int value = func_02012FFC();
    void *desc = ((struct Obj02540 *)p)->f1C;
    func_02043B5C(func_02045770(desc), 15);
    func_0201DD78(1, 2, 15);
    func_02045CAC(((struct Obj02540 *)p)->fC, (unsigned int)a, ((struct Obj02540 *)p)->f3C);
    func_0201F250(((struct Obj02540 *)p)->f8, ((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f3C);
    ((struct Obj02540 *)p)->f14 = func_0201CCE4((unsigned int)desc, 4, 0, *(unsigned int *)&((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f10, value, ((struct Obj02540 *)p)->f18, 0xFFFF, ((struct Obj02540 *)p)->f0, 15);
    if (flag == 0)
        func_0201F73C(desc, 1, 7, 9);
    else
        func_0201F73C(desc, 1, 16, 8);
    func_02045334(desc);
    func_02045374(desc);
    func_02041B6C(func_02045730(desc));
}


void func_021BF2D4(u8*p){func_0201F7A8(*(void* *)&((struct Obj25385 *)p)->f1C,0);}


u32 func_021BF2E0(u8*p){u32 a=((struct Obj25386 *)p)->f14;if(a==0){return 2;}else{return func_0201CE30((void *)a);}}



int func_021BF2F4(char *a)
{
    if (((struct Obj03358 *)a)->f14 != 0) {
        func_020286C4((struct Ctx *)(((struct Obj03358 *)a)->f20), (void *)(((struct Obj03358 *)a)->f14),
                      (void *)(((struct Obj03358 *)a)->f1C));

        switch (func_0201CE30((void *)(((struct Obj03358 *)a)->f14))) {
        case 2:
            func_0201CE48((struct Rec3 *)(((struct Obj03358 *)a)->f14));
            ((struct Obj03358 *)a)->f14 = 0;
            return 1;
        case 1:
            if (func_020362DC() == 1 || func_020362DC() == 2
                || func_02035C60() != 0) {
                func_0201CE38((void *)(((struct Obj03358 *)a)->f14));
                func_020061E4(0x547);
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || func_02035C38() != 0)
                func_0201CE5C((struct Rec *)(((struct Obj03358 *)a)->f14), 0);
            break;
        }
        return 0;
    }
    return 0;
}



int *func_021BF374(char *p, int v)
{
    ((struct Obj14622 *)p)->f30 = v;
    ((struct Obj14622 *)p)->f34 = 0;
    return (int *)(p + 0x30);
}


/*
 * Owner unit_02045C44.c omits func_02045CAC from function:; singleton TU
 * --suggest-split leaves this caller out. the integrator owns that unit.
 * prior fixed-flag ARM9-45CAC.log, using the owner's unit declarations:
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *   u32 size; struct MsgEntry *e;
 *   if (index >= bank->file->count) { func_0204581C(dest); return; }
 *   func_02046180(bank);
 *   if (bank->resident == 0) {
 *     u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *     func_0204960C(bank->stream, pos + (index * 8 + 4));
 *     func_020495F4(bank->stream, 8, &bank->cache); e = &bank->cache;
 *   } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *   if (bank->resident == 0) {
 *     void *buf; size = e->len * 2;
 *     buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                       size, 0, g_020A7E8C, 0xd6);
 *     if (buf != 0) {
 *       func_0204960C(bank->stream, e->off + (bank->origin
 *                     + bank->file->langOff[bank->langIndex]));
 *       func_020495F4(bank->stream, size, buf);
 *       func_02045A00(dest, buf, e->len); func_020307B0(buf);
 *     }
 *   } else { func_02045A00(dest, (u8 *)bank->base + e->off, e->len); }
 *   func_02045E04(dest, index);
 * }
 * lever: u16 heap local places its word home at sp+8; u32 swaps it with
 * the entry pointer at sp+12, leaving seven differing concrete bytes.
 */
void func_021BF384(char *p,u32 *entries,u32 count,int flag)
{
    Config config;
    char *state;
    void *obj;
    u16 heap;
    u32 i;
    state=p+36;
    heap=*(u16 *)p;
    obj=*(void **)(p+56);
    func_02082BCC(state,0,12);
    *(void **)(state+4)=func_0201F81C(count,heap);
    for(i=0;i<count;i++){
        func_02045CAC(*(void **)(p+12),*(u32 *)((char *)entries+i*8),*(void **)(p+60));
        func_0201F898((struct Slot *)((char *)*(void **)(state+4)+i*8),*(u32 *)(p+60),*(u32 *)((char *)entries+i*8+4),heap);
    }
    func_02082BCC(&config,0,52);
    config.arr=*(void **)(state+4);config.obj=obj;
    config.count=count;config.rows=5;config.f14=0;config.f15=16;config.f16=0;
    config.f17lo=2;config.f17hi=1;config.f18lo=15;config.f18hi=2;
    config.f1Alo=0;config.f1Amid=0;config.f1Apad=1;config.f1Amid2=0;config.f1Atop=0;
    config.f1c=0;config.f20=16;config.f22=16;config.f24=0;
    config.f28=func_021BF374(p,(int)obj);config.f2c=*(void **)(p+4);config.f30=*(void **)(p+16);
    *(void **)state=func_0201FF30((struct Src *)(&config),0,0,heap);
    func_02020CF8(*(void **)state,(u32)heap);
    func_02045334(obj);func_02045374(obj);func_020409B4((u8)func_02045730(obj));
    func_0201F73C(obj,1,7,9);
    if(flag)func_02020D10(*(void **)state,0);
    else func_02020D10(*(void **)state,1);
}



/*
 * Trailing two bytes are zero alignment padding.
 */
void func_021BF4E8(char *p)
{
    char *block = p + 0x24;
    func_0201F7A8(((struct Obj10880 *)p)->f38, 0);
    func_02043B5C(func_02045770(((struct Obj10880 *)p)->f38), 0);
    func_02045334(((struct Obj10880 *)p)->f38);
    func_0202020C(((struct Obj14623 *)block)->f0, 0, 0);
    func_0201F868(((struct Obj14623 *)block)->f4);
    func_02082BCC(block, 0, 12);
}


void func_021BF528(u8 *p)
{
    u8 *q=p+36;
    ((struct Obj14624 *)q)->f8=func_020200CC(*(struct Obj * *)&((struct Obj14624 *)q)->f0);
}



/*
 * lever: A switch with -1 before -2 preserves the outlined return order.
 */
int func_021BF538(u8 *p,int *out)
{
    int v=((struct Obj25387 *)p)->f2C;
    switch(v){case -1:return 0;case -2:return 2;}
    if(out!=0)*out=v;
    return 1;
}



int func_021BF55C(u8 *p)
{
    return ((struct Obj25389 *)p)->f8;
}


void func_021BF560(u8 *p)
{
    func_0202EF98(*(u8 * *)&((struct Obj14625 *)p)->f44,func_020056BC(),((struct Obj14625 *)p)->f1C,15,16);
}


void func_021BF580(u8 *p)
{
    if(*(u8 * *)&((struct Obj01292 *)p)->f44!=0){func_0202F038(*(u8 * *)&((struct Obj01292 *)p)->f44);*(u8 * *)&((struct Obj01292 *)p)->f44=0;}
}



void *func_021BF594(unsigned int heap, int kind)
{
    char *p = func_02030734(heap, 108, 1, site_021C0AF0, 98);
    *(void **)(p + 4) = func_02014B08(8, (void *)heap);
    *(unsigned short *)p = heap;
    if (kind != 7)
        func_02016020(*(void **)(p + 4), 7 << 16);
    func_02016024(*(void **)(p + 4), 1 << 14);
    func_02015BF0(*(void **)(p + 4));
    return p;
}


void func_021BF5E0(u8 *p)
{
    int i;
    for(i=0;i<8;i++)if(*(void **)((u32)p+(u32)i*12+8)!=0)func_02015BA4(((struct Obj14626 *)p)->f4,*(void **)((u32)p+(u32)i*12+8));
    func_02014BA8(*(u8 * *)&((struct Obj14626 *)p)->f4);
    func_020307B0(p);
}


void func_021BF610(u8 *p)
{
    func_02014C08(*(char * *)&((struct Obj14627 *)p)->f4);
    func_02014D2C(*(struct McssSys * *)&((struct Obj14627 *)p)->f4);
}



/*
 * Enum zero preserves the clear before the indexed base add.
 */
void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i)
{
    struct Vec pos = defaultPos;
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    *(void **)(base + off) = func_020159C8(((struct Obj25390 *)p)->f4, a, b, c, d);
    func_02015CAC(*(void **)(base + off), (u32 *)(&pos));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = 1;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}
