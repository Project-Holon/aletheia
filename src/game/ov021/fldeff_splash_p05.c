/*
 * file:     fldeff_splash_p05.c
 * unit:     yes
 * function: func_021C4E08, func_021C4E20, func_021C4E34, func_021C4E6C, func_021C4F7C, func_021C51A0, func_021C5224, func_021C5334, func_021C5348, func_021C536C, func_021C5380, func_021C5394, func_021C53A0, func_021C5424, func_021C5440, func_021C54C8, func_021C553C, func_021C56F8, func_021C5768, func_021C576C
 * address:  0x021C4E08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201160C  0x0201160C  thumb
 *   func_0202B934  0x0202B934  thumb
 *   _fdiv          0x0209CE10  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fls           0x0209BC74  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   func_02011638  0x02011638  thumb
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_020520FC  0x020520FC  arm
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040C14  0x02040C14  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C450  0x0201C450  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C40C  0x0200C40C  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   d_021DE498     0x021DE498  data  ov021  a1
 *   d_021DAA60     0x021DAA60  data  a4
 *   d_021DAA54     0x021DAA54  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021C59BC 0x021C59BC thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021C58CC  0x021C58CC  thumb  ov021
 *   func_021C59A8  0x021C59A8  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 *   func_021C59F8  0x021C59F8  thumb  ov021
 *   func_020202FC  0x020202FC  thumb
 *   func_02020324  0x02020324  thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020202EC 0x020202EC thumb
 *   func_02020350 0x02020350 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020200CC 0x020200CC thumb
 *   func_02020344 0x02020344 thumb
 *   func_0200C480 0x0200C480 thumb
 *   func_021C577C 0x021C577C thumb ov021
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 */
#include "../../matched/include/Obj01666.h"
#include "../../matched/include/Obj00960.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj01216.h"
#include "../../matched/include/Obj18304.h"
#include "../../matched/include/Obj07562.h"
#include "../../matched/include/Obj12940.h"
#include "../../matched/include/Obj12941.h"
#include "../../matched/include/Obj12942.h"
#include "../../matched/include/Obj00874.h"
#include "../../matched/include/Obj18305.h"
#include "../../matched/include/Obj04281.h"
#include "../../matched/include/Obj00523.h"
#include "../../matched/include/Obj02094.h"
#include "../../matched/include/Obj20207.h"

struct IcaAnime;
struct Obj11245;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Bank;
struct GfFont;
struct MsgBank;
struct Obj;
struct PrintSys;
struct Rec;
struct Node;
struct Descriptor;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    V3 *pos;
} R;

typedef int            s32_021C4E6C;

typedef unsigned char  u8;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

typedef signed int     s32_021C4F7C;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 f0;
    void *msg;
    u8 pad8[0x1C];
    u32 f24;
    u8 pad28[0xC];
    u16 h34;
    u16 pad36;
    u8 pad38[8];
    u32 f40;
} S;

extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_0201160C(struct Obj11245 *p);
extern u32 func_02011610(struct IcaAnime *t, struct Rec12 *v);
extern void func_0202B934(u32 a, u32 b, V3 *v);
extern u32 func_02011638(struct IcaAnime *ctx, struct Rec12 *hsv);
extern void func_0207ADC4(void *p);
extern void func_020520FC(int h, int s, int v, struct Mtx33 *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02082BCC(void *p, int v, int n);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(int);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern s32_021C4F7C func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021C4F7C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021C4F7C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *obj, unsigned int v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0201C450(u16 n, u32 heap);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C40C(void *sys);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204B3B4(struct Obj *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern u32 func_020307B0(void *p);
extern void func_020061E4(u32 se);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021C59BC(void *a, u8 *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void func_021C58CC(char *p, u16 a, u16 b, u32 heap);
extern u32 func_020452E8(struct Descriptor *d);
extern int func_021C59A8(u32 a, u32 b, u32 c);
extern u32 func_02020350(struct Obj *obj, u32 what);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern u16 func_02020324(struct Obj *obj, u32 n);
extern void func_021C59F8(S *p, int v);
extern void func_020355D8(u8 v);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_02020344(struct Obj *obj, u32 n);
extern u8 func_0200C480(u8 *a, int id, u8 pos);
extern void func_021C577C(void *list, int a, int b);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
void func_021C4E08(R *r, s32 frame);
u32 func_021C4E20(R *r);
void func_021C4E34(R *r);
void func_021C4E6C(char *p);
char *func_021C4F7C(void *a0, int mode, const u16 *a2, u16 a3, u16 heap);
void func_021C51A0(int *a);
void func_021C5224(char *p);
int func_021C5334(u32 a);
void func_021C5348(u8 *p);
void func_021C536C(u8 *p);
int func_021C5380(u8 *p);
u32 func_021C5394(u8 *p, u32 *out);
void func_021C53A0(int *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, int *g, u16 h);
int func_021C5424(u32 a, u32 b);
void func_021C5440(S *p, int mode, u32 c, u32 *done);
void func_021C54C8(int *a, int b, int c, int *d);
void func_021C553C(char *p);
int func_021C56F8(int *a);
int func_021C5768(char *p);
void func_021C576C(void *a);
extern char d_021DE498[];
extern const u32 d_021DAA60[];
extern const u32 d_021DAA54[];







/*
 * Stops the record's task and syncs the final position (EXACT*: pad).
 */
void func_021C4E08(R *r, s32 frame)
{
    if (r->task != 0) {
        func_020115EC((struct IcaAnime *)r->task, frame);
        func_021C4E34(r);
    }
}








/*
 * Returns the task's status word, 0 without a task (EXACT*: pad).
 */
u32 func_021C4E20(R *r)
{
    if (r->task == 0)
        return 0;
    return func_0201160C((struct Obj11245 *)r->task);
}








static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}








/*
 * Syncs the task's current position into the target and its map object.
 */
void func_021C4E34(R *r)
{
    V3 t;

    if (r->task != 0 && func_02011610((struct IcaAnime *)r->task, (struct Rec12 *)&t) == 1) {
        V3_Set(r->pos, t.x, t.y, t.z);
        if (r->f8 != 0)
            func_0202B934(r->f8, r->fC, &t);
    }
}








/*
 * Same HSV-to-RGB shape as arm9 func_02011B8C: three 4.12 channels from
 * func_02011638, wrapped into [0,360), rescaled to 0..65535, handed to
 * func_020520FC.
 */
void func_021C4E6C(char *p)
{
    s32_021C4E6C hsv[3];
    u16 ch;
    u16 cs;
    u16 cv;
    float h;
    float s;
    float v;

    if (((struct Obj01666 *)p)->f10 == 0) {
        return;
    }
    if (func_02011638(((struct Obj01666 *)p)->f10, (struct Rec12 *)hsv) != 1) {
        return;
    }

    h = hsv[0] / 4096.0f;
    s = hsv[1] / 4096.0f;
    v = hsv[2] / 4096.0f;

    while (h < 0.0f) {
        h += 360.0f;
    }
    while (s < 0.0f) {
        s += 360.0f;
    }
    while (v < 0.0f) {
        v += 360.0f;
    }

    ch = (u16)(u32)(65535.0f * (h / 360.0f));
    cs = (u16)(u32)(65535.0f * (s / 360.0f));
    cv = (u16)(u32)(65535.0f * (v / 360.0f));
    func_0207ADC4(*(char * *)&((struct Obj01666 *)p)->f14 + 0x18);
    func_020520FC(ch, cs, cv, (struct Mtx33 *)(*(char * *)&((struct Obj01666 *)p)->f14 + 0x18));
}








/*
 * The heap id is a u16 stack parameter, and the callees it feeds take a u16
 * heap too (docs/idioms/narrow-stack-parameters-and-callee-prototype-free-
 * the-narrow-home-store.md): only then does the u16 a3's home store
 * `str r3, [sp, #0x18]` lead the prologue. With u32 heap it sank below
 * `ldr r7, [sp, #0x40]; str r0, [sp, #0x10]` (6 bytes). pos.y = 0x60 is
 * written once before the loop, and the element address is spelled
 * p + i * 4 + 0x58 (r6 = p + i*4 shared with the table index).
 */
char *func_021C4F7C(void *a0, int mode, const u16 *a2, u16 a3, u16 heap)
{
    Pos pos;
    int x;
    char *p;
    void *arc;
    int i;

    i = 0;
    p = func_02030734(heap, 0x88, 0, d_021DE498, 0xFC);
    func_02082BCC(p, 0, 0x88);
    ((struct Obj00960 *)p)->f74 = 0;
    ((struct Obj00960 *)p)->f78 = 25;
    *(const u16 * *)&((struct Obj00960 *)p)->f7C = a2;
    func_0203FCA0(1, (const struct BgTemplate *)d_021DAA60, 0);
    func_020414AC(1);
    func_02040C14(1, 0, 1, 0);
    ((struct Obj00960 *)p)->f4C = (u32)func_0204B100(8, 0, heap);
    x = 0x80;
    arc = func_020490F4(0x80, heap);
    func_02049B68(arc, 0, 0, x + 0xE0, 0x40, heap);
    ((struct Obj00960 *)p)->f50 = func_0204ABF0(arc, 4, 0, 0x40, heap);
    ((struct Obj00960 *)p)->f52 = func_0204A6C8(arc, 3, 0, 0, heap);
    ((struct Obj00960 *)p)->f54 = func_0204AF28(arc, 2, 1, heap);
    x += 0xC0;
    func_02049B68(arc, 6, 0, x, 0x20, heap);
    func_02049658(arc, 5, 1, 0, 0, 0, heap);
    func_020498F4(arc, 7, 1, 0, 0, 0, heap);
    func_020413B0(1, 0, 11, 32, 1, 10);
    func_02049238(arc);
    func_02082BCC(&pos, 0, 8);
    pos.y = 0x60;
    for (i = 0; i < 3; i++) {
        pos.z = i;
        pos.x = d_021DAA54[i];
        *(u32 *)(p + i * 4 + 0x58) = (u32)func_0204B294((void *)((struct Obj00960 *)p)->f4C, ((struct Obj00960 *)p)->f52,
            ((struct Obj00960 *)p)->f50, ((struct Obj00960 *)p)->f54, &pos, 0, heap);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 0);
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 1);
    }
    ((struct Obj00960 *)p)->f64 = (u32)func_02045B38(0, 2, 0xAD, heap);
    ((struct Obj00960 *)p)->f68 = (u32)func_0201D7EC(0x17, 0, 0, 0, a3);
    ((struct Obj00960 *)p)->f6C = (u32)func_0201C450(0x1000, heap);
    func_021C53A0((int *)p, *(const u16 * *)&((struct Obj00960 *)p)->f7C, ((struct Obj00960 *)p)->f64, ((struct Obj00960 *)p)->f68,
        ((struct Obj00960 *)p)->f6C, (u32)func_0200C40C(func_02012EBC(a0)), (int *)(p + 0x58), a3);
    func_02041B6C(1);
    func_0207D63C(0x04000050, 2, 1, 12, 4);
    switch (mode) {
    case 0:
        func_02040618(1, 3, -0xC0);
        func_02040588(1, 0);
        ((struct Obj00960 *)p)->f70 = 0;
        break;
    case 1:
        func_02040618(1, 3, 0);
        func_02040588(1, 1);
        ((struct Obj00960 *)p)->f70 = 3;
        break;
    }
    return p;
}







