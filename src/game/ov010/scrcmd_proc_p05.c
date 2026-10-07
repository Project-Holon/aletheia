/*
 * file:     scrcmd_proc_p05.c
 * unit:     yes
 * function: func_0215C40C, func_0215C4C8, func_0215C510, func_0215C558, func_0215C584, func_0215C5B0
 * address:  0x0215C40C
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
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   func_020186C8 0x020186C8 thumb
 *   func_02017430 0x02017430 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0202142C 0x0202142C thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_0202F190 0x0202F190 thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02007984  0x02007984  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_020074D8  0x020074D8  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02012934  0x02012934  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 *   func_0200C29C 0x0200C29C thumb
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0200C274 0x0200C274 thumb
 */
struct Sub0200852CObj;
struct SaveBlock;
struct Rec44;
struct BigObj;
struct Sub02007454Entry;
struct Spec;
struct Blk37;
struct Party;
struct PartyMon;
struct Blk34;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct Spec {
    u16 f00, pad02;
    u32 f04, f08, f0c, f10, f14, f18, f1c, f20;
} Spec;

typedef unsigned char  u8;

extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void *func_02017430(u16, u16, u64, u32, u64, u16);
extern void func_02017E40(void *, u32, u32);
extern int func_02020FE4(u16, u32, u16);
extern unsigned short func_0202142C(int a0);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013E4C(u32 id);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_020185C4(void *);
extern u32 func_0201293C(const struct BigObj *p);
extern int func_02007984(void *a);
extern void *func_020185F4(void *p);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void *func_0200CA1C(void *a);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA14(void *p);
extern u32 func_0201AA18(void *p);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern u32 func_0200C29C(struct Blk34 *p, u32 v);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_0200C274(struct Blk34 *p);
void *func_0215C40C(void *a, Spec *s);
int func_0215C4C8(void *a, void *b);
int func_0215C510(void *a, void *b);
int func_0215C558(int a,int b);
int func_0215C584(int a,int b);
int func_0215C5B0(void *a, void *b);

/*
 * lever: func_02017430's matched signature has two u64 inputs; widening the
 * personality result to u64 schedules its high zero before the low-word store.
 */
void *func_0215C40C(void *a, Spec *s)
{
    void *r7;
    void *r4;
    u32 t;
    r7 = func_02012944(a);
    r4 = (void *)func_02008530((const struct Sub0200852CObj *)func_02012944(a));
    t = func_020186C8((u32)r4, (u16)s->f04, (u16)s->f08, (u32)s->f18, (u32)s->f14, (u32)s->f1c);
    r4 = func_02017430(s->f04, s->f0c, (u32)r4, -1, t, s->f00);
    func_02017E40(r4, 0x6F, s->f08);
    func_02017E40(r4, 6, s->f10);
    if (func_02020FE4(s->f20, 0xF, s->f00) == 4)
        func_02017E40(r4, 0x98, (u32)func_0202142C((u16)s->f20));
    func_0202F190(r4, 0, (u32)r7, func_02013E4C(func_02012AC8(func_020127A4(a))), s->f00);
    func_020185C4(r4);
    return r4;
}


int func_0215C4C8(void *a, void *b)
{
    void *r6;
    void *r5;

    r6 = (void *)func_0201293C(a);
    if (func_02007984(r6) >= 0x2D0)
        return 0;
    r5 = func_0215C40C(a, b);
    func_020074D8(r6, (const struct Sub02007454Entry *)((u32)func_020185F4(r5)));
    func_0200CDE0(func_0200CA1C(a), r5);
    func_020307B0(r5);
    return 1;
}


int func_0215C510(void *a, void *b)
{
    void *r6;
    void *r5;

    r6 = func_02012934(a);
    if ((int)func_0201AA14(r6) <= (int)func_0201AA18(r6))
        return 0;
    r5 = func_0215C40C(a, b);
    func_0201A98C(r6, r5);
    func_0200CDE0(func_0200CA1C(a), r5);
    func_020307B0(r5);
    return 1;
}

/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215C558(int a,int b)
{
    void *p = func_0215A5E4((void *)b);
    int k;
    func_020127A4(p);
    k = func_02159B10((void *)a,(void *)b);
    func_0200C278(func_02012F08(p),k);
    return 0;
}

int func_0215C584(int a,int b)
{
    void *p = func_0215A5E4((void *)b);
    int k;
    func_020127A4(p);
    k = func_02159B10((void *)a,(void *)b);
    func_0200C29C(func_02012F08(p),k);
    return 0;
}


int func_0215C5B0(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    unsigned int v = func_02159B10(a, b);
    void *q = func_0215A5E4(b);
    func_020127A4(q);
    *p = v <= func_0200C274(func_02012F08(q)) ? 1 : 0;
    return 0;
}
