/*
 * file:     digitalcardcheck_p04.c
 * unit:     yes
 * function: func_0217D4FC, func_0217D730, func_0217D964, func_0217DA38, func_0217DB0C, func_0217DBE0, func_0217DC20, func_0217DC28, func_0217DE60
 * address:  0x0217D4FC
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217DEA4 0x0217DEA4 thumb ov176
 *   func_020362DC 0x020362DC arm
 *   func_0217E000 0x0217E000 thumb ov176
 *   func_0217DFF0 0x0217DFF0 thumb ov176
 *   func_0217DFD0 0x0217DFD0 thumb ov176
 *   func_0217DFE4 0x0217DFE4 thumb ov176
 *   func_0217DEDC 0x0217DEDC thumb ov176
 *   func_0217DFBC 0x0217DFBC thumb ov176
 *   func_0217DFA8 0x0217DFA8 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021E8AA8 0x021E8AA8 thumb ov177
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
 *   func_021E64C8 0x021E64C8 thumb ov177
 *   func_021E65FC 0x021E65FC thumb ov177
 *   func_021E5EF8 0x021E5EF8 thumb ov177
 *   func_021E62A0 0x021E62A0 thumb ov177
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 */
struct Big;
struct Rec160;
struct Reg2;
struct Obj;
struct Reg;
struct RecBig;
struct Rec1E;
struct Sub0200852CObj;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef u16 Row[3];

typedef struct {
    u8 data[0x92]; u16 pad92;
    u32 color0, color1; u8 *user;
    u16 a0, a2;
    union { u32 total; struct { u16 a4, a6; } h; } v;
    u16 a8, aa;
} Rec;

extern void func_0217DEA4(int *, int);
extern u32 func_020362DC(void);
extern void func_0217E000(int *);
extern int func_0217DFF0(int, int);
extern void func_0217DFD0(int *, int, int);
extern int func_0217DFE4(int *);
extern void func_0217DEDC(char *, int);
extern int func_0217DFBC(int *);
extern void func_0217DFA8(int *);
extern void func_021E8AA0(int *, int);
extern void func_021E8AB4(u32, u32);
extern void func_021E8AB8(u32);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_0200BAC8(void *);
extern void func_0200BBD8(struct Obj *p, int v);
extern void func_0200B110(struct Reg2 *p, u32 id, s32 value);
extern int func_02012DAC(int a0);
extern int func_02012DD0(u8 *p);
extern void func_021E8AA8(int);
extern struct Rec1E *func_0200B204(struct RecBig *, u32);
extern struct Reg *func_0200AE14(struct Reg2 *);
extern void *func_0200E9F4(void *);
extern u8 *func_02012944(void *);
extern int func_021E5548(int *);
extern void func_02082BCC(void *, int, u32);
extern u8 *func_0200B074(struct Reg2 *);
extern void func_02082D44(const void *, void *, u32);
extern int func_0200EA00(int p);
extern u16 func_0200DFD8(Row *, int, int);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int func_0200B078(struct Reg2 *, u32);
extern char *func_021E5D68(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
extern int func_0200EA08(int p);
extern u8 func_0200E918(const u8 *, u32);
extern u32 func_0200AE54(struct Reg *, u32);
extern char *func_021E6118(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);
extern void func_021E5EF8(void *p);
extern void func_021E62A0(void *p);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 index);
extern int func_021E64C8(int);
extern int func_021E65FC(int);
void func_0217D4FC(int *a, int *state, int *p);
void func_0217D730(int *a, int *state, int *p);
void func_0217D964(int *a, int *state, int *p);
void func_0217DA38(int sys, int *state, int *p);
void func_0217DB0C(int sys, int *state, int *p);
void func_0217DBE0(int a, int *state, int *p);
void func_0217DC20(int a);
void func_0217DC28(int *p);
void func_0217DE60(int *p);
int func_0217DE8C(int *p);
int func_0217DE98(int *p);

