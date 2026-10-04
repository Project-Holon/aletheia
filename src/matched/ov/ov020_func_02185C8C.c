/*
 * function: func_02185C8C
 * address:  0x02185C8C
 * packet:   pkt_ov020_02185C8C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02012374  0x02012374  thumb
 *   func_021BE9F0  0x021BE9F0  thumb  ov021
 */

typedef struct { int f[7]; } S7;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
void func_020061E4(u32 a);
struct Ctx;
struct Evt;
int func_02189A08(unsigned char *p);
void func_021CF498(struct Ctx *c, u32 x, int idx);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void func_02184CEC(void *obj, void *p);
int func_02184504(int a, int *state, u8 *p);
void func_02012374(struct Evt *evt, struct Evt **out);
void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4);

int func_02185C8C(int a0, int *st, int *p)
{
    int r7 = p[7];
    int r6 = p[9];
    void *h;
    int *n;

    switch (st[0]) {
    case 0:
        func_020061E4(0x773);
        func_021CF498((struct Ctx *)func_02189A08((unsigned char *)r6), a0, 0x24);
        st[0]++;
        break;
    case 1:
        h = func_020122C0((void *)r7, 0, func_02184504, 0x9c);
        n = func_020124E8(h);
        func_02184CEC(n, (void *)r7);
        *(S7 *)(n + 4) = *(S7 *)p;
        n[0xb] = 0;
        n[0x10] = 0;
        func_02012374((struct Evt *)a0, h);
        st[0]++;
        break;
    case 2:
        func_02012374((struct Evt *)a0, func_021BE9F0((void *)r7, r6, 0, 0, 2));
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
