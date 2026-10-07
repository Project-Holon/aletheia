/*
 * file:     unit_021C6000_p01.c
 * unit:     yes
 * function: func_021C6000, func_021C60A0
 * address:  0x021C6000
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02040C14  0x02040C14  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201C440  0x0201C440  thumb
 *   d_021C8773  0x021C8773  data
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 */
struct CharBuf;
struct Descriptor;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *win[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
    u8 pad32D0[4];
    u8 f32D4;
} Work_021C6000;

typedef unsigned int   u32;

typedef struct {
    u8 pad0[4];
    void *bg[8];
    u8 pad24[0x32CC - 0x24];
    void *f32CC;
} Work_021C60A0;

extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041B6C(u32 bit);
extern u32 func_0201C440(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
void func_021C6000(Work_021C6000 *p);
void func_021C60A0(Work_021C60A0 *p);
extern const u8 d_021C8773[8][6];


/*
 * Addresses are Black-image addresses.
 */
void func_021C6000(Work_021C6000 *p)
{
    const u8 (*tbl)[6] = d_021C8773;
    u8 i;

    func_02045088(p->heap);
    for (i = 0; i < 8; i++) {
        p->win[i] = (void *)func_020450F0(tbl[i][0], tbl[i][1], tbl[i][2], tbl[i][3], tbl[i][4], tbl[i][5], 1);
        func_02043B5C(func_02045770(p->win[i]), 0);
    }
    func_02040C14(7, 0, 1, 0);
    func_0201F5BC(4, 0x31, 0xD, p->f32D4, p->heap);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, p->heap);
    func_02041B6C(7);
    func_02041B6C(4);
    p->f32CC = (void *)func_0201C440((void *)p->heap);
}


void func_021C60A0(Work_021C60A0 *p)
{
    u16 i;

    func_0201C4C0(p->f32CC);
    for (i = 0; i < 8; i++) {
        func_020452E8(p->bg[i]);
    }
    func_020450C8();
}
