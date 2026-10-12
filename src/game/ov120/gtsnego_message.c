/*
 * file:     gtsnego_message.c
 * unit:     yes
 * function: func_021D6A9C, func_021D6AC0, func_021D6AF0, func_021D6B5C, func_021D6B84, func_021D6BB0, func_021D6C64, func_021D6C7C, func_021D6CCC, func_021D6D10, func_021D6D48, func_021D6D94, func_021D6E1C, func_021D6E50, func_021D6E70, func_021D6E84, func_021D6ED8, func_021D6EF4, func_021D6FB4, func_021D6FD8, func_021D6FF8, func_021D7020, func_021D702C, func_021D70C8, func_021D70F0, func_021D7128, func_021D7190, func_021D71B8, func_021D71E8, func_021D7220, func_021D7260, func_021D72A0, func_021D72C8, func_021D72E8, func_021D733C, func_021D7374, func_021D73B0, func_021D73D8, func_021D7484, func_021D74B0, func_021D7550, func_021D75F4, func_021D761C, func_021D7710, func_021D7724, func_021D7858, func_021D7898, func_021D79F4, func_021D7A74, func_021D7AF4, func_021D7B38, func_021D7B60, func_021D7C10, func_021D7C1C, func_021D7C48, func_021D7CD4, func_021D7CE8, func_021D7D30, func_021D7D3C, func_021D7D6C, func_021D7DC8, func_021D7E88, func_021D7E9C, func_021D7EB0, func_021D7EC4, func_021D7ECC, func_021D7F5C, func_021D7FD0, func_021D80D4, func_021D8118, func_021D81E0, func_021D822C, func_021D824C, func_021D82A8, func_021D82D8, func_021D82F8, func_021D8358, func_021D8418, func_021D8430, func_021D846C, func_021D8484, func_021D8520, func_021D8590, func_021D8638, func_021D8648, func_021D8664, func_021D8684, func_021D8784, func_021D880C
 * address:  0x021D6A9C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   data_021D8B73 0x021D8B73 data
 *   func_0204B898 0x0204B898 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021D698C 0x021D698C thumb ov120
 *   func_021D692C 0x021D692C thumb ov120
 *   func_021D6810 0x021D6810 thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0  0x020307B0  arm
 *   func_02042FB0 0x02042FB0 arm
 *   func_021D4F70 0x021D4F70 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   func_02049990 0x02049990 arm
 *   d_021D892C 0x021D892C data a2
 *   d_021D8924 0x021D8924 data a2
 *   d_021D893C 0x021D893C data a2
 *   d_021D8934 0x021D8934 data a2
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_02040618 0x02040618 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02008554 0x02008554 thumb
 *   func_0204B454 0x0204B454 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fgeq 0x0209BB54 arm
 *   _ffix 0x0209C494 arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_02043534 0x02043534 arm
 *   d_021D8AB0 0x021D8AB0 data a4
 *   func_0204B908 0x0204B908 arm
 *   func_02040588 0x02040588 arm
 *   func_02051C6C  0x02051C6C  arm
 *   s_021D8BEC 0x021D8BEC data a1
 *   func_02030734 0x02030734 arm
 *   func_02045088 0x02045088 arm
 *   func_0203101C 0x0203101C arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02028178 0x02028178 thumb
 *   func_0202DBC4 0x0202DBC4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020362DC 0x020362DC arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02051C88 0x02051C88 arm
 *   func_02045730 0x02045730 arm
 *   func_02051B84 0x02051B84 arm
 *   d_021D8AF8 0x021D8AF8 data a4
 *   d_021D8BD8 0x021D8BD8 data a2
 *   d_021D8BE0 0x021D8BE0 data a2
 *   d_021D8B04 0x021D8B04 data a4
 *   func_0204581C 0x0204581C arm
 *   func_02045760 0x02045760 arm
 *   func_02045788 0x02045788 arm
 *   func_02027858  0x02027858  thumb
 *   func_021D60FC 0x021D60FC thumb ov120
 *   func_0202DB0C 0x0202DB0C thumb
 *   func_0202DC08  0x0202DC08  thumb
 *   d_021D8B20 0x021D8B20 data ov120 a4
 *   func_020355C4 0x020355C4 arm
 *   d_021D8AF0 0x021D8AF0 data a4
 *   func_0202822C  0x0202822C  thumb
 *   func_02028230 0x02028230 thumb
 */
#include "ov120_types.h"
#include "../../matched/include/Obj05353.h"

struct Obj;
struct Actor;
struct Vec2;
struct Sub0200852CObj;
struct PtS;
struct Cmd;
struct GfFont;
struct R;
struct Tcbl;
struct U16Vec;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct Cfg;
struct CharBuf;
struct TaskMenu;
struct TaskMenuTmpl;
struct Ctx;
struct StrObj;
struct PmsDraw;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct PosRecord {u16 x,y,z;u8 a,b;} PosRecord;

typedef signed int     s32;


typedef struct Triple { u16 a[3]; } Triple;


typedef signed short s16_021D6FB4;

typedef signed short s16_021D6FD8;

typedef signed short s16_021D6FF8;

typedef signed short s16_021D7020;

typedef signed short s16_021D70C8;

typedef signed short s16_021D70F0;


typedef signed short s16_021D7190;

typedef struct { s16_021D7190 x, y; } Vec;

typedef signed short s16_021D71B8;

typedef signed short s16_021D71E8;

typedef signed short s16_021D72A0;

typedef signed short s16_021D72C8;

typedef signed short s16_021D733C;

typedef signed short s16_021D7374;

typedef struct Pt { s16_021D7374 x,y; } Pt;

typedef signed short s16_021D73B0;


typedef struct Callback { u16 n; u8 *p; void (*f)(u8 *); } Callback;

typedef signed short s16_021D7484;

typedef struct Table { u32 a[16]; } Table;

typedef signed short s16_021D75F4;

typedef signed short   s16_021D79F4;

typedef signed short   s16_021D7A74;

typedef signed short s16_021D7B38;

typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;

typedef signed short s16_021D7C10;

typedef signed short s16_021D7C1C;

typedef signed short s16_021D7C48;

typedef signed short   s16_021D7CE8;

typedef signed short s16_021D7D30;

typedef signed short s16_021D7D3C;

typedef signed short s16_021D7EC4;

typedef signed short   s16_021D7F5C;

typedef short s16_021D7FD0;

typedef short s16_021D8118;

typedef signed short s16_021D822C;

typedef signed short s16_021D82A8;

typedef struct { int a, b; } Pair;

typedef signed short   s16_021D8520;

typedef short s16_021D8684;

typedef signed short   s16_021D8784;

