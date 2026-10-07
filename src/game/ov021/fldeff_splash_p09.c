/*
 * file:     fldeff_splash_p09.c
 * unit:     yes
 * function: func_021C4E20, func_021C4E34, func_021C4E6C, func_021C4F7C
 * address:  0x021C4E20
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
 *   func_021C53A0  0x021C53A0  thumb  ov021
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   d_021DE498     0x021DE498  data  ov021  a1
 *   d_021DAA60     0x021DAA60  data  a4
 *   d_021DAA54     0x021DAA54  data  a4
 */
#include "../../matched/include/Obj01666.h"
#include "../../matched/include/Obj00960.h"

struct Obj11245;
struct IcaAnime;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Bank;
struct GfFont;
struct MsgBank;
struct Obj;
typedef unsigned short u16;

typedef unsigned int u32;

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

extern u32 func_0201160C(struct Obj11245 *p);
extern u32 func_02011610(struct IcaAnime *t, struct Rec12 *v);
extern void func_0202B934(u32 a, u32 b, V3 *v);
extern u32 func_02011638(struct IcaAnime *ctx, struct Rec12 *hsv);
extern void func_0207ADC4(void *p);
extern void func_020520FC(int h, int s, int v, struct Mtx33 *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
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
extern void func_021C53A0(int *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, int *g, u16 h);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
u32 func_021C4E20(R *r);
void func_021C4E34(R *r);
void func_021C4E6C(char *p);
char *func_021C4F7C(void *a0, int mode, const u16 *a2, u16 a3, u16 heap);
extern char d_021DE498[];
extern const u32 d_021DAA60[];
extern const u32 d_021DAA54[];


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
