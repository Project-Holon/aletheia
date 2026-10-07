/*
 * file:     field_wfbc_p07.c
 * unit:     yes
 * function: func_02193F34, func_02193F6C, func_02193F80
 * address:  0x02193F34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021867B0  0x021867B0  thumb  ov020
 *   func_02082BCC  0x02082BCC  arm  arm9
 *   func_02082D44  0x02082D44  arm  arm9
 *   func_02161ECC  0x02161ECC  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

typedef struct E50_02193F34 {
    u16 f00;
    u8  pad02[0x32];
    u8  f34[0x1C];
} E50_02193F34;

typedef struct E18 {
    u8 b[0x18];
} E18;

typedef struct Tbl {
    u8  hdr[8];
    E18 e[10];
} Tbl;

typedef struct V {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50_02193F34 *f04;
    Tbl *f08;
} V;

typedef struct E50_02193F6C {
    u16 f00;
    u8  pad02[0x4E];
} E50_02193F6C;

typedef struct E50_02193F80 {
    u16 f00;
    u16 f02;
    u8  f04[0x30];
    u8  f34[0x18];
    u16 f4c;
    u16 f4e;
} E50_02193F80;

extern int func_021867B0(u8 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02161ECC(void *a);
extern void func_02082D44(void *src, void *dst, int n);
E50_02193F34 *func_02193F34(V *v, u32 key);
void func_02193F6C(E50_02193F6C *e);
void func_02193F80(E50_02193F80 *e, void *a, u8 *b, void *c);


/*
 * Addresses are Black-image addresses.
 */
E50_02193F34 *func_02193F34(V *v, u32 key)
{
    int i;

    if (v->f04 != 0) {
        for (i = 0; i < 10; i++) {
            if (v->f04[i].f00 != 0 && key == func_021867B0(v->f04[i].f34))
                return &v->f04[i];
        }
    }
    return 0;
}


void func_02193F6C(E50_02193F6C *e)
{
    func_02082BCC(e, 0, 0x50);
    e->f00 = 0;
}


void func_02193F80(E50_02193F80 *e, void *a, u8 *b, void *c)
{
    func_02161ECC(a);
    e->f00 = 1;
    func_02082D44(a, e->f34, 0x18);
    func_02082D44(c, e->f04, 0x30);
    e->f4c = b[0];
    e->f4e = b[1];
}