void func_021C51A0(int *a)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    func_02040588(1, 0);
    func_021C5424((int)a, a[0x7c / 4]);
    for (i = 0; i < 3; i++) {
        func_0204B3B4((struct Obj *)a[0x58 / 4 + i]);
    }
    func_0201C6EC((struct PrintSys *)a[0x6c / 4]);
    func_0201C4C0((struct PrintSys *)a[0x6c / 4]);
    func_0201D83C((void *)a[0x68 / 4]);
    func_02045C04((struct Rec *)a[0x64 / 4]);
    func_0204ADA4(((struct Obj00020 *)a)->f50);
    func_0204A8D4(((struct Obj00020 *)a)->f52);
    func_0204AFD8(((struct Obj00020 *)a)->f54);
    func_0204B1CC((struct Bank *)a[0x4c / 4]);
    func_02040DA8(1, 1, 0);
    func_020403F4(1);
    func_020307B0((void *)((int)a));
}







void func_021C5224(char *p)
{
    int r;
    int i;

    if (func_021C5334((u32)p) == 0) {
        return;
    }
    switch (((struct Obj01216 *)p)->f70) {
    case 0:
        break;
    case 1:
        func_020061E4(0x54C);
        ((struct Obj01216 *)p)->f72 = 0;
        ((struct Obj01216 *)p)->f80 = 0;
        ((struct Obj01216 *)p)->f84 = func_020056A0((void *)func_021C59BC, p, 0);
        ((struct Obj01216 *)p)->f70 = 2;
        break;
    case 2:
        if (((struct Obj01216 *)p)->f80 != 0) {
            func_02030EAC(((struct Obj01216 *)p)->f84);
            ((struct Obj01216 *)p)->f70 = 3;
        }
        break;
    case 3:
        func_021C553C(p);
        r = func_021C5768(p);
        switch (r) {
        case -1:
            ((struct Obj01216 *)p)->f74 = 0;
            break;
        case -2:
            ((struct Obj01216 *)p)->f74 = 2;
            break;
        default:
            ((struct Obj01216 *)p)->f74 = 1;
            ((struct Obj01216 *)p)->f78 = r;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0x58 + i * 4), 0);
        }
        ((struct Obj01216 *)p)->f72 = 4;
        ((struct Obj01216 *)p)->f70 = 5;
        break;
    case 5:
        func_02040618(1, 3, ((struct Obj01216 *)p)->f72 * 0xC0 / 4 - 0xC0);
        if ((((struct Obj01216 *)p)->f72)-- == 0) {
            ((struct Obj01216 *)p)->f70 = 0;
        }
        break;
    }
}







