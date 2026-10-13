#ifndef BTLV_FIELD_SHARED_TYPES_H
#define BTLV_FIELD_SHARED_TYPES_H

#include "btlv_effvm_types.h"

typedef struct { int kind, a, b, c; } Ent_021F6B04;

typedef struct {
    void *f0;
    int n;
    Ent_021F6B04 *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    int f1c, f20, f24;
    int f28, f2c, f30;
    int matrix[9];
    void **f58;
    void **f5c;
    u8 f60, f61;
    u8 pad62[10];
    u16 heap;
    u16 pad6e;
} Obj_021F6B04;

typedef struct {
    void *f0;
    int n;              /* 0x04 */
    void *f8;
    void **fc;
    void **f10;
    void *f14;
    void *f18;
    char pad1c[0x58 - 0x1c];
    void *f58;
    void **f5c;
} Obj_021F6CF0;

typedef struct {
    int kind;       /* 0x00 */
    int f4;
    int f8;
    int fc;
} Ent_021F6D5C;

typedef struct {
    int f0;
    int n;              /* 0x04 */
    Ent_021F6D5C *arr;           /* 0x08 */
    char pad0c[0x0c];
    void *h18;          /* 0x18 */
    char pad1c[0x58 - 0x1c];
    char sub[0x10];     /* 0x58 */
    u32 bit0 : 1;       /* 0x68 */
    u32 bit1 : 1;
} Obj_021F6D5C;

typedef struct {
    char pad[0x18];
    void *h;            /* 0x18 */
    int v[3];           /* 0x1c */
    char pad28[0x68 - 0x28];
    unsigned b0 : 1;    /* 0x68 */
} Obj_021F6DD4;

typedef struct {
    char pad[0x60];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned short f6;
} S6DEC;

typedef struct { char pad[0x68]; u32 f : 1; u32 rest : 31; } Obj_021F6E2C;

#endif
