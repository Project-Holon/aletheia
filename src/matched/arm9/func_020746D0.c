/*
 * function: func_020746D0
 * address:  0x020746D0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 *
 * Release callback func_02074048 registers with func_0207482C for the
 * allocation it stores at Arc +0x88: the request drain (func_02074770 /
 * func_020748E0) invokes it as cb(node + 0x20, f08, f10, f14) with f10 the
 * Arc object, and it forgets the pointer.  One of three 12-byte unlabelled
 * leaves disasm.py prints as .word data after pool_020746C0.
 */
typedef unsigned char u8;
typedef unsigned int  u32;

struct Arc { u8 pad_00[0x88]; u32 f88; u32 f8c; u32 f90; };

void func_020746D0(void *payload, u32 size, struct Arc *c)
{
    c->f88 = 0;
}
