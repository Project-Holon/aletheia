/*
 * function: func_021BD2B0
 * address:  0x021BD2B0
 * packet:   pkt_ov088_021BD2B0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02007150  0x02007150  thumb
 *   func_02008764  0x02008764  thumb
 *   func_02007210  0x02007210  thumb
 *   func_02007218  0x02007218  thumb
 *   func_02007214  0x02007214  thumb
 *   func_0200721C  0x0200721C  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    void *h;
    u8 s4;
    u8 s5;
    u8 s6;
    u8 s7;
    u32 v8;
    u32 vC;
} St;

int func_02007150(int a0);
void func_02008764(void *);
struct Sub020071E4Ctrl;
u8 func_02007210(const struct Sub020071E4Ctrl *ctrl);
u8 func_02007218(const struct Sub020071E4Ctrl *ctrl);
void func_02007214(struct Sub020071E4Ctrl *ctrl, u8 v);
void func_0200721C(struct Sub020071E4Ctrl *ctrl, u8 v);

void func_021BD2B0(St *p)
{
    if (p->s7 != 1) {
        func_02007150((int)p->h);
        if (p->s7 == 0) {
            func_02008764(p->h);
            p->v8 = func_02007210(p->h);
            p->vC = func_02007218(p->h);
            func_02007214(p->h, 0);
            func_0200721C(p->h, 0);
        }
        p->s4 = 1;
    }
}
