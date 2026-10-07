/*
 * file:     musical_dressup_sys_p05.c
 * unit:     yes
 * function: func_02155FB4, func_02155FC8
 * address:  0x02155FB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FD948  0x021FD948  thumb  ov132
 *   func_02156F68  0x02156F68  thumb  ov010
 *   func_02156FC4  0x02156FC4  thumb  ov010
 *   func_021572E4  0x021572E4  thumb  ov010
 *   func_021FD4F8  0x021FD4F8  thumb  ov132
 *   func_02157000  0x02157000  thumb  ov010
 *   func_02157174  0x02157174  thumb  ov010
 */
struct Deal;
struct Party;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Work_02155FB4 {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[0x38 - 0x2C];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
} Work_02155FB4;

typedef unsigned long long u64;

typedef struct Stage {
    u8 pad00[0x14];
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
} Stage;

typedef struct Work_02155FC8 {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[4];
    Stage *f30;         /* 0x30 */
    u8 pad34[4];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
    u8 pad40[4];
    u8 f44[4];          /* 0x44 */
} Work_02155FC8;

extern void func_021FD948(char *p, u32 value);
extern Stage *func_02156F68(u32 heap, void *p);
extern int func_02156FC4(int a0, int a1, int a2);
extern void func_021572E4(struct Deal *d, void *a, u8 b, u8 slot, u16 y);
extern u32 func_021FD4F8(struct Ctx *p, u8 key);
extern int func_02157000(int a0, int a1, int a2);
extern void func_02157174(u32 heap, struct Deal *d, struct Party *party);
void func_02155FB4(Work_02155FB4 *w);
void func_02155FC8(Work_02155FC8 *w);


/*
 * 2026-10-05 (D9 lane 02): callee 0x021FD948 is the ov132 setter, already matched in ov132_func_021FD938.c. Region hint ov132 added.
 */
void func_02155FB4(Work_02155FB4 *w)
{
    if (w->f14 == 1)
        func_021FD948(w->f28, (u32)w->f3C);
}


/*
 * Byte-correct (first draft). Blocker: 0x021FD4F8 has no func_ label in any
 * overlay listing (ov094/ov132/ov135/ov186 overlap it).
 *
 * 2026-10-05 (D9 lane 02): callee 0x021FD4F8 is a real function in ov132 (not ov186/ov094/ov135, where the address is mid-function). Filed it as the EXACT
 *   witness src/matched/ov/ov132_func_021FD4F8.c (50 bytes, finds the entry with a given id byte); symbols line now names ov132. Bytes unchanged. Stays MATCH only until that file gets its shard.
 */
void func_02155FC8(Work_02155FC8 *w)
{
    u8 i;
    u8 j;
    u32 r;

    w->f30 = func_02156F68(4, w->f28);
    if (w->f14 == 0) {
        for (i = 0; i < 4; i++) {
            if (i == 0)
                func_02156FC4((int)w->f30, w->f44[i], (int)w->f3C);
            else
                func_021572E4(w->f38, w->f30, w->f44[i], i - 1, 4);
        }
    } else {
        j = 0;
        for (i = 0; i < 4; i++) {
            r = func_021FD4F8(w->f28, w->f44[i]);
            if (r != 0) {
                func_02157000((int)w->f30, w->f44[i], r);
            } else {
                func_021572E4(w->f38, w->f30, w->f44[i], j, 4);
                j++;
            }
        }
    }
    w->f30->f18 = w->f24;
    w->f30->f14 = w->f38;
    func_02157174(4, w->f38, (struct Party *)w->f30);
}
