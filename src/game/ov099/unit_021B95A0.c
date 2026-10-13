/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B9670, func_021B96CC, func_021B96D0, func_021B9788, func_021B97CC, func_021B97F4, func_021B9800, func_021B984C, func_021B989C, func_021B98E4, func_021B98F0, func_021B98F8, func_021B98FC, func_021B9900, func_021B9968, func_021B99F4, func_021B9A34, func_021B9A50, func_021B9A60, func_021B9A70, func_021B9AE0, func_021B9B00, func_021B9B24, func_021B9B54, func_021B9B64, func_021B9B80, func_021B9BA8, func_021B9BC4, func_021B9C4C, func_021B9C9C, func_021B9CD0, func_021B9CF8, func_021B9D30, func_021B9D5C, func_021B9D6C, func_021B9DB0, func_021B9DC0, func_021B9DD4, func_021B9DE4, func_021B9DEC, func_021B9DF4, func_021B9DFC, func_021B9E04, func_021B9E08, func_021B9E0C, func_021B9E50, func_021B9EA0, func_021B9EB8, func_021B9F34, func_021B9F48, func_021B9F84, func_021B9F90, func_021B9FD0, func_021B9FDC, func_021BA04C, func_021BA0F8, func_021BA168, func_021BA190, func_021BA1C4, func_021BA1FC, func_021BA228, func_021BA248, func_021BA264, func_021BA2A4, func_021BA2D0, func_021BA2D4, func_021BA36C, func_021BA418, func_021BA4C8, func_021BA538
 * address:  0x021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BA810  0x021BA810  thumb  ov099
 *   func_021BA81C  0x021BA81C  thumb  ov099
 *   func_021C47A0  0x021C47A0  thumb  ov127
 *   func_021C4800  0x021C4800  thumb  ov127
 *   func_021C4880  0x021C4880  thumb  ov127
 *   func_021C59D0  0x021C59D0  thumb  ov127
 *   func_021BA60C  0x021BA60C  thumb  ov099
 *   func_021C5EEC  0x021C5EEC  thumb  ov127
 *   func_021C5F30  0x021C5F30  thumb  ov127
 *   func_021BA648  0x021BA648  thumb  ov099
 *   func_021C48C0  0x021C48C0  thumb  ov127
 *   func_021C47E4  0x021C47E4  thumb  ov127
 *   func_021C48E8  0x021C48E8  thumb  ov127
 *   func_021C5994  0x021C5994  thumb  ov127
 *   func_021C5A60  0x021C5A60  thumb  ov127
 *   func_021C571C  0x021C571C  thumb  ov127
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C4AC4  0x021C4AC4  thumb  ov127
 *   func_021C4864  0x021C4864  thumb  ov127
 *   func_021C5858  0x021C5858  thumb  ov127
 *   func_021C584C  0x021C584C  thumb  ov127
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021C57DC  0x021C57DC  thumb  ov127
 *   func_021BA5B4  0x021BA5B4  thumb
 *   func_021C4948  0x021C4948  thumb  ov127
 *   func_021C5704  0x021C5704  thumb  ov127
 *   func_021C4A8C  0x021C4A8C  thumb  ov127
 *   func_021C5864  0x021C5864  thumb  ov127
 *   func_021C5814  0x021C5814  thumb  ov127
 *   func_021BA594  0x021BA594  thumb
 *   func_021BA5DC  0x021BA5DC  thumb  ov099
 *   func_021BA5F0  0x021BA5F0  thumb  ov099
 *   func_021BA794  0x021BA794  thumb  ov099
 *   func_021BA7BC  0x021BA7BC  thumb  ov099
 *   func_021BA660  0x021BA660  thumb  ov099
 *   func_021C4A54  0x021C4A54  thumb  ov127
 *   func_021C48D4  0x021C48D4  thumb  ov127
 *   func_021C5370  0x021C5370  thumb  ov127
 *   func_021C5F80  0x021C5F80  thumb  ov127
 *   func_021C4BA4  0x021C4BA4  thumb  ov127
 *   func_021C5590 0x021C5590 thumb ov127
 *   func_021C5664 0x021C5664 thumb ov127
 *   func_021C5608  0x021C5608  thumb  ov127
 *   d_021C289C     0x021C289C  data  a1
 *   func_021C59F4  0x021C59F4  thumb  ov127
 *   func_021C5A4C  0x021C5A4C  thumb  ov127
 *   func_02049B40  0x02049B40  arm
 *   func_02040EBC  0x02040EBC  arm
 *   func_02049624  0x02049624  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_0204B528 0x0204B528 arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_021C47F8  0x021C47F8  thumb  ov127
 *   func_021C47FC  0x021C47FC  thumb  ov127
 *   func_021C5680 0x021C5680 thumb ov127
 *   func_021C5840 0x021C5840 thumb ov127
 *   func_021C4918 0x021C4918 thumb ov127
 *   func_020056EC  0x020056EC  thumb
 *   func_021C57E8  0x021C57E8  thumb  ov127
 *   func_021C5834  0x021C5834  thumb  ov127
 *   func_0203F5FC  0x0203F5FC  arm
 *   _ll_mul        0x0209C054  arm
 *   func_021C5898  0x021C5898  thumb  ov127
 *   func_021C57F4  0x021C57F4  thumb  ov127
 */
#include "work_types.h"
#include "../../matched/include/Obj13676.h"
#include "../../matched/include/Obj22009.h"
#include "../../matched/include/Obj18147.h"
#include "../../matched/include/Obj18148.h"
#include "../../matched/include/Obj04411.h"
#include "../../matched/include/Obj22013.h"
#include "../../matched/include/Obj02660.h"
#include "../../matched/include/Obj02800.h"
#include "../../matched/include/Obj02448.h"

struct Obj_021B9EB8;
struct Actor;
struct Pt;
struct Node;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021B95A0;

typedef struct { u16 w, h; } WH;

typedef unsigned int u32_021B9788;

typedef unsigned long  u32_021B97CC;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021B97F4;

typedef struct {
    char pad[0x570];
    u8 *p;
} W_021B95A0;

typedef unsigned int u32_021B9800;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work;

