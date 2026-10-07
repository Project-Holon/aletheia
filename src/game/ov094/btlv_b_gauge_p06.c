/*
 * file:     btlv_b_gauge_p06.c
 * unit:     yes
 * function: func_02208650, func_0220868C, func_022086F8, func_022087C4, func_02208814
 * address:  0x02208650
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_02207F6C 0x02207F6C thumb ov094
 *   func_022082FC 0x022082FC thumb ov094
 *   func_02208420 0x02208420 thumb ov094
 *   func_02208550 0x02208550 thumb ov094
 *   tbl_020A1B38  0x020A1B38  data
 *   func_022079C0 0x022079C0  thumb  ov094
 *   d_0220AAF0     0x0220AAF0  data   ov094  a4
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 */
struct Struct36;
struct O_022086F8;
struct Obj;
typedef unsigned char u8;

typedef struct { int w[9]; } Struct36;

typedef struct { void *f0; char p4[0x6f - 4]; u8 f6f; } E_02208650;

typedef struct { char p0[0x14]; char *f14; } O_02208650;

typedef struct { char p0[0xc]; void *fc; char p10[0x78 - 0x10]; int f78; } E_0220868C;

typedef struct { char p0[0x14]; char *f14; } O_0220868C;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct E_022086F8 {
    char p0[0x48];
    int f48, f4c, f50, f54, f58, f5c, f60, f64;
    char p68[8];
    u32 b0:1, b1:1, b2:1, b3:1, phase:4, hi:24;
    char p74[12];
} E_022086F8;

typedef struct { char p0[0x40]; E_022086F8 e[8]; } O_022086F8;

typedef short s16;

typedef struct Ang {
    u32 lo : 5;
    u32 ang : 16;
    u32 hi : 11;
} Ang;

typedef struct E_02208814 {
    int h;
    char pad[124];
} E_02208814;

typedef struct O_02208814 {
    char pad[0x54];
    E_02208814 e[8];
} O_02208814;

typedef struct T7 {
    u32 w[7];
} T7;

extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_02082A60(const void *, void *, int);
extern void func_020061E4(u32 a);
extern int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
extern void func_022082FC(struct O_022086F8 *o, int idx, int k);
extern void func_02208420(O_022086F8 *, E_022086F8 *, int);
extern void func_02208550(O_022086F8 *, E_022086F8 *);
extern void func_022079C0(char *obj, int a, s16 *v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B878(struct Obj *p, u16 value);
void func_02208650(O_02208650 *o, E_02208650 *e);
void func_0220868C(O_0220868C *o, E_0220868C *e, int c);
void func_022086F8(O_022086F8 *o, int i);
void func_022087C4(char *obj, int a);
void func_02208814(O_02208814 *obj, int k, int idx);
extern s16 tbl_020A1B38[];
extern T7 d_0220AAF0;


void func_02208650(O_02208650 *o, E_02208650 *e)
{
    Struct36 buf;
    int off;
    enum { VRAM_BASE = 0x06400000 } vram;

    off = 0x360;
    if (e->f6f == 0)
        off = 0x660;
    func_0204B7C8(e->f0, (struct Struct36 *)(&buf));
    vram = VRAM_BASE;
    func_02082A60(o->f14 + off, (void *)(vram + 0x120 + buf.w[1]), 0x20);
}


void func_0220868C(O_0220868C *o, E_0220868C *e, int c)
{
    u8 cnt[6];
    Struct36 buf;
    int n;
    int i;
    enum { VRAM_BASE = 0x06400000 } vram;

    n = e->f78 - c;
    for (i = 0; i < 6; i++)
        cnt[i] = 8;
    for (i = 5; i >= 0; i--) {
        if (n >= 8) {
            cnt[i] = 0;
            n -= 8;
        } else {
            cnt[i] = 8 - n;
            break;
        }
    }
    func_0204B7C8(e->fc, (struct Struct36 *)(&buf));

    i = 0;
    vram = VRAM_BASE;
    for (; i < 6; i++)
        func_02082A60(o->f14 + (cnt[i] * 32 + 0x6a0), (void *)(vram + i * 32 + buf.w[1]), 0x20);
}

void func_022086F8(O_022086F8 *o, int i)
{
    E_022086F8 *e;
    e = &o->e[i];
    if (e->b1 == 0) {
        switch (e->phase) {
        case 0:
            func_020061E4(0x56e);
            e->phase++;
            break;
        case 1:
            e->phase++;
            break;
        case 2:
            e->f54 = 0;
            e->f58 = e->f5c;
            e->f64 = 0x80000000;
            e->f60 = 0;
            func_02207F6C(e->f4c, e->f48, 0, &e->f50, 6, 1);
            func_02207F6C(e->f58, e->f54, 0, &e->f64, 10, 1);
            func_022082FC((struct O_022086F8 *)o, i, 0);
            func_022082FC((struct O_022086F8 *)o, i, 1);
            func_02208420(o, e, e->f48);
            func_02208550(o, e);
            e->b2 = 0;
            break;
        }
    }
}


/*
 * Levers: the angle is read into an int local (asrs, not lsrs); the
 * increment goes through a second cast pointer expression so the word is
 * reloaded instead of CSE'd.
 */
void func_022087C4(char *obj, int a)
{
    s16 v[2];
    Ang *f;
    int i;

    f = (Ang *)(obj + 0x440);
    v[0] = -16;
    i = f->ang;
    v[1] = tbl_020A1B38[2 * (i >> 4)] / 0x800;
    ((Ang *)(obj + 0x440))->ang += 0x400;
    func_022079C0(obj, a, v);
}


void func_02208814(O_02208814 *obj, int k, int idx)
{
    T7 t = d_0220AAF0;

    if (obj->e[idx].h != 0) {
        if (k == 0) {
            func_0204B3DC((struct Obj *)obj->e[idx].h, 0);
            func_0204B878((struct Obj *)obj->e[idx].h, 0);
        } else {
            func_0204B3DC((struct Obj *)obj->e[idx].h, 1);
            func_0204B878((struct Obj *)obj->e[idx].h, t.w[k]);
        }
    }
}
