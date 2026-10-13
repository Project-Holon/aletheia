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
 *
 * symbols:
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
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

struct Party;
extern struct Party *POKEPARTY_Create(u32 heap);
extern void *sub_0200846C(int a0);
extern void *sub_02013234(u32 heap);
struct Big;
struct Sub02008700Obj;
extern void *sub_02012EBC(struct Big *p);
extern struct Sub02008700Obj *SYSTEM_DATA_GetConfig(void *sys);
extern void *sub_020082EC(int a0);
extern void sub_02008314(void *a0, void *a1);
extern void *sub_0200CA1C(void *a);
struct ZoneData;
extern void sub_02013980(struct ZoneData *o, u32 heap);
extern void sub_02082BCC(void *p, int c, int n);

void sub_020138C4(S *p, int a1, void *a2)
{
    u32 i;
    int t;
    int v;

    sub_02082BCC(p, 0, 0xf0);
    for (i = 0; i < 4; i++) {
        p->a24[i] = (void *)POKEPARTY_Create((u32)a2);
        p->a34[i] = (void *)sub_0200846C((int)a2);
        p->a48[i] = (void *)sub_02013234((u32)a2);
    }
    p->f58 = a1;
    t = (int)SYSTEM_DATA_GetConfig(sub_02012EBC((void *)a1));
    v = (int)sub_020082EC((int)a2);
    p->f5c = v;
    sub_02008314((void *)t, (void *)v);
    p->f68 = (int)sub_0200CA1C((void *)a1);
    p->b23 = 1;
    sub_02013980((struct ZoneData *)p, (u32)a2);
}
