/*
 * function: func_021B74CC
 * address:  0x021B74CC
 * packet:   pkt_ov021_021B74CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02190758  0x02190758  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_021907C0  0x021907C0  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
} Entry;

typedef struct {
    u16 f00;
    u8 pad02[6];
    u32 f08;
    u32 f0C;
    u8 pad10[4];
    u32 f14;
    u32 f18;
    u32 f1C;
    int f20;
    Entry *f24;
} Obj;

struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(u32 a0, u32 a1, u32 a2);
extern void func_02190758(int a0, int a1, u16 a2, int a3);
extern void func_0201EFA4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void func_0201F250(u32 a0, u32 a1, u32 a2);
extern void func_02045C04(struct Rec *rec);
extern int func_021907C0(int a);
extern int func_02045730(int a);
extern void func_020409B4(u32 index);

void func_021B74CC(Obj *p)
{
    void *msg;
    int i;

    msg = func_02045B38(0, 2, 0x36, (u16)((p->f00 & 0x7fff) | 0x8000));
    for (i = 0; i < p->f20; i++) {
        func_02045CAC((u32)msg, p->f24[i].a, p->f18);
        func_02190758(p->f0C, 0, i * 14, p->f18);
        func_02045CAC(p->f08, 5, p->f18);
        func_0201EFA4(p->f14, 0, p->f24[i].b, 2, 1, 1);
        func_0201F250(p->f14, p->f1C, p->f18);
        func_02190758(p->f0C, 0x6c, i * 14, p->f1C);
    }
    func_02045C04(msg);
    func_020409B4(func_02045730(func_021907C0(p->f0C)));
}
