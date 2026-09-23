/*
 * docs/families/key.h -- shared declarations for the key.c family
 * (0x02035EE8..0x0203640C in the ARM9 image; the __FILE__ anchor at
 * 0x020A799C reads "key.c" and is loaded by func_02035EE8, line 0x44).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Every declaration is derived from a src/matched file that is EXACT,
 * named beside the field or prototype it evidences.  Written wave 13, after
 * func_02035F38 and func_020360B8 closed, so the whole range is matched.
 *
 * Addresses are Black-image addresses throughout.
 *
 * ISA: ARM throughout.  Compiler: dsi/1.1p1 for every member (../2.0/sp2 was
 * measured on both wave-13 closes and is 4-8 bytes long on each).
 *
 * WHAT THE FAMILY IS.  The pad (button) reader.  One 0x4C-byte state object
 * (struct Key) per context, allocated by func_02035EE8 and reached through
 * the context's first word (func_0203521C, `ldr r0,[r0]; bx lr`, is the
 * getter; func_02035224 returns the current context).  Every public entry
 * point comes in a pair: sub_XXXX(ctx) does the work and the next function
 * is a 16-byte `sub_XXXX(func_02035224())` forwarder.
 */

#ifndef KEY_H
#define KEY_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef volatile u16   vu16;

/* ------------------------------------------------------------------ *
 * struct Key -- 0x4C bytes (func_02035EE8 allocates 0x4c and clears it).
 * ------------------------------------------------------------------ */
struct Key {
    u32 f00;            /* 0x00  func_02036290 stores its a1 here           */
    u8  pad04[0x08];
    u32 cont;           /* 0x0C  hold word of the PREVIOUS frame; trigger
                         *       and repeat are derived against it
                         *       (func_02035F38)                            */
    u32 trg;            /* 0x10  new presses: key & (key ^ cont)            */
    u32 rpt;            /* 0x14  presses + auto-repeat                      */
    u32 f18;            /* 0x18  published HOLD word  } remapped in place   */
    u32 f1c;            /* 0x1C  published TRIGGER    } by func_020360B8    */
    u32 f20;            /* 0x20  published REPEAT     }                     */
    u32 f24;            /* 0x24  latched hold    } every other frame, from  */
    u32 f28;            /* 0x28  latched trigger } the accumulators below   */
    u32 f2c;            /* 0x2C  latched repeat  } (func_02035F38)          */
    u32 f30;            /* 0x30  accumulated hold    } OR-ed each frame,    */
    u32 f34;            /* 0x34  accumulated trigger } zeroed at the latch  */
    u32 f38;            /* 0x38  accumulated repeat  }                      */
    s32 wait;           /* 0x3C  repeat countdown                           */
    s32 speed;          /* 0x40  repeat period; func_02035EE8 sets 8,
                         *       func_02036254 stores its a1                */
    s32 delay;          /* 0x44  first-repeat delay; func_02035EE8 sets 15,
                         *       func_02036254 stores its a2                */
    u32 f48;
};

/* The accessor pairs read f18/f24 (sub_020362EC), f20/f2c (sub_0203631C),
 * f1c/f28 (sub_020362BC): the second (latched) word when ctx->f3d == 30,
 * the live word otherwise.  func_020363B8/D4/F0 store (a1, a2) into
 * (f1c, f28) / (f18, f24) / (f20, f2c).  sub_02036390 zeroes f24..f38.     */

/* The context object: only the two bytes the matched files read. */
struct KeyCtx {
    struct Key *key;    /* 0x00  func_0203521C                               */
    u8  pad04[0x39];
    u8  f3d;            /* 0x3D  == 30 selects the latched words            */
    u8  f3e;            /* 0x3E  frame parity; func_02035F38 latches when
                         *       `f3e % 2 == 0` -- the SIGNED %2 quartet on a
                         *       u8 byte (lsr #31 / rsb / adds ror #31)     */
};

/* The remap table walked by func_020360B8: 12-byte records from
 * key->f00 + key->f08 * 12, op byte at +8 (0 ends the walk). */
struct KeyRemap {
    u32 a;              /* 0x00 */
    u32 b;              /* 0x04 */
    u8  op;             /* 0x08  0 end, 1 OR b where a, 2 swap a<->b, 3 clear a */
    u8  pad09[3];
};

/* ------------------------------------------------------------------ *
 * Hardware, as the SDK inlines spell it (cast constants, NOT relocations;
 * func_02035F38 reuses the 0x02FFFFA8 pool word shifted right by 12 as the
 * 0x2FFF mask).
 * ------------------------------------------------------------------ */
#define HW_BUTTON_XY_BUF    0x02FFFFA8
#define REG_KEYINPUT        0x04000130
#define PAD_ALL_MASK        0x2FFF

static inline s32 PAD_DetectFold(void)
{ return (s32)((*(vu16 *)HW_BUTTON_XY_BUF & 0x8000) >> 15); }

static inline u16 PAD_Read(void)
{ return (u16)(((*(vu16 *)REG_KEYINPUT | *(vu16 *)HW_BUTTON_XY_BUF)
                ^ PAD_ALL_MASK) & PAD_ALL_MASK); }

/* ------------------------------------------------------------------ *
 * Prototypes, address order.
 * ------------------------------------------------------------------ */
struct Key *func_0203521C(struct KeyCtx *ctx);    /* ctx->key               */
struct KeyCtx *func_02035224(void);               /* current context        */
struct Key *func_02035EE8(u32 heap);              /* alloc 0x4c, clear,
                                                     speed 8, delay 15      */
void func_02035F38(struct KeyCtx *ctx);           /* per-frame update       */
void sub_020360A8(void);                          /* func_02035F38(current) */
void func_020360B8(struct Key *k);                /* apply the remap table  */
/* func_020360B8 LEVER (wave 13): the op-2 accumulator is a FRESH zero per
 * word (`u32 v = 0;` in a per-word inline or block).  Three function-scope
 * zeros copied into one v rotate 0xFFFF out of lr (127 bytes). */
struct Key *func_02036254(u32 a0, s32 speed, s32 delay);
struct Key *func_02036270(s32 speed, s32 delay);  /* forwarder              */
struct Key *func_02036290(u32 a0, u32 v);         /* key->f00 = v           */
void *sub_020362BC(struct KeyCtx *ctx);           /* trg or latched trg     */
void *sub_020362EC(struct KeyCtx *ctx);           /* hold or latched hold   */
void *sub_0203631C(struct KeyCtx *ctx);           /* rpt or latched rpt     */
void  sub_0203634C(struct KeyCtx *ctx, u32 *speed, u32 *delay);
void  sub_02036390(struct KeyCtx *ctx);           /* zero f24..f38          */
void  func_0203640C(void *rec, u32 a, int b);     /* a neighbouring record
                                                     init; (short)b at +4   */

#endif /* KEY_H */
