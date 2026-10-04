/*
 * function: ov208_func_021C48CC
 * address:  0x021C48CC
 * packet:   pkt_ov208_021C48CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049B90  0x02049B90  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0204A298  0x0204A298  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   ov208_func_021C4B60  0x021C4B60  thumb
 *   data_021C8830  0x021C8830  data
 *   data_021C8794  0x021C8794  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Menu {
    u32 f0;
    u32 f4;
    u8  pad8[0x54c];
    u32 win[5];
    u32 active[5];
    u32 print[5];
    u32 msg;
    u32 arc;
    u32 msg2;
    u32 str[6];
};

struct Ov208WinTbl {
    u8 d[5][7];
};

extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct CharBuf;
struct MsgBank;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *win);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02045808(struct U16Vec *vec);
extern void ov208_func_021C4B60(u16 *heap, struct Ov208Menu *p, int key, int i);
extern const struct Ov208WinTbl data_021C8830;
extern const u16 data_021C8794[6];

void ov208_func_021C48CC(u16 *heap, struct Ov208Menu *p, int key)
{
    struct Ov208WinTbl t;
    u32 size;
    u32 bmp;
    u32 s;
    u8 i;

    t = data_021C8830;
    func_02049B90(0x17, 5, 4, 0, 0, 0x20, *heap);
    func_02049B90(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 5; i++) {
        p->win[i] = func_020450F0(t.d[i][0], t.d[i][1], t.d[i][2], t.d[i][3], t.d[i][4],
                                  t.d[i][5], t.d[i][6]);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 0);
        func_02045334((struct Descriptor *)p->win[i]);
    }
    p->msg = (u32)func_02045B38(0, 2, 0xea, *heap);
    p->msg2 = (u32)func_02045B38(0, 2, 0xf4, *heap);
    p->arc = func_0204A298(0x62, 0, 0, *heap, &size);
    bmp = (u32)func_02045770((struct Descriptor *)p->win[2]);
    s = (u32)func_02045EC0((struct MsgBank *)p->msg, 0xb8);
    func_0201C724(p->print[2], bmp, 0, 1, s, p->f4, 0x3c40);
    func_02045808((struct U16Vec *)s);
    s = (u32)func_02045EC0((struct MsgBank *)p->msg, 0xb9);
    func_0201C724(p->print[2], bmp, 0, 0x11, s, p->f4, 0x3c40);
    func_02045808((struct U16Vec *)s);
    p->active[2] = 1;
    ov208_func_021C4B60(heap, p, key, 2);
    for (i = 0; i < 6; i++)
        p->str[i] = (u32)func_02045EC0((struct MsgBank *)p->msg, data_021C8794[i]);
}
