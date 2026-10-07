/*
 * file:     event_poke_status_p08.c
 * unit:     yes
 * function: func_02159B10, func_02159B38, func_02159B48, func_02159B94, func_02159BBC, func_02159BC4, func_02159BD4, func_02159BF4, func_02159BF8, func_02159BFC, func_02159C00
 * address:  0x02159B10
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
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_0215A5F4   0x0215A5F4  thumb  ov010
 *   func_02011330   0x02011330  thumb
 *   func_0215901C   0x0215901C  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021728AC  0x021728AC  data
 *   func_02048F60  0x02048F60  arm
 *   func_02159D04  0x02159D04  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02159D68  0x02159D68  thumb  ov010
 */
struct Stream;
struct SaveBlock;
struct Rec44;
struct MapMatrix;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct MapMatrix {
    u16 field00;
    u16 zone_id;
    u32 matrix_id;
    u16 width;
    u16 height;
    u16 mode;
    u16 pad0e;
    u32 count;
    u16 zone_grid[900];
    u32 map_grid[900];
};

typedef struct Obj_02159BF4 {
    char pad[8];
    unsigned short f;
} Obj_02159BF4;

typedef struct Obj_02159BF8 {
    char pad[0xA];
    unsigned short f;
} Obj_02159BF8;

typedef struct Obj_02159BFC {
    char pad[0x10];
    int f;
} Obj_02159BFC;

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern u16 func_02011330(struct Stream *s);
extern unsigned int func_0215901C(void *a, void *b, unsigned int id);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082A7C(int, void *, int);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern int func_02159D04();
extern u32 func_020307B0(void *p);
extern int func_02159D68(int x);
unsigned int func_02159B10(void *a0, void *a1);
int func_02159B38(int a0);
u16 *func_02159B48(int a);
int func_02159B94(int a0, int a1, int a2, int a3);
void func_02159BBC(void *ptr);
u16 func_02159BC4(const struct MapMatrix *m, u32 x, u32 y);
int func_02159BD4(int a0, int a1, int a2);
unsigned short func_02159BF4(Obj_02159BF4 *p);
unsigned short func_02159BF8(Obj_02159BF8 *p);
int func_02159BFC(Obj_02159BFC *p);
void sub_02159C00(struct MapMatrix *m, u32 width, u32 height);
extern const char d_021728AC[];


/*
 * Same three-argument submission as its neighbour, aimed at the second
 * overlay handler.
 */
unsigned int func_02159B10(void *a0, void *a1)
{
    void *v = func_0215A5E4(a1);

    return func_0215901C(func_0215A5F4(a1), v, func_02011330(a0));
}


int func_02159B38(int a0)
{
    void *p;
    void *v0;

    v0 = func_0215A5E4((void *)a0);
loc_02159B3E:
    p = func_020127A4((struct SaveBlock *)v0);
loc_02159B42:
    a0 = func_02012AC8(p);
loc_02159B46:
    return a0;}


u16 *func_02159B48(int a)
{
    u16 *p = func_02030734(a, 0x152c, 1, d_021728AC, 0x4b);
    *p = a;
    func_02082A7C(-1, (u8 *)p + 0x71c, 0xe10);
    func_02082A7C(0xffff, (u8 *)p + 0x14, 0x708);
    return p;
}


int func_02159B94(int a0, int a1, int a2, int a3)
{
    int t5;
    int t6;
    int t7;
    void *t4;

t5 = a0 + 0;
t7 = a2 + 0;
a0 = 9;
a2 = a3 + 0;
t6 = a1 + 0;
    t4 = func_02048F60(a0, a1, a2);
loc_02159BA4:
a0 = t5 + 0;
a2 = t6 + 0;
a3 = t7 + 0;
    a0 = func_02159D04(a0, t4, a2, a3);
loc_02159BB2:
    a0 = func_020307B0(t4);
loc_02159BB8:
    return a0;}


/*
 * Thumb tail call into ENV_SetResourceSet (ARM, 0x020307B0): `ldr r3,
 * [pc, #0]; bx r3` plus the pool word, the shape of the arm9 copy
 * func_02011264.  Unlabelled in the listing (no prologue, called only from
 * arm9), so it is emitted as data words.
 */
void func_02159BBC(void *ptr)
{
    func_020307B0(ptr);
}


/*
 * Read one cell of the matrix object's zone grid: the u16 array at +0x14,
 * row-major over the object's own width at +0x08.  Leaf, no relocations.
 *
 * The companion grid is the u32 array at +0x71C holding a/0/0/8 sub-file
 * indices; func_02159C20 hands out its base.  Both are decoded by
 * func_02159D04 out of one a/0/0/9 sub-file.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02159BC4.c \
 *       --func func_02159BC4 --addr 0x02159BC4 --region ov010 --cc 1.1p1 --thumb
 */
u16 func_02159BC4(const struct MapMatrix *m, u32 x, u32 y)
{
    return m->zone_grid[x + y * m->width];
}


int func_02159BD4(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a2 + 0;
a0 = a1 + 0;
    a0 = func_02159D68(a0);
loc_02159BE0:
t6 = a0 + 0;
a0 = t4 + 0;
    a0 = func_02159D68(a0);
loc_02159BE8:
a2 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159BC4((const struct MapMatrix *)a0, a1, a2);
loc_02159BF2:
    return a0;}


/*
 * Unlabelled leaf accessor (prints as .word): returns the field at +8.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
unsigned short func_02159BF4(Obj_02159BF4 *p)
{
    return p->f;
}


/*
 * Unlabelled leaf accessor (prints as .word): returns the field at +0xA.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
unsigned short func_02159BF8(Obj_02159BF8 *p)
{
    return p->f;
}


/*
 * Unlabelled leaf accessor (prints as .word): returns the field at +0x10.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */
int func_02159BFC(Obj_02159BFC *p)
{
    return p->f;
}


/*
 * Set the matrix object's dimensions, refusing anything that would not fit
 * the two fixed 900-entry grids: width and height are each capped at 30 and
 * their product at 900.  That is what pins the object's layout, since
 * 0x14 + 900 * 2 is exactly the 0x71C where the u32 map-model grid starts.
 *
 * The product is computed before the guards rather than after, so all three
 * checks share one exit and the whole body is a single conjunction
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * 900 is spelled 0xe1 << 2 because it is not an 8-bit Thumb immediate.
 *
 * Another leaf with no lr save, so disasm.py left it unlabelled.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02159C00.c \
 *       --func sub_02159C00 --addr 0x02159C00 --region ov010 --cc 1.1p1 --thumb
 */
void sub_02159C00(struct MapMatrix *m, u32 width, u32 height)
{
    u32 n = width * height;

    if (width <= 30 && height <= 30 && n <= 900) {
        m->width = (u16)width;
        m->height = (u16)height;
        m->count = n;
    }
}
