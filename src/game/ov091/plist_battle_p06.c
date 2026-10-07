/*
 * file:     plist_battle_p06.c
 * unit:     yes
 * function: func_021BB050, func_021BB0C4
 * address:  0x021BB050
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB554  0x021BB554  thumb  ov091
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BEC74     0x021BEC74  data  ov091  a1
 *   d_021BEC75     0x021BEC75  data  ov091  a1
 *   func_02045780 0x02045780 arm
 *   func_0204B09C 0x0204B09C arm
 *   func_020410D0 0x020410D0 arm
 *   func_02045374 0x02045374 arm
 *   d_021BEC6C 0x021BEC6C data ov091 a1
 *   d_021BEC6D 0x021BEC6D data ov091 a1
 */
#define W(k) (*(u32 *)(s+(k)))
struct Cfg;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { short x,y; } Pt;

typedef struct { Pt point; short width,height; } Rect;

extern int func_021BB554(u32 p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 id);
extern void func_02045780(struct Descriptor *p, u8 v);
extern void func_0204B09C(void *,int,void *);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02045374(struct Cfg *cfg);
void func_021BB050(int unused, u8 *s, int k);
void func_021BB0C4(u8 *p,const u8 *s,int d);
extern const u8 d_021BEC74[];
extern const u8 d_021BEC75[];
extern const u8 d_021BEC74[],d_021BEC75[],d_021BEC6C[],d_021BEC6D[];


void func_021BB050(int unused, u8 *s, int k)
{
    if (k == 3 && func_021BB554((u32)s) == 3)
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, 4);
    else if (k == 6 && func_021BB554((u32)s) == 3)
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, 7);
    else
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, k);
    func_02041B6C(2);
}

void func_021BB0C4(u8 *p,const u8 *s,int d)
{
    int i=s[4];
    int x=d_021BEC74[i*2];
    u8 y=d_021BEC75[i*2];
    Pt pt;
    int zero;
    enum Selector {SEL_ZERO,SEL_ONE} selector;
    if (i % 2 == 0) d=-d;
    func_02045780((void *)W(0x20),d+(x+16));
    pt.x=-(x+d)*8;
    pt.y=-y*8;
    func_0204B09C((void *)W(0x24),0,&pt);
    zero=0;
    if (s[4] != 0) zero=1;
    selector=s[4] != 0;
    x+=16;
    d=(unsigned)x+d;
    func_020410D0(2,(u8)d,y,16,6,(u32)(*(u8 **)(p+0x15c)+12),d_021BEC6C[selector*2],d_021BEC6D[zero*2],32,32);
    func_020413B0(2,d,y,16,6,5);
    func_02045374((void *)W(0x20));
    func_02041B6C(1);
    func_02041B6C(2);
}
