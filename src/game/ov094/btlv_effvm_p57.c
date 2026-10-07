/*
 * file:     btlv_effvm_p57.c
 * unit:     yes
 * function: func_021FE79C, func_021FE8AC, func_021FE8D8, func_021FE930
 * address:  0x021FE79C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_02030EE8  0x02030EE8  arm
 *   func_02006BD0  0x02006BD0  thumb
 *   func_021FE410  0x021FE410  thumb  ov094
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FFCB0  0x021FFCB0  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021FF304  0x021FF304  thumb  ov094
 *   func_021FF470  0x021FF470  thumb  ov094
 */
#define REG16(a) (*(volatile u16 *)(a))
#define REG32(a) (*(volatile unsigned int *)(a))
struct S02030EE8;
typedef unsigned short u16;

typedef unsigned char u8;

typedef struct {
    unsigned int *reg;      /* 0x00 */
    char pad04[0x20];
    int k24;                /* 0x24 */
} Ctx;

typedef unsigned int   u32;

typedef struct {
    unsigned int f0 : 10;
    unsigned int f10 : 1;
} Flags;

typedef struct {
    Flags fl;
    char pad04[0x268];
    int tbl[6];
} Obj;

typedef struct {
    int pad0;
    int side;
    int mask;
} Arg;

extern void func_021F89BC(void *);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_02006BD0(u32 i);
extern void func_021FE410(Obj *o, int a, int b, int n);
extern int func_021F7F1C(int i);
extern int func_021F8694(void);
extern int func_021FFCB0(char *p, int key);
extern int func_021F935C(int x);
extern void func_021FF304(char *p, int key, int mode);
extern void func_021FF470(char *p, int key, void *v);
void func_021FE79C(void *h, int *s);
void func_021FE8AC(void *h);
void func_021FE8D8(void *h, Obj **pp);
void func_021FE930(void *h, Arg *a);

static inline void window0(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void window1(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

/*
 * volatile: WININ re-read at 0x021FE7BE; WINOUT and display register accesses.
 */
void func_021FE79C(void *h, int *s)
{
    switch (s[1]) {
    case 0:
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f) | (u8)s[5]);
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f00) | (u16)(s[5] << 8));
        REG16(0x0400004a) = (u16)((REG16(0x0400004a) & ~0x3f) | ((s[5] & 0xff00) >> 8));
        REG32(0x04000000) = (REG32(0x04000000) & ~0xe000) | 0x6000;
        REG16(0x04000042) = 0;
        REG16(0x04000046) = 0;
        s[1]++;
    case 1:
        if (s[7] == 0) {
            s[7] = s[8];
            switch (s[2]) {
            case 0: s[4] -= 0x100; s[4]++; break;
            case 1: s[4] += 0x100; s[4]--; break;
            case 2: s[3] -= 0x100; s[3]++; break;
            case 3: s[3] += 0x100; s[3]--; break;
            }
            window0(s[3] >> 8, s[4] >> 8, s[3], s[4]);
            if ((u8)s[3] == 0xff) {
                window1(1, s[4] >> 8, 0, s[4]);
            } else {
                window1(0, 0, 0, 0);
            }
            s[6]--;
            if (s[6] == 0)
                func_021F89BC(h);
        } else {
            s[7]--;
        }
        break;
    }
}


void func_021FE8AC(void *h)
{
    Ctx *c = (Ctx *)func_02030EE8(h);

    if (c->k24 == 0)
        *(volatile unsigned int *)0x04000000 &= ~0xE000u;
    *c->reg &= ~0x100u;
}


void func_021FE8D8(void *h, Obj **pp)
{
    int i;

    for (i = 0; i < 6; i++) {
        if ((*pp)->tbl[i] != -1) {
            if (func_02006BD0((*pp)->tbl[i]) != 0)
                return;
            (*pp)->tbl[i] = -1;
        }
    }
    func_021FE410(*pp, 0x6b000, 0x7f000, 10);
    (*pp)->fl.f10 = 0;
    func_021F89BC(h);
}


/*
 * Lever: the `mask |= 1 << i` tail is written out in both arms (then-arm
 * innermost, and the else arm); the compiler cross-jumps them and leaves the
 * `b` to the next instruction.  A single shared tail (goto/continue) gives no
 * `b` and hoists r7/r4 in the other order.
 */
void func_021FE930(void *h, Arg *a)
{
    int i = 1;
    int want;

    if (a->side == 0)
        i = 0;
    if (a->side != 0)
        want = 0xaa;
    else
        want = 0x55;
    while (i <= 7) {
        if (func_021F7F1C(i)) {
            if (func_021FFCB0((char *)func_021F8694(), i) == 0) {
                if ((func_021F935C(i) & a->mask) == 0) {
                    func_021FF304((char *)func_021F8694(), i, 0);
                    func_021FF470((char *)func_021F8694(), i, 0);
                    a->mask |= func_021F935C(i);
                }
            }
        } else {
            a->mask |= func_021F935C(i);
        }
        i += 2;
    }
    if (want == a->mask)
        func_021F89BC(h);
}