typedef unsigned int u32_021B984C;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work_021B984C;

typedef struct {
    void *f0;
    void *f4;
} Rec_021B95A0;

typedef short s16_021B98E4;

typedef unsigned int u32_021B98E4;

typedef int s32_021B98E4;

typedef short s16_021B98F0;

typedef unsigned int u32_021B98F0;

typedef int s32_021B98F0;

typedef unsigned long  u32_021B98F8;

typedef signed short   s16_021B98F8;

typedef signed long    s32_021B98F8;

typedef struct {
    u32_021B98F8 f00, f04, f08, f0C;
} S_021B95A0;

typedef unsigned long  u32_021B98FC;

typedef signed short   s16_021B98FC;

typedef signed long    s32_021B98FC;

typedef unsigned int u32_021B9900;

typedef struct {
    char pad[0x570];
    void **f570;
} Work_021B9968;

typedef unsigned int   u32_021B9968;

typedef struct {
    void *f0;
    void *f4;
    short f8;
    short pad;
    short fc;
    short pad2;
    int f10;
    int f14;
    int f18;
} Ent_021B95A0;

typedef struct {
    void *f0;
    void *f4;
    char pad[0x14];
} Obj_021B9A34;

typedef unsigned long  u32_021B9A50;

typedef unsigned long  u32_021B9A60;

typedef struct {
    void *f0;
    void *f4;
    short f8;
    short pad;
    unsigned short fc;
    unsigned short fe;
    int f10;
    int f14;
    int f18;
} Ent_021B9A34;

typedef unsigned int u32_021B9AE0;

typedef unsigned long  u32_021B9B00;

typedef unsigned long  u32_021B9B24;

typedef unsigned long  u32_021B9B54;

typedef unsigned long  u32_021B9B64;

typedef unsigned long  u32_021B9B80;

typedef unsigned long  u32_021B9BA8;

typedef struct {
    char pad[0x570];
    void **f570;
    char pad574[0x14];
    void *f588;
} Work_021B9BC4;

typedef unsigned int   u32_021B9BC4;

typedef struct {
    char pad[0x588];
    void *f588;             /* 0x588 */
    void *f58c;             /* 0x58c */
    char pad590[0xc];
    void *f59c;             /* 0x59c */
} Work_021B9C4C;

typedef unsigned int u32_021B9C9C;

typedef unsigned long  u32_021B9CD0;

typedef unsigned long  u32_021B9CF8;

typedef unsigned int u32_021B9D30;

typedef unsigned long  u32_021B9D5C;

typedef struct {
    u8 b[11];
} Tab;

typedef struct {
    char pad[0x10];
    void *f10;
    char pad14[4];
    void *f18;
    char pad1c[0x598 - 0x1c];
    int f598;
} Obj_021B9D6C;

typedef unsigned long  u32_021B9A34;

typedef unsigned int u32_021B9E0C;

typedef unsigned int u32_021B9E50;

typedef struct {
    char pad[8];
    int f8;
    int fc;
    int f10;
} Obj;

typedef signed int     s32_021B9E50;

typedef unsigned long  u32_021B9EA0;

typedef signed long    s32_021B9EA0;

typedef struct {
    char pad[8];
    void *f08;
    void *f0C;
    void *f10;
} S_021B9A34;

typedef unsigned int u32_021B9EB8;

typedef struct {
    u32_021B9EB8 f0;
    u32_021B9EB8 f4;
    u32_021B9EB8 f8;
    u32_021B9EB8 fc;
    u32_021B9EB8 f10;
    u32_021B9EB8 f14;
    u32_021B9EB8 f18;
} Obj_021B9EB8;

typedef struct {
    u16 a, b, c;
    u8 d, e;
} Rec_021B9EB8;

typedef unsigned long  u32_021B9F34;

typedef struct {
    char pad[0x14];
    void *f14;
    void *f18;
} S_021B9EB8;

typedef unsigned int u32;

typedef struct { short x,y; } Pos_021B9EB8;

typedef unsigned long  u32_021B9F84;

typedef struct {
    char pad[0x28];
    void *f28;
} S_021B9F84;

typedef struct {
    char pad[0x2c];
    void *f2c;              /* 0x2c */
} Obj_021B9F84;

typedef unsigned int   u32_021B9F90;

typedef unsigned long  u32_021BA0F8;

typedef struct {
    char pad00[0x588];
    void *f588;
} W_021BA0F8;

typedef unsigned long  u32_021BA168;

typedef unsigned int u32_021BA190;

typedef unsigned int u32_021BA1C4;

typedef struct { short x,y; u16 a,b,c,d; } Params;

typedef unsigned long  u32_021BA1FC;

typedef signed long    s32_021BA0F8;

typedef struct {
    char pad[0x0C];
    u16 f0C;
} S;

typedef unsigned int u32_021BA228;

typedef struct {
    char pad[8];
    u16 f08;
    char pad2[2];
    u16 f0C;
    void *f10;
    void *f14;
    void *f18;
} S_021BA248;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fa;
    s16 fc;
    s16 fe;
    void *f10;
    void *f14;
    void *f18;
} S_021BA264;

typedef unsigned int u32_021BA2A4;

typedef signed int     s32_021BA2D4;


typedef struct {
    void *f0;
    void *f4;
    u16 f8;
} S_021BA2D4;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
} S_021BA36C;

typedef struct {
    char pad00[0xc];
    int fc;
} W_021BA418;

typedef struct {
    void *f0;
} S_021BA418;

typedef struct {
    char pad00[0x570];
    void **f570;
} W_021BA4C8;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    u8 fa;
    u8 fb;
} S_021BA4C8;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
} S_021BA538;

