/*
 * function: func_021BB808
 * address:  0x021BB808
 * packet:   pkt_ov021_021BB808
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_021BB7B4  0x021BB7B4  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 */

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

int func_02188C58(int a);
int func_0218EC2C(int a);
void func_021BB7B4(int a, Vec *b, Vec *c);
void func_0207C9D0(Vec *a, Vec *b, Vec *c);

void func_021BB808(int *o, Vec *out)
{
    int r3;
    Vec w;

    switch (o[7]) {
    case 0:
        o[10] += o[11];
        if (o[10] != 0) {
            o[11] = o[11] - 0x2000;
        } else {
            o[11] = 0;
            o[7] = o[7] + 1;
        }
        break;
    case 1:
        o[8] = o[8] + 1;
        if (o[8] >= 30) {
            o[7] = o[7] + 1;
            o[9] = 1;
        }
        break;
    }
    r3 = func_0218EC2C(func_02188C58(o[6]));
    {
        Vec v = {0, 0, 0};

        v.y = o[10] + 0x16000;
        w = v;
    }
    func_021BB7B4(r3, &w, &w);
    func_0207C9D0(&w, out, out);
}
