/*
 * docs/families/net_lower_data.h -- shared declarations for the
 * net_lower_data.c family (0x0203E5F8..0x0203EE18, matched through
 * 0x0203EFC8).  The __FILE__ anchor is "net_lower_data.c" at 0x020A7D74
 * (eight pool sites, 0x0203E6B8..0x0203EF50).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Every declaration
 * is derived from an EXACT file in src/matched, named beside it.
 *
 * ISA: ARM throughout (pass --arm).  COMPILER: dsi/1.1p1; no sp2 pin.
 *
 * SHAPE RULES
 *  - Every accessor opens with SDK_ASSERT-style checks that survive in the
 *    release build: `if (g_021469F4 == 0) func_02034714(file, line, expr);`
 *    with file 0x020A7D74 and the expression strings 0x020A7D88.. (see
 *    func_0203E758.c for the pattern and line numbers).
 *  - The table-slot guard `if (g == 0 || g->ch[idx] == 0) return;` appears
 *    twice around func_0203D798() in func_0203ECD8 / func_0203EE18.  When the
 *    function RETURNS a value and the two null exits must share one trailing
 *    `return 0`, write the FIRST guard as a wrapping positive test
 *    (`if (g != 0 && g->ch[idx] != 0) { ... } return 0;`) -- func_0203EC7C.
 *  - A long state machine is a plain if / else-if chain with no gotos
 *    (func_0203EA9C was exact on the first compile that way).
 * ------------------------------------------------------------------------- */

#ifndef NET_LOWER_DATA_H
#define NET_LOWER_DATA_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* A channel record, 0x48 bytes at heap from func_02030734 (func_0203E808). */
typedef struct NetLowerCh {
    void *buf;          /* +0x00 data; freed when flags bit1 (owns) is set */
    u32   f4;           /* +0x04 func_0203E808's a0 */
    u32   f8;
    u32   len;          /* +0x0C func_0203E9DC returns it; func_0203EC7C returns buf+len */
    u8    flags;        /* +0x10 bit0 used by func_0203EE18, bit1 = owns buf */
} NetLowerCh;

/* The manager, 0x48 bytes, created by func_0203E5F8, freed by func_0203E6C0. */
typedef struct NetLowerMgr {
    NetLowerCh *ch[8];  /* +0x00 eight channel slots (func_0203E6C0 loops 8) */
    void *sendData;     /* +0x20 transfer in progress (func_0203E758 sets) */
    u32   sendTotal;    /* +0x24 */
    u8    sendTag;      /* +0x28 */
    u8    pad29[3];
    u32   sendMode;     /* +0x2C 1 selects func_0203996C(0xFF) / the +0x6C window */
    u32   endPosted;    /* +0x30 */
    u32   firstPending; /* +0x34 */
    u32   f38;          /* +0x38 ctor's a1; ==1 disarms after each chunk */
    u32   armed;        /* +0x3C */
    u32   ackPending;   /* +0x40 */
    u32   sent;         /* +0x44 */
} NetLowerMgr;
/* NOTE: func_0203ECD8.c declares the slot array as [0xe]; only [8] fits
 * before +0x20, which func_0203E758 / func_0203EA9C use as scalars. */

extern NetLowerMgr *g_021469F4;     /* 0x021469F4 */
extern void        *g_021469F0;     /* 0x021469F0  a separate 0x10C-byte state
                                     * (func_0203E538 / func_0203E5AC) */

void func_0203E5F8(int heap, int a1);          /* create */
void func_0203E6C0(void);                      /* destroy */
void func_0203E758(void *data, u32 total, u8 tag, u32 mode);   /* start a send */
void func_0203E808(void *f4, u32 idx, int heap, void *buf);   /* open channel */
void func_0203E8C8(u32 idx);                   /* close channel */
void *func_0203E96C(u32 idx);                  /* channel buffer */
u32  func_0203E9DC(u32 idx);                   /* channel length */
void func_0203EA9C(void);                      /* per-frame send pump */
int  func_0203EC04(int len);                   /* send one chunk; returns 1 on success
                                                * (func_0203EA9C tests it; the matched
                                                * file spells it void) */
u32  func_0203EC7C(u32 idx);                   /* buf + len of channel idx */
void func_0203ECD8(u32 idx, u32 delta, u32 a2, u32 a3, u32 who);
int  func_0203ED84(int kind);                  /* post control packet 0/1/2; returns 1
                                                * when posted (func_0203EA9C; the matched
                                                * file spells it void) */

#endif /* NET_LOWER_DATA_H */
