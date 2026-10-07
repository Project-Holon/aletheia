/*
 * file:     dup_fitting_item_p02.c
 * unit:     yes
 * function: func_021B6BA4, func_021B6E4C, func_021B6E74, func_021B6F00, func_021B7368
 * address:  0x021B6BA4
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F5444 0x021F5444 thumb ov112
 *   func_021F5204 0x021F5204 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F5350 0x021F5350 thumb ov112
 *   func_0200A644 0x0200A644 thumb
 *   func_0200A680 0x0200A680 thumb
 *   func_0200A628 0x0200A628 thumb
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F4F10 0x021F4F10 thumb ov112
 *   func_021F4B3C 0x021F4B3C thumb ov112
 *   func_021F4B4C 0x021F4B4C thumb ov112
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_021F4C1C 0x021F4C1C thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4DE0 0x021F4DE0 thumb ov112
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047388 0x02047388 arm
 *   func_020473B8 0x020473B8 arm
 *   func_020473EC 0x020473EC arm
 *   func_02046F48 0x02046F48 arm
 *   func_02047250 0x02047250 arm
 *   func_0206A124 0x0206A124 arm
 *   func_0206A12C 0x0206A12C arm
 *   func_020862F0 0x020862F0 arm
 *   func_0204EDD0 0x0204EDD0 arm
 *   func_0204F044 0x0204F044 arm
 *   func_0204EFC8 0x0204EFC8 arm
 *   func_0204F428 0x0204F428 arm
 *   func_0204F720 0x0204F720 arm
 *   func_021B9028 0x021B9028 thumb ov133
 *   func_021BA0CC 0x021BA0CC thumb ov133
 *   func_021BA19C 0x021BA19C thumb ov133
 *   func_021BA100 0x021BA100 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021B7A18 0x021B7A18 thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 *   d_020A8148    0x020A8148 data
 *   d_021BA3E0    0x021BA3E0 data ov133 a4
 *   func_021B7458 0x021B7458 thumb ov133
 *   func_021BA188 0x021BA188 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../../matched/include/Obj02852.h"

#define H (*(u16 *)p)
#define W(o) (*(u32 *)(p + (o)))
struct Obj;
struct BgTemplate;
struct Big;
struct Board;
struct Desc;
struct Layer;
struct Object;
struct Tagged;
struct Vec3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16_021B6BA4;

typedef struct {s16_021B6BA4 x,y,index;u8 a,b;} Params;

typedef signed int     s32;

typedef short s16_021B6F00;

typedef struct Vec_021B6F00 { int x, y, z; } Vec_021B6F00;

typedef signed short s16_021B7368;

typedef struct { int x,y,z; } Vec_021B7368;

typedef struct { u32 x,y; } Pair;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02041EE4(u32,u32,u32);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02049238(void *);
extern void func_020409B4(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned int,unsigned int);
extern void func_020414AC(unsigned int);
extern void *func_021F5164(u32 heap);
extern void func_021F5438(void **p, int b);
extern void func_021F5444(u8 *, int);
extern u8 *func_021F5204(u8 *, void *, int);
extern void func_021F51E8(u8 *);
extern void func_021F51F4(void **p);
extern u8 *func_021F545C(u8 *p);
extern void func_021F5350(int *p, int *q);
extern u32 func_0200A644(struct Big *p, u8 index);
extern u32 func_0200A680(struct Big *p, u8 index);
extern u8 *func_0200A628(struct Big *p);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern u32 func_021F4F10(u8 *p);
extern void *func_021F4B3C(int type);
extern void func_021F4B4C(struct Tagged *a0);
extern u8 *func_021F4F54(u8 *, int);
extern int func_021F4F70(int *);
extern void func_021F4EE8(u8 *, u8 *, int);
extern u8 *func_021F4C1C(u8 *, int, u32, Vec_021B6F00 *);
extern void func_021F4E6C(u8 *, u8 *, u32);
extern void func_021F4EB4(u32 unused, u32 p, s16_021B6F00 a, s16_021B6F00 b);
extern void func_021F4DE0(char *p, char *e, void *a2);
extern int func_02046FF8(int *self);
extern u32 func_02047388(struct Layer *layer);
extern u32 func_020473B8(struct Layer *layer);
extern int func_020473EC(int a0);
extern void *func_02046F48(struct Tagged *p);
extern void *func_02047250(void *);
extern void func_0206A124(int *p, int v);
extern void func_0206A12C(void *, u32);
extern void func_020862F0(void *, u32);
extern void func_0204EDD0(int, u16 *, u16 *);
extern int func_0204F044(struct Board *b, int w, int h, int a3, u32 a4, u8 a5, u8 a6);
extern u32 func_0204EFC8(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6);
extern s32 func_0204F428(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void func_0204F720(void *, u32, u32 *);
extern void func_021B9028(u8 *, int, u16);
extern u8 *func_021BA0CC(u16, int);
extern u8 *func_021BA19C(u16 heap, struct Object *q, u8 *r, int *v);
extern void func_021BA100(u8 *p, u8 *q);
extern u32 func_021BA218(u8 *p);
extern void func_021B7A18(u8 *);
extern void *func_021B765C(u8 *p, u16 base, s16_021B6F00 speed, u16 rx, u16 ry);
extern void func_021B7458(void *unused, int *p);
extern unsigned short func_021BA188(char *p);
extern void func_021BA21C(u8 *p, const u8 *src);
void func_021B6BA4(u8 *p);
void func_021B6E4C(const void *t,unsigned int id);
void func_021B6E74(u8 *p);
void func_021B6F00(u8 *p);
void func_021B7368(u8 *p,u16 id);
extern u32 d_021BA3E0[];

/*
 * note 2026-10-05 (wD9r lane78): EXACT. Closed by declaring func_02049658 with its real return type u32
 *   (it returns sub_0204968C's u32 result, as the matched sibling func_02049624 does), not void. The void
 *   prototype hoisted 4 into r7 and turned later zeros into adds rN,r6,#0 copies. 0xd and -128 are literals.
 *   See docs/idioms/a-getter-declared-void-changes-constant-hoisting.md.
 */
