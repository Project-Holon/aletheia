/*
 * file:     field_place_name_p10.c
 * unit:     yes
 * function: func_021BCD34, func_021BCD70
 * address:  0x021BCD34
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
 *   func_021BD0C0  0x021BD0C0  thumb  ov021
 *   func_021BCEB4  0x021BCEB4  thumb  ov021
 *   func_021BD0D0  0x021BD0D0  thumb  ov021
 *   func_021BCB9C  0x021BCB9C  thumb  ov021
 */
typedef unsigned short u16;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj;

typedef unsigned char  u8;

typedef unsigned int   u32;

extern u8 func_021BD0C0(u8 *p);
extern void func_021BCEB4(char *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021BD0D0(Obj *p);
extern void func_021BCB9C(void *p, int keep);
void func_021BCD34(Obj *p);
void func_021BCD70(Obj *p);


void func_021BCD34(Obj *p)
{
    switch (func_021BD0C0((u8 *)p)) {
    case 0:
        func_021BCEB4((char *)p);
        func_02040588(3, 1);
        func_021BD0D0(p);
        break;
    case 1:
        if (p->h42 > 10) {
            func_021BCB9C(p, 3);
        }
        break;
    }
}


void func_021BCD70(Obj *p)
{
    if (p->h42 > 10) {
        func_021BCB9C(p, 4);
    }
}
