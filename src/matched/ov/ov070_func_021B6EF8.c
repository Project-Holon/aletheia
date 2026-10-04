/*
 * function: func_021B6EF8
 * address:  0x021B6EF8
 * packet:   pkt_ov070_021B6EF8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The switch arms are in the original's layout order (0,1,3,4-5,2,8,9,6,7);
 * the table entry at 0x021BB9C8 is d_021BB9C4[i].fn, one extern through
 * its field (the pool word is the symbol + 4).
 *
 * symbols:
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_02027324  0x02027324  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B7640  0x021B7640  thumb  ov070
 *   func_02020FE4  0x02020FE4  thumb
 *   func_021B6EC8  0x021B6EC8  thumb  ov070
 *   d_021BB9C4     0x021BB9C4  data  a4
 *   func_021B690C  0x021B690C  thumb  ov070
 *   func_021B6934  0x021B6934  thumb  ov070
 *   func_021B6A78  0x021B6A78  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6AD8  0x021B6AD8  thumb  ov070
 *   func_021B7804  0x021B7804  thumb  ov070
 *   func_021B811C  0x021B811C  thumb  ov070
 *   func_021B8134  0x021B8134  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   func_021B9AAC  0x021B9AAC  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021BA9AC  0x021BA9AC  thumb  ov070
 *   func_02027858  0x02027858  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RangeEnt {
    u16 lo;
    u16 n;
    void (*fn)(void *);
} RangeEnt;

extern const RangeEnt d_021BB9C4[8];

struct MsgBank;
struct WordSet;
extern int func_021BADF0(int p);
struct Obj;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_021BB580(void *o, int v);
extern void func_02027324(u16 id);
extern void func_021B6100(void *obj, void *fn);
extern void func_021B7640(struct Obj *o);
extern u32  func_02020FE4(u16 a, u32 sel, u32 id);
extern int  func_021B6EC8(u16 id);
extern int  func_021B690C(u16 id);
extern void func_021B6934(u8 *p);
extern void func_021B6A78(u8 *p);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6AD8(int p);
extern void func_021B7804(struct Obj *o);
extern int func_021B811C(u8 *p);
extern int  func_021B8134(void *o, int k);
extern void func_021B6138(void *o);
extern void func_021BB3F4(int p, int mode);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021B8AF4(void *o);
extern u8 func_020355C4(void);
extern void func_021B9AAC(void *o);
extern void func_021B80C4(void *o, int v);
extern void func_021BA9AC(void *o);
extern void func_02027858(struct TaskMenu *m);

void func_021B6EF8(u8 *p)
{
    int flag = 0;
    u32 x;
    int r;

    if (func_021BADF0((int)p) == 0)
        return;
    if (func_020279E8(*(void **)(p + 0x77C))) {
        x = *(u32 *)(p + 0x828 + func_02027A04(*(void **)(p + 0x77C)) * 4);
        *(u32 *)(p + 0x848) = x;
        switch (x) {
        case 0:
            func_021BB580(p, 0);
            if (*(u32 *)(p + 0x80C) != 4)
                func_02027324(*(u32 *)(p + 0x84C));
            if (*(u32 *)(p + 0x80C) == 2) {
                func_021B6100(p, (void *)func_021B7640);
            } else if (func_02020FE4(*(u32 *)(p + 0x84C), 0x1D, *(u16 *)(p + 0x544)) == 1) {
                *(u32 *)(p + 0x844) = 0xC;
                func_021B6100(p, 0);
            } else if (func_021B6EC8(*(u32 *)(p + 0x84C)) >= 0) {
                d_021BB9C4[func_021B6EC8(*(u32 *)(p + 0x84C))].fn(p);
            } else {
                r = func_021B690C(*(u32 *)(p + 0x84C));
                if (r == 1) {
                    func_021B6100(p, (void *)func_021B6934);
                } else if (r == 2) {
                    func_021B6100(p, (void *)func_021B6A78);
                } else {
                    *(u32 *)(p + 0x844) = 5;
                    func_021B6100(p, 0);
                }
            }
            break;
        case 1:
            func_021BB580(p, 0);
            if (func_02028754(*(void **)(p + 0xC), 0)) {
                *(u32 *)(p + 0x844) = 0xB;
                func_021B6100(p, 0);
            } else {
                func_02045CAC((struct MsgBank *)(*(u32 *)(p + 0x51C)), 0x39, (void *)(*(u32 *)(p + 0x524)));
                func_0201F02C((struct WordSet *)(*(u32 *)(p + 0x520)), 0, (void *)(*(u32 *)(p + 8)));
                func_0201F250((struct WordSet *)(*(u32 *)(p + 0x520)), (void *)(*(u32 *)(p + 0x528)), (void *)(*(u32 *)(p + 0x524)));
                func_021B6100(p, (void *)func_021B6AD8);
            }
            break;
        case 3:
            func_021B6100(p, (void *)func_021B7804);
            break;
        case 4:
        case 5:
            if (func_021B811C(p) == 1) {
                func_021B8134(p, *(u32 *)(p + 0x810));
                func_021B6138(p);
                func_021BB3F4((int)p, 1);
                func_0204B92C(*(void **)(p + 0x6A8), 1);
                func_021B8AF4(p);
            }
            break;
        case 2:
            func_021BB580(p, 0);
            if ((int)*(u32 *)(p + 0x84C) >= 0x89 && (int)*(u32 *)(p + 0x84C) <= 0x94) {
                *(u32 *)(p + 0x844) = 0x13;
                func_021B6100(p, 0);
            }
            break;
        case 8:
            if (func_020355C4() == 1)
                func_021B9AAC(p);
            func_021B80C4(p, func_020355C4() == 0);
            func_021BB3F4((int)p, 1);
            func_0204B92C(*(void **)(p + 0x6A8), 1);
            func_021B8AF4(p);
            break;
        case 9:
            *(u32 *)(p + 0x844) = 1;
            func_021B6100(p, 0);
            break;
        case 6:
            *(u32 *)(p + 0x844) = 2;
            func_021BB580(p, 0);
            func_021B6100(p, 0);
            break;
        case 7:
            break;
        }
        flag = 1;
    }
    if (flag) {
        func_021BA9AC(p);
        func_02027858(*(void **)(p + 0x77C));
        *(u32 *)(p + 0x77C) = 0;
    }
}
