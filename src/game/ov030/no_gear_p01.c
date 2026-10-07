/*
 * file:     no_gear_p01.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEC4, func_021EFECC, func_021EFF54
 * address:  0x021EFEC0
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02043598  0x02043598  arm
 *   d_021F0134     0x021F0134  data  ov030  a4
 *   d_021F0140     0x021F0140  data  ov030  a4
 *   func_02040588  0x02040588  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_0204047C  0x0204047C  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021F014C     0x021F014C  data  ov030  a4
 *   d_021F016C     0x021F016C  data  ov030  a4
 *   d_021F018C     0x021F018C  data  ov030  a4
 */
struct Ctx;
struct Sub0200852CObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 pad0[2];
    u16 heap;
    u16 pad1;
    u32 pad2[2];
    u32 w14;
    void *w18;
} Obj;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *h);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
void func_021EFEC0(int *p, int v);
void func_021EFEC4(int *p, int v);
void func_021EFECC(Obj *p);
void func_021EFF54(void);
extern const u32 d_021F0134[];
extern const u32 d_021F0140[];
extern struct BgTemplate d_021F014C;
extern struct BgTemplate d_021F016C;
extern struct BgTemplate d_021F018C;

void func_021EFEC0(int *p, int v)
{
    *p = v;
}


/*
 * Tail call to the unlabelled ov030 leaf func_021EFEC0; its ABS32 pool word
 * is now witnessed by the EXACT shard entry for func_021EFEC0 (matched x1).
 */
void func_021EFEC4(int *p, int v)
{
    func_021EFEC0(p, v);
}


void func_021EFECC(Obj *p)
{
    void *h;
    int i;

    h = func_020490F4(0x1E, p->heap);
    i = func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4(p->w18)));
    func_02049B68(h, d_021F0134[i], 4, 0, 0, p->heap);
    p->w14 = func_02049740(h, d_021F0140[i], 6, 0, 0, p->heap);
    func_02049990(h, 3, 6, 0, (u16)p->w14, 0, 0, p->heap);
    func_02049238(h);
    func_0203D34C(0, p->heap);
    func_02043598(0x10, 1);
}


void func_021EFF54(void)
{
    int i;

    for (i = 4; i <= 7; i++) {
        func_02040588((u8)i, 0);
    }
    {
        struct BgTemplate t = d_021F014C;
        func_0203FCA0(6, &t, 0);
        func_02040588((u8)6, 1);
        func_0204047C(6, 3);
        func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(6);
    }
    {
        struct BgTemplate t = d_021F016C;
        func_0203FCA0(5, &t, 0);
        func_02040588((u8)5, 1);
        func_0204047C(5, 1);
        func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(5);
    }
    {
        struct BgTemplate t = d_021F018C;
        func_0203FCA0(4, &t, 0);
        func_02040588((u8)4, 1);
        func_0204047C(4, 2);
        func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
        func_020409B4(4);
    }
}
