/*
 * function: func_021EF594
 * address:  0x021EF594
 * packet:   pkt_ov093_021EF594
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021EEFE0  0x021EEFE0  thumb  ov093
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

extern u8 func_021B8FF4(u8 *p);
extern int func_021B9F70(char *p, int i);
extern void func_021EEFE0(u32 a, u32 b, u32 c);
extern void func_02045CAC(u32 a, u32 b, u32 c);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern D d_021F6398;

void func_021EF594(u32 a, u32 b, u32 *p)
{
    u8 id = p[0];
    int k;

    if (id != func_021B8FF4((u8 *)d_021F6398.f0)) {
        if (func_021B9F70((char *)d_021F6398.f0, id))
            k = 0x23;
        else
            k = 0x22;
    } else {
        k = 0x21;
    }
    func_02045CAC(d_021F6398.f10, k, d_021F6398.fc);
    func_021EEFE0(d_021F6398.fc, (u32)p, d_021F6398.f8);
    func_0201F250(d_021F6398.f8, a, d_021F6398.fc);
}