extern void func_02082BCC(void *p, u32_021B95A0 v, u32_021B95A0 n);
extern WH func_021BA810(int i);
extern u32_021B95A0 func_021BA81C(int i);
extern void *func_021C47A0(u32_021B95A0 w, u32_021B95A0 h, u32_021B95A0 heap);
extern void func_021C4800(u8 *p, void *out);
extern void *func_021C4880(u32_021B95A0 count, u32_021B95A0 heap);
extern void func_021C59D0(void *p);
extern void func_021BA60C(char *a, char *p, u32_021B95A0 unused, u32_021B95A0 arc);
extern void *func_021C5EEC(int n, int heap);
extern void func_021C5F30(u8 *p);
extern void func_021BA648(int unused, void *p);
extern void func_021C48C0(u8 *p);
extern void func_021C47E4(u8 *p);
extern void func_021C48E8(u8 *p);
extern void func_021C5994(void *p, void *q);
extern void func_021C5A60(char *p, void *q);
extern void func_021C571C(u8 *p);
extern u32_021B95A0 func_0203630C(void);
extern u32_021B95A0 func_020362DC(void);
extern int func_021C49A4(u8 *p, unsigned int i);
extern Pos func_021C4AC4(void *v);
extern u32_021B9800 func_021C4864(u8 *p, u16 x, u16 y);
extern int func_021C5858(u8 *p);
extern void func_021C584C(u8 *p, int a);
extern void func_021C57D8(u8 *p, int v);
extern void func_021C57DC(u8 *p);
extern void func_021BA5B4(void *a, int b, u8 **p);
extern void func_021C5704(u8 *p);
extern void func_021C4948(void *p);
extern unsigned char func_021C4A8C(int i);
extern void func_021C5864(u8 *p, int b);
extern void func_021C5814(void *p, Pos pos);
extern void func_021BA594(char *p, int a, int b, int c);
extern int func_021BA5DC(void *b);
extern void func_021BA5F0(void *a, char *b, u8 c);
extern void func_021BA794(u8 *p, u8 b);
extern void func_021BA7BC(char *p);
extern void func_021BA660(int unused, void *p);
extern Pos func_021C4A54(Pos p, int n);
extern int func_021C5F80(void *q, int *out);
extern int func_021C5370(void *a, void *b, const u8 *desc, int *out);
extern void func_021C48D4(void *a, u8 *q);
extern u8 *func_021C4BA4(u8 *p, void *list, int n);
extern void *func_021C5590(void *,void *,u32_021B9D30,void *,int,u32_021B9D30,u32_021B9D30);
extern void func_021C5664(char *,int,int);
extern void func_021C5608(u8 *p);
extern int func_021C59F4(void *a, void *b, Tab *t, int x);
extern void func_021C5A4C(u8 *p);
extern void func_02049B40(u32_021B9E0C a, u32_021B9E0C b, u32_021B9E0C c, u32_021B9E0C d, u32_021B9E0C e, u16 f);
extern void func_02040EBC(u32_021B9E0C a, u32_021B9E0C b);
extern u32_021B9E0C func_02049624(void *a0, void *a1, void *a2, void *a3, u32_021B9E0C a4, u32_021B9E0C a5, u16 a6);
extern s32_021B9E50 func_0204A6C8(void *a, u32_021B9E50 b, u32_021B9E50 c, u32_021B9E50 a3, u16 flags);
extern s32_021B9E50 func_0204AC18(void *a, u32_021B9E50 b, u32_021B9E50 c, u32_021B9E50 d, u16 e, u16 f, u16 g);
extern s32_021B9E50 func_0204AF28(void *owner, u32_021B9E50 first, u32_021B9E50 second, u32_021B9E50 mode);
extern void CLACT_ReleaseCharacter(u32_021B9EA0 i);
extern void CLACT_ReleasePalette(u32_021B9EA0 i);
extern void CLACT_ReleaseCellAnim(u32_021B9EA0 i);
extern struct Obj_021B9EB8 *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, u16 f, u16 g);
extern void func_0204B3DC(struct Obj_021B9EB8 *p, unsigned int v);
extern void func_0204B92C(struct Obj_021B9EB8 *a, u32_021B9EB8 b);
extern void CLACT_DeleteActor(struct Obj_021B9EB8 *p);
extern void func_0204B528(void *,Pos_021B9EB8 *);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32_021B9F90 val);
extern u16 func_021C47F8(u16 *p);
extern u16 func_021C47FC(u16 *p);
extern u8 *func_021C5680(u8 *,void *,int,u32_021BA190);
extern void func_021C5840(char *,int);
extern void *func_021C4918(void *,Params *);
extern u32_021BA0F8 func_020056EC(u32_021BA0F8 x);
extern void func_021C57E8(char *p);
extern int func_021C5834(char *p);
extern int func_0203F5FC(u32 x);
extern void func_021C5898(void *p, Pos v);
extern void func_021C57F4(u8 *p);
void func_021B95A0(char *p, int heap, u32_021B95A0 x2, u32_021B95A0 x3, u32_021B95A0 a4, u32_021B95A0 a5, u32_021B95A0 a6, u32_021B95A0 a7);
void func_021B9670(char *p);
int func_021B96CC(int *p);
u32_021B95A0 func_021B96D0(char *p);
int func_021B9788(int a, int *b);
void func_021B97CC(char *p);
u8 func_021B97F4(W_021B95A0 *w);
void func_021B9800(Work *w);
int func_021B984C(Work_021B984C *w);
void func_021B989C(void *o, Rec_021B95A0 *r);
void func_021B98E4(int a, u8 *b);
void func_021B98F0(void *p);
void func_021B98F8(S_021B95A0 *s, u32_021B98F8 v);
u32_021B98FC func_021B98FC(S_021B95A0 *s);
u8 *func_021B9900(u8 *p, int v);
void *func_021B9968(Work_021B9968 *o, int a, int b);
void func_021B99F4(void *o, Ent_021B95A0 *e);
void func_021B9A34(Obj_021B9A34 *p);
u8 func_021B9A50(char *p);
unsigned char func_021B9A60(char *p);
void func_021B9A70(void *o, Ent_021B9A34 *e, int n);
void func_021B9AE0(void *w,u8 *s);
void func_021B9B00(void *a, char *b, u8 c);
void func_021B9B24(char *p);
void func_021B9B54(char *p);
void func_021B9B64(char *p);
void func_021B9B80(char *p);
BOOL func_021B9BA8(char *p);
int func_021B9BC4(Work_021B9BC4 *w);
void func_021B9C4C(Work_021B9C4C *w);
void func_021B9C9C(u8 *p);
void func_021B9CD0(char *p);
void *func_021B9CF8(char *p, u32_021B9CF8 *q, int c);
void func_021B9D30(u8 *p,void *q,u32_021B9D30 heap);
void func_021B9D5C(char *p);
void func_021B9D6C(Obj_021B9D6C *o, int x, int unused, int c);
void func_021B9DB0(char *p);
void func_021B9DC0(void *a, u32_021B9A34 b, u32_021B9A34 c);
void func_021B9DD4(void *a);
void func_021B9DE4(void *a, int b, u32_021B9A34 c);
void func_021B9DEC(void *a);
void func_021B9DF4(void *a, int b);
void func_021B9DFC(void *a);
void func_021B9E04(void *a, int heap);
void func_021B9E08(int a0);
void func_021B9E0C(void *a, u32_021B9E0C b, u32_021B9E0C c, u32_021B9E0C d);
void func_021B9E50(Obj *o, int a, u32_021B9E50 c);
void func_021B9EA0(S_021B9A34 *s);
void func_021B9EB8(Obj_021B9EB8 *o, int a);
void func_021B9F34(S_021B9EB8 *s);
void func_021B9F48(u8 *p);
void func_021B9F84(S_021B9F84 *s);
void func_021B9F90(Obj_021B9F84 *o, Pos pos, int c);
void func_021B9FD0(void *p);
int func_021B9FDC(Work *w);
void func_021BA04C(char *p, u16 *out, u32 c);
void func_021BA0F8(W_021BA0F8 *w, u16 *out);
u8 *func_021BA168(u8 *p);
void func_021BA190(u8 *p,u8 *s,int n);
void func_021BA1C4(u8 *p,void **out,short *xy,int a,u16 d,u8 c,int b);
BOOL func_021BA1FC(S *s);
void func_021BA228(void *w,u8 *s);
void func_021BA248(int unused, S_021BA248 *s);
void func_021BA264(void *w, S_021BA264 *s);
void func_021BA2A4(void *w,u8 *s);
void func_021BA2D0(void);
void func_021BA2D4(void *w, S_021BA2D4 *s);
void func_021BA36C(void *w, S_021BA36C *s);
int func_021BA418(W_021BA418 *w, S_021BA418 *s);
int func_021BA4C8(W_021BA4C8 *w, S_021BA4C8 *s);
int func_021BA520(W_021BA4C8 *w, S_021BA4C8 *s);
int func_021BA538(void *w, S_021BA538 *s);
int func_021BA578(void *w, S_021BA538 *s);
int func_021BA590(void);
extern Tab d_021C289C;







