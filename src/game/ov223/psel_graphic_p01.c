/*
 * file:     psel_graphic_p01.c
 * unit:     yes
 * function: func_021BB450, func_021BB508, func_021BB520, func_021BB540, func_021BB62C, func_021BB630, func_021BB7A4, func_021BB840, func_021BB844, func_021BB944, func_021BB954
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
 */
#include "../../matched/include/Obj00084.h"
#include "../../matched/include/Obj06727.h"
#include "../../matched/include/Obj26099.h"
#include "../../matched/include/Obj06728.h"
#include "../../matched/include/Obj14793.h"

struct MsgBank;
struct U16Vec;
struct TaskMenu;
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
extern const struct Ent d_021BC73C[3];
extern const u8 d_021BC6FC[];
extern const u8 d_021BC708[];

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
