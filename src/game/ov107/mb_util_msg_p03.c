/*
 * file:     mb_util_msg_p03.c
 * unit:     yes
 * function: func_021F19B8, func_021F19C8, func_021F19E4, func_021F1A24, func_021F1A2C, func_021F1A58, func_021F1AFC, func_021F1B00, func_021F1B04, func_021F1B08, func_021F1B14, func_021F1B24, func_021F1B38
 * address:  0x021F19B8
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
 *   func_02027858 0x02027858 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02028470 0x02028470 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */
#include "../../matched/include/Obj13765.h"
#include "../../matched/include/Obj13766.h"
#include "../../matched/include/Obj22305.h"
#include "../../matched/include/Obj13767.h"
#include "../../matched/include/Obj22306.h"
#include "../../matched/include/Obj22307.h"
#include "../../matched/include/Obj22310.h"

#define P(k) (*(void **)(p+(k)))
#define I(k) (*(int *)(p+(k)))
struct TaskMenu;
struct MsgBank;
struct CharBuf;
struct Rec;
struct Rec3;
struct U16Vec;
struct Descriptor;
struct PrintSys;
struct Cfg;
typedef unsigned int   u32;

typedef struct {
    unsigned char f00;
    unsigned char f01;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
} Ov107Win;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned char pad04[0x44];
    Ov107Win win;
    unsigned char pad4E[2];
    void *f50;
} Ov107Ctx_021F19E4;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef struct {
    unsigned char pad00[0x50];
    void *f50;
} Ov107Ctx_021F1A2C;

typedef struct { u8 pad00[0x30]; struct PrintSys *f30; } Context;

typedef struct {
    unsigned char pad00[0x18];
    void *f18;
} Ov107Ctx_021F1B14;

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned char pad04[0xC];
    void *f10;
    unsigned char pad14[0x24];
    int f38;
} Ov107Ctx_021F1B24;

extern void func_02027858(struct TaskMenu *);
extern u32 func_020279E8(struct TaskMenu *m);
extern unsigned char func_02027A04(const unsigned char *);
void *func_0201FDA0(Ov107Win *win, int base, int pal, int pos, int heap);
u32 func_0201FEBC(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *,int,int,int);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02028470(u8 *p, u32 v);
extern void * func_02045770(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_0201CCE4(void *,int,int,void *,void *,int,void *,int,int,int);
extern u32 func_0201C6B4(const struct PrintSys *);
void func_02045374(struct Cfg *cfg);
void func_020409B4(u32 index);
void func_021F19B8(unsigned char *a);
int func_021F19C8(unsigned char *a);
void func_021F19E4(Ov107Ctx_021F19E4 *p);
void func_021F1A24(u8 *p);
int func_021F1A2C(Ov107Ctx_021F1A2C *p);
void func_021F1A58(char *p,int a);
u32 func_021F1AFC(u8 *p);
u32 func_021F1B00(u8 *p);
unsigned int func_021F1B04(unsigned char *p);
int func_021F1B08(Context *p);
int func_021F1B14(Ov107Ctx_021F1B14 *p);
void func_021F1B24(Ov107Ctx_021F1B24 *p, int x);
void func_021F1B38(u8 *p, u32 v);

void func_021F19B8(unsigned char *a) { func_02027858(*(struct TaskMenu * *)&((struct Obj13765 *)a)->f3C); ((struct Obj13765 *)a)->f3C=0; }

int func_021F19C8(unsigned char *a) { if(func_020279E8(((struct Obj13766 *)a)->f3C)==1) return func_02027A04(((struct Obj13766 *)a)->f3C)+1; return 0; }


void func_021F19E4(Ov107Ctx_021F19E4 *p)
{
    p->win.f00 = p->f03;
    p->win.f01 = 0x18;
    p->win.f02 = 0xD;
    p->win.f03 = 0xE;
    p->win.f04 = 0;
    p->f50 = func_0201FDA0(&p->win, 1, 0xD, 0, p->f00);
}


void func_021F1A24(u8 *p) { ((struct Obj22305 *)p)->f50 = 0; }


int func_021F1A2C(Ov107Ctx_021F1A2C *p)
{
    int r = func_0201FEBC(p->f50);
    if (r == 0) {
        p->f50 = 0;
        return 1;
    }
    if (r == -2) {
        p->f50 = 0;
        return 2;
    }
    return 0;
}

void func_021F1A58(char *p,int a)
{
    void *s;
    s=func_02045B38(0,3,158,((struct Obj13767 *)p)->f0);
    if(P(0x18)){func_0201CE48(P(0x18));P(0x18)=0;}
    I(0x38)=0;I(0x58)=0;
    if(P(0x20)){func_02045808(P(0x20));P(0x20)=0;}
    func_02043B5C(func_02045770(P(0x10)),15);
    P(0x20)=func_02045EC0(s,22);
    P(0x18)=func_0201CCE4(P(0x10),0,0,P(0x20),P(0x14),a,P(12),2,((struct Obj13767 *)p)->f0,15);
    func_0201F73C(P(0x10),1,1,13);
    func_02045C04(s);
    if(I(8)==1)func_02028470((u8 *)(p+0x28),6);else func_02028470((u8 *)(p+0x28),4);
}


u32 func_021F1AFC(u8 *p) { return ((struct Obj22306 *)p)->f1C; }


u32 func_021F1B00(u8 *p) { return ((struct Obj22307 *)p)->f24; }

/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
unsigned int func_021F1B04(unsigned char *p)
{
    return *(unsigned int *)(p + 0x14);
}

/*
 * leaf: parent cleared original 12-byte Thumb tail getter. Full matched
 * 0201C6B4 returns only0/1 and reads its first input's pointer field10.
 */
int func_021F1B08(Context *p)
{
    return func_0201C6B4(p->f30);
}


int func_021F1B14(Ov107Ctx_021F1B14 *p)
{
    if (p->f18 == 0) {
        return 1;
    }
    return 0;
}


void func_021F1B24(Ov107Ctx_021F1B24 *p, int x)
{
    p->f38 = x;
    func_02045374(p->f10);
    func_020409B4(p->f02);
}


void func_021F1B38(u8 *p, u32 v) { ((struct Obj22310 *)p)->f58 = v; }
