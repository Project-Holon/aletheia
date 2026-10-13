/*
 * function: ARC_TOOL_ReadHandleHeader
 * address:  0x0204919C
 * packet:   pkt_0204919C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02078B44  0x02078B44  arm
 *   func_02078B70  0x02078B70  arm
 *
 * Walk the reader past its own header.  A halfword count at +0x4c is read
 * first, then skipped by, then a six-byte record is read into a stack buffer
 * whose first word is added to that count and whose third halfword lands in
 * the object at +0x4e; the running total then skips the following four-byte
 * field, which is read into the second half of the same buffer and added to
 * the total for the final offset at +0x48.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadHandleHeader.c \
 *       --func ARC_TOOL_ReadHandleHeader --addr 0x0204919C --cc 1.1p1 --arm
 */
#include "../include/Obj05745.h"
#include "../include/Obj08859.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct FSFile;
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);

void ARC_TOOL_ReadHandleHeader(u8 *p)
{
    u8 buf[12];
    u32 off;

    ((struct Obj05745 *)p)->f4C = 0;
    func_02078B44((struct FSFile *)p, 0xc, 0);
    func_02078B70((struct FSFile *)p, p + 0x4c, 2);
    func_02078B44((struct FSFile *)p, ((struct Obj05745 *)p)->f4C + 4, 0);
    func_02078B70((struct FSFile *)p, buf, 6);
    ((struct Obj05745 *)p)->f4E = ((struct Obj08859 *)buf)->f4;
    off = ((struct Obj05745 *)p)->f4C + ((struct Obj08859 *)buf)->f0;
    func_02078B44((struct FSFile *)p, off + 4, 0);
    func_02078B70((struct FSFile *)p, buf + 8, 4);
    ((struct Obj05745 *)p)->f48 = off + ((struct Obj08859 *)buf)->f8;
}