int func_021C5334(u32 a)
{
func_0201C4E4((struct PrintSys *)(((struct Obj18304 *)((u8 *)(a)))->f6C));
return func_021C56F8((int *)a);
}







/*
 * Starts the fade sequence once (state 0 to 1).
 */
void func_021C5348(u8 *p)
{
    if (((struct Obj07562 *)p)->f70 == 0) {
        ((struct Obj07562 *)p)->f74 = 0;
        ((struct Obj07562 *)p)->f78 = 0x19;
        func_02040588(1, 1);
        ((struct Obj07562 *)p)->f70 = 1;
    }
}







/*
 * Advances the sequence from state 3 to 4 (EXACT*: pad).
 */
void func_021C536C(u8 *p)
{
    if (((struct Obj12940 *)p)->f70 == 3)
        ((struct Obj12940 *)p)->f70 = 4;
}







/*
 * Returns 1 in states 2 and 5.
 */
int func_021C5380(u8 *p)
{
    int r = 1;

    if (((struct Obj12941 *)p)->f70 != 2 && ((struct Obj12941 *)p)->f70 != 5)
        r = 0;
    return r;
}







/*
 * Returns the result word and optionally its argument.
 */
u32 func_021C5394(u8 *p, u32 *out)
{
    if (out != 0)
        *out = ((struct Obj12942 *)p)->f78;
    return ((struct Obj12942 *)p)->f74;
}





