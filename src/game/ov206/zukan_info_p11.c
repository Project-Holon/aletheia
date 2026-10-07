/*
 * file:     zukan_info_p11.c
 * unit:     yes
 * function: func_021BBC9C, func_021BBDA8, func_021BBE34, func_021BBE5C
 * address:  0x021BBC9C
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   tbl_020A1B38 0x020A1B38 data
 *   func_02061CA4 0x02061CA4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_021BC0AC 0x021BC0AC thumb ov206
 *   func_021BC0E0 0x021BC0E0 thumb ov206
 *   func_020490F4 0x020490F4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   tbl_021BC134 0x021BC134 data
 *   tbl_021BC1C4 0x021BC1C4 data
 *   tbl_021BC184 0x021BC184 data
 */
struct Obj;
struct State;
struct MsgBank;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct S_021BBC9C {
    char pad0[0x1c];
    int f1c;
    char pad20[0x194 - 0x20];
    u16 phase;
    u16 pal[5];
    u16 a[5];
    u16 b[5];
} S_021BBC9C;

typedef signed int     s32;

struct State {
    char pad[0xb8]; int ids[3][2]; void *objects[2][2]; int selected,mode;
    char padE8[0x44]; void *other[17]; u8 a,b; char pad172[0x16]; void *last[2]; int index;
};

typedef struct S_021BBE34 {
    char pad0[8];
    int f8;
    char pad0c[0xac - 0xc];
    void *last[2];
    int index;
} S_021BBE34;

typedef struct S_021BBE5C {
    u16 id;
    char pad2[0xa];
    u16 fc;
    u16 fe;
    char pad10[0x1b8 - 0x10];
    void *g[3];
    void *w[7];
    void *objs[35];
    void *x;
    void *a[16];
} S_021BBE5C;

extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_020275E4(void);
extern int func_0202D7C8(int a0);
extern u32 func_021BC0AC(void);
extern u32 func_021BC0E0(void);
extern void *func_020490F4(u32 id, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
s32 func_021BBC9C(S_021BBC9C *p);
void func_021BBDA8(struct State *p, int v);
void func_021BBE34(S_021BBE34 *p, int v);
void func_021BBE5C(S_021BBE5C *p);
extern s16 tbl_020A1B38[];
extern u32 tbl_021BC134[];
extern u16 tbl_021BC1C4[];
extern u32 tbl_021BC184[];

s32 func_021BBC9C(S_021BBC9C *p)
{
    s16 f;
    u8 i;

    if (p->phase + 0x400 >= 0x10000)
        p->phase = p->phase + 0x400 - 0x10000;
    else
        p->phase += 0x400;
    f = (tbl_020A1B38[(p->phase >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        u16 a = p->a[i];
        u16 b = p->b[i];
        u8 a1 = a & 0x1f;
        u8 a2 = (a & 0x3e0) >> 5;
        u8 a3 = (a & 0x7c00) >> 10;
        u8 b1 = b & 0x1f;
        u8 b2 = (b & 0x3e0) >> 5;
        u8 b3 = (b & 0x7c00) >> 10;
        u8 c1 = a1 + (((b1 - a1) * f) >> 12);
        u8 c2 = a2 + (((b2 - a2) * f) >> 12);
        u8 c3 = a3 + (((b3 - a3) * f) >> 12);
        p->pal[i] = c1 | (c2 << 5) | (c3 << 10);
    }
    return func_02061CA4((void *)(p->f1c == 0 ? 0xf : 0x1f), 0x22, (u32)p->pal, 0xa);
}

void func_021BBDA8(struct State *p, int v)
{
    u8 i;
    func_0204B3DC(p->last[p->index],v);
    if(p->mode) {
        if(p->a!=17) func_0204B3DC(p->other[p->a],v);
        if(p->b!=17) func_0204B3DC(p->other[p->b],v);
    } else {
        for(i=0;i<2;i++) {
            if(p->ids[p->selected][i]!=-1)
                func_0204B3DC(p->objects[p->selected][i],v);
        }
    }
}

void func_021BBE34(S_021BBE34 *p, int v)
{
    func_0204B3DC(p->last[p->index], v);
    if (p->f8 == 0)
        v = 0;
    func_021BBDA8((struct State *)p, v);
}

void func_021BBE5C(S_021BBE5C *p)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        switch (i) {
        case 3:
            p->w[i] = func_020490F4(func_020275E4(), p->id);
            break;
        case 4:
            p->w[i] = (void *)func_0202D7C8(p->id);
            break;
        case 5:
            p->w[i] = func_020490F4(func_021BC0AC(), p->id);
            break;
        case 6:
            p->w[i] = func_020490F4(func_021BC0E0(), p->id);
            break;
        default:
            p->w[i] = func_020490F4(tbl_021BC134[i], p->id);
            break;
        }
    }
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] != 0)
                p->objs[i] = p->g[0];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        case 2:
            if (p->g[1] != 0)
                p->objs[i] = p->g[1];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        case 3:
            if (p->g[2] != 0)
                p->objs[i] = p->g[2];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        default:
            p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        }
    }
    p->x = func_0201ADE4(p->fc, p->fe, p->id);
    for (i = 0; i < 16; i++)
        p->a[i] = func_02045EC0(p->objs[0], tbl_021BC184[i]);
}
