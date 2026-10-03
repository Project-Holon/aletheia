/*
 * function: func_021BC008
 * address: 0x021BC008
 * packet: pkt_ov206_021BC008
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201AE14 0x0201AE14 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef struct S {
    char pad0[0x1b8];
    void *g[3];
    void *w[7];
    void *objs[35];
    void *x;
    void *a[16];
} S;
struct Rec;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201AE14(void *);
extern void func_02045C04(struct Rec *rec);
extern void func_02049238(void *);
void func_021BC008(S *p)
{
    u8 i;
    for (i = 0; i < 16; i++)
        func_02045808(p->a[i]);
    if (p->x != 0)
        func_0201AE14(p->x);
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] == 0)
                func_02045C04(p->objs[i]);
            break;
        case 2:
            if (p->g[1] == 0)
                func_02045C04(p->objs[i]);
            break;
        case 3:
            if (p->g[2] == 0)
                func_02045C04(p->objs[i]);
            break;
        default:
            func_02045C04(p->objs[i]);
            break;
        }
    }
    for (i = 0; i < 7; i++)
        func_02049238(p->w[i]);
}
