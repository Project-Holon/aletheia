/*
 * function: func_021F78E4
 * address:  0x021F78E4
 * packet:   pkt_ov094_021F78E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * volatile: 0x021F7980 0x021F7986 (0x04000604 read twice, results unused)
 *
 * symbols:
 *   func_02030D28  0x02030D28  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02050BE8  0x02050BE8  arm
 *   func_02047970  0x02047970  arm
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021F9478  0x021F9478  thumb  ov094
 *   func_021F903C  0x021F903C  thumb  ov094
 *   func_021FEBAC  0x021FEBAC  thumb  ov094
 *   func_021F6934  0x021F6934  thumb  ov094
 *   func_021F6D5C  0x021F6D5C  thumb  ov094
 *   func_021F6ED4  0x021F6ED4  thumb  ov094
 *   func_02206EB4  0x02206EB4  thumb  ov094
 *   func_02201AF0  0x02201AF0  thumb  ov094
 *   func_021F69B0  0x021F69B0  thumb  ov094
 *   func_021F6DD4  0x021F6DD4  thumb  ov094
 *   func_021FEE9C  0x021FEE9C  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x188 - 4];
    void *h188;             /* 0x188 */
    void *h18c;
    void *h190;             /* 0x190 */
    void *h194;
    void *h198;
    void *h19c;
    void *h1a0;
    void *h1a4;
    char pad1a8[0x1e8 - 0x1a8];
    int f1e8;               /* 0x1e8 */
} Work;

extern Work *d_0220AF20;

struct Ctx;
struct W;
extern void func_02030D28(struct Ctx *c);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02050BE8(void);
extern void func_02047970(void);
extern int func_021F9478(void *);
extern void func_021F903C(void);
extern void func_021FEBAC(void *);
extern void func_021F6934(void *);
extern void func_021F6D5C(void *);
extern void func_021F6ED4(int *p);
extern void func_02206EB4(struct W *p);
extern void func_02201AF0(void *);
extern void func_021F69B0(void *);
extern void func_021F6DD4(void *);
extern void func_021FEE9C(int *p);

#define REG_04000604 (*(volatile u16 *)0x04000604)

void func_021F78E4(void)
{
    if (d_0220AF20 != 0) {
        d_0220AF20->f1e8 = func_021F9478(d_0220AF20->h188);
        func_021F903C();
        func_02030D28(d_0220AF20->owner);
        func_021FEBAC(d_0220AF20->h190);
        func_021F6934(d_0220AF20->h194);
        func_021F6D5C(d_0220AF20->h198);
        func_021F6ED4(d_0220AF20->h19c);
        func_02206EB4(d_0220AF20->h1a4);
        func_02201AF0(d_0220AF20->h1a0);
        func_02047964();
        func_020479D8();
        func_021F69B0(d_0220AF20->h194);
        func_021F6DD4(d_0220AF20->h198);
        func_021FEE9C(d_0220AF20->h190);
        REG_04000604;
        func_02050BE8();
        REG_04000604;
        func_02047970();
    }
}
