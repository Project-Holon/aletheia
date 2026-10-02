/*
 * function: func_021BB79C
 * address: 0x021BB79C
 * packet: pkt_ov206_021BB79C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E8 0x020275E8 thumb
 *   func_020275EC 0x020275EC thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_020307B0 0x020307B0 arm
 *   d_021BC128 0x021BC128 data a2
 *   d_021BC150 0x021BC150 data a1
 */
typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct {
    short a, b, c;
    unsigned char d, e;
} Rect;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    unsigned char a, b;
} Tile;

typedef struct {
    char pad[0x14];
    int f14;
} Blob;

extern const unsigned short d_021BC128[];
extern const Tile d_021BC150[];
extern void *func_02049DF4(void *, unsigned short, int, Blob **, unsigned short);
extern void func_0204AA94(void *, int, int, int, int);
extern void func_020307B0(void *);

typedef struct {
    short x, y, z, w;
} Rect4;

extern int func_020275E8(void);
extern int func_020275EC(int);
extern int func_020275F8(int);
extern int func_020275FC(int);
extern int func_02027600(int);
extern void *func_0204AC18(void *, int, int, int, int, int, unsigned short);
extern void *func_0204AF28(void *, int, int, unsigned short);
extern void *func_0204A6C8(void *, int, int, int, unsigned short);
extern void *func_0204B294(void *, void *, void *, void *, Rect4 *, unsigned short, unsigned short);
extern void func_0204B6F4(void *, int, int);
extern void func_0204B800(void *, int);
extern void func_0204B688(void *, int);
extern void func_0204B3DC(void *, int);
extern void func_0204B404(void *, Pos *, unsigned short);

typedef struct {
    unsigned short f0;
    char pad02[0x18 - 2];
    int f18;
    int f1c;
    char pad20[4];
    void *f24;
    char pad28[0xb8 - 0x28];
    int m[2][2];
    void *fc8;
    void *fcc;
    void *n[2][2];
    int fe0;
    int fe4;
    void *a[0x11];
    void *b[0x11];
    unsigned char f170;
    unsigned char f171;
    char pad172[0x1b4 - 0x172];
    int f1b4;
    char pad1b8[0x1c4 - 0x1b8];
    void *f1c4;
    char pad1c8[0x1d0 - 0x1c8];
    void *f1d0;
} Ent;

void func_021BB79C(Ent *p, unsigned x, unsigned y, int z, int row)
{
    Rect4 rr[2];
    Pos pos[2];
    unsigned char sel[2];
    void *arc;
    void *handle;
    int data;
    int ta;
    int tb;
    unsigned char id;
    int ifv;
    int tern;
    short v;
    int j;
    short *zp;
    Blob *blob;

    zp = (short *)rr;
    zp[0] = 0;
    zp[1] = 0;
    zp[2] = 0;
    zp[3] = 0;
    zp[4] = 0;
    zp[5] = 0;
    zp[6] = 0;
    zp[7] = 0;
    ifv = 0;
    if (p->f1c != 0) ifv = 1;
    tern = p->f1c == 0 ? B_FALSE : B_TRUE;
    sel[0] = x;
    sel[1] = y;
    rr[0].x = 0xa8;
    v = p->f1b4 + 0x54;
    rr[0].y = v;
    rr[1].x = 0xd0;
    rr[1].y = v;
    arc = p->f1d0;
    handle = func_02049DF4(p->f1c4, d_021BC128[z], 0, &blob, p->f0);
    data = blob->f14;
    for (j = 0; j < 2; j++) {
        p->m[row][j] = -1;
        id = sel[j];
        if (id != 0x11) {
            p->m[row][j] = (int)func_0204A6C8(arc, func_020275F8(id), 0, ifv, p->f0);
            ta = d_021BC150[id].b << 7;
            tb = d_021BC150[id].a << 11;
            func_0204AA94((void *)p->m[row][j], data + (tb + ta), 0x80, 0, ifv);
            func_0204AA94((void *)p->m[row][j], data + ((tb + (1 << 10)) + ta), 0x80, 0x80, ifv);
        }
    }
    func_020307B0(handle);
    for (j = 0; j < 2; j++) {
        if (p->m[row][j] != -1) {
            p->n[row][j] = func_0204B294(p->f24, (void *)p->m[row][j], p->fc8, p->fcc, &rr[j], (unsigned short)tern, p->f0);
            func_0204B6F4(p->n[row][j], func_020275EC(sel[j]), 1);
            func_0204B800(p->n[row][j], 2);
            func_0204B688(p->n[row][j], 1);
        }
    }
}
