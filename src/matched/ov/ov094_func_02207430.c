/*
 * function: func_02207430
 * address: 0x02207430
 * packet: pkt_ov094_02207430
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0220AAC8 0x0220AAC8 data
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_020216D4 0x020216D4 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_021F8710 0x021F8710 thumb ov094
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct { s16 x, y, z; u8 pri, f7; } Cfg;
typedef struct {
    u32 f40, f44, f48, f4c, f50, f54;
    u32 f58, f5c, f60, f64, f68, f6c, f70, f74, f78, f7c;
    char pad[0x40];
} Entry;
typedef struct {
    u32 f0, f4;
    char pad08[0x10];
    u32 pal[6];
    u32 f30, f34, f38, f3c;
    Entry entries[8];
    char pad440[8];
    u16 heap;
} Work;
extern const Cfg d_0220AAC8;
extern void func_0204ADA4(u32);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_021F86E0(void);
extern u32 func_0204AEF4(u32, int);
struct PalAnmSlot;
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_021F8710(void);
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
void func_02207430(Work *p, int mode, int i)
{
    int chr, pal, cell, cpal, j, n, side;
    Cfg cfg;
    switch (mode) {
    case 0:
    case 1:
    default:
        chr = (i & 1) ? 0xa5 : 0xa8;
        pal = (i & 1) ? 0xa6 : 0xa9;
        cell = (i & 1) ? 0xa7 : 0xaa;
        break;
    case 2:
    case 3:
        chr = (i & 1) ? 0xab : 0xae;
        pal = (i & 1) ? 0xac : 0xaf;
        cell = (i & 1) ? 0xad : 0xb0;
        break;
    case 4:
        break;
    }
    if (mode == 3) {
        j = i;
        if (i >= 2)
            j = i - 2;
        cpal = (i < 4) ? 0xa2 : 0xa3;
        func_0204ADA4(p->pal[j]);
        p->pal[j] = func_0204AC18((void *)p->f4, cpal, 0, (u16)(j << 5), 0, 1, p->heap);
        func_020216D4((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(func_0204AEF4(p->pal[j], 0) >> 1), 0x20);
    }
    p->entries[i].f58 = func_0204A6C8((void *)p->f4, chr, 0, 0, p->heap);
    p->entries[i].f5c = func_0204AF28((void *)p->f4, pal, cell, p->heap);
    p->entries[i].f60 = func_0204A6C8((void *)p->f4, 0xba, 0, 0, p->heap);
    p->entries[i].f64 = func_0204AF28((void *)p->f4, 0xbb, 0xbc, p->heap);
    p->entries[i].f68 = func_0204A6C8((void *)p->f4, 0xb1, 0, 0, p->heap);
    p->entries[i].f6c = func_0204AF28((void *)p->f4, 0xb2, 0xb3, p->heap);
    p->entries[i].f70 = func_0204A6C8((void *)p->f4, 0xb4, 0, 0, p->heap);
    p->entries[i].f74 = func_0204AF28((void *)p->f4, 0xb5, 0xb3, p->heap);
    side = i & 1;
    if (side == 0) {
        p->entries[i].f78 = func_0204A6C8((void *)p->f4, 0xb7, 0, 0, p->heap);
        p->entries[i].f7c = func_0204AF28((void *)p->f4, 0xb8, 0xb9, p->heap);
    }
    cfg = d_0220AAC8;
    j = i;
    if (i >= 2)
        j = i - 2;
    n = (7 - i) * 3;
    cfg.pri = n + 2;
    p->entries[i].f40 = (u32)func_0204B294((void *)p->f0, p->entries[i].f58, p->pal[j], p->entries[i].f5c, &cfg, 0, p->heap);
    cfg.pri = n + 1;
    p->entries[i].f44 = (u32)func_0204B294((void *)p->f0, p->entries[i].f60, p->pal[j], p->entries[i].f64, &cfg, 0, p->heap);
    p->entries[i].f48 = (u32)func_0204B294((void *)p->f0, p->entries[i].f68, p->pal[j], p->entries[i].f6c, &cfg, 0, p->heap);
    if (func_021F8710() == 3 && i >= 4)
        p->entries[i].f54 = (u32)func_0204B294((void *)p->f0, p->f30, p->f3c, p->f34, &cfg, 0, p->heap);
    else
        p->entries[i].f54 = (u32)func_0204B294((void *)p->f0, p->f30, p->f38, p->f34, &cfg, 0, p->heap);
    func_0204B92C((struct Obj *)p->entries[i].f54, 1);
    cfg.pri = n;
    p->entries[i].f4c = (u32)func_0204B294((void *)p->f0, p->entries[i].f70, p->pal[j], p->entries[i].f74, &cfg, 0, p->heap);
    func_0204B3DC((struct Obj *)p->entries[i].f4c, 0);
    if (side == 0 && mode != 2 && mode != 3)
        p->entries[i].f50 = (u32)func_0204B294((void *)p->f0, p->entries[i].f78, p->pal[j], p->entries[i].f7c, &cfg, 0, p->heap);
}
