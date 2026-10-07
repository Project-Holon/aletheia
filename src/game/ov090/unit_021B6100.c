/*
 * file:     unit_021B6100.c
 * unit:     yes
 * function: func_021B6100, func_021B6108, func_021B6114, func_021B6184, func_021B61C4, func_021B61E8
 * address:  0x021B6100
 * region:   ov090
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   d_021B6228     0x021B6228  data  a4
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct {
    u16 a;
    u8 b;
} Msg;

extern void func_0203A5E4(unsigned);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0200FB24(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern u32 func_0203D1A4(struct Link *p);
void func_021B6100(u8 *p);
void func_021B6108(void *unused);
void func_021B6114(u8 *p);
u32 func_021B6184(u8 *p, u8 b, u16 a);
void func_021B61C4(int a, int b, unsigned char *c, unsigned char *d);
void func_021B61E8(void *a, int b);
extern u8 d_021B6228[];

void func_021B6100(u8 *p)
{
    p[0x62] = 0;
}

/*
 * Leaf of ov178 021E54CC; caller unloads overlay 90 immediately after call.
 */
void func_021B6108(void *unused)
{
 func_0203A5E4(0x2D00);
}


void func_021B6114(u8 *p)
{
    switch (p[0x62]) {
    case 0:
        func_02039C68((struct Link *)func_020399A8(), 1, 0x2d);
        p[0x62] = 1;
        break;
    case 1:
        if (func_02039CB4((struct Link *)func_020399A8(), 1, 0x2d) == 1) {
            func_0203A574(0x2d00, (u32)d_021B6228, 1, (u32)p);
            p[0x62] = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_0200FB24() != 0 && p[0x63] == 0)
        p[0x63] = 1;
}


u32 func_021B6184(u8 *p, u8 b, u16 a)
{
    Msg m;
    u32 h;

    h = (u32)func_020399A8();
    m.b = b;
    m.a = a;
    if (p[0x62] != 2)
        return 0;
    return func_0203D3F8(h, 0xff, 0x2d00, 4, (u32)(&m), 1, 0, 0);
}

void func_021B61C4(int a, int b, unsigned char *c, unsigned char *d) {
    func_0203D1A4((struct Link *)((int)func_020399A8()));
    if(c[2]==0) d[148]++;
}

void func_021B61E8(void *a, int b) { func_02039C68((struct Link *)func_020399A8(), b, 45); }
