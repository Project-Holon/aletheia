/*
 * function: func_021BA6DC
 * address:  0x021BA6DC
 * packet:   pkt_ov099_021BA6DC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: source order of the three table reads (fe, then a, then b)
 * decides how the pool loads and ldrb group.
 *
 * symbols:
 *   func_021BA764  0x021BA764  thumb  ov099
 *   func_021BA770  0x021BA770  thumb  ov099
 *   func_02061CA4  0x02061CA4  arm
 *   d_021C287C     0x021C287C  data  ov099  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    char pad00[0xc];
    u8  fc;
    u8  fd;
    s16 fe;
    u8  f10;
} S;

typedef struct {
    u8 a, b, c, d;
} E;

extern const E d_021C287C[];
extern u16 *func_021BA764(S *s, int i);
extern void func_021BA770(S *s);
extern void func_02061CA4(int type, int addr, void *data, int size);

void func_021BA6DC(S *s)
{
    int a = 0;
    int b = 0;
    int c = 0;

    if (d_021C287C[s->fd].a == 1) {
        s->fe = s->fe - 1;
        if (s->fe <= 0) {
            c = 1;
        }
    } else if (s->f10 != 0) {
        s->f10 = 0;
        c = 1;
    }
    if (c != 0) {
        s->fd = s->fd + 1;
        if (s->fd >= 8) {
            func_021BA770(s);
            return;
        }
        s->fe = d_021C287C[s->fd].b;
        a = d_021C287C[s->fd].c;
        b = d_021C287C[s->fd].d;
    }
    if (a != 0) {
        func_02061CA4(0xf, (s->fc + 1) * 2 + 0xe0, func_021BA764(s, b), 2);
    }
}
