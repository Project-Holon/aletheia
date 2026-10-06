/*
 * file:     wipe_sub_p19.c
 * unit:     yes
 * function: func_020247F0, func_02024810, func_02024838, func_02024888, func_020248D8, func_02024910, func_02024918, func_02024934, func_02024938, func_02024988, func_02024994, func_020249A0, func_020249B0, func_02024A20, func_02024ABC
 * address:  0x020247F0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   Table_0209F7AC   0x0209F7AC  data
 *   func_0204581C    0x0204581C  arm
 *   func_02045B38    0x02045B38  arm
 *   func_02045C04    0x02045C04  arm
 *   func_02045CAC    0x02045CAC  arm
 *   g_tbl0   0x0209F7AC  data
 *   g_tbl1   0x0209F792  data
 *   g_0209F792  0x0209F792  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   tbl_0209F784   0x0209F784  data  a1
 *   data_0209F7C8  0x0209F7C8  data
 *   func_02030734       0x02030734  arm
 *   MI_CpuFill8         0x02082BCC  arm
 *   func_020251FC       0x020251FC  thumb
 *   func_020056A0       0x020056A0  thumb
 *   func_0203568C       0x0203568C  arm
 *   func_0201283C       0x0201283C  thumb
 *   func_02012BB0       0x02012BB0  thumb
 *   func_02024DFC       0x02024DFC  thumb
 *   gInfoWin            0x0214693C  data
 *   infowin_File        0x020A7478  data
 *   func_020252A8       0x020252A8  thumb
 *   func_0203CD98       0x0203CD98  arm
 *   func_0203D798       0x0203D798  arm
 *   func_0203D1B4       0x0203D1B4  arm
 *   func_0203D29C       0x0203D29C  arm
 *   func_0201058C       0x0201058C  thumb
 *   func_02026CA0       0x02026CA0  thumb
 */
struct Rec;
struct MsgBank;
struct U16Vec;
struct Sub020071CCCtrl;
struct BigObj;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int    s32;

struct Item {
    u8 bytes[8];
};

struct Obj02024838 {
    u8          pad[8];
    struct Item items[20];
};

struct PmsWordEntry {
    u32 f00;
    u16 word[2];
};

struct PmsWord {
    u32 flags;
    u32 f04;
    struct PmsWordEntry e[20];
};

typedef struct Group {
    const u16 *list;
    int count;
} Group;

struct InfoWin {
    u32 f00;
    u16 f04;
    u8  f06;
    u8  f07;
    u8  f08;
    u8  f09;
    u8  pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u8  f1C;
    u8  f1D;
    u8  f1E;
    u8  f1F;
    u32 f20;
    void *f24;
};

struct Link {
    u8 pad00[0x65];
    u8 f65;
    u8 f66;
    u8 f67;
};

extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0204581C(struct U16Vec *vec);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MI_CpuCopy8(void *dest, const void *src, u32 size);
u32 func_02024934(void);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, unsigned int id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dest, u8 data, u32 size);
extern void  func_020251FC(u32 a, u32 b, u32 heap);
extern void *func_020056A0(void (*cb)(void *), void *work, u32 pri);
extern int func_0203568C(void);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02012BB0(const struct BigObj *p);
extern void func_02024DFC(void);
extern void  func_020252A8(void);
extern int   func_0203CD98(void);
extern void *func_0203D798(void);
extern int   func_0203D1B4(void);
extern u32 func_0203D29C(void);
extern u32 func_0201058C(void *key);
extern int   func_02026CA0(int *p);
void func_020247F0(char *p);
void func_02024810(char *p, int a1, int a2);
void func_02024838(u32 id, void *dest, u32 heap);
u16 func_02024888(u32 idx, u16 add);
int func_020248D8(u32 v, u32 *a1, u32 *a2);
void *func_02024910(char *p, int idx);
void *func_02024988(int a0);
int func_02024994(const u32 *p, u32 idx);
void func_020249A0(int *p, int bit);
int func_020249B0(u32 a, u16 b);
void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap);
void func_02024ABC(void);
extern u16 Table_0209F7AC[];
extern u16 g_tbl0[];
extern u16 g_tbl1[];
extern u16 g_0209F792[];
extern const u8 tbl_0209F784[][2];
extern const Group data_0209F7C8[13];
extern struct InfoWin *gInfoWin;
extern const char infowin_File[];



