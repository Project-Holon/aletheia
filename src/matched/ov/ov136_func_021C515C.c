/*
 * function: func_021C515C
 * address: 0x021C515C
 * packet: pkt_ov136_021C515C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
    u8 flag;
    u8 pad5[3];
} WinSlot;

typedef struct {
    u32 heapId;
    u8 pad4[0x44 - 4];
    void *win[7];
    WinSlot slot[6];
    u8 pad90[0x98 - 0x90];
    void *f98;
} Obj;

extern void func_02045088(u16);
extern void *func_020450F0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void *func_0201C440(u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 layer);

void func_021C515C(Obj *p)
{
    int i;
    void *w;

    func_02045088((u16)p->heapId);
    p->win[0] = func_020450F0(1, 0, 0, 1, 1, 5, 0);
    p->win[1] = func_020450F0(1, 3, 3, 0x1A, 4, 1, 0);
    p->win[2] = func_020450F0(1, 3, 8, 0x1A, 4, 1, 0);
    p->win[3] = func_020450F0(1, 3, 0xD, 0x1A, 4, 1, 0);
    p->win[4] = func_020450F0(1, 8, 0x13, 0xB, 2, 1, 0);
    p->win[5] = func_020450F0(1, 0x15, 0x13, 8, 2, 1, 0);
    p->win[6] = func_020450F0(0, 2, 1, 0x1C, 4, 5, 1);
    for (i = 0; i < 6; i++) {
        p->slot[i].win = p->win[i];
        p->slot[i].flag = 0;
    }
    p->f98 = func_0201C440((u16)p->heapId);
    for (i = 0; i < 7; i++) {
        func_02043B5C(func_02045770(p->win[i]), 0);
        if (i < 5) {
            w = p->win[i];
            func_02045334(w);
            func_02045374(w);
            func_020409B4(func_02045730(w));
        }
    }
}
