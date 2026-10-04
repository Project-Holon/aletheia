/*
 * function: func_021E9010
 * address: 0x021E9010
 * packet: pkt_ov170_021E9010
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_02007E50 0x02007E50 thumb
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021EBB34 0x021EBB34 thumb ov170
 *   func_021DD2B4 0x021DD2B4 thumb ov170
 *   func_021DD718 0x021DD718 thumb ov170
 *   func_021DD8A8 0x021DD8A8 thumb ov170
 *   func_021EC48C 0x021EC48C thumb ov170
 *   func_021DEFF8 0x021DEFF8 thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021EBB58 0x021EBB58 thumb ov170
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021E8F50 0x021E8F50 thumb ov170
 */
extern unsigned func_021DD25C(unsigned char *p, unsigned short a, int box, unsigned id, unsigned v);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Struct_02025CD0;
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021EBB34(unsigned char *p, unsigned item, int b);
extern void func_021DD2B4(int a, int b, int c, int d, int e);
extern int func_021DD718(unsigned char *p, void *mon);
extern void func_021DD8A8(unsigned char *p, unsigned idx);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFF8(unsigned char *p, int idx);
extern void func_020061E4(unsigned se);
extern void func_021EBB58(unsigned char *p, int b);
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021ED55C(char **p, int flag);
extern int func_021E8F50(unsigned char *p, int v);
#define WORK(p) (*(char **)((p) + 0x2C))
int func_021E9010(unsigned char *p)
{
    unsigned item;
    void *mon;
    item = func_021DD25C(p, p[0x16], p[0x14], 6, 0);
    if (func_02007E50(*(void **)(*(char **)p + 0xC), item, 1, 0x4C) == 1) {
        mon = (void *)func_021DD2D0((void ***)p, p[0x14], p[0x16]);
        func_021EBB34(p, item, 0x18);
        func_021DD2B4((int)p, p[0x16], p[0x14], 6, 0);
        if (func_021DD718(p, mon) == 1) {
            func_021DD8A8(p, p[0x16]);
            func_021EC48C(p, p[0x14], p[0x16], *(unsigned char *)(WORK(p) + p[0x16] + 0x3DD2));
        }
        func_021DEFF8(p, p[0x16]);
    } else {
        func_020061E4(0x557);
        func_021EBB58(p, 0x18);
    }
    if (func_020355C4() == 1) {
        func_020260F4(*(void **)(WORK(p) + 0x70), 0);
    } else {
        func_020260F4(*(void **)(WORK(p) + 0x70), 1);
        func_021ED55C((char **)p, 0);
    }
    *(int *)(p + 0x28) = 0xE;
    return func_021E8F50(p, 6);
}
