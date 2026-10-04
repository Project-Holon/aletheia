/*
 * function: func_022056B4
 * address:  0x022056B4
 * packet:   pkt_ov094_022056B4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02041300  0x02041300  arm
 *   func_02021848  0x02021848  thumb
 *   func_02205F64  0x02205F64  thumb  ov094
 *   func_02206128  0x02206128  thumb  ov094
 *   func_02205D34  0x02205D34  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Main {
    void *owner;
    unsigned char pad04[0x64 - 4];
    int f64;
    unsigned char pad68[0x6c - 0x68];
    u32 f6c;
    unsigned char pad70[0x228 - 0x70];
    int o228;
    int o22c;
    int o230;
    int o234;
    unsigned char pad238[0x25a - 0x238];
    u8 b25a[8];
    u8 b262[4];
} Main;

struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
struct Descriptor;
extern void func_02045334(struct Descriptor *);
extern void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6);
extern void func_02021848(int a, int b, u16 c, int d, int e, int f, int g, void *h);
extern void func_02205F64(Main *m);
extern void func_02206128(Main *m);
extern void func_02205D34(Main *m);

void func_022056B4(Main *m)
{
    int i;
    int j;

    m->f6c &= ~2;
    for (i = 0; i < 8; i++) {
        m->b25a[i] = 0;
    }
    for (j = 0; j < 4; j++) {
        m->b262[j] = 0;
    }
    func_02043B5C((struct CharBuf *)m->o22c, 0);
    func_02045334((struct Descriptor *)m->o228);
    func_02043B5C((struct CharBuf *)m->o234, 0);
    func_02045334((struct Descriptor *)m->o230);
    func_02205F64(m);
    func_02206128(m);
    func_02205D34(m);
    func_02041300(4, 0, 0x20, 2, 0x20, 0x20, 0);
    func_02021848(m->f64, 2, 0x3e00, 0, 0, 0, 0, m->owner);
    func_02021848(m->f64, 8, 0x700, 0, 0, 0, 0, m->owner);
}
