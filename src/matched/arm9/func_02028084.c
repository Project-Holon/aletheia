/*
 * unit:     no
 * function: func_02028084
 * address:  0x02028084
 * packet:   pkt_02028084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   sub_020450F0   0x020450F0  arm
 *   func_020282D8  0x020282D8  thumb
 *   sub_0201D304   0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   sub_0201C724   0x0201C724  thumb
 *   g_020A74E0     0x020A74E0  data
 *
 * Nine-argument constructor: allocate a 0x20-byte menu object on heap a8
 * (the __FILE__ pool word 0x020A74E0 is app_taskmenu.c, line 0x337), zero
 * it, then build the BG layer and the text window.  func_0202800C, the only
 * in-image caller, forwards all nine arguments unchanged, which is where the
 * u8/u8/u32/u32/u16 spelling of the five stack arguments comes from.
 *
 * a2 and a3 are u16, not u32.  The earlier DIFF note (45 bytes out, all
 * spill-ordering) held them u32; the permuter's type mutation found that
 * narrowing BOTH closes the residue, and the reading is sound rather than
 * lucky: the original spills them with a full-word `str` and reloads with a
 * full-word `ldr` and never truncates, so writing the narrowing explicitly
 * (`(u16)a2` at the use site, or a u16 local assigned from a u32 parameter)
 * inserts an lsls/lsrs pair the original does not have and takes the diff
 * from 45 bytes to 171.  The only spelling with no truncation anywhere is a
 * parameter that is already 16 bits at entry.  No in-image caller passes a
 * value wider than 16 bits: the single caller func_0202800C forwards its own
 * arguments unchanged, and its caller func_02027FEC does the same; both are
 * BG coordinate arguments handed straight to sub_020450F0.
 *
 * `cellSrc` (src->f08 lifted into a local before the func_020282D8 call) is
 * the last 6 bytes: it pins the load ahead of the argument setup.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Cfg {
    u16 f00;
    u16 f02;
    u8  pad04[0x10 - 0x04];
    u32 f10;
    u32 f14;
};

struct Src {
    u32 f00;
    u16 f04;
    u8  pad06[8 - 6];
    u32 f08;
};

struct Obj {
    u32 f00;
    u8  pad04[0x0c - 0x04];
    u32 f0c;
    u8  pad10[0x12 - 0x10];
    u16 f12;
    u8  pad14[0x18 - 0x14];
    struct Cfg *f18;
    u16 f1c;
    u16 f1e;
};

extern char  g_020A74E0[];
struct Descriptor;
struct StrObj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *p, u8 v, u32 n);
extern u32   sub_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void  func_020282D8(u32 bg, struct Cfg *c, u32 d);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void  sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

struct Obj *func_02028084(struct Cfg *cfg, struct Src *src, u16 a2, u16 a3,
                          u8 a4, u8 a5, u32 a6, u32 a7, u16 heap)
{
    struct Obj *o;
    u32 bg;
    s16 w;
    u32 cellSrc;

    w = 2;
    o = (struct Obj *)func_02030734(heap, 0x20, 0, g_020A74E0, 0x337);
    MI_CpuFill8(o, 0, 0x20);
    o->f18 = cfg;
    o->f0c = 1;
    o->f12 = (u16)(a6 + 1);
    bg = sub_020450F0((u8)cfg->f00, a2, a3, a4, a5, (u8)(cfg->f02 + 1), 1);
    cellSrc = src->f08;
    o->f00 = bg;
    func_020282D8(bg, cfg, cellSrc);
    if (a7 == 1) {
        w = (u8)(((a4 << 3) - sub_0201D304((void *)src->f00, cfg->f10, 0)
                  - 0x10) >> 1);
    }
    sub_0201C724((void *)cfg->f14, (u32)func_02045770((void *)o->f00),
                 (s16)(w + 8), 6, src->f00, cfg->f10, src->f04);
    o->f1c = 0x3545;
    o->f1e = 0x7B2C;
    return o;
}
