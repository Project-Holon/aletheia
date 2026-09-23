/*
 * docs/families/net_ring_buff.h -- shared declarations for the
 * net_ring_buff.c family (0x02036428..0x020367C4 in the ARM9 image, with the
 * matched neighbours 0x0203640C and 0x020367C4..0x020368C0 at either end).
 * The __FILE__ anchor is "net_ring_buff.c" at 0x020A79A4 (pool sites
 * 0x020364CC in func_02036428 and 0x02036538 in func_02036500).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Every declaration
 * is derived from an EXACT file in src/matched, named beside it.
 *
 * ISA: ARM throughout (unusual for game code; always pass --arm).
 * COMPILER: dsi/1.1p1 for every function; no sp2 pin.
 *
 * THE ONE RULE: the two cursors are re-read from memory where the image
 * re-reads them.  The write cursor (+0x0E) is effectively VOLATILE: declare
 * it `volatile short` in the struct (func_02036428) or use `*(volatile short
 * *)` on the re-reads (func_020365E8).  Without it mwccarm CSEs the second
 * `ldrsh [rN, #0xe]` away and the function comes out 4-8 bytes short.  The
 * read cursor (+0x0C) is NOT volatile (func_02036568 goes wrong with it).
 * ------------------------------------------------------------------------- */

#ifndef NET_RING_BUFF_H
#define NET_RING_BUFF_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

typedef struct NetRingBuff {
    u8             *buf;    /* +0x00 storage; func_0203640C */
    int             size;   /* +0x04 capacity; modulus of func_02036624 */
    u32             pad8;
    short           head;   /* +0x0C read cursor (s16: ldrsh) */
    volatile short  tail;   /* +0x0E write cursor */
} NetRingBuff;              /* 0x10 bytes */

void func_0203640C(NetRingBuff *r, u8 *buf, int size);   /* init; zeroes both cursors */
void func_02036428(NetRingBuff *r, const u8 *src, int len);
                                        /* write; refuses (func_02039548) unless
                                         * free > len; asserts src at line 0x44 */
int  func_020364D4(NetRingBuff *r, u8 *dst, u32 len, u32 max);
                                        /* read and advance head (callers pass 4 args;
                                         * the matched file spells only the first) */
u32  func_02036500(NetRingBuff *r);     /* read one byte, assert at line 0x6C */
u16  func_02036540(NetRingBuff *r);     /* read a big-endian u16 */
int  func_02036568(NetRingBuff *r, u8 *dst, int len, int max);
                                        /* peek; DIFF, see docs/notes/pkt_02036568.c.txt */
int  func_020365E8(NetRingBuff *r);     /* used bytes */
int  func_0203660C(NetRingBuff *r);     /* size - used (out of line) */
int  func_02036624(NetRingBuff *r, int i);   /* i % size (_s32_div_f) */
int  func_02036640(NetRingBuff *r);     /* free bytes = size - used, with used
                                         * INLINED from func_020365E8's body */
void func_0203666C(void);               /* empty */

/* The send-queue helpers that share the file (net_queue items; the queue
 * node is 0x14 bytes, the table of them at +0x18 with count at +0x1C). */
typedef struct NetSendItem {
    u8  *src;           /* +0x00 payload source, or NULL = take from the ring */
    u32  pad4, pad8;
    u16  rest;          /* +0x0C bytes still to send */
    u16  fE;            /* +0x0E header word 1 (func_0203675C writes it big-endian) */
    u8   f10;           /* +0x10 header byte */
    u8   headerDone;    /* +0x11 */
} NetSendItem;
typedef struct NetOutBuf { u8 *ptr; u16 len; } NetOutBuf;   /* func_02036738 */

u8  *func_02036670(u32 *q);             /* first free node (+0x0E == 0) */
int  func_020366C0(u8 *q);              /* count of used nodes */
u32  func_020366FC(u32 *list);          /* pop head of a linked list */
void func_02036738(NetOutBuf *o, int byte);  /* put one byte */
int  func_0203675C(NetSendItem *it, NetOutBuf *o);  /* five-byte header */
int  func_020367C4(NetSendItem *it, NetOutBuf *o, NetRingBuff *r, BOOL needHeader);

#endif /* NET_RING_BUFF_H */
