/*
 * function: func_02156FDC
 * address:  0x02156FDC
 * packet:   pkt_ov009_02156FDC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * witness:  callee 0x02060F98 is witnessed by its ARM9 entry
 *           (src/matched/arm9/func_02060F98.c, pkt_02060F98).
 *
 * symbols:
 *   d_021A8268  0x021A8268  data  ov009  a4
 *   d_021A1C78  0x021A1C78  data  ov009  a1
 *   d_021A1C7C  0x021A1C7C  data  ov009  a1
 *   func_02060F98  0x02060F98  arm  arm9
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02060E30  0x02060E30  arm
 *   func_0203C9AC  0x0203C9AC  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u16 f20;
} Obj;

extern Obj *d_021A8268;
extern char d_021A1C78[];
extern char d_021A1C7C[];

typedef unsigned char  u8;
extern u8 func_02060F98(char *p);
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void func_02060E30(u32 heap, void *p);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);

void func_02156FDC(u32 a, void *p)
{
    u32 h;

    if (p == 0) {
        return;
    }
    if (func_02060F98(p) == 0xEA) {
        if (d_021A8268->f8 != 0) {
            h = func_02087988();
            func_02060E30(d_021A8268->f8, p);
            func_0208799C(h);
            d_021A8268->f14--;
            return;
        }
        func_0203C9AC(0, 0, 0, 0x3EE);
        return;
    }
    h = func_02087988();
    func_02060E30(d_021A8268->f0, p);
    func_0208799C(h);
}
