#ifndef BTLV_STAGE_SHARED_TYPES_H
#define BTLV_STAGE_SHARED_TYPES_H

#include "btlv_effvm_types.h"

struct G3dOwner;

struct G3dRec;

struct Tagged;

struct G3dSys;

struct Rec_v6560;

struct Arg_v6560;

typedef struct { int kind, a, b, c; } Ent_021F6560;

typedef struct {
    int f0;
    int ids[4][4];
} Rec_v6560;

typedef struct {
    int f0, f4, f8;
    int sx, sy, sz;
    int matrix[9];
} Xf;

typedef struct {
    void *f0;
    int n;
    Ent_021F6560 *arr[2];
    void **f10;
    void **f14[2];
    void *h1c[2];
    void *h24[2];
    Xf xf[2];
    void **fa4;
    void **fa8;
    u8 fac, fad;
    u8 padae[10];
    u16 heap;
    u16 padba;
} Obj_021F6560;

typedef struct {
    void *f0;           /* 0x00 */
    int n;              /* 0x04 */
    void *f8[2];        /* 0x08 */
    void **f10;         /* 0x10 */
    void **f14[2];      /* 0x14 */
    void *f1c[2];       /* 0x1c */
    void *f24[2];       /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    void *fa4;          /* 0xa4 */
    void **fa8;         /* 0xa8 */
} Obj_021F6898;

typedef struct {
    int kind;       /* 0x00 */
    int f4;
    int f8;
    int fc;
} Ent_021F6934;

typedef struct {
    int f0;
    int n;              /* 0x04 */
    Ent_021F6934 *arr[2];        /* 0x08 */
    char pad10[0x24 - 0x10];
    void *h[2];         /* 0x24 */
    char pad2c[0xa4 - 0x2c];
    char sub[0x10];     /* 0xa4 */
} Obj_021F6934;

typedef struct {
    char pad[0x24];
    void *h[2];             /* 0x24 */
    char xf[2][0x3c];       /* 0x2c */
    char padA4[0xb4 - 0xa4];
    unsigned off : 2;       /* 0xb4 */
} Obj_021F69B0;

typedef struct {
    char pad[0xac];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
} S69E8;

typedef struct { char pad[0xB4]; u32 f : 2; u32 rest : 30; } Obj_021F6A28;

typedef struct {
    int state;
    int armed;
    int a;
    int b;
} Entry_021F6560;

typedef struct {
    char pad[8];
    Entry_021F6560 *tab[1];
} Obj_021F6AA8;

typedef struct {
    int pad0;
    int n;              /* 0x04 */
    Entry_021F6560 *x;           /* 0x08 */
    Entry_021F6560 *y;           /* 0x0c */
} Obj_021F6AD0;

typedef struct {
    u8 b0, b1, b2, b3;
    int f4;
    int f8;
    u16 fc;
} Arg_v6560;

typedef struct {
    u32 **a0;           /* 0 */
    u16 **a4;           /* 4 */
    u8 en;              /* 8 */
    u8 n;               /* 9 */
    u8 cur;             /* 0xA */
    u8 tgt;             /* 0xB */
    u8 cnt;             /* 0xC */
    u8 rl;              /* 0xD */
    u16 col;            /* 0xE */
} P;

#endif
