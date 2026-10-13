#ifndef BTLV_CLACT_SHARED_TYPES_H
#define BTLV_CLACT_SHARED_TYPES_H

struct Bank;

struct Obj;

struct Actor;

struct PtS;

struct Obj_02201DA0;

struct Vec2;

struct Pair_02201B20;

typedef struct { int x, y, z; } Vec;

typedef struct {
    int a, b;
    void *h;
    int d;
} Ent_02201DA0;

typedef struct {
    Ent_02201DA0 *tbl;   /* 0x00 */
    int x, y;   /* 0x04 */
    int pad;    /* 0x0c */
    int idx;    /* 0x10 */
    int mover[1]; /* 0x14 */
} Obj_02201DA0;

typedef struct Pair_02201B20 {
    int x;
    int y;
} Pair_02201B20;

typedef struct Bits_02201B20 { unsigned b0:1; unsigned mid:30; unsigned b31:1; } Bits_02201B20;

typedef struct Obj { char pad[0x64]; void *h64; Bits_02201B20 f68; } Obj;

#endif