void func_021B95A0(char *p, int heap, u32_021B95A0 x2, u32_021B95A0 x3, u32_021B95A0 a4, u32_021B95A0 a5, u32_021B95A0 a6, u32_021B95A0 a7)
{
    WH t;
    u32_021B95A0 n = 0;
    func_02082BCC(p, 0, 0x5A0);
    if (a4 != 0) n = (a4 - 1) >> 3;
    *(u32_021B95A0 *)(p + 0x14) = a6;
    *(u32_021B95A0 *)(p + 4) = heap;
    *(u32_021B95A0 *)(p + 0x18) = a7;
    func_021B9DC0(p + 0x14, heap, x2);
    func_021B9E04(*(void **)(p + 0x10), heap);
    t = func_021BA810(n);
    *(void **)(p + 0x588) = func_021C47A0(t.w, t.h, heap);
    func_021C4800(*(void **)(p + 0x588), (void *)func_021BA81C(n));
    *(void **)(p + 0x58C) = func_021C4880(0x30, heap);
    func_021B9D30((u8 *)p, (void *)x3, heap);
    func_021C59D0(p + 0x594);
    func_021B9D6C((Obj_021B9D6C *)p, heap, x2, n);
    func_021B9E0C(*(void **)(p + 0x10), heap, x2, a5);
    func_021BA60C(p, p + 0x574, x2, a5);
    *(void **)(p + 0x59C) = func_021C5EEC(0x80, heap);
    *(u32_021B95A0 *)p = 1;
}







void func_021B9670(char *p)
{
    func_021C5F30((u8 *)(((Ov099Work *)p)->f59C));
    func_021B9DB0(p);
    func_021BA648((int)p, p + 0x574);
    func_021B9B80(p);
    func_021B9D5C(p);
    func_021C48C0((u8 *)((int)((Ov099Work *)p)->f58C));
    func_021C47E4((u8 *)(((Ov099Work *)p)->f588));
    func_021B9DD4(p + 0x14);
    func_021B9E08(((Ov099Work *)p)->f10);
    func_02082BCC(p, 0, 0x5a0);
}






int func_021B96CC(int *p)
{
    return *p;
}







u32_021B95A0 func_021B96D0(char *p)
{
    if (*(u32_021B95A0 *)0x02FFFC3C & 1) {
        func_021C48E8(*(void **)(p + 0x58C));
        func_021B9C9C((u8 *)p);
        func_021B9C4C((Work_021B9C4C *)p);
        func_021C5994(p + 0x594, **(void ***)(p + 0x570));
        func_021C5A60(*(char **)(p + 0x598), p + 0x594);
        func_021C571C(*(void **)(p + 0x590));
        func_021B9CD0(p);
        func_021B9F84((S_021B9F84 *)p);
    }
    if (func_021B9BA8(p) == 1) {
        func_021B97CC(p);
        if (func_021B9FDC((Work *)p) == 1) {
            func_021B9F48((u8 *)p);
            if (func_0203630C() & 0x80)
                return 1;
        }
        if (func_020362DC() & 1) {
            if (func_021B97F4((W_021B95A0 *)p) != 0)
                return 2;
            if (func_021B9BC4((Work_021B9BC4 *)p) == 1)
                return 3;
        }
    }
    return 0;
}







int func_021B9788(int a, int *b)
{
    int v;
    int c;
    int *r;

    c = func_021C49A4((u8 *)b[0], 6);
    if (func_020362DC() & 1) {
        r = func_021B9CF8((char *)a, (u32_021B9CF8 *)b, c);
        if (r != 0) {
            if (func_021BA1FC((S *)r) == 1)
                v = func_021C49A4((u8 *)r[0], 4);
            else
                v = 0;
        } else
            v = 0;
        ((struct Obj13676 *)b)->fA = v;
    }
    return 1;
}







