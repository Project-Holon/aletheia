/*
 * function: func_021BB630
 * address: 0x021BB630
 * packet: pkt_ov223_021BB630
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note (2026-10-05, wave D4 lane 06): EXACT. Three 0x94-byte fade slots at p+0x74 modelled as a
 *   struct array (src/dst/out palettes, state, step); inner loop indexes p->f[i] directly (no element
 *   pointer); step changes written as ++/-- (the read-modify-write form reloads the step); signed
 *   /16 via an int weight t; dst[j] read into a local before the first split call; colour packed
 *   as A << 10 | (B | C << 5).
 *
 * symbols:
 *   func_021BB520 0x021BB520 thumb ov223
 *   func_02061CA4 0x02061CA4 arm
 *   d_021BC6FC 0x021BC6FC data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u16 src[16];
    u16 dst[16];
    u16 out[16];
    u16 state;
    u16 step;
    u8 pad[0x30];
} Fade;
typedef struct {
    u8 head[0x74];
    Fade f[3];
} Ctx;
extern const u8 d_021BC6FC[];
extern void func_021BB520(int v, unsigned short *a, unsigned short *b, unsigned short *c);
extern int func_02061CA4(void *, unsigned, unsigned, int);
void func_021BB630(Ctx *p)
{
    u8 i;
    for (i = 0; i < 3; i++) {
        int go = 0;
        switch (p->f[i].state) {
        case 1:
            if (p->f[i].step == 0x10) {
                p->f[i].state = 2;
            } else {
                p->f[i].step++;
                p->f[i].step = 0x10;
                go = 1;
            }
            break;
        case 3:
            if (p->f[i].step == 0) {
                p->f[i].state = 0;
            } else {
                p->f[i].step--;
                go = 1;
            }
            break;
        }
        if (go) {
            if (p->f[i].state == 1 || p->f[i].state == 3) {
                u8 j;
                u16 w[6];
                for (j = 0; j < 0x10; j++) {
                    int t = p->f[i].step;
                    u16 c = p->f[i].dst[j];
                    func_021BB520(p->f[i].src[j], &w[5], &w[4], &w[3]);
                    func_021BB520(c, &w[2], &w[1], &w[0]);
                    p->f[i].out[j] =
                        (u16)((w[3] * (16 - t) + w[0] * t) / 16) << 10 | ((u16)((w[5] * (16 - t) + w[2] * t) / 16) | (u16)((w[4] * (16 - t) + w[1] * t) / 16) << 5);
                }
            }
            func_02061CA4((void *)0x1E, d_021BC6FC[i] << 5, (u32)p->f[i].out, 0x20);
        }
    }
}
