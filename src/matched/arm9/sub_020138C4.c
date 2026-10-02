/*
 * function: sub_020138C4
 * address:  0x020138C4
 * packet:   pkt_020138C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad0[0x23];
    u8 b23;
    void *a24[4];
    void *a34[4];
    char pad1[4];
    void *a48[4];
    int f58;
    int f5c;
    char pad2[8];
    int f68;
} S;

extern int sub_0201A920(void *p);
extern int sub_0200846C(void *p);
extern int sub_02013234(void *p);
extern void *sub_02012EBC(void *p);
extern void *sub_0200873C(void *sys);
extern int sub_020082EC(void *p);
extern void sub_02008314(int a, int b);
extern int sub_0200CA1C(int x);
extern void sub_02013980(S *p, void *a);
extern void sub_02082BCC(void *p, int c, int n);

void sub_020138C4(S *p, int a1, void *a2)
{
    u32 i;
    int t;
    int v;

    sub_02082BCC(p, 0, 0xf0);
    for (i = 0; i < 4; i++) {
        p->a24[i] = (void *)sub_0201A920(a2);
        p->a34[i] = (void *)sub_0200846C(a2);
        p->a48[i] = (void *)sub_02013234(a2);
    }
    p->f58 = a1;
    t = (int)sub_0200873C(sub_02012EBC((void *)a1));
    v = sub_020082EC(a2);
    p->f5c = v;
    sub_02008314(t, v);
    p->f68 = sub_0200CA1C(a1);
    p->b23 = 1;
    sub_02013980(p, a2);
}
