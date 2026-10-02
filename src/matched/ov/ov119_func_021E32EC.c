/*
 * function: func_021E32EC
 * address:  0x021E32EC
 * packet:   pkt_ov119_021E32EC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_02047910  0x02047910  arm
 *   func_02047964  0x02047964  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02051534  0x02051534  arm
 *   func_02051574  0x02051574  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02011590  0x02011590  thumb
 *   d_021E7AC8  0x021E7AC8  data a4
 *   d_021E8144  0x021E8144  data a4
 */

typedef unsigned short u16;

typedef struct {
    void (*fn)(char *p, void *out);
    int unused;
} Handler;

typedef struct {
    int x;
    int amount;
} Cfg;

typedef struct {
    char pad00[0x90];
    int *a90;           /* 0x090 */
    int *a94;           /* 0x094 */
    int *a98;           /* 0x098 */
    int *a9C;           /* 0x09C */
    int pada0[2];       /* 0x0A0 */
    int aA8;            /* 0x0A8 */
    int aAC;            /* 0x0AC */
} Sub;

extern const Handler d_021E7AC8[];
extern Cfg d_021E8144;
extern void *func_02048A18(void *, u16);
extern int func_0204779C(void *);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02047964(void);
extern void func_02048AD0(void *);
extern void func_020479D8(void);
extern int func_02051534(void);
extern int func_02051574(void);
extern void func_02047A60(void *, void *);
extern int func_02011590(void *, int);

void func_021E32EC(char *p)
{
    char buf[0x3C];
    void *q;
    int n;
    int i;
    int idx;

    idx = *(int *)(p + 0x109C);
    if (idx == -1)
        return;
    if (d_021E7AC8[idx].fn != 0)
        d_021E7AC8[idx].fn(p, buf);
    if (*(u16 *)(p + 0x824) != 0xFFFF) {
        q = func_02048A18(*(void **)(p + 0x820), *(u16 *)(p + 0x824));
        n = func_0204779C(q);
        for (i = 0; i < n; i++)
            func_02047910(q, (u16)i, d_021E8144.amount);
    }
    func_02047964();
    func_02048AD0(*(void **)(p + 0x83C));
    func_020479D8();
    if (*(void **)(p + 0xC) != 0) {
        func_02051534();
        func_02051574();
    }
    if (*(u16 *)(p + 0x824) != 0xFFFF)
        func_02047A60(func_02048A18(*(void **)(p + 0x820), *(u16 *)(p + 0x824)), buf);
    if (*(Sub **)(p + 0xC) != 0) {
        if ((*(Sub **)(p + 0xC))->a90 != 0) {
            if ((*(Sub **)(p + 0xC))->aA8 == 0)
                (*(Sub **)(p + 0xC))->aA8 = func_02011590((*(Sub **)(p + 0xC))->a90, d_021E8144.amount);
            if ((*(Sub **)(p + 0xC))->aAC == 0)
                (*(Sub **)(p + 0xC))->aAC = func_02011590((*(Sub **)(p + 0xC))->a94, d_021E8144.amount);
        }
        if ((*(Sub **)(p + 0xC))->a9C != 0)
            func_02011590((*(Sub **)(p + 0xC))->a9C, d_021E8144.amount);
        if ((*(Sub **)(p + 0xC))->a98 != 0)
            func_02011590((*(Sub **)(p + 0xC))->a98, d_021E8144.amount);
    }
}
