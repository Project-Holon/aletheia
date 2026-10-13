/*
 * function: GFL_NET_HANDLE_InitWork
 * address:  0x02039834
 * packet:   pkt_02039764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pBaseWork     0x021469D4  data
 *   file_020A7A68  0x020A7A68  data
 *   msg_020A7A7C   0x020A7A7C  data
 *   GFL_NET_HANDLE_CreateHandle  0x02039764  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02030734  0x02030734  arm
 *   func_02034714  0x02034714  arm
 *
 * Module bring-up, the twin of GFL_NET_HANDLE_ExitWork's teardown: reset all eight
 * peer slots through GFL_NET_HANDLE_CreateHandle, reset the own slot (0xFF) too, assert
 * that the module handle _pBaseWork is NOT already live, then allocate the
 * 0x20-byte handle for it out of the heap named by the record's +0x56
 * halfword (line 0xE5; the assert is line 0xE3).
 *
 * TWO LEVERS, both of which the note in docs/notes/pkt_02039764.c.txt was
 * one step short of.
 *
 * DECLARATION ORDER: `int i;` before `u8 *p;`.  With `p` declared first the
 * allocator colours the object pointer r4 and the reset index r5, which is
 * the swap of the image's r5/r4 the note recorded; swapping the two
 * declarations swaps the colours back
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The note tried this "and it does not move it" only because the remaining
 * residue below masked the result.
 *
 * ASSERT POLARITY: the guard is `_pBaseWork != 0`, not `== 0`.  The image
 * skips the report with `beq`, so the report runs on the NON-null handle:
 * bringing a module up twice is the error, where GFL_NET_HANDLE_ExitWork's matching
 * assert at line 0x100 fires on the null handle because tearing down a dead
 * module is the error there.  Getting it backwards is a one-byte diff
 * (the condition field of a single branch) and nothing else.
 *
 * The note's second finding is now stale: GFL_NET_HANDLE_CreateHandle's only branch sites
 * image-wide are this function's own two calls, so `label` still refuses it,
 * but `sole-ref/code` carries it (0x02039764 is a traced function start), and
 * msg_020A7A7C resolves through `sole-ref` the same way.  This file is EXACT,
 * not the MATCH the note predicted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_InitWork.c \
 *       --func GFL_NET_HANDLE_InitWork --addr 0x02039834 --cc 1.1p1 --arm
 */
#include "../include/Obj15945.h"
#include "../include/G_Votes.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct Votes *_pBaseWork;
extern const char file_020A7A68[];
extern const char msg_020A7A7C[];

struct Entry;
extern struct Entry *GFL_NET_HANDLE_CreateHandle(u32 idx);
extern void *func_0203D798(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *file, u32 line, const char *msg);

void GFL_NET_HANDLE_InitWork(void)
{
    int i;
    u8 *p;

    p = func_0203D798();
    for (i = 0; i < 8; i++) {
        GFL_NET_HANDLE_CreateHandle(i);
    }
    GFL_NET_HANDLE_CreateHandle(0xff);

    if (_pBaseWork != 0) {
        func_02034714(file_020A7A68, 0xe3, msg_020A7A7C);
    }
    _pBaseWork = func_02030734(((struct Obj15945 *)p)->f56, 0x20, 1, file_020A7A68, 0xe5);
}