extern void func_0204B878(struct Obj *p, u16 value);
extern u16 func_0204B898(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_021D698C(u8 *);
extern void func_021D692C(u8 *, int);
extern void func_021D6810(u8 *, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *);
extern u32 func_020307B0(void *p);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void *func_021D4F70(void **p, int i);
extern void func_02041B6C(u32 bit);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_0204B9A0(struct Actor *a);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020409B4(u32);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int _s32_div_f(int, int);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_02043534(u32);
extern void func_0204B908(int a0, int a1);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02051C6C(void *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_0201F5DC(void *,u32,u32,u32);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_0201DD78(u32, u32, u32);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02028178(u8 *p);
extern void func_0202DBC4(u8 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_0201DD68(void);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02028148(u8 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *x, s16_021D79F4 y, s16_021D79F4 z, void *s, void *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u32 func_0201CE30(void *p);
extern void func_0201CE38(void *);
extern u32 func_020362DC(void);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(struct Descriptor *d);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern s32 func_02051C88(struct Ctx *c);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 *func_0202800C(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_02025C1C(u32,u32,u32);
extern u32 func_02025C30(u32,u32,u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0204581C(struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 func_02045760(struct Descriptor *p);
extern void func_02045788(struct Descriptor *p, u8 v);
extern void func_02027858(struct TaskMenu *m);
extern u32 func_021D60FC(u8 *p);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0202DC08(struct Obj *p);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern void func_0202DE64(struct PmsDraw *p, u16 v);
extern void func_0202DC60(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern u8 func_020355C4(void);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_0202822C(char *p, int v);
extern u32 func_02028230(u8 *p);
int func_021D6A9C(struct GtsnegoMsgCtx *p,u32 n);
int func_021D6AC0(struct GtsnegoMsgCtx *p);
void func_021D6AF0(u8 *p,u16 x,u16 y,int flag);
void func_021D6B5C(u8 *p);
void func_021D6B84(u8 *p,u32 n);
void func_021D6BB0(u8 *p, int n);
void func_021D6C64(u8 *p);
void func_021D6C7C(struct GtsnegoMsgCtx *p, int n);
void func_021D6CCC(struct GtsnegoMsgCtx *p, int n);
void func_021D6D10(struct GtsnegoMsgCtx *p,void *list,int first);
void func_021D6D48(u8 *p);
void func_021D6D94(u8 *p);
int func_021D6E1C(void *unused,int *p);
int func_021D6E50(void *unused,int *p);
void func_021D6E70(void *unused, int *p, int n);
void func_021D6E84(u8 *p);
void func_021D6ED8(u8 *p);
void func_021D6EF4(u8 *p,int flag);
void func_021D6FB4(u8 *p);
void func_021D6FD8(struct GtsnegoMsgCtx *p, u32 flag);
void func_021D6FF8(struct GtsnegoMsgCtx *p, int state);
void func_021D7020(struct GtsnegoMsgCtx *p);
int func_021D702C(u8 *p, int *out);
void func_021D70C8(u8 *p, int flag);
void func_021D70F0(void *a0);
void func_021D7128(u8 *p, int n, int k);
void func_021D7190(u8 *p, int index, int x, int y);
void func_021D71B8(u8 *p, void *entry, int index);
void func_021D71E8(u8 *p, int index, int delta);
void func_021D7220(u8 *p, void *q);
void func_021D7260(u8 *p, void *q);
void func_021D72A0(u8 *p, void *container, int offset);
int func_021D72C8(struct GtsnegoMsgCtx *p, int index, int count);
int func_021D72E8(struct GtsnegoMsgCtx *p, int n, int count);
void func_021D733C(struct GtsnegoMsgCtx *p, int index, int count);
int func_021D7374(struct GtsnegoMsgCtx *p,int y,int count);
void func_021D73B0(char *p);
void func_021D73D8(u8 *p);
void func_021D7484(char *p);
void func_021D74B0(struct GtsnegoMsgCtx *p,int n);
void func_021D7550(u8 *p);
void func_021D75F4(struct GtsnegoMsgCtx *p);
void func_021D761C(u8 *p);
void func_021D7710(u8 *p);
char *func_021D7724(u32 heap,u32 n);
void func_021D7858(struct GtsnegoMsgCtx *p);
void func_021D7898(char *p);
void func_021D79F4(struct GtsnegoMsgCtx *p,u16 n);
void func_021D7A74(u8 *p, int n);
int func_021D7AF4(struct GtsnegoMsgCtx *p);
void func_021D7B38(struct GtsnegoMsgCtx *p);
void *func_021D7B60(char *p,int n);
int func_021D7C10(struct GtsnegoMsgCtx *p);
void func_021D7C1C(char *p);
int func_021D7C48(u8 *p, int n, int a, int b, int c, int d);
int func_021D7CD4(int a, int b, int c, int d);
void func_021D7CE8(char *p,u16 n,int i);
void func_021D7D30(char *a0);
void func_021D7D3C(char *p);
void func_021D7D6C(char *p,int a,int b);
void func_021D7DC8(char *p,int a,int b,int c,int d,int e);
void func_021D7E88(char *p,int i);
void func_021D7E9C(char *p,int i);
void func_021D7EB0(char *p,int i);
void func_021D7EC4(u8 *p);
void *func_021D7ECC(char *p,u16 n);
void func_021D7F5C(char *p,u16 n);
void func_021D7FD0(char *p,void *r);
void func_021D80D4(struct GtsnegoMsgCtx *p);
int func_021D8118(char *p, void *r, int n);
void func_021D81E0(char *p,void *q);
void func_021D822C(char *p,void *q,int index);
void func_021D824C(char *p);
void func_021D82A8(char *p,void *q,int start);
void func_021D82D8(char *p,void *q,int n);
void func_021D82F8(char *p);
void *func_021D8358(char *p,int n);
void func_021D8418(int a);
void func_021D8430(struct GtsnegoMsgCtx *p,void *q);
void func_021D846C(u8 *p);
void func_021D8484(struct Obj05353 *p, void *n);
void func_021D8520(struct GtsnegoMsgCtx *p, u16 n);
void func_021D8590(u8 *p, int a, int b);
void func_021D8638(struct GtsnegoMsgCtx *p);
void func_021D8648(u8 *p);
int func_021D8664(u8 *p);
void func_021D8684(char *p,int unused,u32 n);
void func_021D8784(char *p, void *n);
void func_021D880C(char *p,void *q,u32 n);
extern const u8 data_021D8B73[];
extern const Triple d_021D892C,d_021D8924,d_021D893C,d_021D8934;
extern const Table d_021D8AB0;
extern const char s_021D8BEC[];
extern const int d_021D8AF8[];
extern const u16 d_021D8BD8[],d_021D8BE0[];
extern const int d_021D8B04[];
extern const u16 d_021D8BD8[];
extern const Pair d_021D8B20;
extern const int d_021D8AF0[];

int func_021D6A9C(struct GtsnegoMsgCtx *p,u32 n){void *obj=p->f134;if(!obj)return 0;func_0204B878(obj,*(const u8 *)((u32)data_021D8B73+n*4));return 1;}

int func_021D6AC0(struct GtsnegoMsgCtx *p){if(!p->f134)return 0;if((u32)func_0204B898(p->f134)>=29){if(func_0204B98C(p->f134)==0)return 1;return 0;}return 0;}

void func_021D6AF0(u8 *p,u16 x,u16 y,int flag) {
PosRecord r;int i;
for(i=0;i<12;i++) {
if(!*(void **)(p+i*4+0xc4)) {
r.x=x;r.y=y;r.z=flag?2:0;r.a=0;r.b=1;
*(void **)(p+0xc4+i*4)=func_0204B294((void *)((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f28,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f74,&r,1,((struct GtsnegoMsgCtx *)p)->fF4);
func_0204B92C(*(void **)(p+0xc4+i*4),1);
func_0204B3DC(*(void **)(p+0xc4+i*4),1);
return;
}
}
}

/*
 * extent: two-byte zero alignment padding follows.
 * lever: base + index*4 + 0xc4 preserves the original add order.
 */
void func_021D6B5C(u8 *p){int i;for(i=0;i<12;i++){if(*(void **)(p+i*4+0xc4)){func_0204B3B4(*(void **)(p+i*4+0xc4));*(int *)(p+i*4+0xc4)=0;}}}

void func_021D6B84(u8 *p,u32 n){int got;int mode;got=func_0204B898(*(void **)(p+0xc4+n*4));mode=1;if(got>=2)mode=3;func_0204B878(*(void **)(p+0xc4+n*4),mode);func_0204B92C(*(void **)(p+0xc4+n*4),1);}

void func_021D6BB0(u8 *p, int n)
{
    void *t;
    func_021D698C(p);
    func_021D692C(p, 8);
    func_021D6810(p, 1);
    t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    ((struct GtsnegoMsgCtx *)p)->f120 = func_02049EF4(t, 21, 0, (void **)(p + 0x11c), ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049BDC(t, 0, 5, 0, 320, 32, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049238(t);
    t = func_020490F4(32, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049BDC(t, 0, 5, 0, 0, 256, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049238(t);
    func_021D6E84(p);
    func_021D6EF4(p, n);
    *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f100 = 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D6C64(u8 *p)
{
    void *q = ((struct GtsnegoMsgCtx *)p)->f120;
    if (q) {
        func_020307B0(q);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->f120 = 0;
    }
}

void func_021D6C7C(struct GtsnegoMsgCtx *p, int n)
{
    u16 *q = (u16 *)(*(u8 * *)&p->f11C + 0xc);
    int base = (u16)p->f0;
    int off;
    int index = 0;
    int y, x;
    y = 0;
    off = 6 * n;
    for (; y < 6; y++)
        for (x = 0; x < 32; x++, index++)
            func_02042FB0(4, x, y + off, base + q[index]);
}

void func_021D6CCC(struct GtsnegoMsgCtx *p, int n)
{
    u8 *q = *(u8 * *)&p->f11C + 0xc;
    int base = (u16)p->f0;
    int off;
    int x, y;
    y = 0;
    off = 6 * n;
    for (; y < 6; y++)
        for (x = 0; x < 32; x++)
            func_02042FB0(4, x, y + off, ((struct GtsnegoMsgCtx *)q)->f3E + base);
}

/*
 * extent: two-byte zero alignment padding follows.
 */
void func_021D6D10(struct GtsnegoMsgCtx *p,void *list,int first){int i;for(i=0;i<6;i++){if(func_021D4F70(list,first+i))func_021D6C7C(p,i);else func_021D6CCC(p,i);}func_02041B6C(4);}

void func_021D6D48(u8 *p)
{
    void *t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    int i;
    for (i = 0; i < 6; i++) {
        if (*(void **)(p + i * 4 + 0x14c)) {
            func_0204B3B4(*(void **)(p + i * 4 + 0x14c));
            *(void **)(p + i * 4 + 0x14c) = 0;
        }
    }
    func_021D698C(p);
    func_021D692C(p, 0);
    func_021D6ED8(p);
    func_02049238(t);
}

void func_021D6D94(u8 *p)
{
    void *t = func_020490F4(144, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_021D6C64(p);
    func_021D6FB4(p);
    func_02041300(6, 0, 0, 0, 32, 32, 17);
    func_02041B6C(6);
    func_02049BDC(t, 2, 5, 0, 256, 256, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t, 18, 4, 0, (u16)(((struct GtsnegoMsgCtx *)p)->f0), 0, 0, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_02041B6C(4);
    func_02049238(t);
}


/*
 * lever: name the p[2]+3 bound and reread p[2] for the increment;
 * retaining a named offset instead exchanges r3 and r4 (4-byte DIFF).
 */
int func_021D6E1C(void *unused,int *p){int idx=p[1];int ret=0;if(idx<2 && idx<p[0]-1){p[1]=idx+1;return 1;}else if(idx==2){int bound=p[2]+3;if(bound<p[0]){p[2]=p[2]+1;ret=2;}}return ret;}


int func_021D6E50(void *unused,int *p){int idx=p[1];int ret=0;if(idx>0){p[1]=idx-1;return 1;}else if(idx==0 && p[2]!=0){p[2]=p[2]-1;ret=2;}return ret;}

void func_021D6E70(void *unused, int *p, int n)
{
    if(n<(u32)p[0])p[1]=n;
    if(p[1]>2)p[1]=2;
}

/*
 * trailing: 2-byte zero alignment padding at 0x021D6ED6.
 */
void func_021D6E84(u8 *p)
{
    PosRecord r;
    r.x = 128; r.y = 200; r.z = 0; r.a = 1; r.b = 1;
    ((struct GtsnegoMsgCtx *)p)->f138 = func_0204B294((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f70, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f24, *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->fBC, &r, 1, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_0204B92C(((struct GtsnegoMsgCtx *)p)->f138, 1);
    func_0204B3DC(((struct GtsnegoMsgCtx *)p)->f138, 1);
}


void func_021D6ED8(u8 *p)
{
    void *q = ((struct GtsnegoMsgCtx *)p)->f138;
    if (q)
        func_0204B3B4(q);
    *(u32 *)&((struct GtsnegoMsgCtx *)p)->f138 = 0;
}

/*
 * lever: declarations x,y,z,b reproduce the descending stack slots; p+i*4+offset keeps the per-element pointer.
 */
void func_021D6EF4(u8 *p,int flag)
{
    PosRecord r;
    Triple x=d_021D892C;
    Triple y=d_021D8924;
    Triple z=d_021D893C;
    Triple b=d_021D8934;
    int i;
    for(i=0;i<3;i++) {
        if(flag || i!=0) {
            r.x=x.a[i]; r.y=y.a[i]; r.z=z.a[i]; r.a=i; r.b=b.a[i];
            *(void **)(p+i*4+0x140)=func_0204B294((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f28,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f74,&r,1,((struct GtsnegoMsgCtx *)p)->fF4);
            func_0204B92C(*(void **)(p+i*4+0x140),1);
            func_0204B3DC(*(void **)(p+i*4+0x140),1);
        }
    }
}

/*
 * matching: declaring element after i puts the element in r4 and the counter in r5.
 */
void func_021D6FB4(u8 *p)
{
    int i;
    u32 element;
    for (i = 0; i < 3; i++) {
        element = (u32)p + (u32)i * 4;
        if (((struct GtsnegoMsgCtx *)element)->f140 != 0) {
            func_0204B3B4(((struct GtsnegoMsgCtx *)element)->f140);
            ((struct GtsnegoMsgCtx *)element)->f140 = 0;
        }
    }
}

void func_021D6FD8(struct GtsnegoMsgCtx *p, u32 flag)
{
    if (p->f140 != 0) {
        func_0204B9A0(p->f140);
        func_0204B92C(p->f140, flag);
    }
}


void func_021D6FF8(struct GtsnegoMsgCtx *p, int state)
{
    p->f108 = state;
    if (state == 2) p->f10C = *(unsigned int *)&p->f104 + 48;
    else if (state == 1) p->f10C = *(unsigned int *)&p->f104 - 48;
}


void func_021D7020(struct GtsnegoMsgCtx *p)
{
    *(unsigned int *)&p->f108 = 0;
}

/*
 * lever: pass the named loaded state to out instead of rematerializing 1 or 2.
 */
int func_021D702C(u8 *p, int *out)
{
    int i;
    int state;
    state=((struct GtsnegoMsgCtx *)p)->f108;
    if (state==2) {
        ((struct GtsnegoMsgCtx *)p)->f104+=8;
        if (*(int *)&((struct GtsnegoMsgCtx *)p)->f10C==((struct GtsnegoMsgCtx *)p)->f104) {
            *out=state;
            ((struct GtsnegoMsgCtx *)p)->f108=0;
            ((struct GtsnegoMsgCtx *)p)->f104-=48;
        }
        for (i=0;i<6;i++) func_021D71E8(p,i,-8);
        ((struct GtsnegoMsgCtx *)p)->f100=1;
    }
    state=((struct GtsnegoMsgCtx *)p)->f108;
    if (state==1) {
        ((struct GtsnegoMsgCtx *)p)->f104-=8;
        if (*(int *)&((struct GtsnegoMsgCtx *)p)->f10C==((struct GtsnegoMsgCtx *)p)->f104) {
            *out=state;
            ((struct GtsnegoMsgCtx *)p)->f108=0;
            ((struct GtsnegoMsgCtx *)p)->f104+=48;
        }
        for (i=0;i<6;i++) func_021D71E8(p,i,8);
        ((struct GtsnegoMsgCtx *)p)->f100=1;
    }
    return ((struct GtsnegoMsgCtx *)p)->f108;
}

void func_021D70C8(u8 *p, int flag)
{
    int i;
    int direction = 1;
    int step;
    if (flag != 0) direction -= 2;
    i = 0;
    step = direction * 48;
    for (; i < 6; i++) func_021D71E8(p, i, step);
}

void func_021D70F0(void *a0)
{
    func_02040618(4, 3, 0);
    func_02040618(6, 3, 0);
    func_02041300(1, 0, 0, 0, 32, 32, 17);
    func_020409B4(1);
}

void func_021D7128(u8 *p, int n, int k)
{
    PosRecord r;
    if (*(void **)(p + 0x14c + n * 4)) func_0204B3B4(*(void **)(p + 0x14c + n * 4));
    r.x = 0; r.y = 0; r.z = 1; r.a = 10; r.b = 2;
    *(void **)(p + 0x14c + n * 4) = func_0204B294((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10, *(u32 *)(p + (k + 6) * 4 + 0x18), *(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f20, *(u32 *)(p + (k + 25) * 4 + 0x18), &r, 1, ((struct GtsnegoMsgCtx *)p)->fF4);
    func_0204B92C(*(void **)(p + 0x14c + n * 4), 1);
    func_0204B3DC(*(void **)(p + 0x14c + n * 4), 0);
}

void func_021D7190(u8 *p, int index, int x, int y)
{
    Vec pos;
    if (index < 6) {
        pos.x = x;
        pos.y = y;
        func_0204B404(*(void **)((u32)p + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
        func_0204B3DC(*(void **)((u32)p + 0x14c + (u32)index * 4), 1);
    }
}

void func_021D71B8(u8 *p, void *entry, int index)
{
    if (entry != 0) {
        func_021D7128(p, index, func_02008554((const struct Sub0200852CObj *)((int)entry)));
        func_021D7190(p, index, 16, -48 * (1 - index));
    }
}

void func_021D71E8(u8 *p, int index, int delta)
{
    Vec pos;
    if (*(void **)((u32)p + 0x14c + (u32)index * 4) != 0) {
        func_0204B454(*(void **)((u32)p + 0x14c + (u32)index * 4), (struct PtS *)&pos, 1);
        pos.y += (s16_021D71E8)delta;
        func_0204B404(*(void **)((u32)p + 0x14c + (u32)index * 4), (const struct Vec2 *)(&pos), 1);
    }
}

void func_021D7220(u8 *p, void *q)
{
    int i;
    if (q) {
        if (((struct GtsnegoMsgCtx *)p)->f14C) func_0204B3B4(((struct GtsnegoMsgCtx *)p)->f14C);
        for (i = 0; i < 5; i++) *(void **)(p + 0x14c + i * 4) = *(void **)(p + 0x150 + i * 4);
        ((struct GtsnegoMsgCtx *)p)->f160 = 0;
        func_021D71B8(p, q, 5);
    }
}

void func_021D7260(u8 *p, void *q)
{
    int i;
    if (q) {
        if (((struct GtsnegoMsgCtx *)p)->f160) func_0204B3B4(((struct GtsnegoMsgCtx *)p)->f160);
        for (i = 5; i > 0; i--) *(void **)(p + 0x14c + i * 4) = *(void **)(p + 0x148 + i * 4);
        ((struct GtsnegoMsgCtx *)p)->f14C = 0;
        func_021D71B8(p, q, 0);
    }
}

void func_021D72A0(u8 *p, void *container, int offset)
{
    int i;
    void *entry;
    for (i = 0; i < 6; i++) {
        if ((int)((u32)i + (u32)offset) >= 0) {
            entry = func_021D4F70(container, (int)((u32)i + (u32)offset));
            if (entry != 0) func_021D71B8(p, entry, i);
        }
    }
}

int func_021D72C8(struct GtsnegoMsgCtx *p, int index, int count)
{
    if (index == 0) return 0;
    count = (int)((u32)count - 1);
    if (index == count) return 132;
    return _s32_div_f((int)((u32)index * 132), count);
}

int func_021D72E8(struct GtsnegoMsgCtx *p, int n, int count)
{
    float f;
    float scale;
    f = (float)(n - 26);
    scale = 132.0f;
    if (count <= 3) return 0;
    f = f / (scale / (float)(count - 2));
    if (f >= (float)(count - 2)) f = (float)(count - 3);
    return (int)f;
}

void func_021D733C(struct GtsnegoMsgCtx *p, int index, int count)
{
    Vec pos;
    if (p->f140 != 0) {
        func_0204B454(p->f140, (struct PtS *)&pos, 1);
        pos.y = func_021D72C8(p, index, count) + 26;
        func_0204B404(p->f140, (const struct Vec2 *)(&pos), 1);
    }
}

int func_021D7374(struct GtsnegoMsgCtx *p,int y,int count) { Pt pt; int result; result=0; if(p->f140) { func_0204B454(p->f140,(struct PtS *)&pt,1); pt.y=y; func_0204B404(p->f140,(const struct Vec2 *)(&pt),1); result=func_021D72E8(p,y,count); } return result; }

/*
 * extent: trailing 2-byte alignment padding only.
 */
void func_021D73B0(char *p) { u16 next; next=func_0204B898(((struct GtsnegoMsgCtx *)p)->f130)+1; if(next>26) next=11; func_0204B878(((struct GtsnegoMsgCtx *)p)->f130,next); }

void func_021D73D8(u8 *p)
{
    Callback c;
    PosRecord r;
    r.x=128; r.y=52; r.z=27; r.a=2; r.b=1;
    ((struct GtsnegoMsgCtx *)p)->f12C=func_0204B294((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f2C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f1C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f78,&r,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_0204B92C(((struct GtsnegoMsgCtx *)p)->f12C,1);
    func_0204B3DC(((struct GtsnegoMsgCtx *)p)->f12C,1);
    r.z=11; r.a=1;
    ((struct GtsnegoMsgCtx *)p)->f130=func_0204B294((void *)*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f10,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f2C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f1C,*(unsigned int *)&((struct GtsnegoMsgCtx *)p)->f78,&r,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_0204B92C(((struct GtsnegoMsgCtx *)p)->f130,1);
    func_0204B3DC(((struct GtsnegoMsgCtx *)p)->f130,1);
    c.n=0; c.p=p; c.f=(void (*)(u8 *))func_021D73B0;
    func_0204BA00(((struct GtsnegoMsgCtx *)p)->f130,(const struct Cmd *)(&c));
    func_02043534(31);
}

void func_021D7484(char *p) { func_0204B3DC(((struct GtsnegoMsgCtx *)p)->f12C,0); func_0204B3B4(((struct GtsnegoMsgCtx *)p)->f12C); func_0204B3DC(((struct GtsnegoMsgCtx *)p)->f130,0); func_0204B3B4(((struct GtsnegoMsgCtx *)p)->f130); }

void func_021D74B0(struct GtsnegoMsgCtx *p,int n)
{
    Table a=d_021D8AB0;
    void *t=func_020490F4(144,p->fF4);
    func_02049990(t,15,0,0,(u16)(p->f4),0,0,p->fF4);
    func_02049238(t);
    func_0204B92C(p->f130,0);
    func_0204B878(p->f130,a.a[n]+11);
    func_0204B908((int)(p->f130),4);
    func_0204B878(p->f12C,28);
    func_02041B6C(0);
    p->f110=0;
    p->f114=0;
}

void func_021D7550(u8 *p)
{
    void *t=func_020490F4(144,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,14,2,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,13,0,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,16,3,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049238(t);
    func_021D73D8(p);
    func_02041B6C(2); func_02041B6C(0); func_02041B6C(3);
    ((struct GtsnegoMsgCtx *)p)->f110=0;
    ((struct GtsnegoMsgCtx *)p)->f114=1;
}

void func_021D75F4(struct GtsnegoMsgCtx *p) { if(p->f114) { func_02040618(2,3,p->f110); p->f110+=1; } }

/*
 * trailing: 2-byte zero alignment padding at 0x021D770E.
 * lever: indexed pointer sum before the far field offset preserves the base.
 */
void func_021D761C(u8 *p)
{
    int i;
    void *t;
    for(i=0;i<6;i++) {
        if(*(void **)(p+i*4+0x14c)) {
            func_0204B3DC(*(void **)(p+i*4+0x14c),0);
            func_0204B3B4(*(void **)(p+i*4+0x14c));
            *(u32 *)(p+i*4+0x14c)=0;
        }
    }
    func_021D6ED8(p);
    func_021D6C64(p);
    func_021D7484((char *)p);
    func_021D6FB4(p);
    func_021D6B5C(p);
    t=func_020490F4((u32)((void *)144),((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,12,0,0,(u16)(((struct GtsnegoMsgCtx *)p)->f4),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049990(t,18,4,0,(u16)(((struct GtsnegoMsgCtx *)p)->f0),0,0,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049BDC(t,2,5,0,0x100,0x100,((struct GtsnegoMsgCtx *)p)->fF4);
    func_02049238(t);
    func_021D698C(p);
    func_021D692C(p,0);
    func_02040588(2,0);
    func_02041B6C(0);
    func_02040588(3,0);
    ((struct GtsnegoMsgCtx *)p)->f110=0;
    ((struct GtsnegoMsgCtx *)p)->f114=0;
}


void func_021D7710(u8 *p)
{
    if (((struct GtsnegoMsgCtx *)p)->f8) {
        func_02051C6C(((struct GtsnegoMsgCtx *)p)->f8);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->f8 = 0;
    }
}

/*
 * interfaces: 0201EC74 heap widened because caller passes the entire ldrh value without byte truncation.
 */
char *func_021D7724(u32 heap,u32 n)
{
    char *p=func_02030734(heap,0xd0,1,s_021D8BEC,0xa9);
    ((struct GtsnegoMsgCtx *)p)->fC8=heap;
    func_02045088(((struct GtsnegoMsgCtx *)p)->fC8);
    func_0201DD60();
    ((struct GtsnegoMsgCtx *)p)->fA0=func_0203101C(((struct GtsnegoMsgCtx *)p)->fC8,((struct GtsnegoMsgCtx *)p)->fC8,1,0);
    ((struct GtsnegoMsgCtx *)p)->fA4=(void *)func_0201C440((void *)(u32)((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f1C=func_020457B0(240,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f18=func_020457B0(240,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f20=func_020457B0(240,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->f14=func_0201D7EC(23,0,0,0,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fC=func_02045B38(0,2,(u16)n,(u16)(((struct GtsnegoMsgCtx *)p)->fC8));
    ((struct GtsnegoMsgCtx *)p)->f10=func_0201EC74(6,64,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fC0=func_02027F60(5,9,*(u32 *)&((struct GtsnegoMsgCtx *)p)->f14,*(u32 *)&((struct GtsnegoMsgCtx *)p)->fA4,((struct GtsnegoMsgCtx *)p)->fC8);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f4=func_0201F5DC((void *)1,12,0,((struct GtsnegoMsgCtx *)p)->fC8);
    *(void * *)&((struct GtsnegoMsgCtx *)p)->f0=func_0201F5DC((void *)6,12,0,((struct GtsnegoMsgCtx *)p)->fC8);
    func_02049B40(23,5,4,0x160,32,((struct GtsnegoMsgCtx *)p)->fC8);
    func_02049B40(23,5,0,0x160,32,((struct GtsnegoMsgCtx *)p)->fC8);
    return p;
}

void func_021D7858(struct GtsnegoMsgCtx *p)
{
    func_0201DD78(1, 2, 15);
    func_020310C4(p->fA0);
    func_0201C4E4(p->fA4);
    if (p->fC4) func_02028178(p->fC4);
    if (p->fCC) func_0202DBC4(p->fCC);
}

static inline u16 decode(u32 value)
{
    u32 n=value >> 16;
    return (u16)n;
}

/*
 * trailing: two zero alignment bytes at 0x021D79F2.
 * lever: decode the high halfword, retain u16 payload arguments, remove
 * the p+16 address temporary and declare every Thumb callee explicitly.
 */
void func_021D7898(char *p)
{
    int i;
    u32 t;
    t=((struct GtsnegoMsgCtx *)p)->f4;
    func_0203FB44(1,(u16)t,decode(t));
    t=((struct GtsnegoMsgCtx *)p)->f0;
    func_0203FB44(6,(u16)t,decode(t));
    func_021D7710((u8 *)p);
    func_0201DD68();
    func_02045C04(((struct GtsnegoMsgCtx *)p)->fC);
    func_0201D83C(((struct GtsnegoMsgCtx *)p)->f14);
    func_02045808(((struct GtsnegoMsgCtx *)p)->f18);
    func_02045808(((struct GtsnegoMsgCtx *)p)->f1C);
    func_02045808(((struct GtsnegoMsgCtx *)p)->f20);
    func_021D846C((u8 *)p);
    if(((struct GtsnegoMsgCtx *)p)->f9C) {func_0201CE48(((struct GtsnegoMsgCtx *)p)->f9C);((struct GtsnegoMsgCtx *)p)->f9C=0;}
    func_0201ED04(((struct GtsnegoMsgCtx *)p)->f10);
    if(((struct GtsnegoMsgCtx *)p)->fC4) {func_02028148(((struct GtsnegoMsgCtx *)p)->fC4);((struct GtsnegoMsgCtx *)p)->fC4=0;}
    func_02027FD8(((struct GtsnegoMsgCtx *)p)->fC0);
    func_02031140(((struct GtsnegoMsgCtx *)p)->fA0);
    func_0201C6EC(((struct GtsnegoMsgCtx *)p)->fA4);
    func_0201C4C0(((struct GtsnegoMsgCtx *)p)->fA4);
    if(((struct GtsnegoMsgCtx *)p)->f30) func_020452E8(((struct GtsnegoMsgCtx *)p)->f30);
    if(((struct GtsnegoMsgCtx *)p)->f84) func_020452E8(((struct GtsnegoMsgCtx *)p)->f84);
    if(((struct GtsnegoMsgCtx *)p)->f98) func_020452E8(((struct GtsnegoMsgCtx *)p)->f98);
    if(((struct GtsnegoMsgCtx *)p)->f90) func_020452E8(((struct GtsnegoMsgCtx *)p)->f90);
    if(((struct GtsnegoMsgCtx *)p)->f8C) func_020452E8(((struct GtsnegoMsgCtx *)p)->f8C);
    if(((struct GtsnegoMsgCtx *)p)->f94) func_020452E8(((struct GtsnegoMsgCtx *)p)->f94);
    if(((struct GtsnegoMsgCtx *)p)->f88) func_020452E8(((struct GtsnegoMsgCtx *)p)->f88);
    if(((struct GtsnegoMsgCtx *)p)->f34) func_020452E8(((struct GtsnegoMsgCtx *)p)->f34);
    if(((struct GtsnegoMsgCtx *)p)->f68) func_020452E8(((struct GtsnegoMsgCtx *)p)->f68);
    for(i=0;i<12;i++) if(*(void **)(p+i*4+0x38)) func_020452E8(*(void **)(p+i*4+0x38));
    for(i=0;i<6;i++) if(*(void **)(p+i*4+0x6c)) func_020452E8(*(void **)(p+i*4+0x6c));
    func_020450C8();
    func_020307B0(p);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021D79F4(struct GtsnegoMsgCtx *p,u16 n)
{
    void *q;
    func_02045CAC(p->fC,n,(void *)(*(int *)&p->f1C));
    if (!p->f30) p->f30=(void *)func_020450F0(1,1,19,30,4,11,1);
    q=p->f30;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,(void *)(*(int *)&p->f1C),(void *)(*(int *)&p->f14));
    func_0201F73C(q,1,(u16)(p->f4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}

void func_021D7A74(u8 *p, int n)
{
    void *q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18));
    if (!((struct GtsnegoMsgCtx *)p)->f30) ((struct GtsnegoMsgCtx *)p)->f30=(void *)func_020450F0(1,1,21,30,2,11,1);
    q=((struct GtsnegoMsgCtx *)p)->f30;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18),(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
    func_0201F73C(q,1,(u16)(((struct GtsnegoMsgCtx *)p)->f4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}

/*
 * follower: two zero padding bytes at 021D7B36.
 */
int func_021D7AF4(struct GtsnegoMsgCtx *p)
{
    if (p->f9C) {
        switch (func_0201CE30(p->f9C)) {
        case 2: func_0201CE48(p->f9C); p->f9C=0; break;
        case 1: if (func_020362DC()==1) func_0201CE38(p->f9C); break;
        }
        return 0;
    }
    return 1;
}

void func_021D7B38(struct GtsnegoMsgCtx *p) { if(p->f30) { func_0201F7A8(p->f30,2); func_020456F8(p->f30); func_02041B6C(1); func_020452E8(p->f30); p->f30=0; } }

void *func_021D7B60(char *p,int n)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)p)->fC8;
    config.count=2;
    config.entries=p+0xa8;
    switch(n) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=func_020457B0(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,25,text);
    ((struct GtsnegoMsgCtx *)p)->fAC=0x39e0;
    text=func_020457B0(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fB4=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,26,text);
    ((struct GtsnegoMsgCtx *)p)->fB8=0x39e0;
    result=func_02027778((struct TaskMenuTmpl *)(&config),((struct GtsnegoMsgCtx *)p)->fC0);
    func_02045808(((struct GtsnegoMsgCtx *)p)->fA8);
    func_02045808(((struct GtsnegoMsgCtx *)p)->fB4);
    return result;
}

int func_021D7C10(struct GtsnegoMsgCtx *p) { return func_02051C88(p->f8); }

void func_021D7C1C(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(((struct GtsnegoMsgCtx *)q)->f38) { func_020452E8(((struct GtsnegoMsgCtx *)q)->f38); ((struct GtsnegoMsgCtx *)q)->f38=0; } } func_0201DD78(1,2,0); }

int func_021D7C48(u8 *p, int n, int a, int b, int c, int d)
{
    int i;
    void *q;
    for(i=0;i<12;i++) {
        if(!*(void **)(p+i*4+0x38)) {
            ((void **)(p+0x38))[i]=(void *)func_020450F0((u8)d,(u8)a,(u8)b,(u8)c,2,11,1);
            q=((void **)(p+0x38))[i];
            func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)q),0);
            func_02045CAC(*(struct MsgBank **)(p+0xc),n,*(void **)(p+0x18));
            func_0201C7A4(func_02045770((struct Descriptor *)q),2,2,*(void **)(p+0x18),*(void **)(p+0x14));
            func_02045334((struct Descriptor *)q);
            func_02045374((struct Cfg *)q);
            return i;
        }
    }
    return 0;
}


int func_021D7CD4(int a, int b, int c, int d)
{
    return func_021D7C48((u8 *)a, b, c, d, 0x14, 6);
}

/*
 * follower: two zero padding bytes at 021D7D2E.
 */
void func_021D7CE8(char *p,u16 n,int i)
{
    void *q=*(void **)(p+0x38+4*i);
    if(q) {
        func_02043B5C(func_02045770(q),0);
        func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18));
        func_0201C7A4(func_02045770(q),2,2,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18),(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
        func_02045334(q);
    }
}

void func_021D7D30(char *a0) { func_02041B6C(6); }

void func_021D7D3C(char *p) { int i; char *q; for(i=0;i<12;i++) { q=(char *)((u32)p+(u32)i*4); if(((struct GtsnegoMsgCtx *)q)->f38) { func_02041B6C(func_02045730(((struct GtsnegoMsgCtx *)q)->f38)); func_0201F7A8(((struct GtsnegoMsgCtx *)q)->f38,2); func_020456F8(((struct GtsnegoMsgCtx *)q)->f38); } } }

void func_021D7D6C(char *p,int a,int b)
{
    func_021D7C1C(p);
    func_021D7C48((unsigned char *)p,0,8,7,16,6);
    func_021D7C48((unsigned char *)p,1,8,13,16,6);
    func_021D7D30(p);
    func_021D7710((unsigned char *)p);
    ((struct GtsnegoMsgCtx *)p)->f8=func_02051B84((u8 *)d_021D8AF8,a,b,((struct GtsnegoMsgCtx *)p)->fC8);
}

/*
 * follower: existing 021D7E88, 021D7E9C, 021D7EB0 files remain separate.
 */
void func_021D7DC8(char *p,int a,int b,int c,int d,int e)
{
    func_021D7C1C(p);
    func_0201DD78(15,2,0);
    func_021D7CD4((int)p,2,0,0);
    func_0201DD78(15,2,0);
    func_021D7CD4((int)p,3,3,6);
    func_021D7CD4((int)p,23,1,11);
    func_021D7CD4((int)p,24,1,16);
    func_0201DD78(1,2,0);
    *(int *)&((struct GtsnegoMsgCtx *)p)->f24=func_021D7CD4((int)p,d_021D8BD8[c],13,6);
    *(int *)&((struct GtsnegoMsgCtx *)p)->f28=func_021D7CD4((int)p,d_021D8BE0[d],16,11);
    *(int *)&((struct GtsnegoMsgCtx *)p)->f2C=func_021D7CD4((int)p,d_021D8BE0[e],16,16);
    func_021D7D30(p);
    func_021D7710((unsigned char *)p);
    ((struct GtsnegoMsgCtx *)p)->f8=func_02051B84((u8 *)d_021D8B04,a,b,((struct GtsnegoMsgCtx *)p)->fC8);
}

/*
 * follower: separately filed 021D7E9C.
 */
void func_021D7E88(char *p,int i) {func_021D7CE8(p,d_021D8BD8[i],*(int *)&((struct GtsnegoMsgCtx *)p)->f24);}

/*
 * follower: separately filed 021D7EB0.
 */
void func_021D7E9C(char *p,int i) {func_021D7CE8(p,d_021D8BE0[i],*(int *)&((struct GtsnegoMsgCtx *)p)->f28);}

void func_021D7EB0(char *p,int i) {func_021D7CE8(p,d_021D8BE0[i],*(int *)&((struct GtsnegoMsgCtx *)p)->f2C);}

void func_021D7EC4(u8 *p) { func_021D7710(p); }

void *func_021D7ECC(char *p,u16 n)
{
    int width;
    void *result;
    void *text;
    text=func_020457B0(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,text);
    ((struct GtsnegoMsgCtx *)p)->fAC=0x39e3;
    ((struct GtsnegoMsgCtx *)p)->fB0=0;
    width=((int)func_0201D304(((struct GtsnegoMsgCtx *)p)->fA8,(int)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14),(int)0)+32)/16;
    result=func_0202800C((u32)(((struct GtsnegoMsgCtx *)p)->fC0),(u32)(p+0xa8),(u8)(16-width),(u8)21,width*2,3,(int)0,(int)1,((struct GtsnegoMsgCtx *)p)->fC8);
    func_02045808(((struct GtsnegoMsgCtx *)p)->fA8);
    return result;
}

void func_021D7F5C(char *p,u16 n)
{
    void *q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,n,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18));
    if(!((struct GtsnegoMsgCtx *)p)->f94) ((struct GtsnegoMsgCtx *)p)->f94=(void *)func_020450F0(1,1,13,14,3,4,1);
    q=((struct GtsnegoMsgCtx *)p)->f94;
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,14,0);
    func_0201C7A4(func_02045770(q),2,3,(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18),(void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
    func_02045334(q);
    func_02045374(q);
}

/*
 * follower: two zero padding bytes at 021D80D2.
 */
void func_021D7FD0(char *p,void *r)
{
    u32 a,b,c,d;
    void *q;
    a=func_0200856C(r);
    b=func_02008570(r);
    c=func_02025C1C(a,b,func_02008564(r));
    d=func_02025C30(a,b,func_02008564(r));
    if(a==c && b==d) {
        func_0201F048(((struct GtsnegoMsgCtx *)p)->f10,0,func_0200856C(r));
        a=func_0200856C(r);
        func_0201F094(((struct GtsnegoMsgCtx *)p)->f10,1,a,func_02008570(r));
    } else {
        func_0201F048(((struct GtsnegoMsgCtx *)p)->f10,0,0);
        func_0201F094(((struct GtsnegoMsgCtx *)p)->f10,1,0,0);
    }
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,34,((struct GtsnegoMsgCtx *)p)->f20);
    func_0201F250(((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f20);
    if(!((struct GtsnegoMsgCtx *)p)->f84) ((struct GtsnegoMsgCtx *)p)->f84=(void *)func_020450F0(1,1,15,30,5,11,1);
    q=((struct GtsnegoMsgCtx *)p)->f84;
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,2,0);
    func_0201C7A4(func_02045770(q),5,5,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f14);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}

/*
 * follower: two zero padding bytes at 021D8116.
 */
void func_021D80D4(struct GtsnegoMsgCtx *p)
{
    if (p->f84) {
        func_02043B5C(func_02045770(p->f84),0);
        func_02045334(p->f84);
        func_020456F8(p->f84);
        func_02041B6C(1);
        func_020452E8(p->f84);
        p->f84=0;
    }
}

int func_021D8118(char *p, void *r, int n)
{
    void **t=(void **)(p+0x6c);
    void *q;
    if(!t[n]) t[n]=(void *)func_020450F0((u8)6,(u8)6,(u8)(n*6+1),(u8)24,4,11,1);
    q=t[n];
    func_02043B5C(func_02045770(q),0);
    func_0204581C(*(void **)(p+0x20));
    func_0204581C(*(void **)(p+0x18));
    func_0201F02C(*(void **)(p+0x10),0,r);
    func_0201EFA4(*(void **)(p+0x10),1,func_02008534(r),5,2,1);
    func_0201F048(*(void **)(p+0x10),2,func_0200856C(r));
    func_02045CAC(*(void **)(p+0xc),28,*(void **)(p+0x20));
    func_0201F250(*(void **)(p+0x10),*(void **)(p+0x18),*(void **)(p+0x20));
    func_0201DD78(15,2,0);
    func_0201C7A4(func_02045770(q),0,0,*(void **)(p+0x18),*(void **)(p+0x14));
    func_02045334(q);
    func_02045374(q);
    return 0;
}

void func_021D81E0(char *p,void *q)
{
    int i;
    void *r;
    func_0201DD78(15,2,0);
    func_021D7C48((u8 *)p,30,0,0,20,5);
    for(i=0;i<3;i++) {
        r=func_021D4F70(q,i);
        if(r) func_021D8118(p,r,i+2);
    }
    func_02041B6C(5);
}

void func_021D822C(char *p,void *q,int index) { func_021D8118(p,func_021D4F70(q,index),5); func_02041B6C(6); }

void func_021D824C(char *p)
{
    int i;
    char *t;
    if(((struct GtsnegoMsgCtx *)p)->f6C) {func_020452E8(((struct GtsnegoMsgCtx *)p)->f6C);((struct GtsnegoMsgCtx *)p)->f6C=0;}
    for(i=1;i<6;i++) {
        t=p+4*i;
        if(((struct GtsnegoMsgCtx *)t)->f6C) {
            func_02045788(((struct GtsnegoMsgCtx *)t)->f6C,func_02045760(((struct GtsnegoMsgCtx *)t)->f6C)-6);
            func_02045374(((struct GtsnegoMsgCtx *)t)->f6C);
        }
    }
    func_02041B6C(6);
    for(i=0;i<5;i++) *(void **)(p+0x6c+4*i)=*(void **)(p+0x70+4*i);
    ((struct GtsnegoMsgCtx *)p)->f80=0;
}

void func_021D82A8(char *p,void *q,int start) { int i; void *r; for(i=0;i<6;i++) { if((int)((u32)i+(u32)start)>=0) { r=func_021D4F70(q,(int)((u32)i+(u32)start)); if(r) func_021D8118(p,r,i); } } func_02041B6C(6); }

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void func_021D82D8(char *p,void *q,int n)
{
    func_021D8118(p,func_021D4F70(q,n),0);
    func_02041B6C(6);
}

void func_021D82F8(char *p)
{
    int i;
    char *t;
    if(((struct GtsnegoMsgCtx *)p)->f80) {func_020452E8(((struct GtsnegoMsgCtx *)p)->f80);((struct GtsnegoMsgCtx *)p)->f80=0;}
    for(i=0;i<6;i++) {
        t=p+4*i;
        if(((struct GtsnegoMsgCtx *)t)->f6C) {
            func_02045788(((struct GtsnegoMsgCtx *)t)->f6C,func_02045760(((struct GtsnegoMsgCtx *)t)->f6C)+6);
            func_02045374(((struct GtsnegoMsgCtx *)t)->f6C);
        }
    }
    func_02041B6C(6);
    for(i=5;i>0;i--) *(void **)(p+0x6c+4*i)=*(void **)(p+0x68+4*i);
    ((struct GtsnegoMsgCtx *)p)->f6C=0;
}

void *func_021D8358(char *p,int n)
{
    TextConfig config;
    void *result;
    void *text;
    config.heap=((struct GtsnegoMsgCtx *)p)->fC8;
    config.count=2;
    config.entries=p+0xa8;
    switch(n) {
    case 0: config.x=32;config.y=14;config.mode=1;break;
    case 1: config.x=32;config.y=24;config.mode=1;break;
    }
    config.a=13;config.b=3;
    text=func_020457B0(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,27,text);
    ((struct GtsnegoMsgCtx *)p)->fAC=0x39e0;
    ((struct GtsnegoMsgCtx *)p)->fB0=0;
    text=func_020457B0(100,((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fB4=text;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,33,text);
    ((struct GtsnegoMsgCtx *)p)->fB8=0x39e0;
    *(int *)&((struct GtsnegoMsgCtx *)p)->fBC=0;
    result=func_02027778((struct TaskMenuTmpl *)(&config),((struct GtsnegoMsgCtx *)p)->fC0);
    func_02045808(((struct GtsnegoMsgCtx *)p)->fA8);
    func_02045808(((struct GtsnegoMsgCtx *)p)->fB4);
    return result;
}


void func_021D8418(int a)
{
    if (a != 0) {
        *(volatile u16 *)0x04000050 = 0;
        func_02027858((struct TaskMenu *)a);
    }
}

void func_021D8430(struct GtsnegoMsgCtx *p,void *q)
{
    if(!p->fCC)
        p->fCC=func_0202DB0C(func_021D60FC(q),0,(u32)(p->fA4),(u32)(p->f14),8,4,p->fC8);
}


void func_021D846C(u8 *p)
{
    if (((struct GtsnegoMsgCtx *)p)->fCC) {
        func_0202DC08(((struct GtsnegoMsgCtx *)p)->fCC);
        *(u32 *)&((struct GtsnegoMsgCtx *)p)->fCC = 0;
    }
}

void func_021D8484(struct Obj05353 *p, void *n)
{
    Pair c = d_021D8B20;
    void *q;
    if (!p->f88) p->f88 = (void *)func_020450F0(1, 1, 15, 30, 5, 11, 1);
    q = p->f88;
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(15, 2, 0);
    func_0202DE5C(p->fCC, 0);
    func_0202DE64(p->fCC, 0x3c40);
    func_0202DC60(p->fCC, (u32)q, n, 0, (u32)(&c));
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}

void func_021D8520(struct GtsnegoMsgCtx *p, u16 n)
{
    void *q;
    func_02045CAC(p->fC, n, (void *)(*(int *)&p->f18));
    if (!p->f68) p->f68 = (void *)func_020450F0(1, 0, 0, 14, 2, 11, 1);
    q = p->f68;
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(15, 2, 0);
    func_0201C7A4(func_02045770(q), 2, 2, (void *)(*(int *)&p->f18), (void *)(*(int *)&p->f14));
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}

void func_021D8590(u8 *p, int a, int b)
{
    void *q = func_020457B0(100, ((struct GtsnegoMsgCtx *)p)->fC8);
    ((struct GtsnegoMsgCtx *)p)->fA8 = q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC, 15, q);
    ((struct GtsnegoMsgCtx *)p)->fAC = 0x39e3;
    ((struct GtsnegoMsgCtx *)p)->fB0 = 0;
    ((struct GtsnegoMsgCtx *)p)->fC4 = func_0202800C((u32)(((struct GtsnegoMsgCtx *)p)->fC0), (u32)(p + 0xa8), 10, 21, 12, 3, 0, 1, ((struct GtsnegoMsgCtx *)p)->fC8);
    if (!func_020355C4()) func_02028218(((struct GtsnegoMsgCtx *)p)->fC4, 1);
    func_02045808(((struct GtsnegoMsgCtx *)p)->fA8);
    func_021D7710(p);
    ((struct GtsnegoMsgCtx *)p)->f8 = func_02051B84((u8 *)d_021D8AF0, a, b, ((struct GtsnegoMsgCtx *)p)->fC8);
}


void func_021D8638(struct GtsnegoMsgCtx *p)
{
    func_0202822C(p->fC4, 1);
}


void func_021D8648(u8 *p)
{
    func_02028148(((struct GtsnegoMsgCtx *)p)->fC4);
    func_02041B6C(5);
    *(u32 *)&((struct GtsnegoMsgCtx *)p)->fC4 = 0;
}

int func_021D8664(u8 *p)
{
    if(func_02028230(((struct GtsnegoMsgCtx *)p)->fC4)){
        func_021D8648((u8 *)((int)p));
        return 1;
    }
    return 0;
}

void func_021D8684(char *p,int unused,u32 n)
{
    void *q;
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,40,((struct GtsnegoMsgCtx *)p)->f18);
    if(!((struct GtsnegoMsgCtx *)p)->f8C) ((struct GtsnegoMsgCtx *)p)->f8C=(void *)func_020450F0(1,21,4,10,2,4,1);
    q=((struct GtsnegoMsgCtx *)p)->f8C;
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,14,0);
    func_0201C7A4(func_02045770(q),0,3,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f14);
    func_02045334(q);
    func_02045374(q);
    func_0201EFA4(((struct GtsnegoMsgCtx *)p)->f10,0,n,5,1,1);
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC,36,((struct GtsnegoMsgCtx *)p)->f20);
    func_0201F250(((struct GtsnegoMsgCtx *)p)->f10,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f20);
    if(!((struct GtsnegoMsgCtx *)p)->f90) ((struct GtsnegoMsgCtx *)p)->f90=(void *)func_020450F0(1,21,6,10,3,11,1);
    q=((struct GtsnegoMsgCtx *)p)->f90;
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,2,0);
    func_0201C7A4(func_02045770(q),0,5,((struct GtsnegoMsgCtx *)p)->f18,((struct GtsnegoMsgCtx *)p)->f14);
    func_02045334(q);
    func_02045374(q);
}

void func_021D8784(char *p, void *n)
{
    void *q;
    func_0201F02C(((struct GtsnegoMsgCtx *)p)->f10, 0, n);
    func_02045CAC(((struct GtsnegoMsgCtx *)p)->fC, 37, (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f20));
    func_0201F250(((struct GtsnegoMsgCtx *)p)->f10, (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18), (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f20));
    if (!((struct GtsnegoMsgCtx *)p)->f98) ((struct GtsnegoMsgCtx *)p)->f98 = (void *)func_020450F0(1, 11, 10, 10, 3, 11, 1);
    q = ((struct GtsnegoMsgCtx *)p)->f98;
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(1, 2, 0);
    func_0201C7A4(func_02045770(q), 0, 0, (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f18), (void *)(*(int *)&((struct GtsnegoMsgCtx *)p)->f14));
    func_02045334(q);
    func_02045374(q);
}

void func_021D880C(char *p,void *q,u32 n)
{
    func_021D8784(p,(void *)q);
    func_021D8684(p,36,n);
    func_021D7F5C(p,41);
    func_021D7FD0(p,q);
    func_021D7A74((u8 *)p,17);
}
