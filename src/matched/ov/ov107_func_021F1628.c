/*
 * function: func_021F1628
 * address:  0x021F1628
 * packet:   pkt_ov107_021F1628
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    unsigned char pad08[8];
    void *f10;
} Ov107Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
u32 func_020452E8(struct Descriptor *d);
u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void *func_02045770(struct Descriptor *p);
void func_02043B5C(struct CharBuf *buf, u8 value);
void func_02045334(struct Descriptor *d);
void func_02045374(struct Cfg *cfg);
void func_020409B4(u32 index);

void func_021F1628(Ov107Ctx *p, int mode)
{
    if (p->f04 != mode) {
        if (p->f10 != 0) {
            func_020452E8(p->f10);
            p->f10 = 0;
        }
        switch (mode) {
        case 0:
            break;
        case 1:
            p->f10 = (void *)func_020450F0(p->f02, 3, 8, 0x1A, 8, 0xE, 1);
            break;
        case 2:
            p->f10 = (void *)func_020450F0(p->f02, 3, 2, 0x1A, 0x12, 0xE, 1);
            break;
        case 3:
            p->f10 = (void *)func_020450F0(p->f02, 3, 2, 0x1A, 0x14, 0xE, 1);
            break;
        case 4:
            p->f10 = (void *)func_020450F0(p->f02, 1, 0x15, 0x1E, 2, 0xE, 1);
            break;
        case 5:
        case 8:
            p->f10 = (void *)func_020450F0(p->f02, 1, 0x13, 0x1E, 4, 0xE, 1);
            break;
        case 6:
            p->f10 = (void *)func_020450F0(p->f02, 1, 0x11, 0x1E, 6, 0xE, 1);
            break;
        case 7:
            p->f10 = (void *)func_020450F0(p->f02, 1, 1, 0x1E, 4, 0xE, 1);
            break;
        }
        p->f04 = mode;
    }
    func_02043B5C(func_02045770(p->f10), 0);
    func_02045334(p->f10);
    func_02045374(p->f10);
    func_020409B4(p->f02);
}
