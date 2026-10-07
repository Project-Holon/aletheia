/*
 * file:     field_wfbc_p06.c
 * unit:     yes
 * function: func_02193EE8, func_02193EFC
 * address:  0x02193EE8
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
 *   func_021938FC  0x021938FC  thumb  ov021
 *   func_021867B0  0x021867B0  thumb  ov020
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16;

typedef struct E50 {
    u16 f00;
    u8  pad02[0x32];
    u8  f34[0x1C];
} E50;

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
    E50 *f04;
    Tbl *f08;
} V;

extern void func_021938FC(void *v);
extern int func_021867B0(u8 *p);
void func_02193EE8(V *v);
E50 *func_02193EFC(V *v, u32 key);


/*
 * Addresses are Black-image addresses.
 */
void func_02193EE8(V *v)
{
    if (v->f01 == 0 && v->f08 != 0)
        func_021938FC(v);
}


E50 *func_02193EFC(V *v, u32 key)
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
