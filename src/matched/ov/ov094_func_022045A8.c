/*
 * function: func_022045A8
 * address:  0x022045A8
 * packet:   pkt_ov094_022045A8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AEB0     0x0220AEB0  data   ov094  a1
 *   func_02030734  0x02030734  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0220461C  0x0220461C  thumb  ov094
 *   func_02204678  0x02204678  thumb  ov094
 *   func_0220684C  0x0220684C  thumb  ov094
 */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Main {
    unsigned char pad00[0x68];
    unsigned int f0 : 1;
    unsigned int st : 3;
    unsigned int hi : 28;
    unsigned char pad6C[0x240 - 0x6C];
    u16 h240;
} Main;

typedef struct Obj {
    Main *main;
    int idx;
    int set;
    int cnt;
} Obj;

extern const char d_0220AEB0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void *cb, void *ctx, int a);
struct Ctx;
extern void func_0220461C(int a0, struct Ctx *c);
extern void func_02204678(void *h);
extern void func_0220684C(char *p, int a, int b);

void func_022045A8(Main *m, int a1, int a2)
{
    Obj *o;

    o = func_02030734((u16)((m->h240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0xc10);
    o->main = m;
    o->idx = 0;
    o->set = a2;
    o->cnt = 2;
    func_0220684C((char *)m, (int)func_020056A0((void *)func_0220461C, o, 0), (int)func_02204678);
    m->st = m->st + 1;
}
