/*
 * docs/families/game_comm.h -- shared declarations for the game_comm.c
 * family, 0x020261E4..0x020266D4 in the ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of any
 * translation unit and `match.py` never sees it.  Written wave 16 from the
 * matched sources: unit_02026454.c, unit_02026490.c, func_02026388.c,
 * func_020263B0.c, func_020264F4.c, unit_020263D8.c.
 *
 * THE OBJECT.  One comm request object, driven by a per-frame state machine
 * (func_0202627C, open, 268 bytes, docs/notes/pkt_0202627C.c.txt).  The byte
 * at +4 is a set of one-bit flags: every clear in the image is `bics` and
 * every set `orrs`, which only BITFIELD stores produce (a hand `&= ~2` gives
 * `ands` against 0xFD and reorders the stores).  The 8-byte sub-object at
 * +0xC is {u32 counter; u8 state; u8 changed}; func_02026490 sets state and
 * changed = 1, and the state machine clears the counter when changed == 1.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u32 f00;          /* frame counter, cleared on a state change */
    u8  state;        /* +0x04: 0 start, 1 wait, 2 run, 3 stop, 4 end, 5 finish */
    u8  changed;      /* +0x05 */
    u8  f06;
    u8  f07;
};

struct Comm {
    u32 f00;
    u8  b0 : 1;       /* +0x04: stop requested (func_0202640C sets it) */
    u8  b1 : 1;       /*        passed to the finish callback */
    u8  b2 : 1;       /*        unit_02026490's getter/setter pair */
    u8  b3 : 5;
    u8  kind;         /* +0x05: index into the callback table, 0 = idle */
    u8  f06;          /* +0x06: last kind started */
    u8  f07;
    u32 f08;
    struct Sub sub;   /* +0x0C */
    u32 f14;          /* the request argument */
    u32 f18;          /* the start callback's result */
    u32 f1c;          /* finish callback argument */
    void (*f20)(u32, u32);   /* finish callback */
};

/* 0x1C-byte records at 0x0209FB5C, indexed by kind (entry 0 unused). */
struct Rec {
    u32  (*start)(struct Sub *, u32);
    u32  (*wait)(struct Sub *, u32, u32);
    void (*run)(struct Sub *, u32, u32);
    u32  (*stop)(struct Sub *, u32, u32);
    u32  (*end)(struct Sub *, u32, u32);
    u32  f14;         /* func_02026388 calls through 0x0209FB70 */
    u32  f18;         /* func_020263B0 calls through 0x0209FB74 */
};

void func_02026490(struct Sub *s, u32 state);            /* unit_02026490 */
void func_020264F4(struct Comm *p);
void func_020263D8(struct Comm *p, u32 kind, u32 arg);   /* unit_020263D8 */
void func_02026400(struct Comm *p);                      /* -> 640C(p,0,0) */
void func_0202640C(struct Comm *p, u32 cb, u32 cbarg);   /* stop: f20 = cb, f1c = cbarg */

/* LEVER THAT CLOSED func_020263D8: the bit clear sits BETWEEN the two plain
 * stores in the source (f14, bit, f05); both other orders schedule the f05
 * store first. */
