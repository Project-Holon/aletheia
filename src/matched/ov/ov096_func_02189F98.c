/*
 * function: TR_AI_CompareGeneric
 * address: 0x02189F98
 * packet: pkt_ov096_02189F98
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Two-byte zero alignment padding follows the compiled function.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   TR_AI_Compare 0x0218A0F4 thumb ov096
 */
#include "../include/Obj21983.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern int TR_AI_Compare(unsigned char *, int, int, int, int);
int TR_AI_CompareGeneric(unsigned char *a, unsigned char *b, int c) { int x,y; x=VM_GetU32((struct Cursor *)a); y=VM_GetU32((struct Cursor *)a); return TR_AI_Compare(a,c,((struct Obj21983 *)b)->fCC,x,y); }
