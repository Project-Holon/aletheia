/*
 * function: func_021CEF1C
 * address:  0x021CEF1C
 * packet:   pkt_ov021_021CEF1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045A98  0x02045A98  arm
 *   func_02190A6C  0x02190A6C  thumb  ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02008534  0x02008534  thumb
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_02045808  0x02045808  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad0[0x26];
    u8 on;
    u8 pad27[5];
} Ent;

typedef struct {
    u32 f0, f4, f8;
    u8 padc[0x13c - 0xc];
    u32 f13c;
    u32 f140;
    Ent ents[16];
    u8 pad404[0x40e - 0x404];
    u8 f40e;
    u8 pad40f[0x528 - 0x40f];
    u16 f528;
} S;

extern u16 func_02045A98(void);
extern void func_02190A6C(u32 a);
struct MsgBank;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190A64(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);

void func_021CEF1C(S *p)
{
    u16 ch;
    u32 c, a, b, d;
    int i;

    ch = func_02045A98();
    if (p->f40e == 1) {
        func_02190A6C(p->f13c);
    }
    a = (u32)func_020457B0(0x40, p->f528);
    b = (u32)func_020457B0(0x40, p->f528);
    c = (u32)func_020457B0(0x40, p->f528);
    d = (u32)func_020457B0(4, p->f528);
    func_02045CAC((struct MsgBank *)p->f8, 0x1a, (void *)a);
    func_02045CAC((struct MsgBank *)p->f8, 0x1b, (void *)b);
    for (i = 0; i < 16; i++) {
        func_0201EFA4((struct WordSet *)p->f4, 0, i + 1, 2, 2, 1);
        if (p->ents[i].on == 1) {
            func_0201F02C((struct WordSet *)p->f4, 1, &p->ents[i]);
            func_0201EFA4((struct WordSet *)p->f4, 2, func_02008534((const struct Sub0200852CObj *)(&p->ents[i])), 5, 2, 1);
            func_0201F250((struct WordSet *)p->f4, (void *)c, (void *)b);
        } else {
            func_02045924((struct Strbuf *)d, &ch);
            func_0201EE0C((struct WordSet *)p->f4, 1, (const void *)d, 0, 1, 2);
            func_0201EE0C((struct WordSet *)p->f4, 2, (const void *)d, 0, 1, 2);
            func_0201F250((struct WordSet *)p->f4, (void *)c, (void *)a);
        }
        func_02190A64(p->f13c, c, i, p->f528);
    }
    func_02045808((struct U16Vec *)b);
    func_02045808((struct U16Vec *)a);
    func_02045808((struct U16Vec *)c);
    func_02045808((struct U16Vec *)d);
    p->f40e = 1;
}
