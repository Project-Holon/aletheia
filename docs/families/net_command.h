/*
 * docs/families/net_command.h -- the net_command.c family, around
 * 0x0203A67C..0x0203AB00 in the ARM9 image (ARM code).  Assert strings:
 * 0x020A7AF8 (file), 0x020A7B20, 0x020A7B50.
 *
 * REFERENCE DOCUMENT ONLY; nothing includes it.  Written 2026-09-23 (wave 15
 * tail lane) from src/matched/func_0203A958.c and the matched
 * func_0203A81C / func_0203AA94 members.
 *
 * LEVER THAT CLOSED IT (shared with net_handle.c func_0203A020): message
 * and record parameters that are only read are `const u8 *`.  Without the
 * pointee const, 1.1p1 orders every store to the table against the reads of
 * the record and loses the image's load hoisting (11 to 39 bytes out).
 */

#ifndef NET_COMMAND_H
#define NET_COMMAND_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8  *g_021469D8;          /* command table; slot i at +i*0x14, fields +0xb8..+0xca */
extern int  func_020399A8(void);
extern int  func_0203A81C(int id, int slot, int word);
extern void func_02034714(char *file, u32 line, char *msg);   /* assert */

extern void func_0203A958(int slot, int a1, const u8 *rec, int a3, int owner);

#endif /* NET_COMMAND_H */