void func_021B97CC(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021B97CC *)(p + i * 0x1C + 0x30) != 0) {
            func_021B9788((int)p, (int *)(p + 0x30 + i * 0x1C));
        }
    }
}







u8 func_021B97F4(W_021B95A0 *w)
{
    return ((u8 *)w->p)[0xA];
}







void func_021B9800(Work *w)
{
    Pos b = func_021C4AC4(*w->f570);

    func_021C4864(w->f588, b.x / 16, b.y / 16);
}






int func_021B984C(Work_021B984C *w)
{
    Pos b = func_021C4AC4(*w->f570);

    return func_021C4864(w->f588, b.x / 16, b.y / 16 + 1);
}






void func_021B989C(void *o, Rec_021B95A0 *r)
{
    Pos p = func_021C4AC4(r->f0);

    func_021B9F90(o, p, func_021C5858(r->f4) - 2);
    func_021C584C(r->f4, 0);
}





void func_021B98E4(int a, u8 *b) { func_021C584C((u8 *)(((struct Obj22009 *)b)->f4), 1); }





void func_021B98F0(void *p) { func_021B9FD0(p); }






void func_021B98F8(S_021B95A0 *s, u32_021B98F8 v)
{
    s->f0C = v;
}






u32_021B98FC func_021B98FC(S_021B95A0 *s)
{
    return s->f0C;
}






u8 *func_021B9900(u8 *p, int v)
{
    u8 *s;
    u16 xy[2];

    s = func_021BA168(p);
    *(u8 **)(p + 0x570) = s;
    func_021BA0F8((W_021BA0F8 *)p, xy);
    func_021BA1C4(p, (void **)s, (short int *)xy, 0, v, 0, 0);
    func_021BA228(p, s);
    func_021BA190(p, s, 1);
    func_021C5994(p + 0x594, **(void ***)(p + 0x570));
    func_021C5A60(*(char **)(p + 0x598), p + 0x594);
    return s;
}






void *func_021B9968(Work_021B9968 *o, int a, int b)
{
    void *e;
    Pos t;
    Pos d;

    e = func_021BA168((u8 *)o);
    func_021BA04C((char *)o, (u16 *)(&t), b - 1);
    if (o->f570 != 0) {
        d = func_021C4AC4(*o->f570);
        if (d.x == t.x && d.y == t.y)
            return 0;
    }
    func_021BA1C4((u8 *)o, e, (short int *)(&t), b, a, 1, 4);
    func_021BA248((int)o, e);
    func_021BA190((u8 *)o, e, 0);
    return e;
}






void func_021B99F4(void *o, Ent_021B95A0 *e)
{
    func_021C49A4(e->f0, 6);
    e->f10 = 0x021BA521;
    e->f8 = 0;
    e->f18 = 0x021BA2D5;
    e->fc = 2;
    func_021C57D8(e->f4, 0);
    func_021C57DC(e->f4);
    func_021BA5B4(o, 4, (u8 **)e);
}








/*
 * ("ldr r3, =0x02082BCC; movs r1, #0; movs r2, #0x18; bx r3"); witness
 * bl from ov099 at 0x021B9A40. Seeding it (ov127 lane) makes this EXACT.
 */
void func_021B9A34(Obj_021B9A34 *p)
{
    func_021C5704(p->f4);
    func_021C4948(p->f0);
    func_02082BCC(p, 0, sizeof(Obj_021B9A34));
}








u8 func_021B9A50(char *p)
{
    return (u8)func_021C49A4(((struct Obj18147 *)p)->f0, 4);
}








/*
 * Two ov127 calls, the second on the first one's answer.
 *
 * NOT EXACT.  MATCH: 16 bytes, the call sequence and the first relocation are
 * right; the second target 0x021C4A8C has no witness.  It is not a `func_` label
 * in any overlay listing, yet nine overlays overlap the address (ov016, ov021,
 * ov093, ov111, ov114, ov127, ov136, ov172, ov208), so a region hint cannot name
 * one either.  It turns EXACT as soon as 0x021C4A8C is labelled or matched.
 *
 * UNBLOCKED: 0x021C4A8C is now an EXACT entry in layout/matched/ov127;
 * the second call site resolves as matched, verdict promoted to EXACT.
 */
unsigned char func_021B9A60(char *p)
{
    return func_021C4A8C(func_021C49A4(((struct Obj18148 *)p)->f0, 6));
}








void func_021B9A70(void *o, Ent_021B9A34 *e, int n)
{
    Pos s;

    e->f14 = e->f10;
    e->f10 = 0x021BA591;
    e->fe = e->fc;
    e->fc = 5;
    func_021BA594(o, 0, n, func_021C49A4(e->f0, 4));
    func_021C57D8(e->f4, 0);
    func_021C5864(e->f4, n);
    s.x = func_021C49A4(e->f0, 0);
    s.y = func_021C49A4(e->f0, 1);
    func_021C5814(e->f4, s);
}







void func_021B9AE0(void *w,u8 *s) { if (s) { if (((struct Obj04411 *)s)->f14) { ((struct Obj04411 *)s)->f10=((struct Obj04411 *)s)->f14; ((struct Obj04411 *)s)->f14=0; ((struct Obj04411 *)s)->fC=((struct Obj04411 *)s)->fE; func_021C57D8(((struct Obj04411 *)s)->f4,1); } } }








void func_021B9B00(void *a, char *b, u8 c)
{
    if (func_021BA5DC(b) == 0) {
        b[0xB] = c;
    } else {
        func_021BA5F0(a, b, c);
    }
}








void func_021B9B24(char *p)
{
    if (func_021B9BC4((Work_021B9BC4 *)p) == 1) {
        s8 x = (s8)func_021B984C((Work_021B984C *)p);
        s8 y = x - 3;

        func_021BA794((u8 *)(p + 0x574), y);
    }
}








void func_021B9B54(char *p)
{
    func_021BA7BC(p + 0x574);
}