void func_020247F0(char *p)
{
    int i;
    for (i = 0; i < 0xd; i++)
        func_02045C04((struct Rec *)(*(int *)(p + 4 + i * 4)));
    func_020307B0(p);
}



void func_02024810(char *p, int a1, int a2)
{
    int x, y;
    func_020248D8(a1, (unsigned int *)(&x), (unsigned int *)(&y));
    func_02045CAC((struct MsgBank *)(*(int *)(p + 4 + x * 4)), y, (void *)a2);
}




/*
 * Loads one archived message/graphics entry into the caller's buffer.
 * The flat id is split by func_020248D8 into a bank index and an
 * entry index; the bank index selects an archive id out of the
 * halfword table at 0x0209F7AC, that archive is opened, the entry is
 * read into dest and the archive closed again.  The sentinel id
 * 0xffff means "nothing to load" and only clears dest.
 */
void func_02024838(u32 id, void *dest, u32 heap)
{
    u32 bank;
    u32 entry;

    if (id != 0xffff) {
        void *arc;

        func_020248D8(id, &bank, &entry);
        bank = Table_0209F7AC[bank];
        arc = func_02045B38(0, 2, bank, heap);
        func_02045CAC(arc, entry, dest);
        func_02045C04(arc);
    } else {
        func_0204581C(dest);
    }
}




u16 func_02024888(u32 idx, u16 add)
{
    u32 i;
    u16 sum;
    u16 k;

    for (i = 0; i < 0xD; i++) {
        if (idx == g_tbl0[i]) {
            k = 0;
            sum = 0;
            for (; k < i; k++) {
                sum = (u16)(sum + g_tbl1[k]);
            }
            return (u16)(sum + add);
        }
    }
    return 0xFFFF;
}





int func_020248D8(u32 v, u32 *a1, u32 *a2)
{
    u32 i;
    u32 sum;

    v &= 0x7ff;
    sum = 0;
    for (i = 0; i < 0xd; i++) {
        u16 n = g_0209F792[i];

        sum += n;
        if (v < sum) {
            *a1 = i;
            *a2 = v - (sum - n);
            return 1;
        }
    }
    return 0;
}



/*
 * Unlabelled Thumb leaf: address of the 8-byte entry idx of the table at p + 8.
 */
void *func_02024910(char *p, int idx)
{
    return p + 8 + idx * 8;
}




void func_02024918(const struct Obj02024838 *p, s32 idx, void *dest)
{
    if (idx < 0 || idx >= 20) {
        return;
    }

    MI_CpuCopy8(dest, &p->items[idx], 8);
}


/*
 * Save-table size callback: returns 0xA8, the size of the block whose
 * init is func_02024938.  Pointer word 0x02024935 at 0x0209DC00.
 */
u32 func_02024934(void)
{
    return 0xA8;
}


/*
 * pms_word.c: clear the flag words, seed all forty word slots to 0xFFFF,
 * then set the flag bit named by the first row of the 7 x 2 byte table at
 * 0x0209F784 whose kind is 2.  The table is a 2D array: `tbl[k][1]` is what
 * gives the image's second pool word 0x0209F785 (symbol + 1, indexed by
 * the same 2k), where a struct {kind, val} folds the +1 into the load
 * (docs/notes/pkt_02024938.c.txt).  k is unsigned (`blo`); the first two
 * loops count in int.
 */
void func_02024938(struct PmsWord *p)
{
    int i, j;
    u32 k;

    p->flags = 0;
    p->f04 = 0;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 2; j++)
            p->e[i].word[j] = 0xffff;
    }
    for (k = 0; k < 7; k++) {
        if (tbl_0209F784[k][0] == 2) {
            func_020249A0((int *)p, tbl_0209F784[k][1]);
            return;
        }
    }
}


void *func_02024988(int a0)
{
    return func_020071CC((struct Sub020071CCCtrl *)a0, 0x27);
}


/*
 * Tiny Thumb leaf that blocks an ov110 caller; filed by wave D2 lane 06.
 */
int func_02024994(const u32 *p, u32 idx){return (*p >> idx) & 1;}


void func_020249A0(int *p, int bit)
{
    *p |= 1 << bit;
}



