#ifndef BTLV_EFFVM_SHARED_TYPES_H
#define BTLV_EFFVM_SHARED_TYPES_H

#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"

struct Rec_vE254;

typedef struct { int x, y, z; } Vec_021F6560;

typedef struct { short x, y; } Pt_021FB8F4;

typedef long long s64;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    BtlvEffVmFlags *fl;
    int a;
    int b;
    int v[3];
} Rec_vE254;

typedef enum { KEY_0 } Key_021FD04C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF1B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF1B0 e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_021FF1B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF228 e[14];            /* 0x008 */
} Work_021FF228;

typedef struct {
    int x, y, z;
} Vec3_vF228;

typedef struct {
    fx32 x, y, z;
} VecFx32_vF5B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_021FF5B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF5B0 e[14];            /* 0x008 */
    char pad510[0x518 - 0x510];
    int mask[4];            /* 0x518 */
    char pad528[0x550 - 0x528];
    u8 cnt[4][14];          /* 0x550 */
} Work_021FF5B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF630;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF630 e[14];            /* 0x008 */
    char pad514[0x520 - 0x008 - 14 * 0x5c];
    int mask;               /* 0x520 */
    char pad524[0x534 - 0x524];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
    char pad540[0x55e - 0x540];
    unsigned char cnt[14];  /* 0x55e */
} Work_021FF630;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_vF5B0;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_vF5B0 e[14];            /* 0x008 */
    char pad510[0x518 - 0x510];
    int mask[4];            /* 0x518 */
    char pad528[0x550 - 0x528];
    u8 cnt[4][14];          /* 0x550 */
} Work_vF5B0;

typedef struct {
    void *owner;            /* 0x000 */
    char pad04[0x520 - 4];
    int mask[4];            /* 0x520 */
    char pad530[0x540 - 0x530];
    u16 heap;               /* 0x540 */
    char pad542[0x588 - 0x542];
    u8 cnt[4][14];          /* 0x588 */
} Work_021FF870;

typedef struct {
    void *owner;
    char pad04[0x514 - 4];
    int mask;
    char pad518[0x540 - 0x518];
    u16 heap;
    u8 cnt[14];
} Work_021FFA18;

typedef struct {
    Work_021FFA18 *w;
    int key, kind, direction, f10, f14, f18, f1c, f20, f24;
    int f28, f2c, f30, f34, f38;
} Obj_021FFA18;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x5c - 4];
} Entry_021FFB04;

typedef struct {
    void *owner;            /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFB04 e[14];            /* 0x008 */
    char pad510[0x514 - 0x510];
    int mask[6];            /* 0x514 */
    char pad52c[0x540 - 0x52c];
    u16 heap;               /* 0x540 */
    u8 cnt[6][14];          /* 0x542 */
} Work_vF7B0;

typedef struct {
    Work_vF7B0 *w;                /* 0x00 */
    int key;                /* 0x04 */
    int v[3];               /* 0x08 */
    char pad14[0x14];
    int f28;                /* 0x28 */
} Obj_vF7B0;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 a;                  /* 0x2c (w+0x34) */
    u32 b;                  /* 0x30 (w+0x38) */
    char pad34[0x28];
} Entry_021FFF68;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFF68 e[14];            /* 0x008 */
} Work_021FFF68;

typedef struct {
    int w[9];
} Rec_021FFFAC;

typedef struct {
    void *h;                /* 0x00 */
    Rec_021FFFAC rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry_021FFFAC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FFFAC e[14];            /* 0x008 */
} Work_021FFFAC;

typedef struct {
    int a, b, c, d;
} Quad_vFE48;

typedef struct {
    void *h;                /* 0x00 */
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char pad24[0x08];
    Quad_vFE48 q;                 /* 0x2c */
    char pad3c[0x20];
} Entry_02200140;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200140 e[14];            /* 0x008 */
} Work_02200140;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x28];
    u32 k2c;                /* 0x2c */
    u32 k30;                /* 0x30 */
    char pad34[0x06];
    u16 k3a;                /* 0x3a */
    char pad3c[0x20];
} Entry_02200218;

typedef struct {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Flags_vFE48;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200218 e[14];            /* 0x008 */
    Flags_vFE48 flags;            /* 0x510 */
} Work_02200218;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x40];
    int f44;                /* 0x44 */
    char pad48[0x14];
} Entry_0220041C;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_0220041C e[14];            /* 0x008 */
} Work_0220041C;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry_02200468;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200468 e[14];            /* 0x008 */
} Work_02200468;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    u32 flags;              /* 0x4c */
    char pad50[0x0c];
} Entry_022004BC;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022004BC e[14];            /* 0x008 */
} Work_022004BC;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 5;    /* 0x4c */
    unsigned int f5 : 1;
    unsigned int mid : 4;
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry_02200654;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200654 e[14];            /* 0x008 */
} Work_02200654;

typedef short s16_02201B20;

typedef struct Ent { void *h8; void *hc; void *h10; void *h14; } Ent;

typedef struct Res_02201B20 { void *owner; void *h; Ent e[7]; } Res_02201B20;

#endif