void func_021B9B64(char *p)
{
    if (*(u32_021B9B64 *)0x02FFFC3C & 1) {
        func_021BA660((int)p, p + 0x574);
    }
}








void func_021B9B80(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021B9B80 *)(p + i * 0x1C + 0x30) != 0) {
            func_021B9A34((Obj_021B9A34 *)(p + 0x30 + i * 0x1C));
        }
    }
}








/*
 * True when the object 0x570 bytes in is not of class 5.
 */
BOOL func_021B9BA8(char *p)
{
    if (func_021C49A4(*(void **)((Ov099Work *)p)->f570, 5) == 0) {
        return 1;
    }

    return 0;
}








int func_021B9BC4(Work_021B9BC4 *w)
{
    Pos b;
    Pos d;
    int n;
    int r;

    b = func_021C4AC4(*w->f570);
    n = func_021C49A4(*w->f570, 6);
    d = func_021C4A54(b, n);
    r = func_021C4864(w->f588, d.x / 16, d.y / 16);
    if (n == 0 && r == 2)
        return 1;
    return 0;
}








void func_021B9C4C(Work_021B9C4C *w)
{
    int a;
    int b[2];

    while (func_021C5F80(w->f59c, &a) == 1) {
        if (func_021C5370(w->f588, w->f58c, (const u8 *)(&a), b) == 1)
            func_021C48D4(w->f58c, (u8 *)b);
    }
}







void func_021B9C9C(u8 *p) { int i; int offset; u8 *base; i=0; base=p+48; for(;i<48;i++) { offset=i*28; if (*(u32_021B9C9C *)(p+offset+48)) { if ((*(int (**)(void *,void *))(p+offset+64))(p,base+offset)==1) func_021B9A34((Obj_021B9A34 *)(base+offset)); } } }








/*
 * Walks the 0x30 records of 0x1C bytes at +0x30 and calls the handler stored
 * at +0x48 of each occupied one with (p, record).
 */
void func_021B9CD0(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021B9CD0 *)(p + i * 0x1C + 0x30) != 0) {
            void (*f)(char *, char *) = *(void (**)(char *, char *))(p + i * 0x1C + 0x48);

            f(p, p + 0x30 + i * 0x1C);
        }
    }
}








/*
 * Asks the ov127 routine at 0x021C4BA4 for a handle (the word the caller
 * points at, plus the pointer at +0x58C) and then walks the 0x30 records of
 * 0x1C bytes at +0x30 looking for it; returns the record address or zero.
 * The record expression is written field-constant-first on the return
 * (`p + 0x30 + i * 0x1C`), which is the spelling whose register choice the
 * image has.
 */
void *func_021B9CF8(char *p, u32_021B9CF8 *q, int c)
{
    void *v = func_021C4BA4((void *)*q, ((Ov099Work *)p)->f58C, c);
    int i;

    if (v != 0) {
        for (i = 0; i < 0x30; i++) {
            if (*(void **)(p + i * 0x1C + 0x30) == v) {
                return (char *)(p + 0x30) + i * 0x1C;
            }
        }
    }
    return 0;
}







void func_021B9D30(u8 *p,void *q,u32_021B9D30 heap) { void *r; r=func_021C5590(((Ov099Work *)p)->f14,0,48,q,0,0,heap); ((Ov099Work *)p)->f590=r; func_021C5664(r,2,heap); }








/*
 * Tail call into ov127 on the pointer 0x590 bytes into the block.
 */
void func_021B9D5C(char *p)
{
    func_021C5608(((Ov099Work *)p)->f590);
}







void func_021B9D6C(Obj_021B9D6C *o, int x, int unused, int c)
{
    Tab t = d_021C289C;

    t.b[9] += (u8)c;
    o->f598 = func_021C59F4(o->f18, o->f10, &t, x);
}







void func_021B9DB0(char *p)
{
    func_021C5A4C(((Ov099Work *)p)->f598);
}







void func_021B9DC0(void *a, u32_021B9A34 b, u32_021B9A34 c)
{
    func_021B9DE4(a, b, c);
    func_021B9DF4(a, b);
}







void func_021B9DD4(void *a)
{
    func_021B9DFC(a);
    func_021B9DEC(a);
}







/*
 * Tail call thunk onto func_021B9E50.
 */
void func_021B9DE4(void *a, int b, u32_021B9A34 c)
{
    func_021B9E50(a, b, c);
}







void func_021B9DEC(void *a)
{
    func_021B9EA0(a);
}







/*
 * Tail call thunk onto func_021B9EB8.
 */
void func_021B9DF4(void *a, int b)
{
    func_021B9EB8(a, b);
}







void func_021B9DFC(void *a)
{
    func_021B9F34(a);
}






/*
 * Empty body: the original is a bare `bx lr`.  disasm.py labels it only
 * because something branches to it.
 */
void func_021B9E04(void *a, int heap)
{
}





void func_021B9E08(int a0)
{
}






void func_021B9E0C(void *a, u32_021B9E0C b, u32_021B9E0C c, u32_021B9E0C d)
{
    u32_021B9E0C z = 0;
    func_02049B40(d, 7, 0, 0, 0x100, b);
    func_02040EBC(0, 0);
    func_02049624((void *)d, (void *)0x10, 0, 0, z, z, b);
}






void func_021B9E50(Obj *o, int a, u32_021B9E50 c)
{
    o->f8 = func_0204A6C8((void *)c, 0x11, 0, 0, a);
    o->fc = func_0204AC18((void *)c, 8, 0, 0x160, 0, 2, a);
    o->f10 = func_0204AF28((void *)c, 0x14, 0x20, (u16)a);
}






/*
 * Releases three pointers at +8, +0xC and +0x10 through three arm9 helpers.
 */
void func_021B9EA0(S_021B9A34 *s)
{
    CLACT_ReleaseCharacter((u32_021B9EA0)s->f08);
    CLACT_ReleasePalette((u32_021B9EA0)s->f0C);
    CLACT_ReleaseCellAnim((u32_021B9EA0)s->f10);
}








