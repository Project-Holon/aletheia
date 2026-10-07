/*
 * file:     unit_02173658_p05.c
 * unit:     yes
 * function: func_02173AE0, func_02173B20, func_02173B44
 * address:  0x02173AE0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021754E8 0x021754E8 thumb ov011
 */
struct Entry;
typedef unsigned int   u32;

typedef unsigned char u8;

int func_021736D8(void);
struct Entry *func_020399A8(void);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_021754E8(u8 *p, int a, int b, int c);
int func_02173AE0(int a, int b, int c, int d);
void func_02173B20(int a, int b, u8 *c, u8 *d);
int func_02173B44(void *a, int b, int c);


int func_02173AE0(int a, int b, int c, int d)
{
    unsigned char buf[4];

    if (func_021736D8() == 0) {
        return 0;
    }
    buf[0] = c;
    buf[1] = d;
    return func_0203D3F8((int)func_020399A8(), (unsigned char)b, 0x208, 4, (u32)buf, 0, 0, 0);
}


void func_02173B20(int a, int b, u8 *c, u8 *d)
{
    if (d[0x154] == a && d[0x158] == c[0]) func_021754E8((u8 *)((int)d), a, 3, c[0]);
}


int func_02173B44(void *a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((int)func_020399A8(), (unsigned char)b, 0x209, 1, (u32)(&c), 0, 0, 0);
}
