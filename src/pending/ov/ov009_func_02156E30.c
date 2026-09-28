/*
 * function: func_02156E30
 * address:  0x02156E30
 * packet:   pkt_ov009_02156E30
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  relocation witness (label/sole-ref): callees 0x02060F18 and 0x02060F40 have no outside witness
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   func_02030734  0x02030734  arm
 *   func_02060C5C  0x02060C5C  arm
 *   func_02060F18  0x02060F18  arm
 *   func_02060F40  0x02060F40  arm
 */

typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
} Obj;

extern Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];

extern void func_02034714(void *file, int line, void *msg);
extern u32 func_02030734(u32 heap, u32 size, u32 align, const char *file, u32 line);
extern u32 func_02060C5C(u32 a, u32 b, u32 c);
extern void func_02060F18(u32 a, u32 b);
extern void func_02060F40(u32 a, u32 b);

void func_02156E30(u32 a, u32 b, u32 c, u32 d)
{
    if (d_021A8268 == 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->fC != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    if (d_021A8268->f8 != 0) {
        func_02034714(d_021A1C78, 0, d_021A1C78);
    }
    d_021A8268->fC = func_02030734(d, b - 0x80, 0, d_021A1C7C, 0x62);
    d_021A8268->f8 = func_02060C5C((d_021A8268->fC + 0x1f) & ~0x1f, b - 0xc0, 0);
    d_021A8268->f10 = a;
    func_02060F18(d_021A8268->f8, 1);
    func_02060F40(d_021A8268->f8, 0xea);
    d_021A8268->f18 = c;
}