void func_0217D4FC(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4(p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x67, 1);
        *state = 19; func_021E8AB4((u32)a, 4); break;
    case 4: func_0217DEDC((char *)p, 2); *state = 5; break;
    case 5:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: func_0217DFD0(p, 0x71, 1); *state = 19; func_021E8AB4((u32)a, 7); break;
    case 7: func_0217DEDC((char *)p, 0); *state = 8; break;
    case 8:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: func_0217DFD0(p, 0x72, 1); *state = 19; func_021E8AB4((u32)a, 10); break;
    case 10: func_0217DEDC((char *)p, 0); *state = 11; break;
    case 11:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: func_0217DFD0(p, 0x6B, 2); *state = 19; func_021E8AB4((u32)a, 13); break;
    case 13:
        base = func_02012EBC((void *)p[12]);
        record = func_0200B1D4(func_0200B358(base), p[5]);
        base = func_0200BAC8(base);
        func_0200BBD8(base, p[5] == 0 ? 1 : 2);
        func_0200B110(record, 10, 4); *state = 14; break;
    case 14: func_02012DAC((int)((void *)p[12])); *state = 15; break;
    case 15:
        result = func_02012DD0((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: func_0217DFD0(p, 0x73, 1); *state = 19; func_021E8AB4((u32)a, 17); break;
    case 17: if (func_0217DE98(p)) *state = 18; break;
    case 18: func_021E8AA0(a, (int)func_0217DC20); break;
    case 19: if (func_0217DFE4(p)) func_021E8AB8((u32)a); break;
    }
}

void func_0217D730(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4(p, 0); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x68, 1);
        *state = 19; func_021E8AB4((u32)a, 4); break;
    case 4: func_0217DEDC((char *)p, 2); *state = 5; break;
    case 5:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: func_0217DFD0(p, 0x69, 1); *state = 19; func_021E8AB4((u32)a, 7); break;
    case 7: func_0217DEDC((char *)p, 0); *state = 8; break;
    case 8:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: func_0217DFD0(p, 0x72, 1); *state = 19; func_021E8AB4((u32)a, 10); break;
    case 10: func_0217DEDC((char *)p, 0); *state = 11; break;
    case 11:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: func_0217DFD0(p, 0x6B, 2); *state = 19; func_021E8AB4((u32)a, 13); break;
    case 13:
        base = func_02012EBC((void *)p[12]);
        record = func_0200B1D4(func_0200B358(base), p[5]);
        base = func_0200BAC8(base);
        func_0200BBD8(base, p[5] == 0 ? 1 : 2);
        func_0200B110(record, 10, 4); *state = 14; break;
    case 14: func_02012DAC((int)((void *)p[12])); *state = 15; break;
    case 15:
        result = func_02012DD0((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: func_0217DFD0(p, 0x6C, 1); *state = 19; func_021E8AB4((u32)a, 17); break;
    case 17: if (func_0217DE98(p)) *state = 18; break;
    case 18: func_021E8AA0(a, (int)func_0217DC20); break;
    case 19: if (func_0217DFE4(p)) func_021E8AB8((u32)a); break;
    }
}

void func_0217D964(int *a, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4((int *)p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3: func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x6D, 1); *state = 4; break;
    case 4: if (func_0217DFE4(p)) *state = 5; break;
    case 5: func_0217DEDC((char *)p, 1); *state = 6; break;
    case 6:
        result = func_0217DFBC(p);
        if (result != -1) {
            func_0217DFA8(p);
            if (result == 0) *state = 7;
        }
        break;
    case 7: if (func_0217DE98(p)) *state = 8; break;
    case 8: func_021E8AA0(a, (int)func_0217DC20); break;
    }
}

/*
 * DFF0 receives the context in r0 even though its forwarding body ignores it.
 */
void func_0217DA38(int sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4((int *)p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x6e, 1);
        *state = 4; break;
    case 4: if (func_0217DFE4(p)) *state = 5; break;
    case 5: func_0217DEDC((char *)p, 1); *state = 6; break;
    case 6:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 7; }
        break;
    case 7: if (func_0217DE98(p)) *state = 8; break;
    case 8: func_021E8AA0((int *)sys, (int)func_0217DC20); break;
    }
}

