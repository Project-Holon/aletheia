/*
 * file:     wifibattlematch_view_p22.c
 * unit:     yes
 * function: func_021E8754, func_021E8844
 * address:  0x021E8754
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02028604  0x02028604  thumb
 *   func_021E8848  0x021E8848  thumb  ov177
 *   func_020056BC  0x020056BC  thumb
 *   func_0202EE30  0x0202EE30  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02034714  0x02034714  arm
 *   func_02028470  0x02028470  thumb
 *   func_02028590  0x02028590  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   d_021E8DEC     0x021E8DEC  data
 */
struct CharBuf;
struct Descriptor;
struct PrintSys;
struct Rec3;
typedef struct {
    int            f0;
    int            f4;
    int            f8;
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad0[3];
    int            f28;
    int            f2c;
    int            f30;
    int            f34;
    char           f38[1];
} S;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02028604(int a0);
extern void func_021E8848(S *);
extern u32 func_020056BC(void);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02028470(u8 *p, u32 v);
extern int  func_02028590(int, int, int, int);
extern signed char func_02012FFC(void);
extern int  func_0201CCE4(int, int, int, int, int, int, int, int, int, int);
void func_021E8754(S *p, int mode);
int func_021E8844(const int *p);
extern unsigned char d_021E8DEC[];


/*
 * note 2026-10-02: all code matches except the case 2 arm: original ends it with an
 *   explicit `b` onto the immediately following case 0 block (+2 bytes, 238 vs 240).
 *   Fallthrough case 2 -> case 0 emits no such branch. Tried default arm, goto, guarded if.
 *
 * note 2026-10-05: orig layout is dispatch (cmp 0 beq A; cmp 1 beq B; cmp 2 bne end), case 2 block,
 * `b .+2` (0xE7FF), case 0 block A, case 1 block B, join store. Tried: if/else chain with `goto L0` into A (240 B
 * but A laid out first, wrong order); switch with case 2 first and `goto L0` before `case 0: L0:` (the
 * goto to the next label is deleted, 236 B); case 0 body under `if (mode == 0 || mode == 2)` (244 B).
 * None emits the branch to the next instruction. Still DIFF (residue is the 2-byte branch plus shifted offsets).
 *
 * note 2026-10-05 (wD9 lane20): EXACT. Case 2 repeats the whole case 0 body and its own break; cross-jumping
 *   then replaces that copy with a branch to the case 0 block, which is laid out next (the `b .+2`).
 */
void func_021E8754(S *p, int mode)
{
    int q;

    func_0201C6EC((struct PrintSys *)p->f28);
    func_02043B5C(func_02045770((struct Descriptor *)p->f14), (unsigned char)p->f1c);
    if (p->f8 != 0) {
        func_0201CE48((struct Rec3 *)p->f8);
        p->f8 = 0;
    }
    if (p->f34 != 0) {
        func_02028604(p->f34);
        p->f34 = 0;
    }
    func_021E8848(p);
    switch (mode) {
    case 2:
        p->f10 = (int)func_0202EE30((void *)func_020056BC(), (void *)p->f14, (unsigned char)p->f1c, 0x10, p->f1e);
        q = p->f28;
        func_0201C6FC((struct PrintSys *)q, (u32)func_02045770((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 0:
        q = p->f28;
        func_0201C6FC((struct PrintSys *)q, (u32)func_02045770((struct Descriptor *)p->f20), 0, 0, (void *)p->f18, p->f4);
        p->f24 = 1;
        p->f2c = 0;
        break;
    case 1:
        if (p->f34 != 0) {
            func_02034714((const char *)d_021E8DEC, 0, (const char *)d_021E8DEC);
        }
        func_02028470((u8 *)p->f38, 2);
        p->f34 = func_02028590(p->f1c, 1, 0, p->f1e);
        p->f8 = func_0201CCE4(p->f14, 0, 0, p->f18, p->f4, func_02012FFC(), p->fc, 0, p->f1e, p->f1c);
        p->f2c = 1;
        break;
    }
    p->f30 = 0;
}

int func_021E8844(const int *p)
{
    return p[0x30 / 4];
}