void func_021C53A0(int *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, int *g, u16 h)
{
    int i = 0;
    int r;

    func_02082BCC(a, 0, 0x4c);
    a[3] = e;
    a[8] = f;
    ((struct Obj00874 *)a)->f34 = h;
    a[0xe] = c;
    a[0xf] = d;
    for (i = 0; i < 3; i++) {
        a[0xa + i] = g[i];
    }
    r = func_020450F0(1, 1, 0xc, 0x1e, 0xc, 0xb, 1);
    a[2] = r;
    func_02045334((struct Descriptor *)r);
    func_02045374((struct Cfg *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    a[4] = a[2];
    ((struct Obj00874 *)a)->f14 = 0;
    func_021C58CC((char *)a, b[0], b[1], h);
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C5424(u32 a, u32 b)
{
func_021C59A8(a, b, (b + 2));
func_020452E8((struct Descriptor *)(((struct Obj18305 *)((u8 *)(a)))->f8));
return func_02082BCC((void *)a, 0, 76);
}





/*
 * Message-window step: opens the window and plays SE 0x548, or scrolls to
 * the cursor line. Load-bearing: int-typed line count (stops (c-1)-(n-1)
 * folding) and the u16 local for the line index.
 */
void func_021C5440(S *p, int mode, u32 c, u32 *done)
{
    int n;
    u16 tmp;
    u16 h;

    if (mode == 0) {
        n = func_02020350(p->msg, 3);
        func_021C59A8((u32)p, 0, 0);
        func_021C58CC((char *)p, (c - 1) - (n - 1), n - 1, p->h34);
        if (p->f24 == 1)
            p->f40 = 1;
        func_020061E4(0x548);
        *done = 1;
    } else if (p->f40 == 1 && p->f24 == 1) {
        func_020202FC(p->msg, 0, &tmp);
        h = func_02020324(p->msg, tmp) >> 3;
        func_021C59F8(p, (h + 0xC) * 8);
        p->f40 = 0;
        *done = 1;
    }
}




void func_021C54C8(int *a, int b, int c, int *d)
{
    u16 v;
    u16 w;

    if (b == c - 1) {
        if (a[9] == 1) {
            func_020202FC((struct Obj *)a[1], 0, &v);
            w = func_02020324((struct Obj *)a[1], (u16)(v + 1)) >> 3;
            func_021C59F8((S *)a, (w + 0xc) << 3);
            a[16] ^= 1;
        }
        if (a[16] == 0) {
            func_021C59A8((u32)a, 0, 0);
            func_021C58CC((char *)a, 0, 0, ((struct Obj04281 *)a)->f34);
        }
        func_020061E4(0x548);
        *d = 1;
        return;
    }
    a[16] = 0;
}




void func_021C553C(char *p)
{
    int flag;
    u16 c[2];
    u16 b[2];
    u16 a[2];
    int redraw;
    int sel;
    u32 n;
    int i;

    sel = -1;
    redraw = 0;
    flag = 0;
    func_020355D8(0);
    func_020202EC(((struct Obj00523 *)p)->f4, &c[1]);
    n = func_02020350(((struct Obj00523 *)p)->f4, 2);
    if (func_0203633C() & 0x40) {
        func_021C5440((S *)p, c[1], n, (u32 *)&flag);
    } else if (func_0203633C() & 0x80) {
        func_021C54C8((int *)p, c[1], n, &flag);
    }
    if (flag == 0) {
        sel = func_020200CC(((struct Obj00523 *)p)->f4);
    }
    if (sel == -1) {
        if (func_020362DC() & 0x400) {
            sel = -2;
            func_020061E4(0x551);
        } else if (func_020362DC() & 0x800) {
            func_020202EC(((struct Obj00523 *)p)->f4, &c[0]);
            sel = func_02020344(((struct Obj00523 *)p)->f4, c[0]);
            func_020061E4(0x54C);
        } else if ((func_020362DC() & 4) && ((struct Obj00523 *)p)->f24 == 1) {
            func_020202EC(((struct Obj00523 *)p)->f4, &b[1]);
            sel = func_02020344(((struct Obj00523 *)p)->f4, b[1]);
            func_020061E4(0x54C);
        }
    }
    if (((struct Obj00523 *)p)->f24 == 0) {
        ((struct Obj00523 *)p)->f18 = sel;
    } else if (((struct Obj00523 *)p)->f24 == 1) {
        if (sel == -2) {
            redraw = 1;
        } else if (sel != -1) {
            sel = func_02020344(((struct Obj00523 *)p)->f4, (u16)(((struct Obj00523 *)p)->f1C + ((struct Obj00523 *)p)->f1E));
            func_020202EC(((struct Obj00523 *)p)->f4, &b[0]);
            if (((struct Obj00523 *)p)->f40 != 0) {
                sel = func_0200C480(((struct Obj00523 *)p)->f20, sel, 0xFF);
            } else {
                sel = func_0200C480(((struct Obj00523 *)p)->f20, sel, b[0]);
            }
            func_021C59A8((u32)p, (u32)(&a[0]), (u32)(&a[1]));
            if (b[0] - 1 == sel) {
                a[1]--;
            }
            func_021C58CC(p, a[0], a[1], ((struct Obj00523 *)p)->f34);
            redraw = 1;
        }
    }
    if ((func_020362DC() & 4) && ((struct Obj00523 *)p)->f24 == 0 && func_02020350(((struct Obj00523 *)p)->f4, 2) > 1) {
        func_020061E4(0x54C);
        redraw = 1;
    }
    if (redraw) {
        ((struct Obj00523 *)p)->f24 ^= 1;
        if (((struct Obj00523 *)p)->f24 == 0) {
            ((struct Obj00523 *)p)->f40 = 0;
            for (i = 0; i < 3; i++) {
                func_0204B3DC((struct Obj *)*(u32 *)(p + 0x28 + i * 4), 0);
            }
            func_021C577C(((struct Obj00523 *)p)->f4, 0, 0);
            return;
        }
        if (((struct Obj00523 *)p)->f24 == 1) {
            func_020202FC(((struct Obj00523 *)p)->f4, (u16 *)(p + 0x1C), (u16 *)(p + 0x1E));
            ((struct Obj00523 *)p)->f48 = 1;
        }
    }
}



int func_021C56F8(int *a)
{
    int r4 = a[3];
    int i;
    int r7;

    if (((struct Obj02094 *)a)->f14 != 0) {
        if (func_0201C6C4((struct PrintSys *)r4, (void *)((int)func_02045770((struct Descriptor *)a[4]))) == 0) {
            func_02045334((struct Descriptor *)a[4]);
            ((struct Obj02094 *)a)->f14 = 0;
        }
    }
    r7 = 1;
    if (((struct Obj02094 *)a)->f14 != 0) {
        r7 = 0;
    }
    if (r7 != 0) {
        if (a[0x11] != 0) {
            func_021C577C((void *)a[1], 0, 0);
            a[0x11] = 0;
        }
        if (a[0x12] != 0) {
            for (i = 0; i < 3; i++) {
                func_0204B3DC((struct Obj *)a[0xa + i], 1);
            }
            a[0x12] = 0;
        }
    }
    return r7;
}




/*
 * Unlabelled leaf (no lr save): returns the selection func_021C553C
 * stores at +0x18. Called from func_021C5224.
 */
int func_021C5768(char *p)
{
    return ((struct Obj20207 *)p)->f18;
}




/*
 * Raises the done flag on map object 0x13 (EXACT*: pad).
 */
void func_021C576C(void *a)
{
    *(u32 *)(func_02020350(a, 0x13) + 0x44) = 1;
}
