/*
 * function: func_021BD9B4
 * address: 0x021BD9B4
 * packet: pkt_ov209_021BD9B4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (wD7 lane20): pointer locals per loop group (arr, pb, pc) and literal zeros; mwcc itself keeps 0 in r6/r4 and 0x6b in r7.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AF28 0x0204AF28 arm
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(int);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 POKE_TOOL_CalcGraphicIndex(u32, u32, u32, u32);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern int func_0201BCEC(void);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);

struct R { u8 pad[0xB64]; int a[0x24]; int b[6]; int c[6]; };
void func_021BD9B4(struct R *p)
{
    int h, h2, h3;
    u32 i;
    u32 k;
    u32 a;
    int *arr;
    int *pb;
    int *pc;

    for (k = 0; k < 0x24; k++) p->a[k] = -1;
    for (k = 0; k < 6; k++) p->b[k] = -1;
    for (k = 0; k < 6; k++) p->c[k] = -1;

    h = (int)func_020490F4(0x9f, 0x806B);
    p->a[0x23] = func_0204A6C8((void *)h, 0x37, 0, 0, 0x6b);
    p->b[5] = func_0204ABF0((void *)h, 0x33, 0, 0, 0x6b);
    p->c[5] = func_0204AF28((void *)h, 0x3d, 0x47, 0x6b);
    func_02049238(h);

    h2 = (int)func_020490F4(7, 0x806B);
    arr = p->a;
    pb = &p->b[0];
    pc = &p->c[0];
    for (i = 0; i < 0x10; i++)
        arr[i] = func_0204A6C8((void *)h2, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 0, 0x6b);
    *pb = func_0204ACEC((void *)h2, func_0201BC3C(), 0, 0x80, 0x6b);
    a = func_0201BC40();
    *pc = func_0204AF28((void *)h2, a, func_0201BCB4(), 0x6b);

    arr = &p->a[0x10];
    pb = &p->b[1];
    pc = &p->c[1];
    for (i = 0; i < 0x10; i++)
        arr[i] = func_0204A6C8((void *)h2, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 1, 0x6b);
    *pb = func_0204ACEC((void *)h2, func_0201BC3C(), 1, 0, 0x6b);
    a = func_0201BC78();
    *pc = func_0204AF28((void *)h2, a, func_0201BCEC(), 0x6b);
    func_02049238(h2);

    h3 = (int)func_020490F4(func_020275E4(), 0x806B);
    p->a[0x22] = func_0204A6C8((void *)h3, func_02027618(), 0, 0, 0x6b);
    p->b[4] = func_0204ABF0((void *)h3, func_02027614(), 0, 0xe0, 0x6b);
    a = func_0202761C(2);
    p->c[4] = func_0204AF28((void *)h3, a, func_02027620(2), 0x6b);
    func_02049238(h3);
}
