/*
 * function: func_021C7B20
 * address:  0x021C7B20
 * packet:   pkt_ov111_021C7B20
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * callee:   0x02008A54 (arm9, labelled by seeds_3) is still a near miss; its one call site
 *           here attests through the sole-ref class (docs/notes/pkt_02008A54.c.txt)
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   sub_02008A54  0x02008A54  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   func_021C7AD4  0x021C7AD4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

typedef short s16;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Rec;

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern Rec sub_02008A54(void *obj, int i);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_021C7AD4(Work *p, int x, int k, void *str);
extern void STRBUF_Delete(struct U16Vec *vec);

void func_021C7B20(Work *p, int mode, int idx)
{
    void *str;
    Rec r;
    void *v;
    int i;

    str = STRBUF_Create(0x68, 0x27);
    BMP_Clear(BMP_WIN_GetBmp(p->f8), 0xF);
    switch (mode) {
    case 0:
        r = sub_02008A54(p->f184, idx);
        func_0201EFA4(p->f24, 0, r.a + 0x7D0, 4, 0, 1);
        func_0201EFA4(p->f24, 1, r.b, 2, 0, 1);
        func_0201EFA4(p->f24, 2, r.c, 2, 0, 1);
        MSGDATA_ReadString(p->f20, idx * 3 + 0x58, str);
        func_0201F250(p->f24, p->f28, str);
        v = p->f14;
        PRINTSYS_PrintQueColor(v, (u32)BMP_WIN_GetBmp(p->fC), (int)0, (s16)0, (u32)p->f28, (u32)p->f4, (int)0x44F);
        p->f10 = 1;
        for (i = 1; i < 3; i++) {
            MSGDATA_ReadString(p->f20, i + (idx * 3 + 0x58), str);
            v = p->f14;
            PRINTSYS_PrintQueColor(v, (u32)BMP_WIN_GetBmp(p->fC), (int)0, (s16)(i << 5), (u32)str, (u32)p->f4, (int)0x44F);
            p->f10 = 1;
        }
        break;
    case 1:
        for (i = 0; i < 2; i++) {
            func_021C7AD4(p, i, idx, str);
        }
        if (p->f17C[idx]) {
            func_021C7AD4(p, 2, idx, str);
        }
        break;
    }
    STRBUF_Delete(str);
}
