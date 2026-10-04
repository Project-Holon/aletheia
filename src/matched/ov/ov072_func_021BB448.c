/*
 * function: func_021BB448
 * address:  0x021BB448
 * packet:   pkt_ov072_021BB448
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned int   u32;
typedef signed short   s16;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct MsgBank;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_021BB448(u32 *p, u32 a, int x, int y)
{
    u32 w;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[0])), 0);
    func_02045CAC((struct MsgBank *)p[3], a, (void *)p[1]);
    func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)p[0])), x, y, (void *)p[1], (void *)p[2]);
    w = p[0];
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(func_02045730((struct Descriptor *)w));
}
