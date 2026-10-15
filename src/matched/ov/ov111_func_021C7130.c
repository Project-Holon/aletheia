/*
 * function: func_021C7130
 * address:  0x021C7130
 * packet:   pkt_ov111_021C7130
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Create  0x0201EC74  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_021C70EC  0x021C70EC  thumb
 *   func_021C80B4  0x021C80B4  thumb
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   func_021C8208  0x021C8208  thumb
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
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
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
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

extern void *func_020490F4(u32 id, u32 heap);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern void *func_020056A0(void (*cb)(void *, Work *), Work *p, int pri);
extern void func_021C70EC(void *unused, Work *p);
extern void func_021C80B4(Work *p);
extern void *GAME_DATA_GetSaveBlock21(void **h);
extern void func_021C8208(Work *p);

void func_021C7130(Work *p, Parent *parent)
{
    int i;

    p->f108 = parent;
    p->f110 = 0;
    p->f0 = func_020490F4(0x28, 0x27);
    p->f20 = func_02045B38(0, 2, 0xBB, 0x27);
    for (i = 0; i < 7; i++) {
        p->f2C[i] = func_02045EC0(p->f20, i);
        STRBUF_GetChars(p->f2C[i]);
    }
    p->f28 = STRBUF_Create(0x68, 0x27);
    p->f24 = WORDSET_Create(8, 0x40, 0x27);
    p->fF4 = func_020056A0(func_021C70EC, p, 0);
    p->f118 = 8;
    p->f144 = -1;
    func_021C80B4(p);
    p->f184 = GAME_DATA_GetSaveBlock21(p->f108->f4);
    func_021C8208(p);
}
