/*
 * file:     btl_server_p22.c
 * unit:     yes
 * function: func_021BD170, func_021BD1B0
 * address:  0x021BD170
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCAAC  0x021BCAAC  thumb  ov093
 *   func_021BCB98  0x021BCB98  thumb  ov093
 *   func_021BCA08 0x021BCA08 thumb ov093
 *   func_021BCC50 0x021BCC50 thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 a, b, c; u8 d0, flag; u16 pad; } E;

extern u8 *func_021BCAAC(u8 *p, u8 *q, u8 i);
extern int func_021BCB98(u8 *p, u8 *x, int i);
extern E *func_021BCA08(void *, u8);
extern void func_021BCC50(void *, E *);
int func_021BD170(u8 *p, u8 *q);
int func_021BD1B0(void *p, u8 x);


int func_021BD170(u8 *p, u8 *q)
{
    int i = 0;
    int r;
    u8 *x = func_021BCAAC(p, q, 0);
    r = 0;
    while (x) {
        i = func_021BCB98(p, x, i);
        if (i < 0) break;
        i++;
        x = func_021BCAAC(p, q, i);
        r = 1;
    }
    return r;
}

int func_021BD1B0(void *p, u8 x)
{
    E *e = func_021BCA08(p, x);
    if (e && e->flag == 0) {
        func_021BCC50(p, e);
        return 1;
    }
    return 0;
}
