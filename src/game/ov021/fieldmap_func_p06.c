/*
 * file:     fieldmap_func_p06.c
 * unit:     yes
 * function: func_021BBC58, func_021BBCBC
 * address:  0x021BBC58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_02030734  0x02030734  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_021BBD0C  0x021BBD0C  thumb  ov021
 *   d_021DE30C  0x021DE30C  data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* 0x24-byte ring entry; the ring holds 30 of them (see func_021BBBD8) */
typedef struct Entry {
    u8 d[0x18];
    u16 h;       /* 0x18 */
    u8 key[6];   /* 0x1a, compared 6 bytes at a time */
    u8 pad[4];
} Entry;

typedef struct Ring {
    Entry e[30];
    u8 head;
    u8 tail;
    u8 pad2[2];
    int count;
} Ring;

typedef signed int     s32;

typedef struct {
    void *owner;
    void *res;
    char pad[0x34];
    int f3c;
} Obj;

Entry *func_021BBC2C(Ring *r, int i);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C88(u8 *p);
extern void func_021BBD0C(u32 *p);
/* A u16 `c` (not int/u32) is what stores c's spill before b's. */ int func_021BBC58(Ring *r, const void *b, u16 c);
Obj *func_021BBCBC(void *owner, u32 heap);
extern const char d_021DE30C[];


/* A u16 `c` (not int/u32) is what stores c's spill before b's. */
int func_021BBC58(Ring *r, const void *b, u16 c)
{
    int i;
    Entry *p;

    for (i = r->count; i > r->count - 30; i--) {
        if (i < 0) return 1;
        p = func_021BBC2C(r, i);
        if (p != 0 && func_0203EFC8(p->key, b, 6) == 0) {
            if (p->h != c) return 1;
            return 0;
        }
    }
    return 1;
}


Obj *func_021BBCBC(void *owner, u32 heap)
{
    Obj *o;

    o = func_02030734(heap, 0x40, 1, d_021DE30C, 0x9d);
    o->owner = owner;
    o->res = (void *)func_02188C88((u8 *)func_021ABE14(owner));
    func_021BBD0C((u32 *)o);
    o->f3c = 0x2000;
    return o;
}
