/*
 * function: func_020319F0
 * address:  0x020319F0
 * packet:   pkt_020319F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   str_020A7848   0x020A7848  data
 *   g_02146994     0x02146994  data
 *   func_02030734  0x02030734  arm
 *   func_02034F84  0x02034F84  arm
 *   func_02033200  0x02033200  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020335AC  0x020335AC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020319C0  0x020319C0  arm
 *   func_02034FB8  0x02034FB8  arm
 *
 * Erase the whole backup device in 0x1000-byte pages.  A 0x1000-byte scratch
 * page is allocated on the heap named by the u16 second argument (the
 * __FILE__ is "backup_system.c" at 0x020A7848 and the __LINE__ is 0x1e8),
 * filled with 0xff by func_02082A7C, and written over every page of the
 * device: the job's +8 word is the total length, its +0 word the destination
 * base, and the device handle comes from the +0x208 field of the object
 * behind the global at 0x02146994, re-read once per page along with the base.
 *
 * The literal 1 is materialised ONCE into r4 and reused as the second
 * argument of the first func_02033200 call
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md);
 * the second call's 2 is its own `mov`.  The 0x1000 page size is materialised
 * twice, once for the allocation and once into callee-saved r8 for the loop,
 * because the fill call in between clobbers it.
 *
 * The lengths compare unsigned (`bls`/`blo`), so a zero-length device skips
 * the loop entirely; the +4 word is a second length whose inequality with
 * +0 triggers an extra func_02033200(obj, 2) pass before the fill.
 *
 * Declaration order is one/off/page, which is what shares r4 between the
 * literal 1 and the loop cursor and leaves r5 for the scratch page
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * page-first gives the exact same 240 bytes with r4 and r5 swapped, 12 out.
 * The heap id is a u32 parameter truncated at the call site, not a u16
 * parameter: the explicit `(u16)` is what produces the `lsl`/`lsr` pair at
 * +0x0008/+0x0018, and a u16 parameter folds it to a single `mov` for 236.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020319F0.c \
 *       --func func_020319F0 --addr 0x020319F0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Job {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x10];
    u8  f1c;
};

struct Dev {
    u8  pad_00[0x208];
    u32 f208;
};

extern const char str_020A7848[];
extern struct Dev *g_02146994;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_02034F84(u32 a);
extern void  func_02033200(struct Job *job, u32 mode);
extern void  func_02082A7C(u32 v, void *p, u32 n);
extern u32 func_020335AC(u32 a, u32 b, u32 c, u32 d);
extern void  func_020307B0(void *p);
extern void  func_020319C0(struct Job *job);
extern void  func_02034FB8(u32 a, u32 b);

int func_020319F0(struct Job *job, u32 heap)
{
    u32 one;
    u32 off;
    void *page;

    page = func_02030734((u16)heap, 0x1000, 0, str_020A7848, 0x1e8);

    one = 1;
    func_02034F84(one);
    func_02033200(job, one);
    if (job->f00 != job->f04)
        func_02033200(job, 2);

    func_02082A7C(0xFFFFFFFF, page, 0x1000);

    for (off = 0; off < job->f08; off += 0x1000)
        func_020335AC(off + job->f00, (u32)page, 0x1000, g_02146994->f208);

    func_020307B0(page);
    func_020319C0(job);
    job->f1c = 0;
    func_02034FB8(1, 0);
    return 1;
}
