/*
 * function: BSUBWAY_RECORD_LIST_CreateWindows
 * address:  0x021B9C44
 * packet:   pkt_ov069_021B9C44
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   sWindowTemplates  0x021BA874  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u32 f0;
    u8 f4, f5, f6, f7;
    u16 f8;
} Ent;

typedef struct Obj {
    unsigned char pad000[0x10];
    int b[10];
    int a[8];
} Obj;

extern Ent *sWindowTemplates[];

extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);

void BSUBWAY_RECORD_LIST_CreateWindows(Obj *o)
{
    int i;
    int j;
    int h;
    Ent *e;

    BMP_WIN_Init(0x80);
    for (i = 0; i < 8; i++) {
        e = sWindowTemplates[i];
        o->a[i] = (int)BMP_WIN_Create((u8)e->f0, (int)e->f4, (int)e->f5, (int)e->f6, (int)e->f7, e->f8, (int)1);
        BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)o->a[i])), 0);
        h = o->a[i];
        BMP_WIN_TransferChars((struct Descriptor *)h);
        BMP_WIN_MakeScreen((struct Cfg *)h);
        func_020409B4(func_02045730((struct Descriptor *)h));
    }
    for (j = 0; j < 10; j++) {
        o->b[j] = (int)BMP_WIN_Create((u8)1, (int)2, (int)1, (int)10, (int)2, 1, (int)1);
        BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)o->b[j])), 4);
    }
}