void func_021B9EB8(Obj_021B9EB8 *o, int a)
{
    Rec_021B9EB8 r;

    r.a = 1;
    r.b = 1;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    o->f14 = (u32_021B9EB8)(struct Obj *)func_0204B294((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    r.c = 2;
    r.d = 0xfe;
    r.e = 3;
    o->f18 = (u32_021B9EB8)(struct Obj *)func_0204B294((void *)o->f0, o->f8, o->fc, o->f10, &r, 0, a);
    func_0204B3DC((struct Obj_021B9EB8 *)o->f14, 0);
    func_0204B3DC((struct Obj_021B9EB8 *)o->f18, 0);
    func_0204B92C((struct Obj_021B9EB8 *)o->f14, 1);
    func_0204B92C((struct Obj_021B9EB8 *)o->f18, 1);
}








void func_021B9F34(S_021B9EB8 *s)
{
    CLACT_DeleteActor(s->f14);
    CLACT_DeleteActor(s->f18);
}






void func_021B9F48(u8 *p) { Pos_021B9EB8 b; Pos_021B9EB8 a; func_021BA0F8((W_021BA0F8 *)p,(u16 *)&b); b.x+=8; b.y+=32; a.x=b.x; a.y=b.y; func_0204B528(((Ov099Work *)p)->f28,&a); func_0204B3DC(((Ov099Work *)p)->f28,1); }







void func_021B9F84(S_021B9F84 *s)
{
    func_0204B3DC((struct Obj_021B9EB8 *)s->f28, 0);
}







void func_021B9F90(Obj_021B9F84 *o, Pos pos, int c)
{
    Pos t;

    t.x = pos.x + 8;
    t.y = pos.y;
    func_0204B528(o->f2c, (Pos_021B9EB8 *)((const struct Pt *)(&t)));
    CLACT_SetActorDrawPriority(o->f2c, (unsigned char)c);
    func_0204B3DC((struct Obj_021B9EB8 *)o->f2c, 1);
}






/*
 * Unlabelled Thumb tail-call thunk in a .word run:
 *   ldr r0,[r0,#0x2c]; ldr r3,[pc,#4]; movs r1,#0; bx r3; .word 0x0204B3DC
 */
void func_021B9FD0(void *p)
{
    func_0204B3DC((struct Obj_021B9EB8 *)((struct Obj *)((struct Obj22013 *)p)->f2C), 0);
}






int func_021B9FDC(Work *w)
{
    Pos b;
    int n;

    if (w->f570 == 0)
        return 0;
    b = func_021C4AC4(*w->f570);
    n = func_021C49A4(*w->f570, 6);
    if (func_021C4864(w->f588, b.x / 16, b.y / 16) == 15 && n == 1)
        return 1;
    return 0;
}




void func_021BA04C(char *p, u16 *out, u32 c)
{
    u32 y, h, x, w;
    u32 hi = c >> 3;
    u32 lo = c & 7;

    w = func_021C47F8(*(void **)(p + 0x588));
    h = func_021C47FC(*(void **)(p + 0x588));
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if ((void *)func_021C4864((u8 *)(*(void **)(p + 0x588)), x, y) == (void *)(lo + 7)
                && (void *)func_021C4864((u8 *)(*(void **)(p + 0x588)), x, y + 1) == (void *)(hi + 3)) {
                out[0] = x << 4;
                out[1] = y << 4;
                return;
            }
        }
    }
}






void func_021BA0F8(W_021BA0F8 *w, u16 *out)
{
    u32_021BA0F8 j;
    u32_021BA0F8 n2;
    u32_021BA0F8 i;
    u32_021BA0F8 n1;

    n1 = func_021C47F8(w->f588);
    n2 = func_021C47FC(w->f588);
    for (j = 0; j < n2; j++) {
        for (i = 0; i < n1; i++) {
            if (func_021C4864(w->f588, i, j) == 0xf) {
                out[0] = i * 16;
                out[1] = j * 16;
                return;
            }
        }
    }
}







/*
 * Scans the 0x30 records of 0x1C bytes at +0x30 and returns the address of the
 * first whose leading word is zero, else 0.  Two earlier lanes read the
 * product/address register pair as allocator taste; it is the two address
 * spellings.  With both written field-constant-first the compiler homes the
 * `i * 0x1C` product in r2 and prints `adds r3, r0, r2`, which is not what the
 * image has.  Writing the load field-last (`p + i * 0x1C + 0x30`, giving
 * `adds r2, r0, r3 ; ldr r2, [r2, #0x30]`) and the exit field-first
 * (`(u8 *)(p + 0x30) + i * 0x1C`, giving `adds r0, #0x30 ; adds r0, r0, r3`)
 * is what reproduces the image exactly.
 */
u8 *func_021BA168(u8 *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32_021BA168 *)(p + i * 0x1C + 0x30) == 0) {
            return (u8 *)(p + 0x30) + i * 0x1C;
        }
    }
    return 0;
}






void func_021BA190(u8 *p,u8 *s,int n) { *(u8 * *)&((struct Obj02660 *)s)->f4=func_021C5680((u8 *)((Ov099Work *)p)->f590,((struct Obj02660 *)s)->f0,n,(unsigned int)((Ov099Work *)p)->f4); if (n==0) { func_021C57D8(((struct Obj02660 *)s)->f4,0); func_021C57DC(*(u8 * *)&((struct Obj02660 *)s)->f4); func_021C5840(*(char * *)&((struct Obj02660 *)s)->f4,0); } }






void func_021BA1C4(u8 *p,void **out,short *xy,int a,u16 d,u8 c,int b) { Params q; q.x=xy[0]; q.y=xy[1]; q.a=a; q.b=b; q.c=c; q.d=d; *out=func_021C4918(((Ov099Work *)p)->f58C,&q); }







BOOL func_021BA1FC(S *s)
{
    switch (s->f0C) {
    case 0:
    case 3:
    case 4:
        return 1;
    case 1:
    case 2:
    case 5:
        return 0;
    }

    return 0;
}






void func_021BA228(void *w,u8 *s) { ((struct Obj02800 *)s)->f10=(void *)func_021BA418; ((struct Obj02800 *)s)->f18=(void *)func_021BA2D0; ((struct Obj02800 *)s)->fC=0; func_021BA5B4(w,0,(u8 **)s); }






