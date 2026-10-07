/*
 * file:     unit_021F5260_p01.c
 * unit:     yes
 * function: func_021F5260, func_021F532C
 * address:  0x021F5260
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02010F94  0x02010F94  thumb
 *   sub_02010E14   0x02010E14  thumb
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_021F5488  0x021F5488  thumb  ov083
 *   func_02010FA0  0x02010FA0  thumb
 *   func_0201292C  0x0201292C  thumb
 *   sub_02007F1C   0x02007F1C  thumb
 *   func_021652C4  0x021652C4  thumb  ov010
 *   func_021657B0  0x021657B0  thumb  ov010
 *   func_02010F8C  0x02010F8C  thumb
 */
struct Ctx;
struct Rec02010F94;
struct BigObj;
struct Desc;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02010F7C(u32 heap);
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern unsigned int func_02010F94(struct Rec02010F94 *p, int idx);
extern void sub_02010E14(int slot, u8 *rec, int select);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02158F74(void *p);
extern void  func_021F5488(void *a0, void *a1, int a2);
extern u16   func_02010FA0(void *rec, int slot);
extern void *func_0201292C(const struct BigObj *p);
extern u32 sub_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021652C4(void *a0);
extern void  func_021657B0(int a0);
extern void  func_02010F8C(void *p);
void *func_021F5260(void *a0, int *a1);
void func_021F532C(void *p);


void *func_021F5260(void *a0, int *a1)
{
    void *h;
    void *s;
    void *obj;
    void *rec;
    int id;
    int x;
    u16 q;

    obj = func_020120F4(a0);
    rec = func_02010F7C(0x8015);
    id = a1[0];
    h = func_02158768((int)a0, 0x28B9, 0, 0x15);
    s = (void *)func_021589D0((int)h);
    if (id == 0x30 || id > 0x2D) {
        id = 0;
    }
    x = func_02010F94(rec, id);
    sub_02010E14(id, rec, a1[1]);
    if (id == 0x27) {
        func_02159058((int)s, (u16)id, (u16)0xB, (u16)a1[1], (u32)0);
    } else {
        func_02159058((int)s, (u16)id, (u16)x, (u16)a1[1], (u32)0);
    }
    func_021F5488(a0, func_02158F74(s), x);
    if (a1[1] != 0) {
        q = func_02010FA0(rec, id);
        sub_02007F1C(func_0201292C(obj), 0x23F, q, 0x8015);
        func_021652C4((void *)id);
    } else {
        func_021657B0(id);
    }
    func_02010F8C(rec);
    return h;
}

void func_021F532C(void *p) { func_02158768((int)p,0x28ba,0,0x15); }
