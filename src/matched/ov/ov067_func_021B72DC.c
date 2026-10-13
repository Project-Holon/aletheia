/*
 * function: YESNO_MENU_Close
 * address:  0x021B72DC
 * packet:   pkt_021B72DC
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S {
    u8 _0[0x14];
    u8 f14;
    u8 _15[0x18 - 0x15];
    u8 f18;
    u8 _19[0x88 - 0x19];
    void *f88;
    void *f8c;
    u8 _90[0x98 - 0x90];
    u32 f98;
    u8 _9c[0xa0 - 0x9c];
    void *arrA0[4];
};

extern void func_02040588(unsigned char which, unsigned char enable);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Obj;
extern void func_0204B92C(struct Obj *a, u32 b);

void YESNO_MENU_Close(struct S *s)
{
    int p;
    u8 i;

    func_02040588(s->f14, 0);
    func_02040588(s->f18, 0);
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f88)), 0);
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f8c)), 0);
    p = (int)s->f88;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    p = (int)s->f8c;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    for (i = 0; i < 4; i++) {
        func_0204B3DC((struct Obj *)s->arrA0[i], 0);
        func_0204B92C(s->arrA0[i], 0);
    }
    s->f98 = 0;
}
