/*
 * file:     unit_02067CB0.c
 * unit:     yes
 * function: func_02067CB0, func_02067D14
 * address:  0x02067CB0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02148B48  0x02148B48  data
 *   func_02067998 0x02067998  arm
 *   func_02067340 0x02067340  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef void (*CB)(void *, u32);

struct OamSoftEmuParams {
    u8 pad_00[0x10];
    u32 isEnabled;                     /* 0x10 */
    u32 mode;                          /* 0x14 */
    CB pBeforeRenderFunc;                    /* 0x18 */
    CB pAfterRenderFunc;                    /* 0x1c */
};

struct OamSoftEmuContext {
    struct OamSoftEmuParams *pParams;      /* 0x00 */
    u8 pad_04[0x0c];
    u32 queuedCount;                   /* 0x10 */
    u8 pad_14[0x14];
    u32 drawnCount;                    /* 0x28 */
    u32 skippedCount;                  /* 0x2c */
    u32 isRenderRequested;             /* 0x30 */
};

extern void func_02067998(struct OamSoftEmuParams *params, void *pOamList);
extern void func_02067340(struct OamSoftEmuParams *params, u32 pOamList);
void func_02067CB0(void);
void func_02067D14(u32 pOamList);
extern struct OamSoftEmuContext *g_02148B48;


void func_02067CB0(void)
{
    struct OamSoftEmuContext *ctx = g_02148B48;

    if (ctx->pParams->mode == 0) {
        volatile u32 *reg = (volatile u32 *)0x04000440;
        reg[0] = 0;
        reg[2] = 1;
        reg[0] = 1;
    } else {
        ctx->queuedCount = 0;
        g_02148B48->skippedCount = 0;
        g_02148B48->drawnCount = 0;
    }
    g_02148B48 = 0;
}


/*
 * blocked:  MATCH, byte-exact, 180 bytes. Two call targets have no witness outside this
 *           function's own range: 0x02067998 and 0x02067340, each called from nowhere else
 *           in the image. It turns EXACT the moment either gets an entry of its own.
 */
void func_02067D14(u32 pOamList)
{
    struct OamSoftEmuContext *st = g_02148B48;
    struct OamSoftEmuParams *params = st->pParams;

    if (params->isEnabled == 0) {
        return;
    }

    st->isRenderRequested = 1;

    if (params->pBeforeRenderFunc != 0) {
        params->pBeforeRenderFunc(g_02148B48, pOamList);
    }

    if (g_02148B48->isRenderRequested != 0) {
        switch (params->mode) {
        case 0:
            func_02067998(params, (void *)pOamList);
            break;
        case 1:
        case 2:
            func_02067340(params, pOamList);
            break;
        case 3:
            break;
        }
    }

    if (params->pAfterRenderFunc != 0) {
        params->pAfterRenderFunc(g_02148B48, pOamList);
    }
}
