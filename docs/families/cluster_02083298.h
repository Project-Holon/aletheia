/*
 * docs/families/cluster_02083298.h -- shared declarations for the
 * pseudo-family pkt_02083298 (0x02083298, 0x02083334, 0x020833D0 in the ARM9
 * image).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Black-image addresses.
 *
 * WHAT IT IS.  TwlSDK libmi mi_memory.o, MI_CpuMove (0x02083194, 788 bytes,
 * libmatch 785 of 788 concrete, ends 0x020834A8).  The three open addresses
 * are its misalignment-1/2/3 backward kernels (shift 8/24, 16/16, 24/8), each
 * leaving by a plain `b 0x02083460` into the byte tail that lies inside the
 * third one.  NOT FUNCTIONS; see docs/families/cluster_02083028.h for the
 * full proof and the integrator fix.  docs/notes/pkt_02083298.c.txt (wave 7)
 * had the not-C verdict right but read it as MSL memmove; the library is
 * libmi, and libmatch already holds the bytes.
 *
 * The matched neighbours that follow the tail are the same object's other
 * asm members: MI_Zero36B at 0x020834A8 (Thumb, libmatch) and
 * func_020834B8 (`swp r0,r0,[r1]`, EXACT asm, src/matched/func_020834B8.c).
 */

#ifndef CLUSTER_02083298_H
#define CLUSTER_02083298_H

typedef unsigned int u32;

extern void MI_CpuMove(const void *src, void *dest, u32 size);   /* 0x02083194 */
extern int  func_020834B8(int val, int *ptr);                    /* EXACT, asm */

#endif /* CLUSTER_02083298_H */
