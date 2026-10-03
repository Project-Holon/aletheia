/*
 * function: func_0204F10C
 * address:  0x0204F10C
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Hand the 0x28-stride entry's payload buffer to func_020307E0 with its
 * length.  The payload pointer is a named local, not an inline call argument,
 * or the entry pointer would have to stay live in a third callee-saved
 * register across both calls.  Same shape as src/matched/sub_02046FCC.c.
 *
 * symbols:
 *   func_02046F48  0x02046F48  arm
 *   func_02047250  0x02047250  arm
 *   func_020307E0  0x020307E0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tagged {
    u16   tag;
    u16   pad02;
    void *buf;
};

struct Record {
    u8  pad00[0x14];
    u32 size;
};

struct Entry {
    void *payload;
    u8    pad04[0x28 - 4];
};

extern void *func_02046F48(struct Tagged *p);
extern struct Record *func_02047250(void *p);
extern void func_020307E0(void *p, u32 size);

void func_0204F10C(void *table, u32 idx)
{
    struct Entry  *e       = &((struct Entry *)*(void **)((u8 *)table + 4))[idx];
    void          *payload = e->payload;
    void          *buf     = func_02046F48(payload);
    struct Record *last    = func_02047250(payload);

    func_020307E0(buf, (u32)((u8 *)last + last->size - (u8 *)buf));
}
