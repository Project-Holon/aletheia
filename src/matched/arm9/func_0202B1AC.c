/*
 * function: ISS_ROAD_SYS_Create
 * address:  0x0202B1AC
 * packet:   pkt_0202AFFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates a 0x18-byte node with the allocator entry point, zeroes its
 * first two words, stores the first argument at +8, and copies a 12-byte
 * record from func_02012AA0(first) into +0xc.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ROAD_SYS_Create.c \
 *       --func ISS_ROAD_SYS_Create --addr 0x0202B1AC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Copy {
    u32 a, b, c;
} Copy;

struct Node {
    u32 f0, f4, f8;
    Copy body;
};

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Rec44;
struct Vec12;
extern struct Vec12 *func_02012AA0(struct Rec44 *p);

struct Node *ISS_ROAD_SYS_Create(u32 a, u32 heapId)
{
    struct Node *p = (struct Node *)func_02030734(heapId, 0x18, 0,
                                                  (const void *)0x020A7708, 0x4a);
    const Copy *s;

    p->f0 = 0;
    p->f4 = 0;
    p->f8 = a;

    s = (const Copy *)func_02012AA0((struct Rec44 *)a);
    p->body = *s;
    return p;
}
