/*
 * function: func_021D65C8
 * address: 0x021D65C8
 * packet: pkt_ov093_021D65C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned long loop index keeps its scaled offset in r7; direct u16 assignment truncates the first getter result before the second call.
 * symbols:
 *   func_021D66A0 0x021D66A0 thumb ov093
 *   func_021D5BDC 0x021D5BDC thumb ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   func_021D5970 0x021D5970 thumb ov093
 *   func_021D6D70 0x021D6D70 thumb ov093
 *   func_021D63B8 0x021D63B8 thumb ov093
 *   func_021D53C0 0x021D53C0 thumb ov093
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
struct Slot {u32 kind:3, rest:29;};
struct Byte7 {u8 v[7];};
struct Work {u8 pad[0x1c]; struct Slot slots[36]; u8 counters[36]; u8 padD0[0x2c]; struct Byte7 copy; u8 pad103[0xef]; u16 f1f2;};
extern int func_021D66A0(u32);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern int func_021D58A8(u8 *, int);
extern void func_021D5970(u8 *, int, u16);
extern void func_021D6D70(u8 *);
extern void func_021D63B8(u8 *p, int all);
extern void func_021D53C0(unsigned char *p);
extern void func_02082BCC(void *, u8, u32);
void func_021D65C8(struct Work *p, struct Work *q)
{
    unsigned long i;
    u16 t;
    u16 t2;
    p->copy = q->copy;
    p->f1f2 = q->f1f2;
    for (i = 0; i < 36; i++) {
        if (q->slots[i].kind != 0 && func_021D66A0(i)) {
            p->slots[i] = q->slots[i];
            p->counters[i] = q->counters[i];
        }
    }
    if (func_021D5BDC((void *)q, 10)) {
        func_021D5FE4((u8 *)p, 10);
        t = func_021D58A8((u8 *)p, 8);
        t2 = func_021D58A8((u8 *)p, 9);
        func_021D5970((u8 *)p, 8, t2);
        func_021D5970((u8 *)p, 9, t);
    }
    if (func_021D5BDC((void *)q, 9)) func_021D5FE4((u8 *)p, 9);
    func_021D6D70((u8 *)q);
    func_021D63B8((void *)q, 0);
    func_021D53C0((unsigned char *)((char *)q + 0xfc));
    func_02082BCC((u8 *)q + 0x155, 0, 2);
}
