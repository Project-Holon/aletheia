/*
 * file:     intrude_subdisp_p05.c
 * unit:     yes
 * function: func_0217E2E0, func_0217E3D0, func_0217E4D0
 * address:  0x0217E2E0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02021F64  0x02021F64  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0217F118  0x0217F118  thumb  ov018
 *   d_021836A4     0x021836A4  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 *   func_02012B70  0x02012B70  thumb
 *   func_02025774  0x02025774  thumb
 */
struct Obj;
struct BigObj;
struct Ctx;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 pad00[0x5c];
    void *f5c[16];
    u8 pad9C[0xdc - 0x9c];
    int fdc;
    u8 padE0[4];
    u8 *fe4;
    u8 padE8[0x16a - 0xe8];
    u8 f16a;
    u8 f16b;
} Work;

typedef unsigned int   u32;

typedef signed char s8;

typedef short s16;

typedef struct { u16 a, b; u8 x, y; } Ent;

typedef struct {
    unsigned int id : 10;
    unsigned int rest : 22;
    u8 pad04[0x0A - 0x04];
    u8 x;
    u8 y;
} Mon;

typedef struct {
    Mon *mon;
    u16 id;
    u16 pad06;
} Slot;

typedef struct {
    int f00;
    u8 pad04[0x98 - 0x04];
    int f98;
    u8 pad9C[0xEC - 0x9C];
    Slot slots[1];
} Obj;

extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02082A60(const void *, void *, int);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern u32 func_02013D5C(u32 id);
extern Mon *func_0217BEA8(int a0);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *a0, unsigned int a1);
extern void func_0217F118(Obj *p, int a1);
extern int func_02012B70(const struct BigObj *p);
extern void func_02025774(u8 *g, u32 a);
void func_0217E2E0(Work *p);
void func_0217E3D0(Obj *p, int a1, u16 id);
void func_0217E4D0(int *p, int a1);
extern const s8 d_021836A4[][2];
extern const Ent d_02176AA0[];



void func_0217E2E0(Work *p)
{
    int sel;
    int v;
    int c;
    u16 buf[16];

    if (p->fdc == 3 && p->fe4 != 0) {
        sel = p->fe4[0x28];
        c = -1;
        v = p->f16a;
        if (v != 4 && v != sel) {
            func_0204B6F4(p->f5c[v + 12], (u8)(v + 1), (int)1);
        }
        if (p->f16a != sel) {
            func_02082A60((void *)(0x05000600 + (sel + 1) * 32), buf, 0x20);
            func_02021F64(buf, buf, 0x10, 8, 0x7fff);
            func_02082A60(buf, (void *)0x05000720, 0x20);
            p->f16a = sel;
        }
        p->f16b++;
        if (p->f16b == 15) {
            c = 9;
        } else if (p->f16b >= 30) {
            c = sel + 1;
            p->f16b = 0;
        }
        if (c != -1) {
            func_0204B6F4(p->f5c[sel + 12], (u8)c, (int)1);
        }
        return;
    }
    v = p->f16a;
    if (v != 4) {
        func_0204B6F4(p->f5c[v + 12], (u8)(v + 1), (int)1);
        p->f16a = 4;
        p->f16b = 0;
    }
}



void func_0217E3D0(Obj *p, int a1, u16 id)
{
    s16 pos[2];
    int sel;
    int idx;
    Mon *m;
    int i;
    int v;
    int h;

    idx = func_02012B58(func_020120F4((const struct Ctx *)p->f00));
    sel = 0xFF;
    if (func_02013D5C(id) == 1) {
        pos[0] = d_021836A4[idx][0] + 0x80;
        pos[1] = d_021836A4[idx][1] + 0x4C;
        sel = 8;
        p->slots[idx].mon = 0;
    } else {
        if (id != p->slots[idx].id) {
            m = func_0217BEA8(id);
        } else {
            m = p->slots[idx].mon;
        }
        p->slots[idx].mon = m;
        p->slots[idx].id = id;
        if (m != 0) {
            pos[0] = m->x + d_021836A4[idx][0];
            pos[1] = m->y + d_021836A4[idx][1];
            v = m->id;
            for (i = 0; i < 8; i++) {
                if (v == d_02176AA0[i].a || v == d_02176AA0[i].b) {
                    sel = i;
                    break;
                }
            }
        } else {
            pos[0] = 0xE8;
            pos[1] = idx * 0x18 + 0x50;
            sel = 0xFF;
            p->slots[idx].mon = 0;
        }
    }
    h = p->f98;
    func_0204B404((struct Obj *)h, (const struct Vec2 *)pos, 0);
    func_0204B3DC((struct Obj *)h, 1);
    func_0217F118(p, sel);
    p->slots[idx].id = id;
}


void func_0217E4D0(int *p, int a1)
{
    int h;

    h = (int)func_020120F4((const struct Ctx *)p[0]);
    if (*((u8 *)p + 0xe9) == 0 && func_02012B70((const struct BigObj *)h) == 1) {
        switch (p[0xdc / 4]) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0204B3DC((struct Obj *)p[0x9c / 4], 0);
            func_02025774((u8 *)p[0xc0 / 4], 0);
            break;
        }
    }
}