void func_021B6BA4(u8 *p)
{
    Params cfg;
    void *g = func_020490F4(0x2e, H);
    func_02049B68(g, 4, 0, 0, 0, H);
    func_02049658(g, 7, 3, 0, 0, 0, H);
    func_020498F4(g, 0xc, 3, 0, 0, 0, H);
    func_020498F4(g, 0xb, 2, 0, 0, 0, H);
    func_02049B68(g, 3, 4, 0, 0, H);
    func_02049658(g, 0xa, 4, 0, 0, 0, H);
    func_02049658(g, 9, 7, 0, 0, 0, H);
    func_020498F4(g, 0x10, 4, 0, 0, 0, H);
    func_020498F4(g, 0xf, 6, 0, 0, 0, H);
    func_020498F4(g, 0xe, 5, 0, 0, 0, H);
    func_020498F4(g, 0xd, 7, 0, 0, 0, H);
    func_02041EE4(6, 0, 128);
    func_02041EE4(5, 0, -128);
    *(struct Obj **)(p + 0x1858) = (struct Obj *)func_0204ABF0(g, 2, 0, 0, H);
    *(struct Obj **)(p + 0x1864) = (struct Obj *)func_0204A6C8(g, 8, 0, 0, H);
    *(struct Obj **)(p + 0x1870) = (struct Obj *)func_0204AF28(g, 0x14, 0x18, H);
    *(struct Obj **)(p + 0x1860) = (struct Obj *)func_0204ABF0(g, 1, 1, 0, H);
    *(struct Obj **)(p + 0x186c) = (struct Obj *)func_0204A6C8(g, 6, 0, 1, H);
    *(struct Obj **)(p + 0x1878) = (struct Obj *)func_0204AF28(g, 0x13, 0x17, H);
    *(struct Obj **)(p + 0x185c) = (struct Obj *)func_0204ABF0(g, 0, 0, 0x40, H);
    *(struct Obj **)(p + 0x1868) = (struct Obj *)func_0204A6C8(g, 5, 0, 0, H);
    *(struct Obj **)(p + 0x1874) = (struct Obj *)func_0204AF28(g, 0x11, 0x15, H);
    cfg.x = 32; cfg.y = 224; cfg.index = 0; cfg.a = 0; cfg.b = 2;
    *(struct Obj **)(p + 0x184c) = func_0204B294((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 224; cfg.y = 224; cfg.index = 1;
    *(struct Obj **)(p + 0x1850) = func_0204B294((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    cfg.x = 128; cfg.y = 96; cfg.index = 2; cfg.a = 0; cfg.b = 0;
    *(struct Obj **)(p + 0x1854) = func_0204B294((void *)W(0x1848), W(0x1864), W(0x1858), W(0x1870), &cfg, 0, H);
    func_0204B3DC(*(struct Obj **)(p + 0x184c), 1);
    func_0204B3DC(*(struct Obj **)(p + 0x1850), 1);
    func_0204B3DC(*(struct Obj **)(p + 0x1854), 0);
    func_02049238(g);
    func_020409B4(3);
    func_020409B4(2);
    func_020409B4(7);
}

void func_021B6E4C(const void *t,unsigned int id) {func_0203FCA0(id,t,0);func_02040588(id,1);func_020414AC(id);func_020409B4(id);}

void func_021B6E74(u8 *p)
{
    int v[3];
    int *q;
    *(u8 * *)&((struct Obj02852 *)p)->f187C = func_021F5164(((struct Obj02852 *)p)->f0);
    func_021F5438((void **)(*(u8 * *)&((struct Obj02852 *)p)->f187C), 0x50000);
    func_021F5444(*(u8 * *)&((struct Obj02852 *)p)->f187C, 0x3fe0);
    *(u8 * *)&((struct Obj02852 *)p)->f1880 = func_021F5204(*(u8 * *)&((struct Obj02852 *)p)->f187C, (*(void ***)(p + 4))[1], 0);
    func_021F51E8(*(u8 * *)&((struct Obj02852 *)p)->f187C);
    func_021F51F4((void **)(*(u8 * *)&((struct Obj02852 *)p)->f187C));
    q = (int *)func_021F545C(*(u8 * *)&((struct Obj02852 *)p)->f1880);
    v[0] = (0x80000 - q[0]) / 16;
    v[1] = (0xc0000 - (0x70000 - q[1])) / 16;
    v[2] = 0x28000;
    func_021F5350((int *)(*(u8 * *)&((struct Obj02852 *)p)->f1880), v);
}

extern u32 (*d_020A8148)(u32, u32, u32);


void func_021B6F00(u8 *p)
{
    int i;
    int j;
    u32 zero;
    u8 *table;
    void *h;
    int w;
    u32 flags;
    u32 vram;
    u32 hgt;
    u32 sz;
    u16 sizes[2];
    u16 dims[2];
    u16 *pal;
    u32 n;
    u8 k;
    u8 *buf;
    void *res;
    u8 *e;

    *(u16 *)(p + 0xa8) = 0;
    zero = 0;
    for (i = 0; i < 250; i++) {
        if (func_0200A644(*(void **)(*(u8 **)(p + 4) + 8), i) == 1) {
            *(u16 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xac) = i;
            *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xb8) = zero;
            if (func_0200A680(*(void **)(*(u8 **)(p + 4) + 8), i) == 1)
                *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = 1;
            else
                *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = zero;
            (*(u16 *)(p + 0xa8))++;
        }
    }
    for (j = 0; *(u16 *)(p + 0xa8) + j < 250; j++) {
        *(u16 *)(p + (*(u16 *)(p + 0xa8) + j) * 0x14 + 0xac) = 0xff;
        *(u32 *)(p + (*(u16 *)(p + 0xa8) + j) * 0x14 + 0xb8) = 0;
        *(u32 *)(p + *(u16 *)(p + 0xa8) * 0x14 + 0xbc) = 1;
    }

    *(u8 **)(p + 0x1884) = (u8 *)func_021F48C0((u32)(*(void **)(p + 0x188c)), 0x98, *(u16 *)p);
    table = (u8 *)func_021F4F10(*(u8 **)(p + 0x1884));

    for (i = 0; i < *(u16 *)(p + 0xa8); i++) {
        h = func_021F4B3C(*(u16 *)(p + i * 0x14 + 0xac));
        func_02046FF8(h);
        w = func_02047388(h);
        hgt = func_020473B8(h);
        sz = ((hgt & 0xFFFF0000) >> 16) << 3;
        vram = d_020A8148(sz, 0, 0);
        flags = func_021F4F70((int *)func_021F4F54(table, *(u16 *)(p + i * 0x14 + 0xac)));
        func_0204EDD0(flags, &sizes[1], &sizes[0]);
        *(u32 *)(p + i * 0x14 + 0xb0) = func_0204F044(*(void **)(p + 0x188c), w, hgt, 0, flags, sizes[1], sizes[0]);
        pal = (u16 *)func_020473EC((int)h);
        n = sz >> 1;
        for (k = 0; k < n; k++) {
            u16 c = pal[k];
            u32 b = (u32)(u8)((c & 0x7C00) >> 10) >> 3;
            u32 r = (u32)(u8)(c & 0x1F) >> 3;
            u32 g = (u32)(u8)((c & 0x3E0) >> 5) >> 3;
            pal[k] = r | (g << 5) | (b << 10);
        }
        buf = func_02046F48(h);
        res = func_02047250(h);
        func_0206A124(res, vram);
        func_020862F0(buf, *(u32 *)(buf + 8));
        func_0206A12C(res, 1);
        *(u32 *)(p + i * 0x14 + 0xb4) = func_0204F044(*(void **)(p + 0x188c), w, vram, 0, flags, sizes[1], sizes[0]);
        func_021F4B4C(h);
    }

    func_021B9028(p, 8, 0);
    *(u8 **)(p + 0x181c) = func_021BA0CC(*(u16 *)p, 0xe);
    *(u8 **)(p + 0x1820) = func_021BA0CC(*(u16 *)p, 0x80);
    *(u8 **)(p + 0x1824) = func_021BA0CC(*(u16 *)p, 9);
    *(u8 **)(p + 0x1828) = func_021BA0CC(*(u16 *)p, 4);

    for (i = 0; i < 14; i++) {
        Vec_021B6F00 v = {0, 0, 0};
        e = func_021BA19C(*(u16 *)p, *(void **)(p + 0x1884), p + 0xac + i * 0x14, (int *)(&v));
        func_021BA100(*(void **)(p + 0x181c), e);
        func_021F4EE8(*(u8 **)(p + 0x1884), (u8 *)func_021BA218(e), 0);
    }

    {
    Vec_021B6F00 v2 = {0, 0, 0};
    *(u16 *)(p + 0x50) = 0;
    flags = func_021F4F70((int *)func_021F4F54(table, *(u16 *)(p + 0x50)));
    func_0204EDD0(flags, &dims[1], &dims[0]);
    h = func_021F4B3C(*(u16 *)(p + 0x50));
    func_02046FF8(h);
    w = func_02047388(h);
    *(u32 *)(p + 0x54) = func_0204F044(*(void **)(p + 0x188c), w, func_020473B8(h), 0, flags, dims[1], dims[0]);
    *(u8 **)(p + 0x4c) = func_021F4C1C(*(u8 **)(p + 0x1884), *(u16 *)(p + 0x50), *(u32 *)(p + 0x54), &v2);
    func_021F4E6C(*(u8 **)(p + 0x1884), *(u8 **)(p + 0x4c), 0);
    func_021F4EB4((u32)(*(u8 **)(p + 0x1884)), (u32)(*(u8 **)(p + 0x4c)), 0x1000, 0x1000);
    func_021F4DE0((char *)(*(u8 **)(p + 0x1884)), (char *)(*(u8 **)(p + 0x4c)), h);
    func_021F4B4C(h);
    }

    *(u32 *)(p + 0x58) = func_0204EFC8(*(void **)(p + 0x188c), 0x2e, 0x19, 2, 0x22, 0x20, 0x20);
    for (k = 0; k < 14; k++) {
        Vec_021B6F00 v3 = {0, 0, 0};
        n = func_0204F428(*(void **)(p + 0x188c), *(u32 *)(p + 0x58), 0x1000, 0x1000, (struct Vec3 *)(&v3), 0x1f, 0, 0);
        *(u32 *)(p + k * 4 + 0x5c) = n;
        func_0204F720(*(void **)(p + 0x188c), n, d_021BA3E0);
    }

    *(u16 *)(p + 0x94) = 0;
    e = func_0200A628(*(void **)(*(u8 **)(p + 4) + 8));
    for (k = 0; k < 8; k++) {
        if (e[k * 6] != 10)
            func_021B7368(p, *(u16 *)(e + k * 6 + 2));
    }
    func_021B7A18(p);
    *(u32 *)(p + 0x1834) = *(u16 *)(p + 0xa8) * 0x1249 - 0x8000;
    func_021B765C(p, 0, 0, 0x48, 0x30);
}

void func_021B7368(u8 *p,u16 id)
{
    Pair pos;
    Vec_021B7368 scale;
    u8 *e,*q;
    u8 i;
    e=0;
    for(i=0;i<*(u16 *)(p+0xa8);i++){
        if(id==*(u16 *)(p+i*20+0xac)){e=p+0xac+i*20;break;}
    }
    if(e){
        int y;
        func_021B7458(p,(int *)(&pos));
        if((int)pos.x>0) scale.x=(int)(0.5f+(float)((int)pos.x<<12));
        else scale.x=(int)((float)((int)pos.x<<12)-0.5f);
        if((int)pos.y>0) y=(int)(0.5f+(float)((int)pos.y<<12));
        else y=(int)((float)((int)pos.y<<12)-0.5f);
        scale.y=y;
        scale.z=(10<<12)-(func_021BA188((char *)(*(u8 **)(p+0x1820)))<<10);
        q=func_021BA19C(*(u16 *)p,*(void **)(p+0x1884),e,(int *)(&scale));
        func_021BA100(*(void **)(p+0x1820),q);
        func_021BA21C(q,(const u8 *)(&pos));
        func_021F4EB4(*(int *)(p+0x1884),func_021BA218(q),0x1000,0x1000);
        *(u32 *)(e+0xc)=1;
    }
}
