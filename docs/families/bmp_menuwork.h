/*
 * docs/families/bmp_menuwork.h -- the bmp_menuwork.c family (menu item
 * lists), 0x0201F81C..0x0201F91C.  __FILE__ anchor 0x020A7374
 * "bmp_menuwork.c", loaded by func_0201F81C (pool word 0x0201F864).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file.  Written 2026-09-23
 * (wave 14).  EXACT: func_0201F81C (new), func_0201F868, func_0201F878,
 * func_0201F898, func_0201F8B8, func_0201F8F4, func_0201F91C.  No open row.
 */

#ifndef BMP_MENUWORK_H
#define BMP_MENUWORK_H

typedef unsigned int u32;

/* 8 bytes per entry; the list ends with { 0xFFFFFFFF, heap }. */
typedef struct {
    const void *str;    /* +0x00  message string (NULL = free slot) */
    u32         param;  /* +0x04  value returned on selection */
} BmpMenuWork;

extern char sBmpMenuWorkFile[];     /* 0x020A7374 */
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u32 line);

/* n cleared entries plus the terminator, line 0x29.  The loop stores zero;
 * reading it as storing the index was the old DIFF. */
BmpMenuWork *func_0201F81C(u32 n, u32 heap);

/* Add one entry from a message archive.  Callers pass a fifth, stack word
 * (the heap id, func_0201FDA0 stores it at [sp]); the matched body is
 * written with four because the fifth is never read. */
void func_0201F878(BmpMenuWork *list, void *msg, u32 strId, u32 param,
                   u32 heap);

#endif
