/*
 * function: func_021F6B04
 * address: 0x021F6B04
 * packet: pkt_ov094_021F6B04
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: u8 variant spills at entry before the other parameter copies;
 * int variant moves that spill three instructions later (8 differing bytes).
 * The ov094 caller at 021F76D6 passes the byte-derived selector.
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   func_02048F60 0x02048F60 arm
 *   func_02046DB8 0x02046DB8 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_02047564 0x02047564 arm
 *   func_0204767C 0x0204767C arm
 *   func_020477A4 0x020477A4 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02046F48 0x02046F48 arm
 *   func_0206E964 0x0206E964 arm
 *   sub_020307B0 0x020307B0 arm
 *   d_0220AC50 0x0220AC50 data ov094 a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int kind, a, b, c; } Ent;
typedef struct {
    void *f0;
    int n;
    Ent *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    int f1c, f20, f24;
    int f28, f2c, f30;
    int matrix[9];
    void **f58;
    void **f5c;
    u8 f60, f61;
    u8 pad62[10];
    u16 heap;
    u16 pad6e;
} Obj;
extern const char d_0220AC50[];
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void *func_02048F60(u32, u32, u32);
extern void *func_02046DB8(u32, u32);
extern int func_02046FF8(int *);
extern void *func_02047400(void *, u32, void *);
struct G3dOwner;
struct G3dRec;
struct Tagged;
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
struct G3dSys;
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0207ADC4(int *);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void sub_020307B0(void *);

Obj *func_021F6B04(int unused, int group, u8 variant, u16 heap)
{
    Obj *o;
    int (*table)[4][4];
    int i, j;
    int bytes;
    o = sub_02030734(heap, 0x70, 1, d_0220AC50, 0x56);
    table = func_02048F60(0x98, 1, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (table[group][0][variant] != -1)
        o->f0 = func_02046DB8(11, table[group][0][variant]);
    else
        o->f0 = func_02046DB8(11, table[group][0][0]);
    func_02046FF8(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group][i][variant] != -1) o->n++;
    o->f14 = func_02047400(o->f0, 0, o->f0);
    j = 0;
    if (o->n != 0) {
        o->fc = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7e);
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, d_0220AC50, 0x7f);
        o->f8 = sub_02030734(o->heap, o->n * 16, 1, d_0220AC50, 0x80);
        for (i = 1; i < 4; i++) {
            if (table[group][i][variant] != -1) {
                o->fc[j] = func_02046DB8(11, table[group][i][variant]);
                o->f10[j] = func_02047564(o->f14, o->fc[j], 0);
                o->f8[j].kind = 0;
                j++;
            }
        }
        o->f18 = func_0204767C((u32)o->f14, (u32 *)o->f10, (u16)o->n);
        for (j = 0; j < o->n; j++) func_020477A4(o->f18, (u16)j);
    } else {
        o->f18 = func_0204767C((u32)o->f14, 0, (u16)0);
    }
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f28 = 0x1000;
    o->f2c = 0x1000;
    o->f30 = 0x1000;
    func_0207ADC4(o->matrix);
    bytes = *(u16 *)(func_0206E964(func_02046F48(o->f0)) + 0x30) * 8;
    o->f58 = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xaa);
    o->f5c = sub_02030734(o->heap, 4, 0, d_0220AC50, 0xab);
    *o->f58 = o->f0;
    *o->f5c = sub_02030734(o->heap, bytes, 0, d_0220AC50, 0xae);
    o->f60 = 0;
    o->f61 = 1;
    sub_020307B0(table);
    return o;
}
