/*
 * function: func_0217E3D0
 * address:  0x0217E3D0
 * packet:   pkt_ov018_0217E3D0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_0217BEA8  0x0217BEA8  thumb  ov018
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0217F118  0x0217F118  thumb  ov018
 *   d_021836A4     0x021836A4  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
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

struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern Mon *func_0217BEA8(int a0);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void func_0204B3DC(struct Obj *a0, unsigned int a1);
extern void func_0217F118(Obj *p, int a1);
extern const s8 d_021836A4[][2];
extern const Ent d_02176AA0[];

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
