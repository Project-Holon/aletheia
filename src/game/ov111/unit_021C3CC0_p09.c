/*
 * file:     unit_021C3CC0_p09.c
 * unit:     yes
 * function: func_021C51E4, func_021C523C
 * address:  0x021C51E4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C6FA0  0x021C6FA0  thumb  ov111
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C59DC  0x021C59DC  thumb  ov111
 */
struct Obj;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x98];
    void *obj[8];
} Anim;

typedef struct {
    u8 pad0[0x3070];
    Anim anim;
} Work_021C51E4;

typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x32C7];
    u8 blink;
    u8 phase;
} Work_021C523C;

extern void func_021C6FA0(Anim *a, int idx, u8 x, u8 y);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021C59DC(u32 bg, int mode);
void func_021C51E4(Work_021C51E4 *p, int flag);
void func_021C523C(Work_021C523C *p, int flag);


/*
 * Addresses are Black-image addresses.
 */
void func_021C51E4(Work_021C51E4 *p, int flag)
{
    if (flag == 0) {
        func_021C6FA0(&p->anim, 2, 0xB, 1);
        func_0204B3DC(p->anim.obj[4], 0);
        func_0204B3DC(p->anim.obj[5], 0);
    } else {
        func_021C6FA0(&p->anim, 2, 0xD, 1);
        func_0204B3DC(p->anim.obj[4], 1);
        func_0204B3DC(p->anim.obj[5], 1);
    }
}


void func_021C523C(Work_021C523C *p, int flag)
{
    if (flag) {
        p->phase = 0;
        p->blink = 0;
    } else {
        p->phase = 2;
    }
    func_021C59DC(7, p->phase);
}
