/*
 * file:     zukan_detail_graphic_p09.c
 * unit:     yes
 * function: func_021BD574, func_021BD634
 * address:  0x021BD574
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020416D4  0x020416D4  arm
 *   func_021BD56C  0x021BD56C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BD880  0x021BD880  thumb
 *   func_021BD89C  0x021BD89C  thumb
 *   data_021C8314  0x021C8314  data
 */
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Scrn {
    u8  pad0[0xc];
    u16 data[1];
};

typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActKind {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
};

struct Ov208Pos {
    s16 x;
    s16 y;
    u16 h4;
    u8  b6;
    u8  b7;
};

struct Ov208ActObj {
    u32 f0;
    u32 f4;
    u32 f8;
    void (*fc)(void);
    u32 f10;
    struct Ov208ActDesc desc;
    u32 f34;
};

extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 channel);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u8   func_020416D4(u32 layer);
extern int func_021BD56C(int *p, int i);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BD880(char *p);
extern void func_021BD89C(char *p);
void ov208_func_021BD574(u32 a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6, u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap);
void ov208_func_021BD634(struct Ov208ActObj *p, u32 owner, const int *res, struct Ov208ActDesc *desc, u32 prio, u16 mode);
extern const struct Ov208ActKind data_021C8314[];


void ov208_func_021BD574(u32 a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                         u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap)
{
    struct Scrn *scr;
    u32 file;
    int i;
    u16 *d;

    file = (u32)func_0204A380((void *)a0, a1, a13, (u16)((heap & 0x7fff) | 0x8000));
    func_02062B30((void *)file, (void **)(&scr));
    if (add != 0 && func_0204169C((u8)channel) == 0) {
        d = scr->data;
        for (i = 0; i < a6 * a7; i++)
            d[i] += (u16)add;
    }
    if ((int)func_0204162C((u8)channel) != 0) {
        func_020410D0((u8)channel, x, y, w, h, (u32)scr->data, a4, a5, a6, a7);
        func_020413B0(channel, x, y, w, h, pal);
        func_020409B4(channel);
    }
    func_020307B0((void *)file);
}


void ov208_func_021BD634(struct Ov208ActObj *p, u32 owner, const int *res, struct Ov208ActDesc *desc,
                         u32 prio, u16 mode)
{
    struct Ov208Pos pos;
    u32 i;
    u32 j;
    u32 k;
    int n;

    func_02082BCC(p, 0, 0x38);
    p->desc = *desc;
    p->f4 = 1;
    p->f34 = 0;
    func_02082BCC(&pos, 0, 8);
    pos.b7 = func_020416D4((u8)res[3]);
    pos.x = desc->x;
    pos.y = desc->y;
    if (desc->f0 >= 7) {
        i = desc->ha;
        j = desc->hc;
        k = desc->he;
        p->f10 = 0;
    } else {
        i = func_021BD56C((int *)res, 1);
        j = func_021BD56C((int *)res, 0);
        k = func_021BD56C((int *)res, 2);
        n = desc->f0;
        p->desc.h10 = data_021C8314[n].a;
        p->desc.h12 = data_021C8314[n].b;
        p->desc.h14 = data_021C8314[n].c;
        p->desc.f18 = data_021C8314[n].e;
        p->desc.f1c = data_021C8314[n].d;
        p->f10 = data_021C8314[n].f;
    }
    p->f8 = p->desc.h10;
    pos.h4 = p->desc.h10;
    p->f0 = (u32)func_0204B294((void *)owner, i, j, k, &pos, prio, mode);
    func_0204B92C((struct Obj *)p->f0, 1);
    switch (p->f10) {
    case 0:
        p->fc = (void (*)(void))func_021BD880;
        break;
    case 1:
        p->fc = (void (*)(void))func_021BD89C;
        break;
    }
}
