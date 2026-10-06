/*
 * function: func_0217D3AC
 * address:  0x0217D3AC
 * packet:   pkt_ov018_0217D3AC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217EBD8  0x0217EBD8  thumb  ov018
 *   func_0217EEB4  0x0217EEB4  thumb  ov018
 *   func_0217EF44  0x0217EF44  thumb  ov018
 *   func_0217E638  0x0217E638  thumb  ov018
 *   func_0217E714  0x0217E714  thumb  ov018
 *   func_0217DE68  0x0217DE68  thumb  ov018
 *   func_0217E014  0x0217E014  thumb  ov018
 *   func_0217E0F4  0x0217E0F4  thumb  ov018
 *   func_0217E3D0  0x0217E3D0  thumb  ov018
 *   func_0217E4D0  0x0217E4D0  thumb  ov018
 *   func_0217E524  0x0217E524  thumb  ov018
 *   func_0217F194  0x0217F194  thumb  ov018
 */

typedef struct {
    void *f0;
    unsigned char pad004[0xDC];
    int fE0;
    unsigned char pad0E4[0x88];
    unsigned char f16C;
} Ov018Menu;

typedef struct { unsigned char a : 7; unsigned char b : 1; } FlagsF8;

struct Ctx;
unsigned int func_02012138(const struct Ctx *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
void *func_020120F4(const struct Ctx *p);
u8 *func_020120F8(const struct Ctx *p);
struct Rec44;
unsigned short func_02012AC8(const struct Rec44 *);
int func_02012B70(const struct BigObj *p);
u32 func_02013D5C(u32 id);
u32 func_02026454(void *obj);
u32 func_0202648C(void *obj);
int func_02158344(int a0);
int func_02175DA8(u8 *p);
int func_02175B8C(u8 *p);
void *func_0217EBD8(u8 *p);
void func_0217EEB4(int *p);
void func_0217EF44(Ov018Menu *, unsigned char *);
void func_0217E638(Ov018Menu *, int);
void func_0217E714(Ov018Menu *, unsigned char *, int);
void func_0217DE68(Ov018Menu *, int);
void func_0217E014(u8 *p, int a1);
void func_0217E0F4(Ov018Menu *, unsigned char *, int);
void func_0217E3D0(Ov018Menu *, int, int);
void func_0217E4D0(int *p, int a1);
void func_0217E524(Ov018Menu *, int);
void func_0217F194(Ov018Menu *);

void func_0217D3AC(Ov018Menu *w)
{
    void *s1;
    void *s2;
    unsigned char *p;
    int q;
    int flag;
    int k;

    s1 = (void *)func_02012138(w->f0);
    s2 = func_020120F4(w->f0);
    p = (unsigned char *)func_02158344((int)s1);
    q = func_02012AC8((const struct Rec44 *)func_020120F8(w->f0));
    flag = 0;
    k = (int)func_0217EBD8((u8 *)w);
    if (p != 0 && func_02175DA8(p + 0x1AC) == 0) {
        flag = 1;
    } else if (p == 0 && func_02012B70(s2) == 1 && func_02026454(s1) != 2
               && func_0202648C(s1) == 0 && func_02013D5C(q) == 1) {
        flag = 1;
    }
    if (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 1) {
        flag = 0;
    }
    if (flag == 1) {
        func_0217EEB4((int *)w);
        func_0217EF44(w, p);
        func_0217E638(w, q);
        func_0217E714(w, p, q);
        func_0217DE68(w, k);
        func_0217E014((u8 *)w, k);
        func_0217E0F4(w, p, k);
        func_0217E3D0(w, k, q);
        func_0217E4D0((int *)w, k);
        func_0217E524(w, k);
        func_0217F194(w);
        return;
    }
    if (p != 0 && func_02175DA8(p + 0x1AC) == 1 && func_02175B8C(p + 0x1AC) == 1
        && w->f16C == 0 && w->fE0 == 0) {
        func_0217E524(w, k);
        w->f16C = 1;
    }
}
