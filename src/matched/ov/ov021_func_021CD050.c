/*
 * function: func_021CD050
 * address:  0x021CD050
 * packet:   pkt_ov021_021CD050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021CD004  0x021CD004  thumb  ov021
 *   func_02190788  0x02190788  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190764  0x02190764  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02045808  0x02045808  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 padE[0xA0 - 0xE];
    u32 fA0;
    u32 fA4;
    u32 fA8;
    u32 fAC;
    u32 fB0;
    u32 fB4;
    u32 fB8;
} Obj;

extern void func_021CD004(Obj *p);
struct MsgBank;
struct WordSet;
extern void func_02190788(u8 *p);
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02190764(u32 a, u16 b, u32 c, void *d, u16 e, u32 f);
extern int func_02190740(u32 a, u16 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);

void func_021CD050(Obj *p, void *party)
{
    void *buf1;
    void *buf2;
    int n;
    int i;
    void *mon;
    u32 v5;
    u32 v6e;
    u32 v9e;
    u32 vad;
    int x;

    func_021CD004(p);
    func_02190788((u8 *)p->fB4);
    buf1 = func_020457B0(0x40, p->heap);
    buf2 = func_020457B0(0x40, p->heap);
    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, 0x4c, 0) != 0) {
            continue;
        }
        v5 = func_02017E1C(mon, 5, 0);
        vad = func_02017E1C(mon, 0xad, 0);
        v9e = func_02017E1C(mon, 0x9e, 0);
        v6e = func_02017E1C(mon, 0x6e, 0);
        func_02045CAC((struct MsgBank *)p->fA8, 4, buf2);
        func_0201EFA4((struct WordSet *)p->fA0, 0, v9e, 3, 0, 1);
        func_0201F250((struct WordSet *)p->fA0, buf1, buf2);
        x = i * 0x28;
        func_02190764(p->fB4, x, 0x20, buf1, 0x440, p->fB8);
        if (v6e == 2) {
            continue;
        }
        if ((v5 == 0x1d || v5 == 0x20) && vad == 0) {
            continue;
        }
        if (v6e == 0) {
            func_02190740(p->fB4, x + 0x1f, 0x10, 5);
        } else {
            func_02190740(p->fB4, x + 0x1f, 0x10, 6);
        }
    }
    func_02045808(buf1);
    func_02045808(buf2);
}
