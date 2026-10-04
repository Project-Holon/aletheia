/*
 * function: func_021F3880
 * address:  0x021F3880
 * packet:   pkt_ov060_021F3880
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B40  0x02012B40  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_020127AC  0x020127AC  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 *   func_021F3870  0x021F3870  thumb  ov060
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

struct BigObj;
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_02012B40(const struct BigObj *p);
extern int func_020127B8(void *p);
typedef unsigned int   u32;
struct Rec1B0;
struct SaveBlock;
extern void *func_020127AC(struct SaveBlock *p, u32 idx);
extern u16 func_0200BDF8(struct Rec1B0 *p);
extern u16 func_0200BDFC(struct Rec1B0 *p);
extern int func_021F3870(int x);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4B4(void *p, int i, u16 j, int v);

u8 func_021F3880(void *a, void *b, void *unused)
{
    int r6;
    int r4;
    int r5;
    int r7;
    int e;
    V *p;

    r6 = func_02012B80(a);
    r4 = r6 - func_02012B58(a);
    if (r4 < 0) {
        r4 += func_02012B40(a);
    }
    if (r6 == func_02012B58(a)) {
        e = func_020127B8(a);
    } else {
        e = (int)func_020127AC(a, r6);
    }
    r7 = e;
    r5 = func_021F3870(func_0200BDF8((struct Rec1B0 *)r7));
    r7 = func_021F3870(func_0200BDFC((struct Rec1B0 *)r7));
    p = func_021BE480(b, 0, r5 + 10);
    r4 = (r4 << 22) + 0x1F8000;
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    p = func_021BE480(b, 0, r7);
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    func_021BE4B4(b, 0, r5 + 10, 0);
    func_021BE4B4(b, 0, r7, 0);
    return r6;
}
