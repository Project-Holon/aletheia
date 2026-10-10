/*
 * function: func_021F81EC
 * address: 0x021F81EC
 * packet: pkt_ov094_021F81EC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov094/btlv_effvm.c and filed here.
 *
 * symbols:
 *   d_0220AF20 0x0220AF20 data a4
 *   func_02030DA8 0x02030DA8 arm
 *   func_02208870 0x02208870 thumb ov094
 *   func_021F896C 0x021F896C thumb
 *   func_0220074C 0x0220074C thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int fx32;

typedef struct BtlvEff {
    void *owner;                /* 0x000 */
    void *buf;                  /* 0x004 */
    void *handle[32];           /* 0x008 */
    void (*cb[32])(void *);     /* 0x088 */
    int arg[32];                /* 0x108 */
    void *h188;                 /* 0x188 */
    void *h18c;
    void *h190;                 /* 0x190 */
    void *h194;
    void *h198;
    void *h19c;
    void *h1a0;
    void *h1a4;
    void *h1a8[2];              /* 0x1a8 */
    void *h1b0;                 /* 0x1b0 */
    void *h1b4;
    void *h1b8;
    int mode;                   /* 0x1bc */
    int f1c0;
    char pad1c4[0x10];
    unsigned short f1d4[4];                /* 0x1d4 */
    int f1dc;
    int f1e0;
    void *param_battle;         /* 0x1e4 */
    int f1e8;                   /* 0x1e8 */
    unsigned int m0 : 8;                 /* 0x1ec */
    unsigned int m1 : 8;
    unsigned int m2 : 2;
    unsigned int v : 8;
    unsigned int b26 : 1;
    unsigned short heap;                   /* 0x1f0 */
    char pad1f2[2];
    int f1f4;                   /* 0x1f4 */
    int slots[8];               /* 0x1f8 */
    unsigned int tbl[8];                 /* 0x218 */
    int f238;                   /* 0x238 */
    int f23c;
    int f240;
    int f244;
    int f248;
} BtlvEff;

typedef struct {
    fx32 x, y, z;
} VecFx32_vFE48;

typedef struct {
    void *owner;        /* 0x000 */
    char pad[0x540 - 4];
    u16 heap;           /* 0x540 */
} Work_0220074C;

extern void *func_02030DA8(void *owner, void (*fn)(void *, void *), void *p, u32 n);
void func_02208870(void *w, int sel);
void func_021F81EC(int sel);
void func_021F896C(void *h, void (*cb)(void *), int arg);
void func_0220074C(Work_0220074C *w, int i, int kind, VecFx32_vFE48 *p, VecFx32_vFE48 *q, int n, int f48, int f4c, void *fn, void (*cb)(void *), int flip, u8 f50);
extern BtlvEff *d_0220AF20;

void func_021F81EC(int sel)
{
    func_02208870((void *)d_0220AF20->h1a4, sel);
}
