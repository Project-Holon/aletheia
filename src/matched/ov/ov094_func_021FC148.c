/*
 * function: func_021FC148
 * address:  0x021FC148
 * packet:   pkt_ov094_021FC148
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0202142C  0x0202142C  thumb
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021F86F0  0x021F86F0  thumb  ov094
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_021FF3F4  0x021FF3F4  thumb  ov094
 *   func_02201B20  0x02201B20  thumb  ov094
 */
typedef unsigned short u16;
typedef short s16;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
    char pad2[0x254 - 0x240];
    u16 f254;
} State;

typedef struct {
    int x;
    int y;
    int z;
} Pt;

extern int func_0201134C(int);
extern unsigned short func_0202142C(int a0);
extern void func_0206DF3C(Pt *p, int *a, int *b);
extern int func_021F8694(void);
extern int func_021F86F0(void);
extern int func_021FCF2C(int a, int idx);
extern void func_021FF3F4(void *obj, void *out, int idx);
typedef unsigned int   u32;
extern int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16 x, s16 y, u32 e, u32 f);

int func_021FC148(int a, State *s)
{
    int idx = func_0201134C(a);
    int q = func_021FCF2C(a, func_0201134C(a));
    int dx = func_0201134C(a);
    int dy = func_0201134C(a);
    int p5 = func_0201134C(a);
    int p6 = func_0201134C(a);
    Pt pt;
    int o1;
    int o2;
    int m;

    func_021FF3F4((void *)func_021F8694(), &pt, q);
    pt.x += dx;
    pt.y += dy;
    func_0206DF3C(&pt, &o1, &o2);
    m = func_0202142C(s->f254);
    m = (m == 0 || m > 0x19) ? 4 : m;
    m = (m == 0x19) ? 0x11 : m;
    m *= 2;
    s->t[idx] = (int)func_02201B20((char *)func_021F86F0(), 0x5f, m + 0x81, m + 0x82, 0x81, 0x82, o1, o2, p5, p6);
    return s->f23c;
}
