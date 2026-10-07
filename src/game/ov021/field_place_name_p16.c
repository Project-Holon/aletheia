/*
 * file:     field_place_name_p16.c
 * unit:     yes
 * function: func_021BD340, func_021BD36C, func_021BD394
 * address:  0x021BD340
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
 *   func_021BD2D8  0x021BD2D8  thumb  ov021
 *   func_021BD304  0x021BD304  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[0x28];
    int f;
} Inner_021BD36C;

typedef struct {
    char pad[0x2C];
    int f;
} Inner_021BD394;

extern u32 func_021BD2D8(u8 *p);
extern unsigned char *func_021BD304(unsigned char *p);
int func_021BD340(void *a);
int func_021BD36C(void *p);
int func_021BD394(void *p);


int func_021BD340(void *a)
{
if (func_021BD2D8((u8 *)a) == 0) {
    return 1;
}
if (func_021BD36C((void *)a) != 0) {
    if (func_021BD394((void *)a) != 0) {
        return 1;
    }
}
return 0;
}


int func_021BD36C(void *p)
{
    Inner_021BD36C *q = (Inner_021BD36C *)func_021BD304(p);

    if (func_021BD2D8(p) == 0) {
        return 1;
    }
    if (q->f <= 0) {
        return 1;
    }
    return 0;
}


int func_021BD394(void *p)
{
    Inner_021BD394 *q = (Inner_021BD394 *)func_021BD304(p);

    if (func_021BD2D8(p) == 0) {
        return 1;
    }
    if (q->f <= 0) {
        return 1;
    }
    return 0;
}
