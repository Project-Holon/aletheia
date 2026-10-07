/*
 * file:     fieldmap_func_p08.c
 * unit:     yes
 * function: func_021BBD64, func_021BBD84
 * address:  0x021BBD64
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
 *   d_021D9AE8     0x021D9AE8  data  a4
 */
struct BbActSys;
typedef unsigned short u16;

typedef struct {
    int pad0;
    int f4;
    u16 h8[0x1A];
} Obj;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct Row { u8 b[4]; } Row;

extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
void func_021BBD64(Obj *p);
int func_021BBD84(int a, int n, int x, int y);
extern Row d_021D9AE8[];


void func_021BBD64(Obj *p)
{
    int i;

    for (i = 0; i < 0x1A; i++) {
        func_02050278((struct BbActSys *)p->f4, p->h8[i], 1);
    }
}


int func_021BBD84(int a, int n, int x, int y)
{
    int r = 0;
    switch (n) {
    case 0: r = x; break;
    case 1: r = d_021D9AE8[y].b[x]; break;
    case 2: r = x + 10; break;
    case 3: r = d_021D9AE8[y].b[x] - 4; r += 14; break;
    case 4: r = d_021D9AE8[y].b[x] - 4; r += 20; break;
    }
    return r;
}
