/*
 * function: func_0215F424
 * address:  0x0215F424
 * packet:   pkt_ov010_0215F424
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215911C  0x0215911C  thumb  ov010
 *   func_02162774  0x02162774  thumb  ov010
 *   func_02162788  0x02162788  thumb  ov010
 *   func_0215A480  0x0215A480  thumb  ov010
 *   func_02012844  0x02012844  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u32 f00;
    u16 f04;
    u16 f06;
} Entry;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u32 func_0215911C(void *p);
extern void func_02162774(char *p, unsigned i, u16 v);
extern void func_02162788(char *p, unsigned i, u16 v);
struct BigObj;
extern u16 func_0215A480(unsigned a);
extern u32 func_02012844(const struct BigObj *p);

int func_0215F424(int a0, int a1)
{
    void *w = func_0215A5F4((void *)a1);
    int s0 = func_02159B10((void *)a0, (void *)a1);
    int s1 = func_02159B10((void *)a0, (void *)a1);
    int s2 = func_02159B10((void *)a0, (void *)a1);
    int i0 = func_02159B10((void *)a0, (void *)a1);
    int i1 = func_02159B10((void *)a0, (void *)a1);
    int i2 = func_02159B10((void *)a0, (void *)a1);
    int obj = func_02012844(func_0215A5E4((void *)a1));
    Entry *t = (Entry *)func_0215911C(w);
    func_02162774((char *)obj, s0, t[i0].f04);
    func_02162774((char *)obj, s1, t[i1].f04);
    func_02162774((char *)obj, s2, t[i2].f04);
    func_02162788((char *)obj, s0, func_0215A480(t[i0].f06));
    func_02162788((char *)obj, s1, func_0215A480(t[i1].f06));
    func_02162788((char *)obj, s2, func_0215A480(t[i2].f06));
    return 0;
}