/*
 * Unlabelled arm9 leaf: true when a == b, or when the first of 13 halfword
 * groups that contains a also contains b. Filed as the relocation witness for
 * ov021 func_021D213C (wave A1).
 */
int func_020249B0(u32 a, u16 b)
{
    u32 i;
    int j, k;

    if (a == b) {
        return 1;
    }
    for (i = 0; i < 13; i++) {
        for (j = 0; j < data_0209F7C8[i].count; j++) {
            if (a == data_0209F7C8[i].list[j]) {
                for (k = 0; k < data_0209F7C8[i].count; k++) {
                    if (b == data_0209F7C8[i].list[k]) {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}



/*
 * note:     infowin constructor.  The heap id is u16: as u32 mwcc reuses r3
 *           for the allocator call instead of reloading the spilled home
 *           (17 bytes).  Found by tools/permuter.py --types.
 */
void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap)
{
    gInfoWin = func_02030734(heap, 0x28, 0, infowin_File, 0x103);
    MI_CpuFill8(gInfoWin, 0, 0x28);
    gInfoWin->f06 = a0;
    gInfoWin->f07 = a1;
    func_020251FC(a0, a1, heap);
    gInfoWin->f24 = func_020056A0((void (*)(void *))func_02024DFC, gInfoWin, 1);
    gInfoWin->f20 = 0;
    gInfoWin->f1F = func_0203568C();
    if (a2 != 0) {
        gInfoWin->f0C = func_0201283C(a2);
        gInfoWin->f10 = func_02012BB0(a2);
    } else {
        gInfoWin->f0C = 0;
        gInfoWin->f10 = 0;
    }
    gInfoWin->f08 = 0;
    func_02024ABC();
    gInfoWin->f04 = 0x3f;
}



/*
 * note:     infowin per-frame state poll (the TCB-less update): clock tick,
 *           link/wireless state, then the dirty bits of +0x04.  Two shape
 *           facts carry the whole match: every flag update is spelled out
 *           (`f = (u16)(f | X)`, which reuses the tested load; `|=` re-reads
 *           it), and every clear mask is the u16 constant (the pool holds
 *           0x0000EFFF, not ~0x1000).
 */
void func_02024ABC(void)
{
    int flag = 0;
    u8 n = 0;
    struct Link *link = 0;
    u32 bits;
    int idx;

    if (gInfoWin == 0)
        return;

    func_020252A8();
    gInfoWin->f1E++;
    if (gInfoWin->f1E > 60) {
        u8 v = func_0203568C();
        if (gInfoWin->f1F != v) {
            gInfoWin->f1F = v;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x20);
        }
        gInfoWin->f1E = 0;
    }

    if (func_0203CD98() == 1) {
        link = func_0203D798();
        n = func_0203D1B4();
        if (func_0203D29C() == 1)
            flag = 1;
    }

    if (n < 2 && flag == 0) {
        bits = func_0201058C((void *)gInfoWin->f0C);
        idx = 0;
        if (gInfoWin->f10 == 1 && func_02026CA0(&idx) != 0x1E) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x1000);
        } else {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xEFFF);
        }
        if (!(bits & 2)) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
            }
        }
        if (bits & 0x3C) {
            if (bits & 0xC) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f08 = 0;
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f08 = 0;
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
        }
        if (bits & 0x3C0) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    } else if (link != 0) {
        if (link->f65 == 3) {
            if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x200);
            }
        } else if (((gInfoWin->f04 & 0x200) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 4);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFDFF);
        }
        if (link->f65 == 0 || link->f65 == 4 || link->f65 == 5) {
            if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
                gInfoWin->f08 = 0;
            }
            if (link->f67 == 2) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x400);
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x800);
            }
        } else if (((gInfoWin->f04 & 0x400) ? 1 : 0) == 1) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 0x10);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xFBFF);
            gInfoWin->f04 = (u16)(gInfoWin->f04 & 0xF7FF);
            gInfoWin->f08 = 0;
        }
        if (link->f65 == 1 || link->f65 == 2 || link->f65 == 6) {
            if (gInfoWin->f20 == 0) {
                gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
                gInfoWin->f20 = 1;
            }
        } else if (gInfoWin->f20 != 0) {
            gInfoWin->f04 = (u16)(gInfoWin->f04 | 8);
            gInfoWin->f20 = 0;
        }
    }
}
