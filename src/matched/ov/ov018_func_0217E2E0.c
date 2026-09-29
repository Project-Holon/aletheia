/*
 * function: func_0217E2E0
 * address:  0x0217E2E0
 * packet:   pkt_ov018_0217E2E0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02082A60  0x02082A60  arm
 *   func_02021F64  0x02021F64  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x5c];
    void *f5c[16];
    u8 pad9C[0xdc - 0x9c];
    int fdc;
    u8 padE0[4];
    u8 *fe4;
    u8 padE8[0x16a - 0xe8];
    u8 f16a;
    u8 f16b;
} Work;

extern void func_0204B6F4(void *, u8, int);
extern void func_02082A60(const void *, void *, int);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);

void func_0217E2E0(Work *p)
{
    int sel;
    int v;
    int c;
    u16 buf[16];

    if (p->fdc == 3 && p->fe4 != 0) {
        sel = p->fe4[0x28];
        c = -1;
        v = p->f16a;
        if (v != 4 && v != sel) {
            func_0204B6F4(p->f5c[v + 12], v + 1, 1);
        }
        if (p->f16a != sel) {
            func_02082A60((void *)(0x05000600 + (sel + 1) * 32), buf, 0x20);
            func_02021F64(buf, buf, 0x10, 8, 0x7fff);
            func_02082A60(buf, (void *)0x05000720, 0x20);
            p->f16a = sel;
        }
        p->f16b++;
        if (p->f16b == 15) {
            c = 9;
        } else if (p->f16b >= 30) {
            c = sel + 1;
            p->f16b = 0;
        }
        if (c != -1) {
            func_0204B6F4(p->f5c[sel + 12], c, 1);
        }
        return;
    }
    v = p->f16a;
    if (v != 4) {
        func_0204B6F4(p->f5c[v + 12], v + 1, 1);
        p->f16a = 4;
        p->f16b = 0;
    }
}