void func_0217DB0C(int sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4((int *)p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x70, 1);
        *state = 4; break;
    case 4: if (func_0217DFE4(p)) *state = 5; break;
    case 5: func_0217DEDC((char *)p, 1); *state = 6; break;
    case 6:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 7; }
        break;
    case 7: if (func_0217DE98(p)) *state = 8; break;
    case 8: func_021E8AA0((int *)sys, (int)func_0217DC20); break;
    }
}

void func_0217DBE0(int a, int *state, int *p)
{
    switch (*state) {
    case 0:
        func_0217DFD0(p, 0x6F, 1);
        *state = 1;
        break;
    case 1:
        if (func_0217DFE4(p))
            *state = 2;
        break;
    case 2:
        func_021E8AA0((int *)a, (int)func_0217DC20);
        break;
    }
}

void func_0217DC20(int a) { func_021E8AA8(a); }

/*
 * Note 2026-10-04 (wD2 lane12): byte-correct. Unresolved: func_0200EA00 and func_0200EA08 (witness). Filed src/matched/arm9/func_0200EA00.c and func_0200EA08.c (EXACT) this wave; they need a manifest/shard, then this file re-verifies as EXACT with no C change.
 * blockers: ARM9 0200EA00 and 0200EA08 have no outside witness; Ilias owns filing.
 *   unsigned char *func_0200EA00(unsigned char *p) { return p + 0x5a; }
 *   unsigned char *func_0200EA08(unsigned char *p) { return p; }
 * Lever: explicit unsigned left/right shifts pack the low bytes in 568 bytes;
 * byte casts followed by placement shifts compile to 584 bytes.
 * AE14's empty body leaves its incoming pointer in r0; caller saves it.
 */
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
            table = (u16 (*)[3])func_0200EA00((int)stats);
            rec.a0 = func_0200DFD8(table, 10, 0);
            total = func_0200DFD8(table, 10, 1);
            rec.v.total = total + func_0200DFD8(table, 10, 2);
            rec.user = (u8 *)func_02008554((const struct Sub0200852CObj *)win);
            a = func_0200B078(obj, 6); b = func_0200B078(obj, 5); c = func_0200B078(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = func_0200B078(obj, 9); b = func_0200B078(obj, 8); d = func_0200B078(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.aa = func_0200B078(obj, 11);
            p[2] = (int)func_021E5D68((char *)(&rec), 0, win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        } else {
            Rec rec;
            const u8 *table;
            int a, b, c, d;
            func_02082BCC(&rec, 0, 0xac);
            func_02082D44(func_0200B074(obj), &rec, 0x92);
            table = (const u8 *)func_0200EA08((int)stats);
            rec.a0 = func_0200E918(table, 1); rec.a2 = func_0200E918(table, 2);
            rec.v.h.a4 = func_0200E918(table, 0);
            rec.v.h.a6 = func_0200AE54(reg, 22);
            rec.user = (u8 *)func_02008554((const struct Sub0200852CObj *)win);
            a = func_0200B078(obj, 6); b = func_0200B078(obj, 5); c = func_0200B078(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = func_0200B078(obj, 9); b = func_0200B078(obj, 8); d = func_0200B078(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.a8 = func_0200B078(obj, 11);
            p[2] = (int)func_021E6118((char *)(&rec), win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        }
        func_0217DFF0((int)p, 0);
    }
}

void func_0217DE60(int *p)
{
    if (p[2]) {
        if (p[5] == 0)
            func_021E5EF8((void *)p[2]);
        else
            func_021E62A0((void *)p[2]);
        p[2] = 0;
    }
    func_020414EC(1);
    func_020409B4(1);
}

int func_0217DE8C(int *p) { return func_021E64C8(p[2]); }

int func_0217DE98(int *p) { return func_021E65FC(p[2]); }