void func_021BA248(int unused, S_021BA248 *s)
{
    s->f10 = (void *)func_021BA4C8;
    s->f18 = (void *)func_021BA2D4;
    s->f08 = 0x2D;
    s->f0C = 1;
}






/*
 * Lever: n = 0x400 in a u32_021BA0F8 local keeps 0x400>>2 a runtime lsrs.
 * func_021BA2D0 is the empty callback filed as its own ov099 leaf.
 */
/*
 * Lever: n = 0x400 in a u32 local keeps 0x400>>2 a runtime lsrs.
 * func_021BA2D0 is the empty callback filed as its own ov099 leaf.
 */
void func_021BA264(void *w, S_021BA264 *s)
{
    u32_021BA0F8 n;

    s->f10 = (void *)func_021BA538;
    s->f18 = (void *)func_021BA2D0;
    n = 0x400;
    s->f8 = func_020056EC(n) + (n >> 2);
    s->fc = 3;
    func_021BA5B4(w, 0, (u8 **)s);
    func_021C57D8(s->f4, 1);
}




void func_021BA2A4(void *w,u8 *s) { ((struct Obj02448 *)s)->f10=(void *)func_021BA578; ((struct Obj02448 *)s)->f18=(void *)func_021BA36C; ((struct Obj02448 *)s)->f8=28; ((struct Obj02448 *)s)->fC=4; func_021BA5B4(w,4,(u8 **)s); func_021C57D8(((struct Obj02448 *)s)->f4,0); }




void func_021BA2D0(void)
{
}




void func_021BA2D4(void *w, S_021BA2D4 *s)
{
    Pos pos;
    Pos q;

    func_021C57E8(s->f4);
    if (func_021C5834(s->f4) == 0) {
        func_021C5840(s->f4, 1);
    }
    pos.x = func_021C49A4(s->f0, 0);
    pos.y = func_021C49A4(s->f0, 1);
    q = pos;
    pos.y = pos.y + (s16)((s32_021BA2D4)(((long long)func_0203F5FC(s->f8) * -786432 + 0x800) >> 12) >> 12);
    func_021C5814(s->f4, pos);
    func_021C5898(s->f4, q);
}




/*
 * Parked at MATCH: every byte is right, the single wildcard is the
 * blx to the unlabelled arm9 leaf 0x0203F5FC (no witness outside the range;
 * an arm9 leaf is the integrator's).  Same blocker as ov099_func_021BA2D4.c.
 *
 * with `one --arm` (no --region), C:
 *
 *   typedef unsigned long u32;
 *   typedef signed short s16;
 *   extern const s16 d_020A1B38[];   (0x020A1B38 data a2)
 *   int func_0203F5FC(u32 a)
 *   {
 *       int t;
 *       if (a >= 360) {
 *           return 0;
 *       }
 *       t = (int)(a * 65535) / 360;
 *       return d_020A1B38[(t >> 4) * 2];
 *   }
 */
void func_021BA36C(void *w, S_021BA36C *s)
{
    Pos pos;
    Pos q;
    int t;

    pos.x = func_021C49A4(s->f0, 0);
    pos.y = func_021C49A4(s->f0, 1);
    q = pos;
    t = (s16)(s->f8 - 16);
    if (t > 0) {
        pos.y = pos.y - (s16)((s32_021BA2D4)(((long long)func_0203F5FC((u16)(180 * (s16)(t % 6) / 6)) * 16384 + 0x800) >> 12) >> 12);
    }
    func_021C5814(s->f4, pos);
    func_021C5898(s->f4, q);
    func_021C5864(s->f4, 1);
}




/*
 * Lever: the pad read is a named local (t) assigned before k = 2, so the
 * movs r7,#2 lands after the first blx.
 */
int func_021BA418(W_021BA418 *w, S_021BA418 *s)
{
    int a;
    int b;
    int k;
    int t;

    a = func_021C49A4(s->f0, 6);
    b = func_021C49A4(s->f0, 4);
    if (func_021C49A4(s->f0, 5) != 0) {
        return 0;
    }
    if (w->fc == 1) {
        return 0;
    }
    t = func_0203630C();
    k = 2;
    if (t & 2) {
        k = 3;
    }
    if (func_0203630C() & 0x40) {
        if (a == 0) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 0, b);
        }
    } else if (func_0203630C() & 0x80) {
        if (a == 1) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 1, b);
        }
    } else if (func_0203630C() & 0x20) {
        if (a == 2) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 2, b);
        }
    } else if (func_0203630C() & 0x10) {
        if (a == 3) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 3, b);
        }
    }
    return 0;
}




int func_021BA4C8(W_021BA4C8 *w, S_021BA4C8 *s)
{
    int a;
    int b;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        func_021C57F4(s->f4);
        func_021C57D8(s->f4, 1);
        a = func_021C49A4(*w->f570, 4);
        b = func_021C49A4(s->f0, 4);
        if (b == a) {
            func_021BA228(w, (u8 *)s);
        } else {
            func_021BA5F0(w, (char *)s, s->fb);
        }
    }
    return 0;
}




int func_021BA520(W_021BA4C8 *w, S_021BA4C8 *s)
{
    s->f8 = s->f8 + 1;
    if (s->f8 > 0x2d) {
        return 1;
    }
    return 0;
}




/*
 * func_021BA578 (counter reload leaf) and func_021BA590 (returns 0) are
 * the unlabelled leaves after the lead function (seed function_starts
 * 0x021BA578, 0x021BA590).
 */
int func_021BA538(void *w, S_021BA538 *s)
{
    int r;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        s->f8 = func_020056EC(0x400) + 0x100;
        r = func_020056EC(4);
        func_021BA594(w, 0, r, func_021C49A4(s->f0, 4));
    }
    return 0;
}




int func_021BA578(void *w, S_021BA538 *s)
{
    s->f8 = s->f8 - 1;
    if (s->f8 < 0) {
        s->f8 = 0x1c;
    }
    return 0;
}




int func_021BA590(void)
{
    return 0;
}
