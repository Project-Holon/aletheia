/*
 * file:     palette_anime_p03.c
 * unit:     yes
 * function: func_021C13E8, func_021C14DC, func_021C15B8, func_021C1610, func_021C1628
 * address:  0x021C13E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C1D28  0x021C1D28  thumb  ov217
 *   func_021C1AB4  0x021C1AB4  thumb  ov217
 *   func_021C1B28  0x021C1B28  thumb  ov217
 *   d_02148D8C  0x02148D8C  data  a4
 *   d_02148D98  0x02148D98  data  a4
 *   d_02148DA4  0x02148DA4  data  a4
 *   d_02148B98  0x02148B98  data  a4
 *   d_02148BCC  0x02148BCC  data  a4
 *   d_02148B54  0x02148B54  data  a4
 *   func_0207D7C4  0x0207D7C4  arm
 *   func_0207D760  0x0207D760  arm
 *   func_0206A700  0x0206A700  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_0207C554  0x0207C554  arm
 *   func_0206A854  0x0206A854  arm
 *   func_021C1638 0x021C1638 thumb ov217
 *   func_021C1648 0x021C1648 thumb ov217
 *   func_021C1658 0x021C1658 thumb ov217
 *   func_021C1670 0x021C1670 thumb ov217
 *   func_021C1680 0x021C1680 thumb ov217
 *   func_021C16C4 0x021C16C4 thumb ov217
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *   func_021C16E8  0x021C16E8  thumb  ov217
 *   func_021C16FC  0x021C16FC  thumb  ov217
 */
#include "../../matched/include/G_Glb.h"
#include "../../matched/include/Obj04640.h"
#include "../../matched/include/Obj26010.h"
#include "../../matched/include/Obj04641.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021C13E8;

typedef unsigned int u32;

struct Ent { s16_021C13E8 x, y, z; };

struct Cam {
    u8 cnt;
    u8 pad1[7];
    s16_021C13E8 x, y, z;
    struct Ent t[4];
};

struct Big { u8 pad[0x1AC]; struct Cam c; };

typedef struct { int x, y, z; } V;

typedef struct { u32 w0,w4,type,wc,counter; } Rec;

typedef signed char    s8;

typedef signed short   s16_021C1610;

typedef signed int     s32;

typedef signed short   s16_021C1628;

extern int func_021C1D28(u8 *p);
extern void *func_021C1AB4(void *p, u32 n);
extern void func_021C1B28(u8 *e, u8 *a, u8 *b);
extern void func_0207D7C4(V *a, V *b, V *c, int d, int e);
extern void func_0207D760(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void func_0206A700(void);
extern void func_0207BCA0(V *a, V *b, V *c, V *d);
extern void func_0207C554(int a, int b, int c, int d, int e, int f, int g, V *h);
extern void func_0206A854(void);
extern void func_021C1638(u8 *);
extern void func_021C1648(u8 *);
extern void func_021C1658(u32);
extern void func_021C1670(u8 *);
extern void func_021C1680(Rec *);
extern void func_021C16C4(void *);
extern u32 func_021C0E64();
extern void func_021C16E8(u32 a0);
extern void *func_021C16FC(void *p, u32 v);
void func_021C13E8(struct Big *p);
void func_021C14DC(u8 *p);
void func_021C15B8(u8 *p);
void func_021C1610(u32 a0);
void func_021C1628(u8 *a0);
extern V d_02148D8C;
extern V d_02148D98;
extern V d_02148DA4;
extern V d_02148B98;
extern struct Glb d_02148BCC;
extern V d_02148B54;


/*
 * GX FIFO line draw: for each entry with state >= 3, a degenerate triangle from the
 * centre (c.x, c.y) to the centre plus vertex t[min]. Closed 2026-10-05 (wD9r lane52):
 * the vertex is indexed as a struct array p->c.t[b[1]] (not a p + k*6 base pointer),
 * the vertex words are packed x first ((u16)x | (u16)y << 16, the GX_FX16PAIR order),
 * and i is declared before n (spill slots n@0, i@4).
 *
 * Addresses are Black-image addresses.
 */
void func_021C13E8(struct Big *p)
{
    u8 b[2];
    u8 *e;
    int i;
    int n;

    if (func_021C1D28((u8 *)p) == 0) {
        *(volatile u32 *)0x040004A4 = 0x001F00C0;
        n = p->c.cnt;
        for (i = 0; i < n; i++) {
            e = func_021C1AB4((u8 *)p, i);
            func_021C1B28(e, &b[1], &b[0]);
            if (e[8] >= 3) {
                s16_021C13E8 px, py, x, y;
                u32 va, vb;
                px = p->c.x;
                py = p->c.y;
                x = px + p->c.t[b[1]].x;
                y = py + p->c.t[b[1]].y;
                *(volatile u32 *)0x04000500 = 0;
                *(volatile u32 *)0x04000480 = 0;
                va = (u16)px | ((u32)(u16)py << 16);
                vb = (u16)x | ((u32)(u16)y << 16);
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = vb;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x04000504 = 0;
            }
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C14DC(u8 *p)
{
    V a;
    V b;
    V c;

    a.x = 0;
    a.y = 0;
    a.z = 0x1000;
    b.x = 0;
    b.y = 0x1000;
    b.z = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    func_0207D7C4(&a, &b, &c, 1, 0);
    func_0207D760(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, 1, 0);
    func_0206A700();
    d_02148D8C = a;
    d_02148D98 = b;
    d_02148DA4 = c;
    func_0207BCA0(&a, &b, &c, &d_02148B98);
    d_02148BCC.flag &= ~0xE8;
    func_0207C554(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, &d_02148B54);
    d_02148BCC.flag &= ~0x50;
    func_0206A854();
}

void func_021C15B8(u8 *p)
{
    if (((struct Obj04640 *)p)->f14==0) {
        switch (((struct Obj04640 *)p)->f8) {
        case 0: func_021C1610((u32)p); break;
        case 1: func_021C1628(p); break;
        case 2: func_021C1638(p); break;
        case 3: func_021C1648(p); break;
        case 4: func_021C1658((u32)p); break;
        case 5: func_021C1670(p); break;
        }
    }
    func_021C1680((Rec *)p);
    func_021C16C4(p);
}

void func_021C1610(u32 a0)
{
    if (func_021C0E64(((struct Obj26010 *)(((u8*)a0)))->fC) == 0) {
    func_021C16E8(a0);
    }
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void func_021C1628(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 120) {
    func_021C16FC(a0, 4);
    }
}
