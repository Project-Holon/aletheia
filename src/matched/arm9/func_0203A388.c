/*
 * function: GFL_NET_HANDLE_RecvInfoData
 * address:  0x0203A388
 * packet:   pkt_0203A388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0203996C  0x0203996C  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   func_0203D798  0x0203D798  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   file_020A7A68  0x020A7A68  data
 *   file_020A7ACC  0x020A7ACC  data
 *
 * Install a payload into slot `id`: bail out when the receiver is the own
 * link (GFL_NET_HANDLE_GetNetHandleID returning 0xFF), report at line 0x3D1 (977) when the
 * slot index is out of range, free whatever the slot already holds, allocate
 * `len` bytes out of the heap named by the record's +0x56 halfword (line
 * 0x3D8), publish the buffer and its length together, and copy the payload
 * in.
 *
 * THIS FUNCTION TAKES FIVE PARAMETERS, NOT FOUR.  That is the whole of what
 * docs/notes/pkt_0203A388.c.txt diagnosed as a register-colouring residue.
 * The prologue is `push {r3, r4, r5, r6, r7, lr}`, six registers and so 0x18
 * bytes of frame, which makes the `ldr r0, [sp, #0x18]` at +0x18 a read
 * ABOVE the frame -- the caller's fifth argument -- and not the r3 home slot
 * the note read it as.  r3 is a dead fourth argument, the table-handler shape
 * this family uses throughout (GFL_NET_HANDLE_RecvNegotiationReturn, GFL_NET_HANDLE_RecvTimingSync, GFL_NET_HANDLE_RecvRemoveHandle).
 * Written with four parameters the compiler has to keep the receiver in a
 * register across func_0203D798, which costs r8, an extra callee-saved and a
 * spill slot: 172 bytes against 156.  With the fifth parameter the body is
 * size-exact and two bytes out, both of them trivial:
 *
 *   - the slot bound is SIGNED (`int id`, `id >= 9`).  The image's `blt`
 *     becomes `blo` the moment the index is unsigned.
 *   - the allocator's name argument is the file string 0x020A7A68, the same
 *     word the assert's first argument uses, NOT the message 0x020A7ACC.
 *     Both are pool words at nearly the same displacement, so the wrong one
 *     costs exactly one byte of `ldr` offset.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_RecvInfoData.c \
 *       --func GFL_NET_HANDLE_RecvInfoData --addr 0x0203A388 --cc 1.1p1 --arm
 */
#include "../include/Obj15954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *file, u32 line, const char *msg);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
extern void *func_0203D798(void);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern const char file_020A7A68[];
extern const char file_020A7ACC[];

struct Slot {
    void *buf;
    u32   len;
};

void GFL_NET_HANDLE_RecvInfoData(int id, u32 len, const void *src, u32 a3, void *obj)
{
    u8 *g;
    struct Slot *s;

    g = func_0203D798();
    if (GFL_NET_HANDLE_GetNetHandleID(obj) == 0xff)
        return;
    if (id >= 9)
        func_02034714(file_020A7A68, 0x3D1, file_020A7ACC);
    s = (struct Slot *)func_0203996C(id);
    if (s->buf != 0)
        func_020307B0(s->buf);
    s->buf = func_02030734(((struct Obj15954 *)g)->f56, len, 1, file_020A7A68, 0x3D8);
    s->len = len;
    MI_CpuCopy8(src, s->buf, len);
}
