/*
 * function: func_021C1DCC
 * address:  0x021C1DCC
 * packet:   pkt_ov021_021C1DCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   abs_id_4A      0x0000004A  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F54E0  0x021F54E0  thumb  ov075
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_020124E8  0x020124E8  thumb
 *   func_021C313C  0x021C313C  thumb  ov021
 *   func_021C2D68  0x021C2D68  thumb  ov021
 *   func_021C2CF4  0x021C2CF4  thumb  ov021
 */

typedef unsigned char u8;

extern unsigned char abs_id_4A[];
void func_02034AC4(const void *id);
void func_02034A5C(const void *id);
int *func_021F54E0(int a);
int func_021C1CB0(int a, char *b, u8 c);
int func_020124E8(int a);
void func_021C313C(char *a, int b);
void func_021C2D68(void);
void func_021C2CF4(void);

int func_021C1DCC(int a, char *b, int c, int d)
{
    int *q;
    int r;
    int x;
    int *s;

    func_02034AC4(abs_id_4A);
    q = func_021F54E0(c);
    r = func_021C1CB0(a, b, *q);
    if (r == 0) {
        func_02034A5C(abs_id_4A);
        return 0;
    }
    x = func_020124E8(r);
    func_021C313C(b, x);
    *(int *)(x + 0x3c) = d;
    if (q[4] != 0)
        *(void **)(b + 0x128) = func_021C2D68;
    else
        *(void **)(b + 0x128) = 0;
    *(void **)(b + 0x12c) = func_021C2CF4;
    *(int *)(b + 0xc) = 2;
    s = (int *)(b + 0x9c);
    *(int *)(b + 0x9c) = q[3];
    s[1] = q[1];
    s[2] = q[2];
    if (q[4] == 1)
        s[3] = 1;
    else
        s[3] = 0;
    if (q[0] == 0xd && s[3] != 0)
        s[4] = 1;
    else
        s[4] = 0;
    func_02034A5C(abs_id_4A);
    return r;
}
