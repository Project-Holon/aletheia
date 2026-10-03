/*
 * function: func_0217DE68
 * address:  0x0217DE68
 * packet:   pkt_ov018_0217DE68
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0217F284  0x0217F284  thumb  ov018
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02021F64  0x02021F64  thumb
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct {
    void *f00;
    u8 pad04[0x5c - 0x04];
    void *f5c[8];
    void *f7c;
    u8 pad80[0xd8 - 0x80];
    u8 fd8;
    u8 padD9[0x113 - 0xd9];
    u8 f113;
    u8 f114;
    u8 f115;
    u8 pad116[2];
    s16 f118;
    s8 f11a;
    u8 f11b;
    u8 f11c;
    u8 pad11D[3];
    u16 f120[4];
    u16 f128[4];
    u16 f130[4];
} Work;

typedef unsigned int   u32;
struct BigObj;
struct Ctx;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern int func_0217F284(Work *);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_02012B70(const struct BigObj *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B6F4(void *, u8, int);
extern void func_02082A60(const void *, void *, int);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);

void func_0217DE68(Work *p)
{
    void *sys;
    int i;
    int c;
    int q;
    void *act;

    sys = func_020120F4(p->f00);
    if (func_0217F284(p) == 1) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 0);
        }
        func_0204B3DC(p->f7c, 0);
    } else if (p->fd8 == func_02012B58(sys) || func_02012B70(sys) == 0) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 0);
        }
        func_0204B3DC(p->f7c, 0);
    } else {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(p->f5c[i], 1);
        }
        func_0204B3DC(p->f7c, 1);
    }
    for (i = 6; i <= 8; i++) {
        func_02082A60((void *)(0x05000602 + (p->fd8 + 1) * 32), (void *)(0x0500060C + i * 32), 2);
    }
    if (p->f114 == 1) {
        if (p->f115 % 2 == 0) {
            if (((unsigned)p->f115 >> 1) & 1) {
                c = 6;
            } else {
                c = 7;
            }
            q = p->f113;
            if (q != 8) {
                act = p->f5c[q];
            } else {
                act = p->f7c;
            }
            func_0204B6F4(act, c, 1);
        }
        if (p->f115 < 10) {
            p->f115++;
        }
        return;
    }
    if (p->f11b == 0xff) {
        return;
    }
    if (p->f11a == 0) {
        p->f118 += 0x100;
        if (p->f118 >= 0x1100) {
            p->f118 = 0x2000 - p->f118;
            p->f11a = 1;
        }
    } else {
        p->f118 -= 0x100;
        if (p->f118 < 0) {
            p->f118 = 0x100 - p->f118;
            p->f11a = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        func_02021F64(&p->f120[i], &p->f130[i], 1, p->f118 >> 8, p->f128[i]);
    }
    p->f11c = 1;
}
