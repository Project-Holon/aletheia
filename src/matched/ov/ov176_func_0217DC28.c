/*
 * function: func_0217DC28
 * address: 0x0217DC28
 * packet: pkt_ov176_0217DC28
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Note 2026-10-04 (wD2 lane12): byte-correct. Unresolved: func_0200EA00 and func_0200EA08 (witness). Filed src/matched/arm9/func_0200EA00.c and func_0200EA08.c (EXACT) this wave; they need a manifest/shard, then this file re-verifies as EXACT with no C change.
 * blockers: ARM9 0200EA00 and 0200EA08 have no outside witness; Ilias owns filing.
 * blocker: 0x0200EA00 Thumb EXACT (scratch one, fixed flags)
 *   unsigned char *func_0200EA00(unsigned char *p) { return p + 0x5a; }
 * blocker: 0x0200EA08 Thumb EXACT (scratch one, fixed flags)
 *   unsigned char *func_0200EA08(unsigned char *p) { return p; }
 * Lever: explicit unsigned left/right shifts pack the low bytes in 568 bytes;
 * byte casts followed by placement shifts compile to 584 bytes.
 * AE14's empty body leaves its incoming pointer in r0; caller saves it.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B204 0x0200B204 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200E9F4 0x0200E9F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_0200B074 0x0200B074 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0200EA00 0x0200EA00 thumb
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200B078 0x0200B078 thumb
 *   func_021E5D68 0x021E5D68 thumb ov177
 *   func_0200EA08 0x0200EA08 thumb
 *   func_0200E918 0x0200E918 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_021E6118 0x021E6118 thumb ov177
 *   func_0217DFF0 0x0217DFF0 thumb ov176
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef u16 Row[3];
struct Big; struct Reg; struct Rec160; struct RecBig; struct Rec1E; struct Reg2;
typedef struct {
    u8 data[0x92]; u16 pad92;
    u32 color0, color1; u8 *user;
    u16 a0, a2;
    union { u32 total; struct { u16 a4, a6; } h; } v;
    u16 a8, aa;
} Rec;
extern void *func_02012EBC(struct Big *);
extern void *func_0200B358(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *, u32);
extern struct Rec1E *func_0200B204(struct RecBig *, u32);
extern struct Reg *func_0200AE14(struct Reg2 *);
extern void *func_0200E9F4(void *);
extern u8 *func_02012944(void *);
extern int func_021E5548(int *);
extern void func_02082BCC(void *, int, u32);
extern u8 *func_0200B074(struct Reg2 *);
extern void func_02082D44(const void *, void *, u32);
extern Row *func_0200EA00(void *);
extern u16 func_0200DFD8(Row *, int, int);
extern u8 *func_02008554(u8 *);
extern int func_0200B078(struct Reg2 *, u32);
extern void *func_021E5D68(Rec *, int, u8 *, int, int, int, int, int, int, struct Rec1E *, int, int);
extern const u8 *func_0200EA08(void *);
extern u8 func_0200E918(const u8 *, u32);
extern u32 func_0200AE54(struct Reg *, u32);
extern void *func_021E6118(Rec *, u8 *, int, int, int, int, int, int, struct Rec1E *, int, int);
extern int func_0217DFF0(int, int);
void func_0217DC28(int *p)
{
    void *save, *stats;
    struct Rec160 *base;
    struct Reg2 *obj;
    struct Rec1E *sub;
    struct Reg *reg;
    u8 *win;
    int flag;
    if (p[2] == 0) {
        save = func_02012EBC((struct Big *)p[12]);
        base = func_0200B358(func_02012EBC((struct Big *)p[12]));
        obj = (struct Reg2 *)func_0200B1D4(base, p[5]);
        sub = func_0200B204((struct RecBig *)base, p[5]);
        reg = func_0200AE14(obj);
        stats = func_0200E9F4(save);
        win = func_02012944((void *)p[12]);
        flag = func_021E5548((int *)p[11]);
        if (p[5] == 0) {
            Rec rec;
            Row *table;
            int total, a, b, c, d;
            func_02082BCC(&rec, 0, 0xac);
            func_02082D44(func_0200B074(obj), &rec, 0x92);
            table = func_0200EA00(stats);
            rec.a0 = func_0200DFD8(table, 10, 0);
            total = func_0200DFD8(table, 10, 1);
            rec.v.total = total + func_0200DFD8(table, 10, 2);
            rec.user = func_02008554(win);
            a = func_0200B078(obj, 6); b = func_0200B078(obj, 5); c = func_0200B078(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = func_0200B078(obj, 9); b = func_0200B078(obj, 8); d = func_0200B078(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.aa = func_0200B078(obj, 11);
            p[2] = (int)func_021E5D68(&rec, 0, win, flag, p[10], p[7], p[9], p[0], p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        } else {
            Rec rec;
            const u8 *table;
            int a, b, c, d;
            func_02082BCC(&rec, 0, 0xac);
            func_02082D44(func_0200B074(obj), &rec, 0x92);
            table = func_0200EA08(stats);
            rec.a0 = func_0200E918(table, 1); rec.a2 = func_0200E918(table, 2);
            rec.v.h.a4 = func_0200E918(table, 0);
            rec.v.h.a6 = func_0200AE54(reg, 22);
            rec.user = func_02008554(win);
            a = func_0200B078(obj, 6); b = func_0200B078(obj, 5); c = func_0200B078(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = func_0200B078(obj, 9); b = func_0200B078(obj, 8); d = func_0200B078(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.a8 = func_0200B078(obj, 11);
            p[2] = (int)func_021E6118(&rec, win, flag, p[10], p[7], p[9], p[0], p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        }
        func_0217DFF0((int)p, 0);
    }
}
