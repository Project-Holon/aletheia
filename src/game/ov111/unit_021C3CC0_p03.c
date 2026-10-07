/*
 * file:     unit_021C3CC0_p03.c
 * unit:     yes
 * function: func_021C42C0, func_021C436C, func_021C43C4
 * address:  0x021C42C0
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
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02049F34  0x02049F34  arm
 *   d_021C8E20     0x021C8E20  data  a4
 *   d_021C86E8     0x021C86E8  data  a4
 */
struct Rec;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u16 heap;
    u8 pad2[0x31FC - 2];
    void *f31FC;
    void *f3200;
    void *f3204;
    void *f3208;
    void *f320C;
    void *f3210;
    void *f3214;
    void *f3218[3];
    void *f3224[2];
    void *f322C[26];
    void *f3294[5];
} Work_021C42C0;

typedef struct {
    u8 kind;
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info *info;
    u8 pad2C[0x31E8 - 0x2C];
    void *f31E8;
    void *f31EC;
} Work_021C436C;

typedef struct {
    u16 heap;
} Work_021C43C4;

extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
void func_021C42C0(Work_021C42C0 *p);
void func_021C436C(Work_021C436C *p, int k, int alt);
void func_021C43C4(Work_021C43C4 *p, int k);
extern const u32 d_021C8E20[][2];
extern const u32 d_021C86E8[][2];


/*
 * Addresses are Black-image addresses.
 */
void func_021C42C0(Work_021C42C0 *p)
{
    int i;

    func_0201ED04(p->f3204);
    for (i = 0; i < 5; i++) {
        func_02045808(p->f3294[i]);
    }
    for (i = 0; i < 26; i++) {
        func_02045808(p->f322C[i]);
    }
    func_02045808(p->f3224[1]);
    func_02045808(p->f3224[0]);
    func_02045808(p->f3218[2]);
    func_02045808(p->f3218[1]);
    func_02045808(p->f3218[0]);
    func_02045808(p->f320C);
    func_02045808(p->f3214);
    func_02045808(p->f3210);
    func_02045808(p->f3208);
    func_02045C04(p->f3200);
    func_0201D83C(p->f31FC);
}


void func_021C436C(Work_021C436C *p, int k, int alt)
{
    int j = 1;
    u32 file;

    if (p->info->kind == 0x14) {
        j = 0;
    } else if (p->info->kind != 0x15) {
        k = 6;
    }
    file = d_021C8E20[k][j];
    func_02049B40(0x28, file, 4, 0, 0x200, p->heap);
    p->f31E8 = func_02049F34(0x28, file, (u32)(&p->f31EC), p->heap);
}


void func_021C43C4(Work_021C43C4 *p, int k)
{
    func_02049B40(0x29, d_021C86E8[k][1], 4, 0x80, 0x20, p->heap);
}
