/*
 * function: func_021F5260
 * address:  0x021F5260
 * packet:   pkt_ov083_021F5260
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct. Only blockers: four unlabelled arm9 leaves (the integrator's), each
 * with no witness outside the range.
 * blocker:
 *   0x02010F7C thumb (verified EXACT in ov083_func_021F5390.c's header):
 *     extern int func_02048F60(int a, int b, int c);
 *     int func_02010F7C(int a) { return func_02048F60(0x26, 0, a); }
 *   0x02010F94 thumb (EXACT, `one --thumb`, no --region):
 *     typedef struct { u8 pad[10]; u8 fA; u8 fB; } Rec;
 *     u8 GPOWER_GetPowerType(Rec *rec, int slot) { return rec[slot].fA; }
 *   0x02010FA0 thumb (verified EXACT in ov032_func_021F1A28.c's header):
 *     u16 GPOWER_GetPowerCost(unsigned char *rec, int slot)
 *     { return *(u16 *)(rec + slot * 0xc + 2); }
 *   0x02010F8C thumb (verified in ov071_func_021B6458.c's header):
 *     void func_02010F8C(void *p) { void func_020307B0(void *); func_020307B0(p); }
 * The slot result is `int` (a `u8` local drops the per-use `lsls #16`), and
 * the declaration order h, s, obj puts them at sp+0x10, 0xc, 8.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   GPOWER_GetPowerType  0x02010F94  thumb
 *   GPOWER_Activate   0x02010E14  thumb
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_021F5488  0x021F5488  thumb  ov083
 *   GPOWER_GetPowerCost  0x02010FA0  thumb
 *   func_0201292C  0x0201292C  thumb
 *   MYITEM_SAVEDATA_RemoveItem   0x02007F1C  thumb
 *   func_021652C4  0x021652C4  thumb  ov010
 *   func_021657B0  0x021657B0  thumb  ov010
 *   func_02010F8C  0x02010F8C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Rec02010F94;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02010F7C(u32 heap);
struct BigObj;
struct Desc;
extern struct Desc *func_02158768(int a0, int a1, int a2, int a3);
extern int func_021589D0(int a0);
extern unsigned int GPOWER_GetPowerType(struct Rec02010F94 *p, int idx);
extern void GPOWER_Activate(int slot, u8 *rec, int select);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern void *func_02158F74(void *p);
extern void  func_021F5488(void *a0, void *a1, int a2);
extern u16   GPOWER_GetPowerCost(void *rec, int slot);
extern void *func_0201292C(const struct BigObj *p);
extern u32 MYITEM_SAVEDATA_RemoveItem(u8 *base, u16 id, u16 qty, u16 d);
extern void func_021652C4(void *a0);
extern void  func_021657B0(int a0);
extern void  func_02010F8C(void *p);

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
    x = GPOWER_GetPowerType(rec, id);
    GPOWER_Activate(id, rec, a1[1]);
    if (id == 0x27) {
        func_02159058((int)s, (u16)id, (u16)0xB, (u16)a1[1], (u32)0);
    } else {
        func_02159058((int)s, (u16)id, (u16)x, (u16)a1[1], (u32)0);
    }
    func_021F5488(a0, func_02158F74(s), x);
    if (a1[1] != 0) {
        q = GPOWER_GetPowerCost(rec, id);
        MYITEM_SAVEDATA_RemoveItem(func_0201292C(obj), 0x23F, q, 0x8015);
        func_021652C4((void *)id);
    } else {
        func_021657B0(id);
    }
    func_02010F8C(rec);
    return h;
}
